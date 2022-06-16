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

		DEBUG(
			void print() const {
				// THIS TEST CODE BRINGS SOME HEAP USAGE AFTER FREE ERRORS
				// if (data && data->first)
				// 	std::cout << "data: " << data->first << " - " << data->second;
				// else
				// 	std::cout << " | no data";
				// if (left && left->data && left->data->first)
				// 	std::cout << " | left data: " << left->data->first << " - " << left->data->second;
				// else
				// 	std::cout << " | no left";
				// if (right && right->data && right->data->first)
				// 	std::cout << " | right data: " << right->data->first << " - " << right->data->second;
				// else
				// 	std::cout << " | no right";
				// if (parent && parent->data && parent->data->first)
				// 	std::cout << " | parent data: " << parent->data->first << " - " << parent->data->second << std::endl;
				// else
				// 	std::cout << " | no parent" << std::endl;
			}
		)

        ~BSTnode() {}
    };
}
#endif