#ifndef RBT_NODE_HPP
# define RBT_NODE_HPP

namespace ft {
    enum Color {
        BLACK,
        RED,
    };

    template<class T>
    struct RBTnode {
        typedef T value_type;
        typedef T *pointer;
        
        Color color;
        pointer data;
        RBTnode *parent;
        RBTnode *left;
        RBTnode *right;

        explicit RBTnode(Color c = RED)
            : color(c)
            , data(0)
            , parent(0)
            , left(0)
            , right(0)
        {}

        explicit RBTnode(pointer data_ptr)
            : color(RED)
            , data(data_ptr)
            , parent(0)
            , left(0)
            , right(0)
        {}

        explicit RBTnode(RBTnode &other)
        {
            *this = other;
        }

        RBTnode &operator=(RBTnode &rhs) {
            if (*this == rhs)
                return (*this);
            color = rhs.color;
            data = rhs.data;
            parent = rhs.parent;
            left = rhs.left;
            right = rhs.right;
            return (*this);
        }

        ~RBTnode() {}
    };
}
#endif