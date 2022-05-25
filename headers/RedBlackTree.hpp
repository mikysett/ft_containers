#ifndef REDBLACKTREE_HPP
# define REDBLACKTREE_HPP

# include <stdexcept>
# include <sstream>

# include "RBTnode.hpp"
# include "iterator.hpp"
# include "type_traits.hpp"
# include "RBTiterator.hpp"
# include "RBTreverse_iterator.hpp"

namespace ft {
	template<
		class T,
		class Compare,
		class Allocator >
	class RedBlackTree
	{
		public:
		typedef T value_type;
		typedef Allocator alloc_type;
		typedef Compare key_compare;
		typedef RBTnode<T> node;
		typedef node *node_pointer;
		typedef RBTiterator<value_type, false> iterator;
		typedef RBTiterator<value_type, true> const_iterator;
		typedef RBTreverse_iterator<iterator> reverse_iterator;
		typedef RBTreverse_iterator<const_iterator> const_reverse_iterator;

		RedBlackTree(const key_compare &comp = key_compare(),
			const alloc_type &alloc = alloc_type())
			: _comp(comp)
			, _alloc(alloc)
			, _nil(new node(BLACK))
			, _root(_nil)
		{}

		RedBlackTree(const RedBlackTree &other)
		{
			*this = other;
		}

		~RedBlackTree()
		{
			clear();
			delete(_nil);
		}

		RedBlackTree &operator=(const RedBlackTree &other)
		{
			this->~RedBlackTree();

			_comp = other._comp;
			_alloc = other._alloc;
			_nil = new node(BLACK);
			_root = _nil;

			node_pointer curr_node = other.start();
			node_pointer last = other.last();

			for ( ; curr_node != last ; curr_node = successor(curr_node))
				insert(*curr_node->data);
			if (curr_node)
				insert(*curr_node->data);
			return (*this);
		}

		node_pointer start() const
		{
			return (min(_root));
		}

		node_pointer last() const
		{
			return (max(_root));
		}

		static node_pointer successor(node_pointer start)
		{
			if (start && start->right->parent)
				return (min(start->right));
			else {
				node_pointer parent = start->parent;
				while (parent && parent->right == start)
				{
					start = parent;
					parent = start->parent;
				}
				return (parent);
			}
		}

		static node_pointer predecessor(node_pointer start)
		{
			if (start && start->left->parent)
				return (max(start->left));
			else {
				node_pointer parent = start->parent;
				while (parent && parent->left == start)
				{
					start = parent;
					parent = start->parent;
				}
				return (parent);
			}
		}

		void insert(const value_type &key)
		{
			node_pointer new_node = newNode(key);

			bstInsert(new_node);
			fixInsert(new_node);
		}

		private:
		key_compare _comp;
		alloc_type _alloc;
		node_pointer _nil;
		node_pointer _root;

		void clear(node_pointer curr_node)
		{
			if (curr_node == _nil)
				return ;
			clear(curr_node->left);
			clear(curr_node->right);

			freeNode(curr_node);
		}

		void freeNode(node_pointer node)
		{
			_alloc.destroy(node->data);
			_alloc.deallocate(node->data, 1);
			delete(node);
		}

		node_pointer newNode(const value_type &key)
		{
			node_pointer new_node = new node(_alloc.allocate(1));

			_alloc.construct(new_node->data, key);
			new_node->parent = 0;
			new_node->left = _nil;
			new_node->right = _nil;
			return (new_node);
		}

		static node_pointer min(node_pointer node)
		{
			if (!node || !node->left)
				return NULL;
			while (node->left->parent)
				node = node->left;
			return (node);
		}

		static node_pointer max(node_pointer node)
		{
			if (!node || !node->right)
				return NULL;
			while (node->right->parent)
				node = node->right;
			return (node);
		}
	};
}

#endif
