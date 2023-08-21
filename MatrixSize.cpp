//
// Created by fdilf on 2023-08-01.
//

#include "MatrixSize.h"

namespace fdil {


    ostream &operator<<(ostream &os, const MatrixSize &size) {
        os << "sizeM: " << size.m << " x " << size.n;
        return os;
    }

    MatrixSize::MatrixSize(int m, int n) {
        if (!valueIsPositive(m) || !valueIsPositive(n))
            throw exception();

        this->m = m;
        this->n = n;
    }

    int MatrixSize::getM() const {
        return m;
    }

    void MatrixSize::setM(int x) {
        if (!valueIsPositive(x))
            throw exception();

        m = x;
    }

    int MatrixSize::getN() const {
        return n;
    }

    void MatrixSize::setN(int x) {
        if (!valueIsPositive(x))
            throw exception();

        n = x;
    }

    bool MatrixSize::operator==(const MatrixSize &rhs) const {
        // same dimensions
        return m == rhs.m &&
               n == rhs.n;
    }

    bool MatrixSize::operator!=(const MatrixSize &rhs) const {
        return !(rhs == *this);
    }

    void MatrixSize::operator++(int) {
        m++;
    }

    void MatrixSize::operator++() {
        n++;
    }

    void MatrixSize::operator--(int) {
        if (m > 1)
            m--;
    }

    void MatrixSize::operator--() {
        if (n > 1)
            n--;
    }


} // fdil