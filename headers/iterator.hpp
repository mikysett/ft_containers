#ifndef ITERATOR_HPP
# define ITERATOR_HPP

# include <cstddef>
# include "iterator_traits.hpp"

namespace ft
{
	template<class T>
	class random_access_iterator
	{
	public: 
		typedef T value_type;
		typedef value_type &reference;
		typedef const value_type &const_reference;
		typedef value_type *pointer;
		typedef const value_type *const_pointer;
		typedef std::ptrdiff_t difference_type;
		typedef std::random_access_iterator_tag iterator_category;

		random_access_iterator()
			: _ptr(NULL)
		{}

		random_access_iterator(const random_access_iterator &other) {
			*this = other;
		}

		random_access_iterator(pointer ptr)
			: _ptr(ptr)
		{}

		~random_access_iterator() {}

		random_access_iterator &operator=(const random_access_iterator &rhs) {
			_ptr = rhs._ptr;
			return (*this);
		}

		operator random_access_iterator<const value_type>() const {
			return (_ptr);
		}

		bool operator==(const random_access_iterator &rhs) const {
			return (_ptr == rhs._ptr);
		}

		bool operator!=(const random_access_iterator &rhs) const {
			return (_ptr != rhs._ptr);
		}

		bool operator<(const random_access_iterator &rhs) const {
			return (_ptr < rhs._ptr);
		}

		bool operator>(const random_access_iterator &rhs) const {
			return (_ptr > rhs._ptr);
		}

		bool operator<=(const random_access_iterator &rhs) const {
			return (_ptr <= rhs._ptr);
		}

		bool operator>=(const random_access_iterator &rhs) const {
			return (_ptr >= rhs._ptr);
		}

		reference operator*() const {
			return (*_ptr);
		}

		pointer operator->() const {
			return (_ptr);
		}

		random_access_iterator &operator++() {
			_ptr++;
			return (*this);
		}

		random_access_iterator operator++(int) {
			random_access_iterator old = *this;
			_ptr++;
			return (old);
		}

		random_access_iterator &operator--() {
			_ptr--;
			return (*this);
		}

		random_access_iterator operator--(int) {
			random_access_iterator old = *this;
			_ptr--;
			return (old);
		}

		random_access_iterator operator+(difference_type n) const {
			return (random_access_iterator(_ptr + n));
		}

		random_access_iterator operator-(difference_type n) const {
			return (random_access_iterator(_ptr - n));
		}

		difference_type operator-(const random_access_iterator &rhs) const {
			return (_ptr - rhs._ptr);
		}

		random_access_iterator &operator+=(int n) {
			_ptr += n;
			return (*this);
		}

		random_access_iterator &operator-=(int n) {
			_ptr -= n;
			return (*this);
		}

		reference operator[](difference_type n) const {
			return (_ptr[n]);
		}

	private:
		pointer _ptr;
	};
}

#endif
