#pragma once
#include <exception>
#include <initializer_list>

template<typename T, size_t N>
class array {
public:

	array() {}

	array(std::initializer_list<T> list);

	T& at(size_t index);

	T& operator[] (size_t index);

	array<T, N>& operator=(array<T, N>& other);

	T& front();

	T& back();

	T* data() const;

	bool empty() const;

	size_t size() const;

	size_t max_size() const;

	void fill(const T& value);

	void swap(array<T, N>& other);


private:
	T arr[N];
};


template<typename T, size_t N>
array<T, N>::array(std::initializer_list<T> list) {
	auto  itList = list.begin();
	for (size_t i = 0; i < N; ++i) {
		arr[i] = *(itList++);
	}
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
T* array<T, N>::data() const {
	if (N == 0)
		return nullptr;
	return arr;
}

template<typename T, size_t N>
bool array<T, N>::empty() const {
	return N == 0 ? true : false;
}

template<typename T, size_t N>
size_t array<T, N>::size() const {
	return N;
}

template<typename T, size_t N>
size_t array<T, N>::max_size() const {
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
		arr[i] = other.at(i);
	}
	return *this;
}
