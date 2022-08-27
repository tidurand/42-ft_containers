/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_black_tree.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidurand <tidurand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 07:26:23 by tidurand          #+#    #+#             */
/*   Updated: 2022/08/27 09:35:56 by tidurand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RED_BLACK_TREE
# define RED_BLACK_TREE

#include <memory>
#include <functional>
#include "utils.hpp"
#include <iostream>


#define BLACK 0
#define RED 1

namespace ft {

// template <class Key, class Value>
// struct node {
// 	struct node *left;
// 	struct node *right;
// 	struct node *parent;
// 	int color;
// 	Key key;
// 	Value value;
// };

template <class Key, class Value, class Data, class Compare = std::less<Key>,
 class Allocator = std::allocator<ft::pair<const Key, Value> > >
class tree
{
	public:
	typedef  node<Data> node;
	public:
		node *root;
		node *leaf;
		Compare comp;
		Allocator alloc;
		std::size_t size;
		void insert_fix(node *n)
		{
			while (n->parent->color == RED)
			{
				if (n->parent == n->parent->parent->left)
				{
					if (n->parent->parent->right->color == RED)
					{
						n->parent->parent->left->color = BLACK;
						n->parent->parent->right->color = BLACK;
						n->parent->parent->color = RED;
						n = n->parent->parent;
					}
					else 
					{
						if (n == n->parent->right)
						{
							n = n->parent;
							left_rotate(n);
						}
						n->parent->color = BLACK;
						n->parent->parent->color = RED;
						right_rotate(n->parent->parent);
					}
				}
				else
				{
					if (n->parent->parent->left->color == RED)
					{
						n->parent->parent->left->color = BLACK;
						n->parent->parent->right->color = BLACK;
						n->parent->parent->color = RED;
						n = n->parent->parent;
					}
					else 
					{
						if (n == n->parent->left)
						{
							n = n->parent;
							right_rotate(n);
						}
						n->parent->color = BLACK;
						n->parent->parent->color = RED;
						left_rotate(n->parent->parent);
					}
				}
				if (n == root)
					break ;
			}
			root->color = BLACK;
			
		};
		void delete_fix(node *n)
		{
			node *y;
			while (n != root && n->color == BLACK)
			{
				if (n->parent->left == n)
				{
					y = n->parent->right;
					if (y->color == RED)
					{
						y->color = BLACK;
						n->parent->color = RED;
						left_rotate(n->parent);
						y = n->parent->right;
					}
					if (y->left->color == BLACK && y->right->color == BLACK)
					{
						y->color = RED;
						n = n->parent;
					}
					else if (y->right->color == BLACK)
					{
						y->left->color = BLACK;
						y->color = RED;
						right_rotate(y);
						y = n->parent->right;
					}
					else
					{
						y->color = n->parent->color;
						n->parent->parent->color = BLACK;
						y->right->color = BLACK;
						left_rotate(n->parent);
						n = root;
					}
				}
				else
				{
					y = n->parent->left;
					if (y->color == RED)
					{
						y->color = BLACK;
						n->parent->color = RED;
						right_rotate(n->parent);
						y = n->parent->left;
					}
					if (y->left->color == BLACK && y->right->color == BLACK)
					{
						y->color = RED;
						n = n->parent;
					}
					else if (y->left->color == BLACK)
					{
						y->right->color = BLACK;
						y->color = RED;
						left_rotate(y);
						y = n->parent->left;
					}
					else
					{
						y->color = n->parent->color;
						n->parent->parent->color = BLACK;
						y->left->color = BLACK;
						right_rotate(n->parent);
						n = root;
					}
				}
			}
			n->color = BLACK;
		};
		void right_rotate(node *x)
		{
			node *y = x->left;
			if (y == leaf)
				return;
			x->left = y->right;
			if (y->right != leaf)
				y->right->parent = x;
			y->parent = x->parent;
			if (x->parent == NULL)
				this->root = y;
			else if (x == x->parent->right)
				x->parent->right = y;
			else
				x->parent->left = y;
			y->right = x;
			x->parent = y;
  		};
		void left_rotate(node *x)
		{
			node *y = x->right;
			if (y == leaf)
				return;
			x->right = y->left;
			if (y->left != leaf)
				y->left->parent = x;
			y->parent = x->parent;
			if (x->parent == NULL)
				this->root = y;
			else if (x == x->parent->left)
				x->parent->left = y;
			else
				x->parent->right = y;
			y->left = x;
			x->parent = y;
		};
		void transplant(node *x, node *y)
		{
			if (x->parent == NULL)
				root = y;
			else if (x == x->parent->left)
				x->parent->left = y;
			else
				x->parent->right = y;
			y->parent = x->parent;
		}
	public:
		tree(Compare c = Compare())
		{
			comp = c;
			leaf = new node();
			leaf->color = BLACK;
			leaf->left = NULL;
			leaf->right = NULL;
			leaf->parent = NULL;
			leaf->is_leaf = true;
			root = leaf;
			size = 0;
		};
		~tree(){};
		node *getRoot() const {return root;};
		size_t getSize() const {return size;};
		Value search(node *node, Key key)
		{
			while (node != NULL && key != node->data.first)
			{
				if (comp(key, node->data.first))
					node = node->left;
				else
					node = node->right;
			}
			if (node == NULL)
				return NULL;
			return node->data.second;
		};
		void insert(Data data)
		{
			node *x;

			node *n = new node(data);
			n->is_leaf = false;
			n->color = RED;
			n->parent = NULL;
			n->left = leaf;
			n->right = leaf;
			n->left->is_leaf = true;
			n->right->is_leaf = true;
			x = root;
			node *y = NULL;
			size++;
			if (x == leaf)
			{
				root = n;
				n->color = BLACK;
				return ;
			}
			while (x != leaf)
			{
				y = x;
				if(comp(n->data.first, x->data.first))
					x = x->left;
				else
					x = x->right;
			}
			n->parent = y;
			if (comp(n->data.first, y->data.first))
				y->left = n;
			else
				y->right = n;
			insert_fix(n);
		};
		void delete_node(node *n)
		{
			node *x;
			node *y;
			node *min;
			size--;
			int original_color = n->color;
			if (n->left == leaf)
			{
				x = n->right;
				transplant(n, x);
			}
			else if (n->right == leaf)
			{
				x = n->left;
				transplant(n, x);
			}
			else
			{
				min = n->right;
				while (min->left != leaf)
					min = min->left;
				y = min;
				original_color = y->color;
				x = y->right;
				if (y->parent == n)
					x->parent = y;
				else
				{
					transplant(y, y->right);
					y->right = n->right;
					y->right->parent = y;
				}
				transplant(n, y);
				y->left = n->left;
				y->left->parent = y;
				y->color = n->color;
			}
			delete n;
			if (original_color == BLACK)
				delete_fix(x);
		}
		node *begin() const
		{
			node *x = root;
			while (x->left && x->left != leaf)
				x = x->left;
			return x;
		}
		node *end() const
		{
			node *x = root;
			node *p;
			while (x->right != NULL)
			{
				p = x;
				x = x->right;
			}
			x->parent = p;
			return x;
		}
		int delete_search(node *node, Key key)
		{
			while (node != NULL && key != node->data.first)
			{
				if (comp(key, node->data.first))
					node = node->left;
				else
					node = node->right;
			}
			if (node == NULL)
				return 0;
			delete_node(node);
			return 1;
		}
		node *node_search(node *node, Key key)
		{
			while (node != NULL && key != node->data.first)
			{
				if (comp(key, node->data.first))
					node = node->left;
				else
					node = node->right;
			}
			if (node == NULL)
				return NULL;
			return node;
		}
		// node *lower_search(node *node, Key key)
		// {
		// 	while (node != NULL && comp(key, node->data.first))
		// 	{
		// 		node = node->left;
		// 	}
		// 	while (node != NULL && !comp(key, node->data.first))
		// 	{
		// 		node = node->right;
		// 	}
		// 	if (node == NULL)
		// 		return NULL;
		// 	return node;
		// }
		// node *upper_search(node *node, Key key)
		// {
		// 	while (node != NULL && key != node->data.first)
		// 	{
		// 		if (comp(key, node->data.first))
		// 			node = node->left;
		// 		else
		// 			node = node->right;
		// 	}
		// 	if (node == NULL)
		// 		return NULL;
		// 	return node;
		// }
		void print()
		{
			std::cout << "Red Black Tree :" << std::endl;
			if (root == leaf)
			{
				std::cout << "Empty" << std::endl;
				return;
			}
			std::cout << "ROOT: " << root->data.first << std::endl;
			
		};
};

}

#endif