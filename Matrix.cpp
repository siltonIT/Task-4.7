#include "Matrix.h"

size_t Matrix::_counter_object = 0;

std::ostream& operator<<(std::ostream& os, const Matrix& matrix) {
	os << matrix._name << '\n';

	for(size_t i = 0; i < matrix._col_size; ++i) { 
		for(size_t j = 0; j < matrix._row_size; ++j)
			os << matrix._matrix[i][j] << ' ';
	
		os << '\n';
	}

	return os;
}

std::istream& operator>>(std::istream& is, Matrix& matrix) {
	for(size_t i = 0; i < matrix._col_size; ++i)
		for(size_t j = 0; j < matrix._row_size; ++j)
			is >> matrix._matrix[i][j];

	return is;
}

Matrix operator+(Matrix res, const Matrix& other) {
	res += other;
	return res;
}

Matrix operator*(const Matrix& a, const Matrix& b) {
	if(a._col_size != b._row_size)
		abort();

	Matrix res(a._col_size, a._row_size);
	for(size_t i = 0; i < a._col_size; ++i) 
		for(size_t j = 0; j < b._row_size; ++j) 
			for(size_t k = 0; k < a._row_size; ++k) 
				res._matrix[i][j] += a._matrix[i][k] * b._matrix[k][j];

	return res;
}

Matrix::Matrix(): _name("Matrix "), _row_size(0),  _col_size(0) {
	++_counter_object;
	_name += std::to_string(_counter_object);
}

Matrix::Matrix(size_t col, size_t row): _name("Matrix "), _row_size(row), _col_size(col) {
	_matrix.set_capacity(_col_size);
	for(size_t i = 0; i < _col_size; ++i)
		_matrix[i].set_capacity(_row_size);

	++_counter_object;
	_name += std::to_string(_counter_object);
}

Matrix::Matrix(const Matrix& other): Matrix(other._col_size, other._row_size) {
	for(size_t i = 0; i < _col_size; ++i)
		for(size_t j = 0; j < _row_size; ++j)
			_matrix[i][j] = other._matrix[i][j];
}

Matrix& Matrix::operator=(const Matrix& other) {
	_row_size = other._row_size;
	_col_size = other._col_size;

	_matrix.set_capacity(_col_size);
	for(size_t i = 0; i < _col_size; ++i) {
		_matrix[i].set_capacity(_row_size);
		for(size_t j = 0; j < _row_size; ++j)
			_matrix[i][j] = other._matrix[i][j];
	}

	++_counter_object;
	_name = "Matrix " + std::to_string(_counter_object);

	return *this;
}

void Matrix::operator+=(const Matrix& other) {
	if(other._row_size != _row_size || other._col_size != _col_size)
		return;
	
	for(size_t i = 0; i < _col_size; ++i)
		for(size_t j = 0; j < _row_size; ++j)
			_matrix[i][j] += other._matrix[i][j];
}

void Matrix::operator*=(const Matrix& other) {
	std::string name = _name;
	*this = *this * other;
	_name = name;
}

Vector<float>& Matrix::operator[](const size_t& ind) {
	if(ind < 0 || ind >= _col_size) {
		throw "Index not found";
		abort();
	}
	
	return _matrix[ind];
}

const Vector<float>& Matrix::operator[](const size_t& ind) const {
	if(ind < 0 || ind >= _col_size) {
		throw "Index not found";
		abort();
	}

	return _matrix[ind];
}

Matrix& Matrix::put_up_pow(const size_t& power) {
	Matrix copy_this(*this);
	for(size_t i = 1; i < power; ++i)
		*this *= copy_this;

	return *this;
}

bool Matrix::is_square() const {
	return _row_size == _col_size;
}

size_t Matrix::row() const {
	return _row_size;
}

size_t Matrix::column() const {
	return _col_size;
}
