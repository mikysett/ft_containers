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
		class Allocator = std::allocator<ft::pair<const Key, T> >
	> class map
	{
		public:
			class value_compare;
		
		private:
			typedef BinarySearchTree<pair<const Key, T>, value_compare, Allocator> BinarySearchTree;
		
		public:
			typedef Key key_type;
			typedef T mapped_type;
			typedef Compare key_compare;
			typedef typename ft::pair<const Key, T> value_type;
			typedef Allocator allocator_type;

			typedef typename BinarySearchTree::iterator iterator;
			typedef typename BinarySearchTree::const_iterator const_iterator;
			typedef typename BinarySearchTree::reverse_iterator reverse_iterator;
			typedef typename BinarySearchTree::const_reverse_iterator const_reverse_iterator;

			typedef typename allocator_type::reference reference;
			typedef typename allocator_type::const_reference const_reference;
			typedef typename allocator_type::pointer pointer;
			typedef typename allocator_type::const_pointer const_pointer;
			typedef typename allocator_type::size_type size_type;

			typedef typename iterator_traits<iterator>::difference_type difference_type;


			typedef typename BinarySearchTree::node_pointer node_pointer;
			
			// Constructors
			explicit map( const key_compare& comp = key_compare(),
				const allocator_type& alloc = allocator_type())
				: _bst(BinarySearchTree(value_compare(comp), alloc))
				, _comp(comp)
				, _alloc(alloc)
				, _size(0)
			{}

			template< class InputIt >
			map( InputIt first, InputIt last,
				const Compare& comp = Compare(),
				const Allocator& alloc = Allocator())
				: _bst(BinarySearchTree(value_compare(comp), alloc))
				, _comp(comp)
				, _alloc(alloc)
				, _size(0)
			{
				insert(first, last);
				// while (first != last)
				// {
				// 	_bst.bstInsert(*first, _bst.getRoot());
				// 	first++;
				// 	_size++;
				// }
			}

			map( const map& other )
			{
				*this = other;
			}

			map &operator=(const map &rhs)
			{
				_bst = rhs._bst;
				_size = rhs._size;
				return *this;
			}

			~map() {}

			// in C++98, it is required to inherit binary_function<value_type,value_type,bool>
			// Many thanks to dcavalei for this precious hint!
			class value_compare : std::binary_function<value_type, value_type, bool>
			{
				protected:
					key_compare comp;

				public:
					typedef bool result_type;
					typedef value_type first_argument_type;
					typedef value_type second_argument_type;
					bool operator()(const value_type &x, const value_type &y) const
					{
						return comp(x.first, y.first);
					}
					value_compare(const key_compare &c = key_compare())
						: comp(c)
					{}
			};

			allocator_type get_allocator() const
			{
				return (_alloc);
			}

			T& at( const Key& key )
			{
				node_pointer node = _bst.findKey(_bst.getRoot(), key);
				return (*(node->data).second);
			}

			const T& at( const Key& key ) const
			{
				node_pointer node = _bst.findKey(_bst.getRoot(), key);
				return (*(node->data).second);
			}

			mapped_type& operator[]( const key_type& key )
			{
				value_type pair(key, mapped_type());
				node_pointer node = _bst.findKey(_bst.getRoot(), pair);
				
				if (node == NULL)
				{
					_bst.insert(pair);
					_size++;
					node = _bst.findKey(_bst.getRoot(), pair);
					if (node == NULL)
					std::cout << "!!!!!!!!!!!ERROR!!!!!!!!!" << std::endl;
				}
				return ((*node->data).second);
			}


			iterator begin() {
				return iterator(_bst.start());
			}

			const_iterator begin() const {
				return const_iterator(_bst.start());
			}

			iterator end() {
				return iterator(_bst.start() + _size);
			}

			const_iterator end() const {
				return (const_iterator(_bst.start() + _size));
			}

			reverse_iterator rbegin() {
				return (reverse_iterator(end()));
			}

			const_reverse_iterator rbegin() const {
				return (const_reverse_iterator(end()));
			}

			reverse_iterator rend() {
				return (reverse_iterator(begin()));
			}

			const_reverse_iterator rend() const {
				return (const_reverse_iterator(begin()));
			}


			bool empty() const
			{
				return (_size == 0);
			}

			size_type size() const
			{
				return (_size);
			}

			size_type max_size() const {
				return (_alloc.max_size());
			}

			void clear()
			{
				_bst.clear();
				_size = 0;
			}

			ft::pair<iterator, bool> insert( const value_type& value )
			{
				ft::pair<iterator, bool> result;
				node_pointer node = _bst.findKey(_bst.getRoot(), value);

				if (node)
					result.second = false;
				else
				{
					_bst.insert(value);
					node = _bst.findKey(_bst.getRoot(), value);
					result.second = true;
					_size++;
				}
				result.first = iterator(node);
				return (result);
			}

			iterator insert( iterator hint, const value_type& value )
			{
				// TODO implement it (as close, prior to (since c++11) hint)
				insert(value);
			}

			void erase( iterator pos )
			{
				_bst.bstRemove(pos.getNode());
			}			

			template< class InputIt >
			void insert( InputIt first, InputIt last )
			{
				while (first != last)
				{
					insert(*first);
					first++;
				}
			}

			value_compare value_comp() const { return (_comp); }

		private:
            BinarySearchTree	_bst;
            key_compare			_comp;
            allocator_type		_alloc;
			size_type			_size;
	};
}

#endif
