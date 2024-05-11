#pragma once

#include <iostream>

#define size_t unsigned int

template<typename T>
class Vector {
public:
	Vector();

	Vector(size_t);

	Vector(const Vector<T>&);

	Vector<T>& operator=(Vector<T>);

	Vector(Vector<T>&&) noexcept;

	Vector<T>& operator=(Vector<T>&&) noexcept;

	void swap(Vector<T>&) noexcept;

	~Vector();

	T& operator[](const size_t&);

	const T& operator[](const size_t&) const;

	void push_back(T);

	void pop_back();

	void clear();

	size_t capacity() const;
	
	void set_capacity(size_t);

	size_t size() const;

private:
	void resize();
		
	size_t _capacity;
	size_t _size;
	T* _data;
};
