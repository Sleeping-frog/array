#include <iostream>
#include "array.h"

int main() {
	array<int, 5> arr = {1, 3, 5, 7, 9};

	for (int i = 0; i < 5; ++i)
		std::cout << arr[i] << std::endl;
	std::cout << std::endl;

	std::cout << arr.at(2) << std::endl;
	std::cout << "Front: " << arr.front() << std::endl;
	std::cout << "Back: " << arr.back() << std::endl << std::endl;
	std::cout << "Size: " << arr.size() << ", Max size: " << arr.max_size() << std::endl;
	std::cout << "Empty: " << arr.empty() << std::endl << std::endl;

	array<int, 5> arr2 = { 5, 4, 3, 2, 1 };

	arr.swap(arr2);
	for (int i = 0; i < 5; ++i)
		std::cout << arr[i] << std::endl;
}