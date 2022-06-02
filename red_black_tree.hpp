/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_black_tree.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidurand <tidurand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 07:26:23 by tidurand          #+#    #+#             */
/*   Updated: 2022/06/02 12:13:57 by tidurand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <memory>

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

template <class Key, class Value>
class tree
{
	public:
		struct node {
			struct node *left;
			struct node *right;
			struct node *parent;
			int color;
			Key key;
			Value value;
		};
	private:
		node *root;
		node *leaf;
		void insert_fix(node *n);
		void delete_fix(node *n);
		void right_rotate(node *x)
		{
			node *y = x->left;
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
	public:
		tree(Allocator alloc = std::allocator)
		{
			leaf = alloc.allocate(sizeof(node));
			leaf->right = NULL;
			leaf->left = NULL;
			leaf->color = BLACK;
			root = leaf;
		};
		~tree();
		node *getRoot() {return root;};
		node *search(node *node, Key key)
		{
			if (node == leaf || key == node->key)
				return node;
			if (std::less(key, node->key))
				search(node->left, key);
			else
				search(node->right, key);
		};
		void insert(Key key, Value value);
		void delete_node(Key key);
		void print();
};

}