#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iterator>
// # include "iterator.hpp"
# include "type_traits.hpp"

namespace ft
{
	template<class T, class Allocator = std::allocator<T> >
	class vector
	{
	public:
		typedef T value_type;
		typedef Allocator allocator_type;                                 // Alloc
		typedef typename allocator_type::const_reference const_reference; // const T&
		typedef typename allocator_type::reference reference;             // T&
		typedef typename allocator_type::const_pointer const_pointer;     // const T*
		typedef typename allocator_type::pointer pointer;                 // T*
		typedef typename allocator_type::difference_type difference_type; // std::ptrdiff_t
		typedef typename allocator_type::size_type size_type;             // std::size_t
		typedef ft::random_access_iterator<const value_type> const_iterator;
		typedef ft::random_access_iterator<value_type> iterator;
		typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;
		typedef ft::reverse_iterator<iterator> reverse_iterator;

		vector()
			: _size(0)
			, _capacity(0)
			, _alloc(allocator_type())
			, _ptr(NULL)
		{ }

		explicit vector( const allocator_type& alloc )
			: _size(0)
			, _capacity(0)
			, _alloc(alloc)
			, _ptr(NULL)
		{ }

		explicit vector( size_type count,
			const value_type& value = value_type(),
			const allocator_type& alloc = allocator_type() )
			: _size(count)
			, _capacity(count)
			, _alloc(alloc)
			, _ptr(_alloc.allocate(count))
		{
			for (size_type i = 0 ; i < this->_size ; i++) {
				_alloc.construct(_ptr + i, value);
			}
		}

		template< class InputIt >
		// TODO pass to ft::
		vector( typename ft::enable_if<
			!ft::is_integral<InputIt>::value,
			InputIt
			>::type first,
			InputIt last,
			const allocator_type& alloc = allocator_type() )
			: _size(last - first)
			, _capacity(last - first)
			, _alloc(alloc)
			, _ptr(_alloc.allocate(last - first))
		{
			InputIt curr_value = first;
			for (size_type i = 0 ; i < this->_size ; i++) {
				_alloc.construct(_ptr + i, curr_value);
				curr_value++;
			}
		}

		vector( const vector& other )
			: _size(other._size)
			, _capacity(this->_size)
			, _alloc(other._alloc)
			, _ptr(_alloc.allocate(this->_size))
		{
			for (size_type i = 0 ; i < this->_size ; i++) {
				_alloc.construct(_ptr + i, other[i]);
			}
		}

		~vector() {
			destroy_all();
			_alloc.deallocate(_ptr, _capacity);
		}

		bool empty() const {
			if (!_size) {
				return (true);
			} else {
				return (false);
			}
		}

		size_type size() const {
			return (_size);
		}

		size_type max_size() const {
			return (_alloc.max_size());
		}

		void reserve( size_type new_cap ) {
			if (new_cap < _capacity)
				return;
			// TODO implement error throw
			if (new_cap > max_size()) {
				return;
			}
			pointer new_ptr = _alloc.allocate(new_cap);
			for (size_type i = 0 ; i < _size ; i++) {
				_alloc.construct(new_ptr + i, _ptr[i]);
			}
			_alloc.deallocate(_ptr, _capacity);
			_ptr = new_ptr;
			_capacity = new_cap;
		}

		size_type capacity() const {
			return (_capacity);
		}

		iterator begin() {
			return iterator(_ptr);
		}

		const_iterator begin() const {
			return const_iterator(_ptr);
		}

		iterator end() {
			return iterator(_ptr + _size);
		}

		const_iterator end() const {
			return (const_iterator(_ptr + _size));
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

		void push_back( const value_type& value ) {
			if (_size == _capacity) {
				if (_size == 0) {
					_capacity = 1;
				}
				else {
					_capacity *= 2;
				}
				pointer new_ptr = _alloc.allocate(_capacity);
				if (_size != 0)
				{
					for (size_type i = 0 ; i < _size ; i++) {
						_alloc.construct(new_ptr + i, _ptr[i]);
					}
					_alloc.deallocate(_ptr, _size);
				}
				_ptr = new_ptr;
			}
			_alloc.construct(_ptr + _size, value);
			_size++;
		}


		value_type& operator[]( size_type pos ) {
			return (_ptr[pos]);
		}

		const value_type& operator[]( size_type pos ) const {
			return (_ptr[pos]);
		}

		vector &operator=(const vector &other) {
			if (this == &other) {
				return (*this);
			}
			if (this->_capacity < other._capacity) {
				this->~vector();
				this->_alloc = other._alloc;
				this->_capacity = other._size;
				this->_ptr = this->_alloc.allocate(this->_capacity);
			} else {
				destroy_all();
				this->_alloc = other._alloc;
			}
			this->_size = other._size;
			for (size_type i = 0 ; i < this->_size ; i++) {
				this->_alloc.construct(_ptr + i, other[i]);
			}
			return (*this);
		}

	private:
		size_type _size;
		size_type _capacity;
		Allocator _alloc;
		pointer _ptr;

		void destroy_all() {
			for (size_type i = 0 ; i < this->_size ; i++) {
				_alloc.destroy(_ptr + i);
			}
		}
	};
}

#endif
