#ifndef BSTNODE_HPP
# define BSTNODE_HPP

namespace ft {

	template<class T>
	struct BSTnode {
		typedef T value_type;
		
		value_type data;
		BSTnode *parent;
		BSTnode *left;
		BSTnode *right;

		BSTnode(value_type data, BSTnode *parent, BSTnode *left, BSTnode *right)
			: data(data)
			, parent(parent)
			, left(left)
			, right(right)
		{}

		// explicit BSTnode(BSTnode &other)
		// {
		// 	*this = other;
		// }

		// BSTnode &operator=(BSTnode &rhs) {
		// 	if (*this == rhs)
		// 		return (*this);
		// 	data = rhs.data;
		// 	parent = rhs.parent;
		// 	left = rhs.left;
		// 	right = rhs.right;
		// 	return (*this);
		// }

		// ~BSTnode() {}
	};
}
#endif