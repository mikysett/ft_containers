#ifndef FT_CONTAINERS_HPP
# define FT_CONTAINERS_HPP

#include <iostream>
#include <stdlib.h>
#include <string>
#include <deque>
#ifdef STDLIB
	#include <map>
	#include <stack>
	#include <vector>
	#include <utility>
	namespace ft = std;
#else
	#include "map.hpp"
	#include "stack.hpp"
	#include "vector.hpp"
	#include "utility.hpp"
	#include "type_traits.hpp"
	#include "RedBlackTree.hpp"
#endif


#include "tests.hpp"

#define MAX_RAM 4294967296
#define BUFFER_SIZE 4096
struct Buffer
{
	int idx;
	char buff[BUFFER_SIZE];
};

#define COUNT (MAX_RAM / (int)sizeof(Buffer))

#endif
