#pragma once

#include <istream>
#include <ostream>
#include <string>
#include "Vector.h"
#include "Vector.cpp"

#define size_t unsigned int

class Matrix {
	friend std::ostream& operator<<(std::ostream&, const Matrix&);

	friend std::istream& operator>>(std::istream&, Matrix&);

	friend Matrix operator+(Matrix, const Matrix&);

	friend Matrix operator*(const Matrix&, const Matrix&);
	
	friend Matrix solve(Matrix);
public:
	static size_t _counter_object;
	
	Matrix();

	Matrix(size_t, size_t);

	Matrix(const Matrix&);

	Matrix& operator=(const Matrix&);

	void operator+=(const Matrix&);

	void operator*=(const Matrix&);

	Vector<float>& operator[](const size_t&);

	const Vector<float>& operator[](const size_t&) const;

	Matrix& put_up_pow(const size_t&);

	bool is_square() const;

	size_t row() const;

	size_t column() const;
private:
	std::string _name; 
	size_t _row_size;
	size_t _col_size;
	Vector<Vector<float>> _matrix; 
};
