#pragma once
#include <exception>
#include <cstdarg>

template<typename T, size_t N>
class array {
private:
	T arr[N];

public:

	array() {}

	array(T arg1, ...);

	T& at(size_t index);

	T& operator[] (size_t index);

	array<T, N>& operator=(array<T, N>& other);

	T& front();

	T& back();

	T* data();

	bool empty();

	size_t size();

	size_t max_size();

	void fill(const T& value);

	void swap(array<T, N>& other);
};


template<typename T, size_t N>
array<T, N>::array(T arg1, ...) {
	va_list args;
	va_start(args, arg1);

	arr[0] = arg1;

	for (size_t i = 1; i < N; ++i) {
		arr[i] = va_arg(args, T);
	}

	va_end(args);
}

template<typename T, size_t N>
T& array<T, N>::at(size_t index) {
	if (index >= N) {
		throw std::exception("Index out of range");
	}
	return arr[index];
}

template<typename T, size_t N>
T& array<T, N>::operator[] (size_t index) {
	return arr[index];
}

template<typename T, size_t N>
T& array<T, N>::front() {
	return arr[0];
}

template<typename T, size_t N>
T& array<T, N>::back() {
	return arr[N - 1];
}

template<typename T, size_t N>
T* array<T, N>::data() {
	if (N == 0)
		return nullptr;
	return arr;
}

template<typename T, size_t N>
bool array<T, N>::empty() {
	return N == 0 ? true : false;
}

template<typename T, size_t N>
size_t array<T, N>::size() {
	return N;
}

template<typename T, size_t N>
size_t array<T, N>::max_size() {
	return N;
}

template<typename T, size_t N>
void array<T, N>::fill(const T& value) {
	for (size_t i = 0; i < N; ++i) {
		arr[i] = value;
	}
}

template<typename T, size_t N>
void array<T, N>::swap(array<T, N>& other) {
	for (size_t i = 0; i < N; ++i) {
		T tmp = other[i];
		other[i] = arr[i];
		arr[i] = tmp;
	}
}

template<typename T, size_t N>
array<T, N>& array<T, N>::operator=(array<T, N>& other) {
	for (size_t i = 0; i < N; ++i) {
		arr[i] = other.at[i];
	}
	return *this;
}