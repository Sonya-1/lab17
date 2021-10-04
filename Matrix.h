#ifndef Matrix_H
#define Matrix_H
#include <iostream>
#include <stdexcept>
#include "point.h"

template <class T>
class Matrix {
private:
	T** m;
	size_t row;
	size_t column;

public:
	class Iterator {
	public:
		Matrix* matrix;
		T* pCol;
		T& operator[](size_t col) {
			if (col < 0 || col >= matrix->column) {
				throw std::out_of_range("Col: index out of range");
			}
			return pCol[col];
		}
		Iterator(T* pCol, Matrix* mi) {
			this->pCol = pCol;
			matrix = mi;
		}
	};

	Iterator operator[](size_t row) {
		if (row >= this->row || row < 0) {
			throw std::out_of_range("Row: index out of range");
		}
		return Iterator(m[row], this);
	}

	Matrix();
	Matrix(size_t row, size_t column);
	Matrix(Matrix& mx);
	Matrix<T>& operator=(const Matrix<T>& mx);
	void set(const T& val, size_t row, size_t column);
	const T& get(size_t row, size_t column);
	int rows() { return row; }
	int columns() { return column; }
	Matrix sum(Matrix& m);
	void print();
	~Matrix();
};

template <class T >
Matrix<T>::Matrix() {
	m = NULL;
	row = 0;
	column = 0;
}

template <class T >
Matrix<T>::Matrix(size_t row, size_t column) {
	this->row = row;
	this->column = column;
	m = new T * [row];
	for (size_t i = 0; i < column; i++) 
		m[i] = new T[column];
}

template <class T >
Matrix<T>::Matrix(Matrix& mx) {
	row = mx.row;
	column = mx.column;
	m = new T * [row];
	for (size_t i = 0; i < column; i++) {
		m[i] = new T[column];
	}
	for (size_t i = 0; i < row; i++) {
		for (size_t j = 0; j < column; j++) {
			m[i][j] = mx.m[i][j];
		}
	}
}

template <class T>
Matrix<T>& Matrix<T>::operator=(const Matrix<T>& mx) {
	if (&mx == this) {
		return *this;
	}

	for (size_t i = 0; i < column; i++) {
		delete[] m[i];
		m[i] = NULL;
	}
	
	row = mx.row;
	column = mx.column;
	m = new T * [row];
	for (size_t i = 0; i < column; i++) {
		m[i] = new T[column];
	}

	for (size_t i = 0; i < row; i++) {
		for (size_t j = 0; j < column; j++) {
			m[i][j] = mx.m[i][j];
		}
	}

	return *this;
}

template <class T>
void Matrix<T>::set(const T& val, size_t row, size_t column) {
	if (row >= this->row || column >= this->column) {
		throw std::out_of_range("Set: value out of range");
	}
	m[row][column] = val;
}

template <class T>
const T& Matrix<T>::get(size_t row, size_t column) {
	if (row >= this->row || column >= this->column) {
		throw std::out_of_range("Get: value out of range");
	}
	return m[row][column];
}

template <class T>
Matrix<T> Matrix<T>::sum(Matrix& m) {
	if (this->row != m.row || this->column != m.column) {
		throw std::range_error("Sum: the addition can't be performed due to the wrong dimension of the matrixs");
	}
	T a, b;
	Matrix sum(row, column);
	for (size_t i = 0; i < row; i++) {
		for (size_t j = 0; j < column; j++) {
			a = this->get(i, j);
			b = m.get(i, j);
			sum.set(a + b, i, j);
		}
	}
	return sum;
}

template <class T>
void Matrix<T>::print() {
	for (int i = 0; i < this->rows(); i++) {
		for (int j = 0; j < this->columns(); j++) {
			std::cout << m[i][j] << ' ';
		}
		std::cout << '\n';
	}
}

template <class T>
Matrix<T>::~Matrix<T>() {
	for (size_t i = 0; i < row; i++) {
		delete[] m[i];
		m[i] = NULL;
	}
}

#endif