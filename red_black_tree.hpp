/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_black_tree.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidurand <tidurand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 07:26:23 by tidurand          #+#    #+#             */
/*   Updated: 2022/06/06 11:21:09 by tidurand         ###   ########.fr       */
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

template <class Key, class Value, class Compare = std::less<Key> >
class tree
{
	public:
		typedef struct node {
			struct node *left;
			struct node *right;
			struct node *parent;
			int color;
			Key key;
			Value value;
		} node;
	private:
		node *root;
		node *leaf;
		Compare comp;
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
					else if (n == n->parent->right)
					{
						n = n->parent;
						left_rotate(n);
					}
					//else
					if (n->parent) //maybe in elsif
					{
						n->parent->color = BLACK;
						if (n->parent->parent)
						{
							n->parent->parent->color = RED;
							right_rotate(n->parent->parent);	
						}
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
					else if (n == n->parent->left)
					{
						n = n->parent;
						right_rotate(n);
					}
					if (n->parent) //maybe in elsif
					{
						n->parent->color = BLACK;
						if (n->parent->parent)
						{
							n->parent->parent->color = RED;
							right_rotate(n->parent->parent);	
						}
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
			if (y->right != NULL)
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
			if (y->left != NULL)
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
			comp = c;
			leaf = new node;
			leaf->color = BLACK;
			leaf->left = NULL;
			leaf->right = NULL;
			leaf->parent = NULL;
			root = leaf;
			size = 0;
		};
		~tree(){};
		node *getRoot() const {return root;};
		size_t getSize() const {return size;};
		Value &search(node *node, Key key)
		{
			while (node != NULL && key != node->key)
			{
				if (comp(key, node->key))
					node = node->left;
				else
					node = node->right;
			}
			if (node == NULL)
				throw ; //do exception
			return node->value;
		};
		void insert(Key key, Value value)
		{
			node *x;

			node *n = new node;
			n->color = RED;
			n->parent = NULL;
			n->key = key;
			n->value = value;
			n->left = leaf;
			n->right = leaf;
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
				if(comp(n->key, x->key))
					x = x->left;
				else
					x = x->right;
			}
			n->parent = y;
			if (comp(n->key, y->key))
				y->left = n;
			else
				y->right = n;
			insert_fix(n);
		};
		void delete_node(Key key);
		node *begin()
		{
			node *x = root;
			while (x->left != leaf)
				x = x->left;
			return x;
		}
		void print()
		{
			std::cout << "Red Black Tree :" << std::endl;
			if (root == leaf)
			{
				std::cout << "Empty" << std::endl;
				return;
			}
			size_t cpy_size = size;
			node *x = root;
			node *y = NULL;
			std::cout << "ROOT Key: " << x->key << " Value: " << x->value << " Color: " << x->color << std::endl;
			while (x->left != leaf)
				x = x->left;
			while (cpy_size > 0)
			{
				std::cout << "Key: " << x->key << " Value: " << x->value << " Color: " << x->color << std::endl;
				cpy_size--;
				y = x->parent;
				if (y->right != leaf)
				{
					y = y->right;
					while (y->left != leaf)
						y = y->left;
				}
				x = y;
			}
		};
};

}

#endif