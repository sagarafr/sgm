#ifndef SGM_POSITION2D_HPP
#define SGM_POSITION2D_HPP

#ifdef DEBUG
#include <iostream>
#endif

namespace sgm
{
    namespace position
    {
        template<typename X, typename Y>
        class Position2D
        {
        private:
            X mXPosition;
            Y mYPosition;
            X mDefaultXPosition;
            Y mDefaultYPosition;

        public:
            Position2D(const X &column = X(), const Y &line = Y(),
                    const X &default_column_value = X(), const Y &default_line_value = Y()):
                    mXPosition(column), mYPosition(line),
                    mDefaultXPosition(default_column_value), mDefaultYPosition(default_line_value)
            {}

            virtual ~Position2D()
            {}

            inline const Y &getY() const
            {
                return mYPosition;
            }

            inline const X &getX() const
            {
                return mXPosition;
            }

            inline void setY(const Y &position)
            {
                mYPosition = position;
            }

            inline void setX(const X &position)
            {
                mXPosition = position;
            }

#ifdef DEBUG
            void print() const
            {
            std::cout << "X = " << mXPosition << " | Y = " << mYPosition << std::endl;
            }
#endif
        };
    }
}

#endif //SGM_POSITION2D_HPP
