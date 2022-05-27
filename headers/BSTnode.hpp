#ifndef BSTNODE_HPP
# define BSTNODE_HPP

namespace ft {

    template<class T>
    struct BSTnode {
        typedef T value_type;
        typedef T *pointer;
        
        pointer data;
        BSTnode *parent;
        BSTnode *left;
        BSTnode *right;

        explicit BSTnode()
            : data(0)
            , parent(0)
            , left(0)
            , right(0)
        {}

        explicit BSTnode(pointer data_ptr)
            : data(data_ptr)
            , parent(0)
            , left(0)
            , right(0)
        {}

        explicit BSTnode(BSTnode &other)
        {
            *this = other;
        }

        BSTnode &operator=(BSTnode &rhs) {
            if (*this == rhs)
                return (*this);
            data = rhs.data;
            parent = rhs.parent;
            left = rhs.left;
            right = rhs.right;
            return (*this);
        }

        ~BSTnode() {}
    };
}
#endif