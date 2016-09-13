//
// Created by sagara on 13/09/16.
//

#ifndef SGM_MATRIX_HPP
#define SGM_MATRIX_HPP

#ifdef DEBUG
#include <iostream>
#endif

template <typename T>
class Matrix
{
private:
    T *mData;
    uint16_t mLine;
    uint16_t mColumn;
    T mDefaultValue;

    void init_data()
    {
        for (uint32_t cpt(0) ; cpt < mLine * mColumn ; ++cpt)
            mData[cpt] = mDefaultValue;
    }

    void delete_data()
    {
        if (mData != nullptr)
            delete []mData;
    }

    Matrix(const Matrix &m) = delete;
    Matrix(const Matrix &&m) = delete;
    const Matrix &operator = (const Matrix &m) = delete;
    const Matrix &operator = (const Matrix &&m) = delete;

public:
    Matrix(const uint16_t &line, const uint16_t &column, const T &default_value = T()):
            mData(new T[line * column]), mLine(line), mColumn(column), mDefaultValue(default_value)
    {
        init_data();
    }

    ~Matrix()
    {
        delete_data();
    }

    inline const T &operator()(const uint16_t &line, const uint16_t &column) const
    {
        return mData[(line * mColumn) + column];
    }

    inline T operator()(const uint16_t &line, const uint16_t &column)
    {
        return mData[(line * mColumn) + column];
    }

    inline const uint16_t line() const
    {
        return mLine;
    }

    inline const uint16_t column() const
    {
        return mColumn;
    }

    void resize(const uint16_t &line, const uint16_t &column, const T &default_value = T())
    {
        delete_data();
        mColumn = column;
        mLine = line;
        mDefaultValue = default_value;
        mData = new T[mLine * mColumn];
        init_data();
    }

#ifdef DEBUG
    void print() const
    {
        for (uint32_t cpt(0) ; cpt < mLine * mColumn ; ++cpt)
        {
            if (cpt != 0 && cpt % mColumn == 0)
                std::cout << '\n';
            else if (cpt % mColumn != 0)
                std::cout << ' ';
            std::cout << mData[cpt];
        }
    }
#endif
};

#endif //SGM_MATRIX_HPP
