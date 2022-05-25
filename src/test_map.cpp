#include <algorithm>
#include <numeric>
#include <iostream>
#include "tests.hpp"

template<class Key, class T>
void print_map_info(ft::map<Key, T> &);

void test_map() {
	
}

template<class Key, class T>
void print_map_info(ft::map<Key, T> &m) {
	std::cout << "size    : " << m.size() << std::endl;
	std::cout << "capacity: " << m.capacity() << std::endl;

	if (m.size() > 0) {
		std::cout << "Elements: ";
		for (size_t i = 0 ; i < m.size() ; i++) {
			std::cout << m[i] << ", ";
		}
		std::cout << std::endl;
	}
}
