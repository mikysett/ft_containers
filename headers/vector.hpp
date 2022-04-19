#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <stdexcept>
# include <sstream>

# include "iterator.hpp"
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
		vector( typename ft::enable_if<
			!ft::is_integral<InputIt>::value,
			InputIt
			>::type first,
			InputIt last,
			const allocator_type& alloc = allocator_type() )
			: _size(last - first)
			, _capacity(this->_size)
			, _alloc(alloc)
			, _ptr(_alloc.allocate(this->_size))
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

		void assign( size_type count, const T& value ) {
			this->~vector();
			_size = count;
			_capacity = count;
			_ptr = _alloc.allocate(count);

			for (size_type i = 0 ; i < this->_size ; i++) {
				_alloc.construct(_ptr + i, value);
			}
		}

		template< class InputIt >
		void assign( typename ft::enable_if<
			!ft::is_integral<InputIt>::value,
			InputIt
			>::type first,
			InputIt last)
		{
			this->~vector();
			_size = last - first;
			_capacity = _size;
			_ptr = _alloc.allocate(_size);
			InputIt curr_value = first;
			for (size_type i = 0 ; i < _size ; i++) {
				_alloc.construct(_ptr + i, *curr_value);
				curr_value++;
			}
		}

		bool empty() const {
			if (!_size) {
				return (true);
			} else {
				return (false);
			}
		}

		allocator_type get_allocator() const {
			return (_alloc);
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
			if (new_cap > max_size()) {
				throw std::length_error	("vector::reserve");
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

		reference front() {
			return (*_ptr);
		}

		const_reference front() const {
			return (*_ptr);
		}

		reference back() {
			return (*(_ptr + _size - 1));
		}

		const_reference back() const {
			return (*(_ptr + _size - 1));
		}

		T* data() {
			return (_ptr);
		}

		const T* data() const {
			return (_ptr);
		}

		reference at( size_type pos ) {
			if (pos >= _size)
			{
				std::string pos_str;
				std::string size_str;
				std::string msg;
				std::stringstream ss_pos;
				std::stringstream ss_size;
				ss_pos << pos;
				ss_pos >> pos_str;
				ss_size << _size;
				ss_size >> size_str;
				msg = "vector::_M_range_check: __n (which is " + pos_str + ") >= this->size() (which is " + size_str + ")";
				throw std::out_of_range(msg);
			}
			else {
				return (*(_ptr + pos));
			}
		}

		const_reference at( size_type pos ) const {
			if (pos >= _size)
			{
				std::string pos_str;
				std::string size_str;
				std::string msg;
				std::stringstream ss_pos;
				std::stringstream ss_size;
				ss_pos << pos;
				ss_pos >> pos_str;
				ss_size << _size;
				ss_size >> size_str;
				msg = "vector::_M_range_check: __n (which is " + pos_str + ") >= this->size() (which is " + size_str + ")";
				throw std::out_of_range(msg);
			}
			else {
				return (*(_ptr + pos));
			}
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

		void clear() {
			destroy_all();
			_size = 0;
		}

		iterator insert( iterator pos, const T& value ) {
			T buf;
			size_type curr_pos = pos - begin();

			auto_expand(_size + 1);
			_size++;
			for (size_type i = _size - 1 ; i != curr_pos ; i--) {
				buf = *(_ptr + i - 1);
				_alloc.destroy(_ptr + i - 1);
				_alloc.construct(_ptr + i, buf);
			}
			_alloc.destroy(_ptr + curr_pos);
			_alloc.construct(_ptr + curr_pos, value);
			return (pos);
		}

		void insert( iterator pos, size_type count, const T& value ) {
			T buf;
			size_type curr_pos = pos - begin();

			auto_expand(_size + count);

			for (size_type i = _size - 1 ; i >= curr_pos ; i--) {
				buf = *(_ptr + i);
				_alloc.destroy(_ptr + i);
				_alloc.construct(_ptr + i + count, buf);
				if (i == 0)
					break;
			}
			_size += count;
			for (size_type i = curr_pos ; count > 0 ; i++) {
				_alloc.destroy(_ptr + i);
				_alloc.construct(_ptr + i, value);
				count--;
			}
		}

		template< class InputIt >
		void insert( iterator pos,
			typename ft::enable_if<
			!ft::is_integral<InputIt>::value,
			InputIt
			>::type first,
			InputIt last ) {
			T buf;
			size_type curr_pos = pos - begin();
			size_type count = last - first;

			auto_expand(_size + count);

			for (size_type i = _size - 1 ; i >= curr_pos ; i--) {
				buf = *(_ptr + i);
				_alloc.destroy(_ptr + i);
				_alloc.construct(_ptr + i + count, buf);
				if (i == 0)
					break;
			}
			_size += count;
			InputIt curr_value = first;
			for (size_type i = curr_pos ; count > 0 ; i++) {
				_alloc.destroy(_ptr + i);
				_alloc.construct(_ptr + i, *curr_value);
				curr_value++;
				count--;
			}
		}

		iterator erase( iterator pos ) {
			size_type curr_pos = pos - begin();
			_alloc.destroy(_ptr + curr_pos);
			for (curr_pos += 1 ; curr_pos < _size ; curr_pos++) {
				_alloc.construct(_ptr + curr_pos - 1, *(_ptr + curr_pos));
				_alloc.destroy(_ptr + curr_pos);
			}
			_size--;
			return (pos);
		}

		iterator erase( iterator first, iterator last ) {
			size_type curr_pos = first - begin();
			size_type nb_to_erase = last - first;

			for (size_type i = 0 ; i < nb_to_erase ; i++) {
				_alloc.destroy(_ptr + curr_pos);
				curr_pos++;
			}
			for ( ; curr_pos < _size ; curr_pos++) {
				_alloc.construct(_ptr + curr_pos - nb_to_erase, *(_ptr + curr_pos));
				_alloc.destroy(_ptr + curr_pos);
			}
			_size -= nb_to_erase;
			return (first);
		}

		void push_back( const value_type& value ) {
			auto_expand(_size + 1);
			_alloc.construct(_ptr + _size, value);
			_size++;
		}

		void pop_back() {
			erase(end() - 1);
		}

		void resize( size_type count, T value = T() ) {
			if (count > _capacity) {
				auto_expand(count);
			}
			if (_size > count) {
				erase(begin() + count, end());
			}
			else {
				for (size_type curr_pos = _size ;
					curr_pos < count ;
					curr_pos++) {
					_alloc.construct(_ptr + curr_pos, value);
				}
			}
			_size = count;
		}

	private:
		size_type _size;
		size_type _capacity;
		allocator_type _alloc;
		pointer _ptr;

		void destroy_all() {
			for (size_type i = 0 ; i < this->_size ; i++) {
				_alloc.destroy(_ptr + i);
			}
		}

		void auto_expand(size_type new_size) {
			if (new_size > _capacity)
			{
				if (_capacity == 0)
					reserve(new_size);
				else if (_capacity * 2 <= max_size()
					&& _capacity * 2 >= new_size)
					reserve(_capacity * 2);
				else if (new_size <= max_size())
					reserve(new_size);
				else
					reserve(max_size());
			}
		}
	};
}

#endif
