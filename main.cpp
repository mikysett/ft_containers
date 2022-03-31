#include "ft_containers.hpp"

void print_info(ft::vector<int>);
void test_constructors(void);

int main(int argc, char **argv) {
	test_constructors();
	
	return (0);
}

void print_info(ft::vector<int> vec) {
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

void test_constructors() {
	std::cout << "----> constructors" << std::endl;
	ft::vector<int> a_vec;
	print_info(a_vec);
	a_vec.push_back(10);
	print_info(a_vec);
	a_vec.push_back(20);
	print_info(a_vec);
	a_vec.push_back(11);
	print_info(a_vec);
	a_vec.push_back(22);
	print_info(a_vec);


	ft::vector<int> b_vec = a_vec;
	print_info(b_vec);
	b_vec.push_back(33);
	std::cout << "Uncopied capacity: " << b_vec.capacity() << std::endl;
	print_info(b_vec);
	print_info(a_vec);

	a_vec = ft::vector<int>(10, 42);
	print_info(a_vec);
	b_vec = ft::vector<int>(0, 20);
	print_info(b_vec);
}