#include <algorithm>
#include <numeric>
#include <iostream>
#include "tests.hpp"

template<class Key, class T>
void print_map_info(ft::map<Key, T> &);
void dcavalei_map_test();
void dcavalei_map_modifiers();
void constructor_test();


void test_map() {
	constructor_test();
	dcavalei_map_test();
	dcavalei_map_modifiers();
}

void constructor_test()
{
	ft::map<int, std::string> m1;

	print_map_info(m1);
}

template<class Key, class T>
void print_map_info(ft::map<Key, T> &m) {
	std::cout << "(print_map_info)" << std::endl;
	std::cout << "size    : " << m.size() << std::endl;
	T* curr_value;

	if (m.size() > 0) {
		std::cout << "Elements: ";
		for (size_t i = 0 ; i < m.size() ; i++) {
			curr_value = &m[i];
			if (curr_value)
			{
				std::cout << "(" << i << ", " << m[i] << ")" << ", ";

			}
			else
				std::cout << "(" << i << ", " << "NO_VALUE" << ")" << ", ";
		}
		std::cout << std::endl;
	}
}


// FOLLOWING TESTS BASED ON DCAVALEI PROJECT, THANKS
typedef std::string string;
typedef ft::map<int, string> map;

void dcavalei_map_test()
{
	ft::pair<int, string> p[10];
	for (size_t i = 0; i < 10; i++)
	{
		p[i].first = i;
		p[i].second = 'a' + i;
	}

	map map_d;
	std::cout << "map_d created" << std::endl;
	print_map_info(map_d);
	std::cout << std::endl;
	map map_r(p, p + 10);
	std::cout << "map_r created" << std::endl;
	print_map_info(map_r);
	std::cout << std::endl;
	map map_c(map_r);
	std::cout << "map_c created" << std::endl;
	print_map_info(map_c);
	std::cout << std::endl;

	map_d.insert(p, p + 10);
	map::iterator itr = map_d.end();
	std::cout << "PRINT MAP_D" << std::endl;
	for (map::iterator it = map_d.begin(); it != itr; ++it)
	{
		std::cout << (*it).first << " - " << (*it).second << std::endl;
	}
	std::cout << "-----" << std::endl;

	std::cout << "PRINT MAP_R" << std::endl;
	print_map_info(map_r);
	ft::pair<int, string> extra_pair;
	extra_pair.first = 11;
	extra_pair.second = 'q';
	map_r.insert(map_r.begin(), extra_pair);
	itr = map_r.end();
	for (map::iterator it = map_r.begin(); it != itr; ++it)
	{
		std::cout << (*it).first << " - " << (*it).second << std::endl;
	}
	map_r.erase(map_r.begin());
	map_r.erase(map_r.begin());
	map_r.erase(map_r.begin());
	print_map_info(map_r);
	std::cout << "-----" << std::endl;

	std::cout << "PRINT MAP_C" << std::endl;
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

	std::cout << "ERASING THE ENTIRE MAP_A" << std::endl;
	map_a.erase(map_a.begin(), map_a.end());
	print_map_info(map_a);
	std::cout << "-----" << std::endl;
}

static unsigned int n;

typedef ft::map<int, char> mapp;
typedef mapp::iterator iterator;
typedef mapp::const_iterator const_iterator;
typedef ft::pair<int, char> pair;

void	printMap(mapp const & map)
{
	std::cout << "[# Test " << ++n << " #]" << std::endl;
	for (const_iterator it = map.cbegin(); it != map.cend(); ++it)
	{
		std::cout << (*it).first << " - " << (*it).second << std::endl;
	}
}


void dcavalei_map_modifiers()
{
	mapp map;
	pair p;
	p.first = 42;
	p.second = 'A';
	ft::pair<iterator, bool> ret_pair;

	std::cout << std::boolalpha;

	std::cout << "[# Test " << ++n << " #]" << std::endl;
	ret_pair = map.insert(p);
	std::cout << "Successfully inserted? " << ret_pair.second << std::endl;
	std::cout << "Pair values: " << ret_pair.first->first << " - " << ret_pair.first->second << std::endl;

	std::cout << "[# Test " << ++n << " #]" << std::endl;
	p = pair(42, 'X');
	ret_pair = map.insert(p);
	std::cout << "Successfully inserted? " << ret_pair.second << std::endl;
	std::cout << "Pair values: " << ret_pair.first->first << " - " << ret_pair.first->second << std::endl;

	std::cout << "[# Test " << ++n << " #]" << std::endl;
	p = pair(21, 'Z');
	ret_pair = map.insert(p);
	std::cout << "Successfully inserted? " << ret_pair.second << std::endl;
	std::cout << "Pair values: " << ret_pair.first->first << " - " << ret_pair.first->second << std::endl;

	std::cout << "[# Test " << ++n << " #]" << std::endl;
	p = pair(43, 'F');
	iterator it = map.insert(ret_pair.first, p);
	std::cout << it->first << " - " << it->second << std::endl;
	p.second = 'G';
	it = map.insert(it, p);
	std::cout << it->first << " - " << it->second << std::endl;

	p = pair(4, 'O');

	it = map.insert(map.begin(), p);
	std::cout << it->first << " - " << it->second << std::endl;

	it = map.rbegin().base();
	p = pair(5, 'O');

	it = map.insert(it, p);


	map[0] = 'X';
	map[1] = 'X';
	map[2] = 'X';
	map[3] = 'X';
	// map[4] = 'X';
	// map[5] = 'X';
	map[6] = 'X';
	map[7] = 'X';
	map[8] = 'X';
	map[9] = 'X';
	map[10] = 'X';
	printMap(map);

	pair pa[10];
	for (size_t i = 0; i < 10; i++)
	{
		pa[i].first = i;
		pa[i].second = '0' + i;
	}

	map.insert(pa, pa + 10);
	printMap(map);

	for (size_t i = 0; i < 10; i++)
	{
		pa[i].first = i + 100;
		pa[i].second = '0' + i;
	}


	map.insert(pa, pa + 10);
	printMap(map);

	std::cout << "[# Test " << ++n << " #]" << std::endl;
	std::cout << "N erased: " << map.erase(103) << std::endl;
	std::cout << "N erased: " << map.erase(7) << std::endl;
	std::cout << "N erased: " << map.erase(109) << std::endl;
	printMap(map);

	map.erase(map.begin());
	printMap(map);

	map.erase(map.begin(), ++(++(++map.begin())));
	printMap(map);

	mapp map_other;

	for (size_t i = 0; i < 20; i++)
	{
		map_other[i] = 'a' + i;
	}
	printMap(map_other);

	std::cout << "---> SWAPPING OPERATION" << std::endl;
	map.swap(map_other);
	printMap(map);
	printMap(map_other);

	map.clear();
	map_other.clear();
	printMap(map);
	printMap(map_other);
}