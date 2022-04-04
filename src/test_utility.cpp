#include "ft_containers.hpp"

template<class T, class U>
void print_pair(const ft::pair<T, U> &p);
void print_bool(bool cond);

void test_utility() {
	ft::pair<int, float> p1;
	print_pair(p1);

	ft::pair<int, double> p2(42, 3.1415);
	print_pair(p2);

	ft::pair<char, int> p3(p2);
	print_pair(p3);

	ft::pair<int, int> p4 = ft::make_pair(20, 42);
	ft::pair<int, int> p5 = ft::make_pair(21, 45);
	ft::pair<int, int> p6 = ft::make_pair(10, 42);

	print_bool(p1 == p1);
	print_bool(p4 == p5);
	print_bool(p4 != p5);
	print_bool(p4 <= p5);
	print_bool(p4 < p5);
	print_bool(p4 >= p5);
	print_bool(p4 > p5);
	print_bool(p5 == p5);
	print_bool(p6 == p5);
}

template<class T, class U>
void print_pair(const ft::pair<T, U> &p) {
	std::cout << "pair: " << p.first << ", " << p.second << std::endl;
}

void print_bool(bool cond) {
	if (cond)
		std::cout << "true" << std::endl;
	std::cout << "false" << std::endl;
}