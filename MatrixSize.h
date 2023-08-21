//
// Created by fdilf on 2023-08-01.
//

#include <iostream>
#include <exception>

#ifndef FDIL_MATRIX_MATRIXSIZE_H
#define FDIL_MATRIX_MATRIXSIZE_H

using std::ostream;
using std::exception;

namespace fdil {

    /**
     * m x n sizeM of a matrix
     */
    class MatrixSize {
    private:
        // number of rows
        int m;
        // number of columns
        int n;

        /**
         * Checks if a value is positive
         * @param x value to check
         * @return If x is greater than 0 or not
         */
        static inline bool valueIsPositive(int x) { return x > 0; }


    public:
        /**
         * Default sizeM: 1 x 1
         */
        MatrixSize() : m(1), n(1) {}

        /**
         * Define a m x n sizeM
         * @param m number of rows
         * @param n number of columns
         */
        MatrixSize(int m, int n);

        // define << so can do a quick print of this class
        friend ostream &operator<<(ostream &os, const MatrixSize &size);

        [[nodiscard]] int getM() const;

        void setM(int x);

        [[nodiscard]] int getN() const;

        void setN(int x);

        // equality checks of m and n both are the same
        bool operator==(const MatrixSize &rhs) const;

        // equivalent to !(rhs == *this)
        bool operator!=(const MatrixSize &rhs) const;

        // checks if size has valid dimensions to do dot product with this
        [[nodiscard]] bool dotValid(const MatrixSize &size) const;

        // checks if size has valid dimensions to do cross product with this
        [[nodiscard]] bool crossValid(const MatrixSize &size) const;

        // pre-increment, adds 1 to m
        void operator++(int);

        // post-increment, adds 1 to n
        void operator++();

        // pre-decrement, subtracts 1 from n, doesn't go below 1
        void operator--(int);

        // post-decrement, subtracts 1 from m, doesn't go below 1
        void operator--();

    };

    // a 2d vector size
    const MatrixSize Vector2DSize(2, 1);

    // a 3d vector size
    const MatrixSize Vector3DSize(3, 1);

    const int num = 10;

} // fdil

#endif //FDIL_MATRIX_MATRIXSIZE_H