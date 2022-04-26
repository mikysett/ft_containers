#ifndef RBTREVERSE_ITERATOR_HPP
# define RBTREVERSE_ITERATOR_HPP

namespace ft {
	template <class Iterator>
	class RBTreverse_iterator
	{
		public:
		typedef Iterator iterator_type;
		typedef typename iterator_traits<Iterator>::iterator_category iterator_category;
		typedef typename iterator_traits<Iterator>::value_type value_type;
		typedef typename iterator_traits<Iterator>::difference_type difference_type;
		typedef typename iterator_traits<Iterator>::pointer pointer;
		typedef typename iterator_traits<Iterator>::reference reference;

		RBTreverse_iterator() : _base(iterator_type()) {}

		explicit RBTreverse_iterator(iterator_type it) : _base(it) {}

		template <class Iter>
		RBTreverse_iterator(const RBTreverse_iterator<Iter> &rev_it) : _base(rev_it._base) {}

		iterator_type base() const
		{
			return (_base);
		}

		bool operator==(const RBTreverse_iterator &rhs) const
		{
			return (_base == rhs._base);
		}

		bool operator!=(const RBTreverse_iterator &rhs) const
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

		RBTreverse_iterator &operator++()
		{
			--_base;
			return (*this);
		}

		RBTreverse_iterator operator++(int)
		{
			RBTreverse_iterator old = *this;
			--_base;
			return (old);
		}

		RBTreverse_iterator &operator--()
		{
			++_base;
			return (*this);
		}

		RBTreverse_iterator operator--(int)
		{
			RBTreverse_iterator old = *this;
			++_base;
			return (old);
		}

		private:
		iterator_type _base;
	};
}

#endif
