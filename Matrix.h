//
// Created by fdil on 2023-08-01.
//

#include <iostream>
#include <vector>
#include "MatrixSize.h"

#ifndef FDIL_MATRIX_MATRIX_H
#define FDIL_MATRIX_MATRIX_H

using namespace std;

namespace fdil {

    template<typename T> class Matrix;

    template<typename T>
    ostream &operator<<(ostream &os, const Matrix<T> &matrix);

    /**
     * Class that represents a mathematical Matrix.
     * @tparam T numerical primitive
     */
    template<typename T>
    class Matrix {
    private:
        MatrixSize sizeM;
        vector<vector<T>> matrixM;

        /**
         * Makes self a deep copy of another Matrix
         * @param src Matrix to copy
         */
        void copy(const Matrix& src);

        /**
         * Sets all value of matrix to 0.
         * sizeM and matrixM needs to already been initialized.
         */
        void setZeroMatrix() { setMatrix(0); }

        /**
         * Sets all value of matrix with val
         * @param val the value to set the matrix with
         */
        void setMatrix(T val);

    public:
        /**
         * Default constructor, makes a 1 x 1 zero matrix
         */
        Matrix() : sizeM(), matrixM(1, vector<T>(1)) {
            setZeroMatrix();
        }

        virtual ~Matrix() = default;

        /**
         * Copy constructor, makes *this a deep copy of another Matrix
         * @param src Matrix to copy
         */
        Matrix(const Matrix& src);

        /**
         * Assignment operator, returns a reference to a deep copy
         * @param rhs Matrix to copy, right side of operator
         * @return reference to the deep copy
         */
        Matrix<T>& operator= (const Matrix& rhs);

        /**
         * Makes a m x n zero matrix
         * @param m number of rows
         * @param n number of columns
         */
        Matrix(int m, int n) : Matrix(MatrixSize(m, n)) {}

        /**
         * Makes a zero matrix of the given sizeM.
         * matrixSize passed is copied,
         * so changes to it later is not reflected in Matrix.
         * @param matrixSize sizeM of the matrix
         */
        explicit Matrix(const MatrixSize& matrixSize);


        /**
         * Simple print function to print matrix.
         * Has an extra '\n' at the end.
         */
        [[maybe_unused]] void print();

        friend ostream &operator<< <>(ostream &os, const Matrix &matrix);

        [[nodiscard]] const MatrixSize &getSize() const;

        // operator overloads //

        // + operator overloads
        /**
         * Adds a constant value to all values of this matrix.
         * The result is stored in a new Matrix stored in heap.
         * @param c constant to add
         * @return reference to the result Matrix
         */
        Matrix& operator+ (T c) const;

        /**
         * Does addition of rhs to this matrix if the sizes are the same and
         * store the result in a new Matrix stored in heap.
         * @param rhs matrix to add, should have the same size as *this
         * @return reference to the result Matrix
         */
        Matrix& operator+ (const Matrix& rhs) const;

        // - operator overloads
        /**
         * Subtracts a constant value to all values of this matrix.
         * The result is stored in a new Matrix stored in heap.
         * @param c constant to subtract
         * @return reference to the result Matrix
         */
        Matrix& operator- (T c) const;

        /**
         * Does the following subtraction : *this - rhs, if the sizes are the same and
         * store the result in a new Matrix stored in heap.
         * @param rhs matrix to subtract, should have the same size as *this
         * @return reference to the result Matrix
         */
        Matrix& operator- (const Matrix& rhs) const;

        // += operator overloads
        /**
         * Adds a constant to all values of matrix inplace.
         * @param c constant to add
         */
        void operator+= (T c);

        /**
         * Does addition of rhs to *this inplace.
         * @param rhs matrix to add, should have the same size as *this
         */
        void operator+= (const Matrix& rhs);

        // -= operator overloads
        /**
         * Subtracts a constant to all values of this matrix inplace.
         * @param c constant to subtract
         */
        void operator-= (T c);

        /**
         * Does the following subtraction in place: *this - rhs.
         * @param rhs matrix to subtract, should have the same size as *this
         */
        void operator -= (const Matrix& rhs);

        // * and *= operator overload
        /**
         * Multiplies a constant to all values of this matrix.
         * Result in a separate matrix stored in heap.
         * @param x constant to multiply by
         * @return reference to result Matrix
         */
        Matrix& operator* (T c) const;

        /**
         * Multiplies a constant to all values of this matrix inplace.
         * @param c constant to multiply by
         */
        void operator*= (T c);

        // / and /= operator overload
        /**
         * Divides a constant to all values of this matrix.
         * Equivalent to calling *(1/c)
         * @param c constant to divide by
         * @return reference to result Matrix
         */
        Matrix& operator/ (T c) const;

        /**
         * Divides a constant to all values of this matrix inplace.
         * Equivalent to calling *=(1/c)
         * @param c constant to divide by
         */
        void operator/= (T c);

        // dot and cross product
        /**
         * Does dot product with other if the dimensions work out.
         * This means that *this is m x n, other is n x p and result is m x p.
         * @param other other matrix to do dot product with
         * @return reference to result Matrix
         */
        Matrix& dot(const Matrix& other) const;

        /**
         * Does cross product with other if both dimensions work out.
         * This means both are 1 x 3 or 3 x 1 matrices (3D vectors).
         * Can also work for 2D vectors
         * @param other other matrix to do cross product with
         * @return reference to result Matrix
         */
        Matrix& cross(const Matrix& other) const;
        // might make a separate class for vectors, then move cross product there
        // for 2D and 3D vectors
    };


    template<typename T>
    Matrix<T>::Matrix(const MatrixSize &matrixSize)  : sizeM(matrixSize), matrixM(matrixSize.getM(), vector<T>(matrixSize.getN())) {
        setZeroMatrix();
    }

    template<typename T>
    Matrix<T>::Matrix(const Matrix& src) {
        copy(src);
    }

    template<typename T>
    Matrix<T>& Matrix<T>::operator=(const Matrix &rhs) {
        copy(rhs);
        return *this;
    }

    template<typename T>
    [[maybe_unused]] void Matrix<T>::print() {
        for (int i = 0; i < sizeM.getM(); ++i) {
            for (int j = 0; j < sizeM.getN(); ++j) {
                cout << matrixM.at(i).at(j) << ' ';
            }
            cout << '\n';
        }
        cout << '\n';
    }

    template<typename T>
    ostream &operator<<(ostream &os, const Matrix<T> &matrix) {
        os << matrix.sizeM << "\n";

        for (int i = 0; i < matrix.sizeM.getM(); ++i) {
            for (int j = 0; j < matrix.sizeM.getN(); ++j) {
                os << matrix.matrixM.at(i).at(j) << ' ';
            }
            os << '\n';
        }
        os << '\n';
        return os;
    }

    template<typename T>
    const MatrixSize &Matrix<T>::getSize() const {
        return sizeM;
    }
    
    template<typename T>
    void Matrix<T>::copy(const Matrix &src) {
        // skip check for small performance boost (as most cases not copy self)
        // copying from self provide no changes to value so safe to do
//        if (this == &src)
//            return;

        // copy all variables from src to this
        // using = operator
        sizeM = src.sizeM;
        matrixM = src.matrixM;
    }

    template<typename T>
    void Matrix<T>::setMatrix(T val) {
        for(int i = 0; i < sizeM.getM(); i++) {
            for (int j = 0; j < sizeM.getN(); ++j) {
                matrixM.at(i).push_back(val);
            }
        }
    }


    
} // fdil

#endif //FDIL_MATRIX_MATRIX_H
