#ifndef BSTITERATOR_HPP
# define BSTITERATOR_HPP

namespace ft
{
    template<
		class T,
		class Compare = std::less<T>,
		class Allocator = std::allocator<T> >
	class BinarySearchTree;

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
    class BSTiterator;

    template <class Iterator>
    class BSTreverse_iterator;

    template <class T, bool is_const = false>
    class BSTiterator
    {
	    public:
        typedef T value_type;
        typedef typename SelectType<is_const, T const &, T &>::type reference;
        typedef typename SelectType<is_const, T const *, T *>::type pointer;
        typedef std::ptrdiff_t difference_type;
        typedef std::bidirectional_iterator_tag iterator_category;
        typedef BSTnode<T> *node_pointer;

        BSTiterator() : _node(NULL) {}

        BSTiterator(const BSTiterator &other)
        {
            *this = other;
        }

        BSTiterator(node_pointer ptr) : _node(ptr) {}

        ~BSTiterator() {}

        operator BSTiterator<value_type, true>()
        {
            return (_node);
        }

        BSTiterator &operator=(const BSTiterator &rhs)
        {
            if (this == &rhs)
            {
                return (*this);
            }

            _node = rhs._node;
            return (*this);
        }

        bool operator==(const BSTiterator &rhs) const
        {
            return (_node == rhs._node);
        }

        bool operator!=(const BSTiterator &rhs) const
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

        BSTiterator &operator++()
        {
            _node = ft::BinarySearchTree<value_type>::successor(_node);
            return (*this);
        }

        BSTiterator operator++(int)
        {
            BSTiterator old = *this;
			_node = ft::BinarySearchTree<value_type>::successor(_node);
            return (old);
        }

        BSTiterator &operator--()
        {
            _node = ft::BinarySearchTree<value_type>::predecessor(_node);
            return (*this);
        }

        BSTiterator operator--(int)
        {
            BSTiterator old = *this;
			_node = ft::BinarySearchTree<value_type>::predecessor(_node);
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
