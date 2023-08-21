//
// Created by fdilf on 2023-08-01.
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
        void print();

        friend ostream &operator<< <>(ostream &os, const Matrix &matrix);

        [[nodiscard]] const MatrixSize &getSize() const;
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
    void Matrix<T>::print() {
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
