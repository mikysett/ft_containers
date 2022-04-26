#ifndef MAP_HPP
# define MAP_HPP

# include <stdexcept>
# include <sstream>

# include "iterator.hpp"
# include "type_traits.hpp"

namespace ft {
	template<
		class Key,
		class T,
		class Compare = std::less<Key>,
		class Allocator = std::allocator<std::pair<const Key, T> >
	> class map
	{
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
			

		private:


	};
}

#endif
