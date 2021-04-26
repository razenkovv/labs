#pragma once

#include "Vector.h"

template <typename T>
class Matrix {
private:
    int m_rows; //число строк
    int m_columns; //число столбцов
    Vector<Vector<T>> data;
public:
    Matrix();

    Matrix(int rows, int columns, const T &value = T());

    void print();
};

template <typename T>
Matrix<T>::Matrix() : m_rows(0), m_columns(0) {
    Vector<Vector<T>> data(0, Vector<T>(0));
}

template <typename T>
Matrix<T>::Matrix(int rows, int columns, const T &value) : m_rows(rows), m_columns(columns) {
    Vector<Vector<T>> data(m_rows, Vector<T>(m_columns, value));
}

template <typename T>
void Matrix<T>::print() {
    for (int i = 0; i < m_columns; ++i) {
        for (int j = 0; j < m_rows; ++j) {
            std::cout << data[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
