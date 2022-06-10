#include <algorithm>
#include <numeric>
#include <iostream>
#include "tests.hpp"

template<class Key, class T>
void print_map_info(ft::map<Key, T> &);
void dcavalei_map_test();
void constructor_test();


void test_map() {
	constructor_test();
	dcavalei_map_test();
}

void constructor_test()
{
	ft::map<int, std::string> m1;

	print_map_info(m1);
}

template<class Key, class T>
void print_map_info(ft::map<Key, T> &m) {
	std::cout << "size    : " << m.size() << std::endl;

	if (m.size() > 0) {
		std::cout << "Elements: ";
		for (size_t i = 0 ; i < m.size() ; i++) {
			std::cout << m[i] << ", ";
		}
		std::cout << std::endl;
	}
}


// FOLLOWING TESTS BY DCAVALEI PROJECT, THANKS
typedef std::string string;
typedef ft::map<int, string> map;
typedef ft::pair<int, string> pair;

void dcavalei_map_test()
{
	pair p[10];
	for (size_t i = 0; i < 10; i++)
	{
		p[i].first = i;
		p[i].second = 'a' + i;
	}

	map map_d;
	std::cout << "map_d created" << std::endl;
	print_map_info(map_d);
	map map_r(p, p + 10);
	std::cout << "map_r created" << std::endl;
	print_map_info(map_r);
	map map_c(map_r);
	std::cout << "map_c created" << std::endl;
	print_map_info(map_c);
	map::iterator itr = map_d.end();

	map_d.insert(p, p + 10);
	for (map::iterator it = map_d.begin(); it != itr; ++it)
	{
		std::cout << (*it).first << " - " << (*it).second << std::endl;
	}
	std::cout << "-----" << std::endl;

	itr = map_r.end();
	for (map::iterator it = map_r.begin(); it != itr; ++it)
	{
		std::cout << (*it).first << " - " << (*it).second << std::endl;
	}
	std::cout << "-----" << std::endl;

	itr = map_c.end();
	for (map::iterator it = map_c.begin(); it != itr; ++it)
	{
		std::cout << (*it).first << " - " << (*it).second << std::endl;
	}
	std::cout << "-----" << std::endl;

	map map_a;
	map_a = map_c;

	itr = map_a.end();
	for (map::iterator it = map_a.begin(); it != itr; ++it)
	{
		std::cout << (*it).first << " - " << (*it).second << std::endl;
	}
	std::cout << "-----" << std::endl;
}
