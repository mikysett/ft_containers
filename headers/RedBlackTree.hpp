#ifndef REDBLACKTREE_HPP
# define REDBLACKTREE_HPP

# include <stdexcept>
# include <sstream>

# include "RBTnode.hpp"
# include "iterator.hpp"
# include "type_traits.hpp"
# include "RBTiterator.hpp"
# include "RBTreverse_iterator.hpp"

namespace ft {
	template<
		class T,
		class Compare,
		class Allocator >
	class RedBlackTree
	{
		public:
		typedef T value_type;
		typedef Allocator alloc_type;
		typedef Compare key_compare;
		typedef RBTnode<T> node;
		typedef node *node_pointer;
		typedef RBTiterator<value_type, false> iterator;
		typedef RBTiterator<value_type, true> const_iterator;
		typedef RBTreverse_iterator<iterator> reverse_iterator;
		typedef RBTreverse_iterator<const_iterator> const_reverse_iterator;

		private:
	};
}

#endif
