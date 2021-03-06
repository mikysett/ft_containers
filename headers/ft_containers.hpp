#ifndef FT_CONTAINERS_HPP
# define FT_CONTAINERS_HPP

#ifdef DEBUG_MODE
# define DEBUG(x) x
#else
# define DEBUG(x)
#endif

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
