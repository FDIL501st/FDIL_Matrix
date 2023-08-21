#include <iostream>
#include "MatrixSize.h"
#include "Matrix.h"

using namespace std;
using namespace fdil;

// separating line to separate chunks of tests
void separator(int n = 10);

int main() {
    std::cout << "Hello, World!" << std::endl;

// test const variables
#if 0
    separator();
    cout << num << '\n';
    cout << Vector2DSize << '\n';
    cout << Vector3DSize << endl;
#endif

// test MatrixSize
#if 0
    separator(10);

    std::cout << fdil::MatrixSize() << '\n';
//    std::cout << fdil::MatrixSize(0, 4) << std::endl;

    // make a separator between tests
    separator(10);

    MatrixSize size1;
    MatrixSize size2(2, 3);
    MatrixSize size3(size2);
    MatrixSize size4 = size2;

    size3.setM(5);
    size4.setN(12);

    cout << size1 << '\n' << size2 << '\n' << size3 << '\n' << size4 << endl;
#endif

// test vector<vector<int>>
#if 0
    separator(10);

    vector<vector<int>> x = vector<vector<int>>();
    x.emplace_back();
    x.emplace_back();
    x[0].push_back(0);
    x[1].push_back(1);
    x[0].push_back(10);
    x[1].push_back(-49);
    for (auto i = x.cbegin(); i < x.cend() ; i++) {
        for (auto j = i->cbegin(); j < i->cend(); j++ ) {
            cout << *j << ' ';
        }
        cout<<'\n';
    }
    cout<< "capacity: " << x.capacity() << endl;

    auto x_ptr = new vector<vector<int>>;
    x_ptr->emplace_back();
    x_ptr->at(0).push_back(0);
    x_ptr->at(0).push_back(1);

    auto ptr = &x_ptr->at(0);


    delete x_ptr;
    /* x_ptr also deletes all things inside as well, including vectors */
    // delete ptr;
#endif

// test vector<vector<int>> constructors
#if 0
    separator(10);

    vector<vector<int>> x(4, vector<int>(2));

    for (auto i = x.cbegin(); i < x.cend() ; i++) {
        for (auto j = i->cbegin(); j < i->cend(); j++ ) {
            cout << *j << ' ';
        }
        cout<<'\n';
    }
    cout<< "capacity: " << x.capacity() << endl;

#endif

// test Matrix<int>
#if 1
    separator();

    Matrix<int> m1 = Matrix<int>(2,4);
//    m1.print();

    Matrix<float> m2 = Matrix<float>(MatrixSize(4, 4));
//    m2.print();

    Matrix<float> m3(m2);
//    m3.print();

    Matrix<float> m2_2(m2);
//    m2_2.print();

    Matrix<short> m4;
//    m4.print();

    std::cout << m4;

    cout << m2;

    auto m2_3 = m2;

    cout << m2_3;
#endif

// test using global const vector 2d and 3d sizes
#if 1
    separator();

    Matrix<double> vector2d(Vector2DSize);
    cout << vector2d;

    Matrix<short> vector3d(Vector3DSize);
    cout << vector3d;

#endif
    return 0;
}


void separator(int n)
{
    for (int i = 0; i < n; i++)
        cout << '-' << ' ';
    cout << '\n';
}