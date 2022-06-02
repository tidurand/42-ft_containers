/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_black_tree.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidurand <tidurand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 07:26:23 by tidurand          #+#    #+#             */
/*   Updated: 2022/06/02 14:56:10 by tidurand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RED_BLACK_TREE
# define RED_BLACK_TREE

#include <memory>
#include <functional>
#include "utils.hpp"


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

template <class Key, class Value, class Compare = std::less<Key> >
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
		Compare comp;
		void insert_fix(node *n)
		{
			node *x;
			while (n->parent->color == RED)
			{
				if (n->parent == n->parent->parent->right)
				{
					x = n->parent->parent->left;
					if (x->color == RED)
					{
						x->color = BLACK;
						n->parent->color = BLACK;
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
				else
				{
					x = n->parent->parent->right;
					if (x->color == RED)
					{
						x->color = BLACK;
						n->parent->color = BLACK;
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
				if (n == root)
					break ;
			}
			root->color = BLACK;
		};
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
		tree(Compare c = Compare())
		{
			leaf = new node;
			leaf->right = NULL;
			leaf->left = NULL;
			leaf->color = BLACK;
			root = leaf;
			comp = c;
		};
		~tree(){};
		node *getRoot() const {return root;};
		node *search(node *node, Key key)
		{
			if (node == leaf || key == node->key)
				return node;
			if (comp(key, node->key))
				search(node->left, key);
			else
				search(node->right, key);
		};
		void insert(Key key, Value value)
		{
			node * n = new node;
			n->parent = NULL;
			n->key = key;
			n->value = value;
			n->left = leaf;
			n->right = leaf;
			n->color = RED;

			node *x = root;
			node *y = NULL;
			
			while (x != leaf)
			{
				y = x;
				if (comp(n->key, x->key))
					x = x->left;
				else
					x = x->right;
			}
			if (n->parent == NULL)
			{
				n->color = BLACK;
				return ;
			}
			if (n->parent->parent == NULL)
				return ;
			insert_fix(n);
		};
		void delete_node(Key key);
		void print();
};

}

#endif