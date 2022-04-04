#ifndef ITERATOR_TRAITS_HPP
# define ITERATOR_TRAITS_HPP

# include <cstddef>
# include <iterator>

namespace ft
{
	// struct input_iterator_tag { };
	// struct output_iterator_tag { };
	// struct forward_iterator_tag : public input_iterator_tag { };
	// struct bidirectional_iterator_tag : public forward_iterator_tag { };
	// struct random_access_iterator_tag : public bidirectional_iterator_tag { };
	// struct contiguous_iterator_tag: public random_access_iterator_tag { };

	template< class Iter >
	struct iterator_traits {
		typedef typename Iter::difference_type;
		typedef typename Iter::value_type;
		typedef typename Iter::pointer;
		typedef typename Iter::reference;
		typedef typename Iter::iterator_category;
	};

	template< class T >
	struct iterator_traits<T*> {
		typedef std::ptrdiff_t difference_type;
		typedef T value_type;
		typedef T* pointer;
		typedef T& reference;
		typedef std::random_access_iterator_tag iterator_category;
	};

	template< class T >
	struct iterator_traits<const T*> {
		typedef std::ptrdiff_t difference_type;
		typedef T value_type;
		typedef const T* pointer;
		typedef const T& reference;
		typedef std::random_access_iterator_tag iterator_category;
	};
}

#endif
