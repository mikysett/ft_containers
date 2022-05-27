#ifndef RBTITERATOR_HPP
# define RBTITERATOR_HPP

namespace ft
{
    template<
		class T,
		class Compare = std::less<T>,
		class Allocator = std::allocator<T> >
	class RedBlackTree;

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

    template <class T, bool is_const = false>
    class RBTiterator
    {
	    public:
        typedef T value_type;
        typedef typename SelectType<is_const, T const &, T &>::type reference;
        typedef typename SelectType<is_const, T const *, T *>::type pointer;
        typedef std::ptrdiff_t difference_type;
        typedef std::bidirectional_iterator_tag iterator_category;
        typedef RBTnode<T> *node_pointer;

        RBTiterator() : _node(NULL) {}

        RBTiterator(const RBTiterator &other)
        {
            *this = other;
        }

        RBTiterator(node_pointer ptr) : _node(ptr) {}

        ~RBTiterator() {}

        operator RBTiterator<value_type, true>()
        {
            return (_node);
        }

        RBTiterator &operator=(const RBTiterator &rhs)
        {
            if (this == &rhs)
            {
                return (*this);
            }

            _node = rhs._node;
            return (*this);
        }

        bool operator==(const RBTiterator &rhs) const
        {
            return (_node == rhs._node);
        }

        bool operator!=(const RBTiterator &rhs) const
        {
            return (!(*this == rhs));
        }

        reference operator*() const
        {
            return (*_node->data);
        }

        pointer operator->() const
        {
            return (_node->data);
        }

        RBTiterator &operator++()
        {
            _node = ft::RedBlackTree<value_type>::successor(_node);
            return (*this);
        }

        RBTiterator operator++(int)
        {
            RBTiterator old = *this;
			_node = ft::RedBlackTree<value_type>::successor(_node);
            return (old);
        }

        RBTiterator &operator--()
        {
            _node = ft::RedBlackTree<value_type>::predecessor(_node);
            return (*this);
        }

        RBTiterator operator--(int)
        {
            RBTiterator old = *this;
			_node = ft::RedBlackTree<value_type>::predecessor(_node);
            return (old);
        }

        node_pointer getNode() const
        {
            return (_node);
        }

    private:
        node_pointer _node;
    };
}

#endif
