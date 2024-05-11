#include"Vector.h"

template<typename T>
Vector<T>::Vector(): _capacity(1), _size(0), _data(new T[_capacity]) {}

template<typename T>
Vector<T>::Vector(size_t capacity): _capacity(capacity), _size(0), _data(new T[_capacity]) {}

template<typename T>
Vector<T>::Vector(const Vector<T>& other): _capacity(other._capacity), _size(other._size), _data(new T[_capacity]) {
	for(size_t i = 0; i < _capacity; ++i)
		_data[i] = other._data[i];
}

template<typename T>
Vector<T>& Vector<T>::operator=(Vector<T> other) {
	swap(other);
	return *this;
}

template<typename T>
Vector<T>::Vector(Vector<T>&& other) noexcept: _capacity(other._capacity), _size(other._size), _data(other._data) {
	other._capacity = 1;
	other._size = 0;
	other._data = nullptr;
}

template<typename T>
Vector<T>& Vector<T>::operator=(Vector<T>&& other) noexcept {
	Vector<T> res(std::move(other));
	std::swap(res);
	return *this;
}

template<typename T>
void Vector<T>::swap(Vector<T>& other) noexcept {
	std::swap(_capacity, other._capacity);
	std::swap(_size, other._size);
	std::swap(_data, other._data);
}

template<typename T>
Vector<T>::~Vector() {
	delete[] _data;
}

template<typename T>
T& Vector<T>::operator[](const size_t& ind) {
	if(ind < 0 || ind >= _capacity) {
		throw "Index not found";
		abort();
	}

	if(ind > _size && ind < _capacity)
		_size = ind;

	return _data[ind];
}

template<typename T>
const T& Vector<T>::operator[](const size_t& ind) const {
	if(ind < 0 || ind >= _capacity){
		throw "Index not found";
		abort();
	}

	return _data[ind];
}

template<typename T>
void Vector<T>::push_back(T data) {
	if(_size >= _capacity)
		resize();

	_data[_size] = data;
	++_size;
}

template<typename T>
void Vector<T>::pop_back() {
	--_size;
}

template<typename T>
void Vector<T>::clear() {
	delete[] _data;
	_size = 0;
	_capacity = 1;
	_data = new T[_capacity] {0};
}

template<typename T>
size_t Vector<T>::capacity() const {
	return _capacity;
}

template<typename T>
void Vector<T>::set_capacity(size_t size) {
	delete[] _data;
	_size = 0;
	_capacity = size;
	_data = new T[_capacity] {0};
}

template<typename T>
size_t Vector<T>::size() const {
	return _size;
}

template<typename T>
void Vector<T>::resize() {
	size_t new_capacity = _capacity * 2;
	T* new_data = new T[new_capacity];

	for(size_t i = 0; i < _capacity; ++i)
		new_data[i] = _data[i];
	
	delete[] _data;
	_data = new_data;
	_capacity = new_capacity;
}












