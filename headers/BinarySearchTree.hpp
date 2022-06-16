#ifndef BINARYSEARCHTREE_HPP
# define BINARYSEARCHTREE_HPP

# include <stdexcept>
# include <sstream>

# include "BSTnode.hpp"
# include "iterator.hpp"
# include "type_traits.hpp"
# include "BSTiterator.hpp"
# include "BSTreverse_iterator.hpp"

namespace ft {
	template<
		class T,
		class Compare,
		class Allocator >
	class BinarySearchTree
	{

		public:
		typedef T value_type;
		typedef Allocator alloc_type;
		typedef Compare key_compare;
		typedef BSTnode<T> node;
		typedef node *node_pointer;
		typedef BSTiterator<value_type, false> iterator;
		typedef BSTiterator<value_type, true> const_iterator;
		typedef BSTreverse_iterator<iterator> reverse_iterator;
		typedef BSTreverse_iterator<const_iterator> const_reverse_iterator;

		private:
		key_compare _comp;
		alloc_type _alloc;
		
		public:
		node_pointer _nil;
		node_pointer _root;

		BinarySearchTree()
			: _nil(new node())
			, _root(_nil)
		{};

		BinarySearchTree(const key_compare &comp,
			const alloc_type &alloc = alloc_type())
			: _comp(comp)
			, _alloc(alloc)
			, _nil(new node())
			, _root(_nil)
		{}

		BinarySearchTree(const BinarySearchTree &other)
		{
			*this = other;
		}

		~BinarySearchTree()
		{
			clear();
			delete(_nil);
		}

		BinarySearchTree &operator=(const BinarySearchTree &other)
		{
			this->~BinarySearchTree();

			_comp = other._comp;
			_alloc = other._alloc;
			_nil = new node();
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

			bstInsert(new_node, _root);
		}

		void insert(const value_type &key, node_pointer start)
		{
			node_pointer new_node = newNode(key);

			bstInsert(new_node, start);
		}

		bool remove(value_type &key)
		{
			node_pointer node_to_remove = findKey(_root, key);

			if (node_to_remove)
			{
				bstRemove(node_to_remove);
				return (true);
			}
			return (false);
		}

		void clear()
		{
			clearHelper(_root);
			_root = _nil;
		}

		node_pointer findKey(node_pointer start, const value_type &key)
		{
			while (start != _nil)
			{
				if (!(_comp(*start->data, key) || _comp(key, *start->data)))
					return start;
				else if (_comp(*start->data, key))
					start = start->right;
				else
					start = start->left;
			}
			return (NULL);
		}

		node_pointer getRoot() const
		{
			return (_root);
		}

		private:
		void clearHelper(node_pointer curr_node)
		{
			if (curr_node == _nil)
				return ;
			clearHelper(curr_node->left);
			clearHelper(curr_node->right);

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

		void bstInsert(node_pointer n, node_pointer start)
		{
			node_pointer curr_node = start;
			node_pointer parent = NULL;

			DEBUG(
				std::cout << "-- bstInsert:" << std::endl;
				std::cout << "---- BSTnode n    : ";
				n->print();
				std::cout << "---- BSTnode start: ";
				start->print();
			)
			while (curr_node != _nil)
			{
				parent = curr_node;
				if (_comp(*n->data, *curr_node->data))
					curr_node = curr_node->left;
				else
					curr_node = curr_node->right;
			}

			n->parent = parent;
			if (!parent)
				_root = n;
			else if (_comp(*n->data, *parent->data))
			{
				parent->left = n;

			}
			else
				parent->right = n;
		}

		void bstRemove(node_pointer to_remove)
		{
			node_pointer child_left = to_remove->left;
			node_pointer child_right = to_remove->right;
			node_pointer parent = to_remove->parent;

			if (to_remove == _root)
			{
				if (child_left != _nil)
					_root = child_left;
				else
					_root = child_right;
			}
			else
			{
				if (to_remove == parent->left)
				{
					if (child_left != _nil)
						parent->left = child_left;
					else
						parent->left = child_right;
				}
				else
				{
					if (child_left != _nil)
						parent->right = child_left;
					else
						parent->right = child_right;
				}
			}
			if (child_left != _nil && child_right != _nil)
			{
				node_pointer where_to_append = max(child_left);
				where_to_append->right = child_right;
			}

			freeNode(to_remove);
		}
	};

}

#endif
