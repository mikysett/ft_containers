#include <algorithm>
#include <numeric>
#include <iostream>
#include "tests.hpp"

void test_constructors();
void test_reserve();
void test_front_back();
void test_data();
void test_assign();
void test_at();
void test_clear();
void test_insert();
void test_erase();

template<class T>
void print_info(ft::vector<T>);

void test_vector() {
	test_constructors();
 	test_reserve();
	test_front_back();
	test_data();
	test_assign();
	test_at();
	test_clear();
	test_insert();
	test_erase();
}

void test_erase() {
	std::cout << "----> erase()" << std::endl;
	ft::vector<int> v1(1, 20);
	v1.push_back(42);
	v1.push_back(41);
	v1.push_back(32);
	v1.push_back(22);
	v1.push_back(12);
	v1.push_back(41);
	v1.push_back(32);
	v1.push_back(22);
	v1.push_back(12);
	#ifdef STDLIB
		auto res = v1.begin();
	# else
		ft::random_access_iterator<int> res;
	#endif
	print_info(v1);
	res = v1.erase(v1.end() - 1);
	std::cout << *res << std::endl;
	print_info(v1);
	res = v1.erase(v1.begin());
	std::cout << *res << std::endl;
	print_info(v1);
	res = v1.erase(v1.begin(), v1.begin());
	std::cout << *res << std::endl;
	print_info(v1);
	res = v1.erase(v1.end() - 1, v1.end());
	std::cout << *res << std::endl;
	print_info(v1);
	res = v1.erase(v1.begin() + 2, v1.begin() + 5);
	std::cout << *res << std::endl;
	print_info(v1);
	res = v1.erase(v1.begin(), v1.end());
	std::cout << *res << std::endl;
	print_info(v1);
}

void test_insert() {
	std::cout << "----> insert()" << std::endl;
	ft::vector<int> v1(11, 20);
	print_info(v1);
	v1.insert(v1.begin(), 42);
	print_info(v1);
	v1.insert(v1.end(), 42);
	print_info(v1);

	ft::vector<int> v2;
	v2.insert(v2.begin(), 10);
	print_info(v2);

	v2.insert(v2.begin(), 11, 2);
	print_info(v2);
	v2.insert(v2.end(), 1, 30);
	print_info(v2);
	v2.insert(v2.begin(), 0, 33);
	print_info(v2);
	v2.insert(v2.end(), 3, 7);
	print_info(v2);
	v1.insert(v1.begin(), 6, 6);
	print_info(v1);
	v1.insert(v1.begin(), v2.begin(), v2.end());
	print_info(v1);
}

void test_clear() {
	std::cout << "----> clear()" << std::endl;
	ft::vector<int> v1(11, 20);
	print_info(v1);
	v1.clear();
	std::cout << "size: " << v1.size() << std::endl;
	print_info(v1);
}


void test_at() {
	std::cout << "----> at()" << std::endl;

	ft::vector<int> v1(10, 20);

	try {
		v1.at(v1.size());
	} catch(std::exception& e) {
		std::cout << "exception out of range :" << std::endl;
		std::cout << e.what() << std::endl;
	}
	try {
		v1.at(0);
	} catch(std::exception& e) {
		std::cout << "exception out of range :" << std::endl;
		std::cout << e.what() << std::endl;
	}
	v1.at(5);
}

void test_assign() {
	std::cout << "----> assign()" << std::endl;

	ft::vector<int> v1(10, 20);
	v1.push_back(42);
	print_info(v1);
	v1.assign(100, 2);
	print_info(v1);
	v1.assign(10, 1);
	print_info(v1);

	ft::vector<int> v2;
	v2.assign(5, 40);
    print_info(v2);
}


void test_front_back() {
	std::cout << "----> front() back()" << std::endl;

	ft::vector<int> v1(10, 20);
	v1.push_back(42);
	std::cout << v1.front() << std::endl;
	std::cout << v1.back() << std::endl;
	const int& ref_front = v1.front();
	const int& ref_back = v1.back();
	std::cout << ref_front << std::endl;
	std::cout << ref_back << std::endl;
}

void test_data() {
	std::cout << "----> data()" << std::endl;
	ft::vector<int> v1(10, 20);
	v1.push_back(42);
	int *v1_data = v1.data();
	for (unsigned long i = 0 ; i < v1.size() ; i++)
		std::cout << *(v1_data + i) << " ";
	std::cout << std::endl;
}


void test_constructors() {
	std::cout << "----> constructors" << std::endl;
	ft::vector<std::string> a_vec;
	print_info(a_vec);
	a_vec.push_back(std::string("10"));
	print_info(a_vec);
	a_vec.push_back(std::string("20"));
	print_info(a_vec);
	a_vec.push_back(std::string("11"));
	print_info(a_vec);
	a_vec.push_back(std::string("22"));
	print_info(a_vec);


	ft::vector<std::string> b_vec = a_vec;
	print_info(b_vec);
	b_vec.push_back(std::string("33"));
	std::cout << "Uncopied capacity: " << b_vec.capacity() << std::endl;
	print_info(b_vec);
	print_info(a_vec);

	b_vec = ft::vector<std::string>(0, std::string("5"));
	print_info(b_vec);
	b_vec = ft::vector<std::string>(10, std::string("20"));
	print_info(b_vec);

	ft::vector<int> nums;
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(4);
	nums.push_back(8);
	nums.push_back(16);
	
    ft::vector<std::string> fruits;
	fruits.push_back("orange");
	fruits.push_back("apple");
	fruits.push_back("raspberry");
    ft::vector<char> empty;
 
    // Sums all integers in the vector nums (if any), printing only the result.
    std::cout << "Sum of nums: "
              << std::accumulate(nums.begin(), nums.end(), 0) << '\n';
 
    // Prints the first fruit in the vector fruits, checking if there is any.
    if (!fruits.empty())
        std::cout << "First fruit: " << *fruits.begin() << '\n';
 
    if (empty.begin() == empty.end())
        std::cout << "vector 'empty' is indeed empty.\n";
}

void test_reserve() {
	std::cout << "reserve()" << std::endl;

	ft::vector<int> v1(10, 20);
	size_t max_size = (size_t)-1;

	try {
		v1.reserve(max_size);
	} catch(std::exception& e) {
		std::cout << "exception thrown because we tried to allocate more than allowed:" << std::endl;
		std::cout << e.what() << std::endl;
	}
	try {
		v1.reserve(v1.max_size());
	} catch(std::exception& e) {
		std::cout << "exception thrown because we tried to allocate more than allowed:" << std::endl;
		std::cout << e.what() << std::endl;
	}
	print_info(v1);
}

template<class T>
void print_info(ft::vector<T> vec) {
	std::cout << "size    : " << vec.size() << std::endl;
	std::cout << "capacity: " << vec.capacity() << std::endl;

	if (vec.size() > 0) {
		std::cout << "Elements: ";
		for (size_t i = 0 ; i < vec.size() ; i++) {
			std::cout << vec[i] << ", ";
		}
		std::cout << std::endl;
	}
}