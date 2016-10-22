#ifndef SGM_MATRIX_HPP
#define SGM_MATRIX_HPP

#include <vector>

#ifdef DEBUG
#include <iostream>
#endif

template <typename T>
class Matrix
{
private:
    std::vector<T> mData;
    uint64_t mColumn;
    uint64_t mLine;
    T mDefaultValue;

    void init_data()
    {
        for (typename std::vector<T>::iterator it = mData.begin() ; it != mData.cend() ; ++it)
            *it = mDefaultValue;
    }

    void delete_data()
    {}

    void reset_data()
    {
        init_data();
    }

    Matrix(const Matrix &m) = delete;
    Matrix(const Matrix &&m) = delete;
    const Matrix &operator = (const Matrix &m) = delete;
    const Matrix &operator = (const Matrix &&m) = delete;

public:
    Matrix(const uint64_t &line, const uint64_t &column, const T &default_value = T()):
            mData(line * column), mColumn(column), mLine(line), mDefaultValue(default_value)
    {
        init_data();
    }

    virtual ~Matrix()
    {
        delete_data();
    }

    inline const T &operator()(const uint64_t &line, const uint64_t &column) const
    {
        if (line * mColumn + column >= mLine * mColumn)
            throw std::logic_error("out of bound");
        return *(mData.begin() + (line * mColumn + column));
    }

    inline T &operator()(const uint64_t &line, const uint64_t &column)
    {
        if (line * mColumn + column >= mLine * mColumn)
            throw std::logic_error("out of bound");
        return *(mData.begin() + (line * mColumn + column));
    }

    inline const uint64_t line() const
    {
        return mLine;
    }

    inline const uint64_t column() const
    {
        return mColumn;
    }

    void resize(const uint64_t &line, const uint64_t &column, const T &default_value = T())
    {
        delete_data();
        mColumn = column;
        mLine = line;
        mDefaultValue = default_value;
        mData.resize(mColumn * mLine);
        init_data();
    }

#ifdef DEBUG
    void print() const
    {
        typename std::vector<T>::const_iterator it = mData.cbegin();
        uint64_t cpt(0);
        while (it != mData.cend())
        {
            if (cpt == mColumn - 1)
            {
                std::cout << *it << '\n';
                cpt = 0;
            }
            else
            {
                std::cout << *it << ' ';
                ++cpt;
            }
            ++it;
        }
    }
#endif
};

#endif //SGM_MATRIX_HPP
