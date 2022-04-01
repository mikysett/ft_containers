#include "ft_containers.hpp"

void print_info(ft::vector<int>);
void test_constructors(void);

int main(int argc, char **argv) {
	test_constructors();
	
	return (0);
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
}