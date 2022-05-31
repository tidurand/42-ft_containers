/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_black_tree.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidurand <tidurand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 07:26:23 by tidurand          #+#    #+#             */
/*   Updated: 2022/05/31 09:25:54 by tidurand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define BLACK 0
#define RED 1

template <class Key>
struct node {
	struct node *left;
	struct node *right;
	struct node *parent;
	int color;
	Key key;
}

template <class Key>
class tree
{
	private:
		node *root;
		node *leaf;

	public:
		tree()
		{
			leaf = new node;
			leaf->right = NULL;
			leaf->left = NULL;
			leaf->color = BLACK;
			root = leaf;
		};
		~tree();
		node *getRoot {return root;}
		node *search(node *node, Key key)
		{
			if (node == leaf || key == node->key)
				return node;
			if (key < node->key)
				search(node->left, key);
			else
				search(node->right, key);
		};
		void insert(Key key);
		void right_rotate(node *n){};
		void left_rotate(node *n){};
};