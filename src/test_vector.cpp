#include <algorithm>
#include <numeric>
#include <iostream>
#include "vector.hpp"

void test_constructors();
template<class T>
void print_info(ft::vector<T>);

void test_vector() {
	test_constructors();
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