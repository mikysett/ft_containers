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


	template<class Iterator>
	class reverse_iterator
	{
	public: 
		typedef Iterator iterator_type;
		typedef typename iterator_traits<Iterator>::value_type value_type;
		typedef typename iterator_traits<Iterator>::reference reference;
		typedef typename iterator_traits<Iterator>::pointer pointer;
		typedef typename iterator_traits<Iterator>::difference_type difference_type;
		typedef typename iterator_traits<Iterator>::iterator_category iterator_category;

		reverse_iterator()
			: _ptr(iterator_type())
		{}

		explicit reverse_iterator( iterator_type x )
			: _ptr(x)
		{}

		template< class U >
		reverse_iterator( const reverse_iterator<U>& other )
			: _ptr(other._ptr)
		{}

		iterator_type base() const {
			return (_ptr + 1);
		}

		reference operator*() const {
			return (*_ptr);
		}

		pointer operator->() const {
			return (_ptr);
		}

		reverse_iterator &operator++() {
			_ptr--;
			return (*this);
		}

		reverse_iterator operator++(int) {
			reverse_iterator old = *this;
			_ptr--;
			return (old);
		}

		reverse_iterator &operator--() {
			_ptr++;
			return (*this);
		}

		reverse_iterator operator--(int) {
			reverse_iterator old = *this;
			_ptr++;
			return (old);
		}

		reverse_iterator operator+(difference_type n) const {
			return (reverse_iterator(base() - n));
		}

		reverse_iterator operator-(difference_type n) const {
			return (reverse_iterator(base() + n));
		}

		reverse_iterator &operator+=(int n) {
			_ptr -= n;
			return (*this);
		}

		reverse_iterator &operator-=(int n) {
			_ptr += n;
			return (*this);
		}

		reference operator[](difference_type n) const {
			return (_ptr[-n]);
		}

	private:
		pointer _ptr;
	};	


	template<class Iterator>		
	bool operator==(const reverse_iterator<Iterator> &lhs,
					const reverse_iterator<Iterator> &rhs) {
		return (lhs._ptr == rhs._ptr);
	}

	template<class Iterator>	
	bool operator!=(const reverse_iterator<Iterator> &lhs,
					const reverse_iterator<Iterator> &rhs) {
		return (lhs._ptr != rhs._ptr);
	}

	template<class Iterator>	
	bool operator<(const reverse_iterator<Iterator> &lhs,
					const reverse_iterator<Iterator> &rhs) {
		return (lhs._ptr < rhs._ptr);
	}

	template<class Iterator>	
	bool operator>(const reverse_iterator<Iterator> &lhs,
					const reverse_iterator<Iterator> &rhs) {
		return (lhs._ptr > rhs._ptr);
	}

	template<class Iterator>	
	bool operator<=(const reverse_iterator<Iterator> &lhs,
					const reverse_iterator<Iterator> &rhs) {
		return (lhs._ptr <= rhs._ptr);
	}

	template<class Iterator>	
	bool operator>=(const reverse_iterator<Iterator> &lhs,
					const reverse_iterator<Iterator> &rhs) {
		return (lhs._ptr >= rhs._ptr);
	}

}

#endif
