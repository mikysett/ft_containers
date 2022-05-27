#ifndef MAP_HPP
# define MAP_HPP

# include <stdexcept>
# include <sstream>

# include "iterator.hpp"
# include "type_traits.hpp"
# include "utility.hpp"
# include "BinarySearchTree.hpp"

namespace ft {
	template<
		class Key,
		class T,
		class Compare = std::less<Key>,
		class Allocator = std::allocator<std::pair<const Key, T> >
	> class map
	{
		public:
			class value_compare;
		
		private:
			typedef BinarySearchTree<ft::pair<const Key, T>, value_compare, Allocator> BinarySearchTree;
		
		public:
			typedef Key key_type;
			typedef T mapped_type;
			typedef typename std::pair<const Key, T> value_type;
			typedef typename std::size_t size_type;
			typedef Compare key_compare;
			typedef Allocator allocator_type;
			typedef value_type& reference;
			typedef const value_type& const_reference;
			typedef typename Allocator::pointer pointer;
			typedef typename Allocator::const_pointer const_pointer;
			// typedef typename std::LegacyBidirectionalIterator<value_type> iterator;
			// typedef typename std::LegacyBidirectionalIterator<const value_type> const_iterator;
			
			// Constructors
			explicit map( const key_compare& comp,
				const allocator_type& alloc = allocator_type() )
				: _bst(BinarySearchTree(value_compare(comp), alloc))
				, _comp(comp)
				, _alloc(alloc)
			{}

		private:
            ft::BinarySearchTree<value_type>    _bst;
            key_compare                     _comp;
            allocator_type                  _alloc;
	};
}

#endif
