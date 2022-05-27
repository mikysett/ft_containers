#ifndef BSTreverse_iterator_HPP
# define BSTreverse_iterator_HPP

namespace ft {
	template <class Iterator>
	class BSTreverse_iterator
	{
		public:
		typedef Iterator iterator_type;
		typedef typename iterator_traits<Iterator>::iterator_category iterator_category;
		typedef typename iterator_traits<Iterator>::value_type value_type;
		typedef typename iterator_traits<Iterator>::difference_type difference_type;
		typedef typename iterator_traits<Iterator>::pointer pointer;
		typedef typename iterator_traits<Iterator>::reference reference;

		BSTreverse_iterator() : _base(iterator_type()) {}

		explicit BSTreverse_iterator(iterator_type it) : _base(it) {}

		template <class Iter>
		BSTreverse_iterator(const BSTreverse_iterator<Iter> &rev_it) : _base(rev_it._base) {}

		iterator_type base() const
		{
			return (_base);
		}

		bool operator==(const BSTreverse_iterator &rhs) const
		{
			return (_base == rhs._base);
		}

		bool operator!=(const BSTreverse_iterator &rhs) const
		{
			return (!(*this == rhs));
		}

		reference operator*() const
		{
			return (*_base);
		}

		pointer operator->() const
		{
			return (&_base);
		}

		BSTreverse_iterator &operator++()
		{
			--_base;
			return (*this);
		}

		BSTreverse_iterator operator++(int)
		{
			BSTreverse_iterator old = *this;
			--_base;
			return (old);
		}

		BSTreverse_iterator &operator--()
		{
			++_base;
			return (*this);
		}

		BSTreverse_iterator operator--(int)
		{
			BSTreverse_iterator old = *this;
			++_base;
			return (old);
		}

		private:
		iterator_type _base;
	};
}

#endif
