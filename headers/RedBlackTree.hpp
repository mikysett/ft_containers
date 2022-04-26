#ifndef REDBLACKTREE_HPP
# define REDBLACKTREE_HPP

# include <stdexcept>
# include <sstream>

# include "iterator.hpp"
# include "type_traits.hpp"

namespace ft {
	template <bool Cond, class IsTrue, class IsFalse>
    struct SelectType;

    template <class IsTrue, class IsFalse>
    struct SelectType<true, IsTrue, IsFalse>
    {
        typedef IsTrue type;
    };

    template <class IsTrue, class IsFalse>
    struct SelectType<false, IsTrue, IsFalse>
    {
        typedef IsFalse type;
    };

    template <class T, bool is_const>
    class RBTiterator;

    template <class Iterator>
    class RBTreverse_iterator;

	enum Color {
		BLACK,
		RED,
	};

	template<class T>
	struct Node {
		typedef T value_type;
		typedef T *pointer;
		
		Color color;
		pointer data;
		Node *parent;
		Node *left;
		Node *right;

		explicit Node(Color c = RED)
			: color(c)
			, data(0)
			, parent(0)
			, left(0)
			, right(0)
		{}

		explicit Node(pointer data_ptr)
			: color(RED)
			, data(data_ptr)
			, parent(0)
			, left(0)
			, right(0)
		{}

		explicit Node(Node &other)
		{
			*this = other;
		}

		Node &operator=(Node &rhs) {
			if (*this == rhs)
				return (*this);
			color = rhs.color;
			data = rhs.data;
			parent = rhs.parent;
			left = rhs.left;
			right = rhs.right;
			return (*this);
		}

		~Node() {}
	};


	template<
		class T,
		class Compare = std::less<T>,
		class Allocator = std::allocator<T> >
	class RedBlackTree
	{
		public:
		typedef T value_type;
		typedef Alloc alloc_type;
		typedef Compare key_compare;
		typedef Node<T> node;
		typedef node *node_pointer;
		typedef RBTiterator<value_type, false> iterator;
		typedef RBTiterator<value_type, true> const_iterator;
		typedef RBTreverse_iterator<iterator> reverse_iterator;
		typedef RBTreverse_iterator<const_iterator> const_reverse_iterator;


		private:
	};
}

#endif
