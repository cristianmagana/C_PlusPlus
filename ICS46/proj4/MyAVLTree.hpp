// Cristian Magana 
// 37578770
// crmagan1

// Jonathan Jin
// 17363386
// jonathj

#ifndef __PROJ_FOUR_AVL_HPP
#define __PROJ_FOUR_AVL_HPP

#include "runtimeexcept.hpp"
#include <string>
#include <vector>

#include <iostream>
#include <algorithm>
using namespace std;

class ElementNotFoundException : public RuntimeException 
{
public:
	ElementNotFoundException(const std::string & err) : RuntimeException(err) {}
};


template<typename Key, typename Value>
class MyAVLTree
{
private:
	struct Node {
		int height = 0;
		Key key_;
		Value value_;
		Node *left;
		Node *right;
		Node * prev;
		unsigned count;
	};

	Node * root;
	Node * curr;
	Node * temp;
	
	int avl_size;
	// fill in private member data here
	// If you need to declare private functions, do so here too.

public:
	MyAVLTree();

	// In general, a copy constructor and assignment operator
	// are good things to have.
	// For this quarter, I am not requiring these. 
	//	MyAVLTree(const MyAVLTree & st);
	//	MyAVLTree & operator=(const MyAVLTree & st);

	void selfDestruct(Node * root);

	// The destructor is, however, required. 
	~MyAVLTree()
	{
		selfDestruct(root);
	}

	// size() returns the number of distinct keys in the tree.
	size_t size() const noexcept;

	// isEmpty() returns true if and only if the tree has no values in it. 
	bool isEmpty() const noexcept;

	// contains() returns true if and only if there
	//  is a (key, value) pair in the tree
	//	that has the given key as its key.
	bool contains(const Key & k) const; 

	// find returns the value associated with the given key
	// If !contains(k), this will throw an ElementNotFoundException
	// There needs to be a version for const and non-const MyAVLTrees.
	Value & find(const Key & k);
	const Value & find(const Key & k) const;

	// Inserts the given key-value pair into 
	// the tree and performs the AVL re-balance
	// operation, as described in lecture. 
	// If the key already exists in the tree, 
	// you may do as you please (no test cases in
	// the grading script will deal with this situation)
	void insert(const Key & k, const Value & v);


	int height(const Node * curr) const;

	int getBalance(const Node * curr) const;

	Node * rightRotation(Node * x);
	Node * leftRotation(Node * x);
	//struct MyAVLTree::Node * leftLeftRotation(struct Node * curr);

	// in general, a "remove" function would be here
	// It's a little trickier with an AVL tree
	// and I am not requiring it for this quarter's ICS 46.
	// You should still read about the remove operation
	// in your textbook. 

	// The following three functions all return
	// the set of keys in the tree as a standard vector.
	// Each returns them in a different order.
	std::vector<Key> inOrder() const;
	std::vector<Key> preOrder() const;
	std::vector<Key> postOrder() const;

	std::vector<Key> preOrderHelper(Node* root) const;
	std::vector<Key> inOrderHelper(Node* root) const;
	std::vector<Key> postOrderHelper(Node* root) const;


};


template<typename Key, typename Value>
MyAVLTree<Key,Value>::MyAVLTree()
{
	this->root = nullptr;
	this->curr = nullptr;
	this->temp = nullptr;
	this->avl_size = 0;
}

template<typename Key, typename Value>
void MyAVLTree<Key,Value>::selfDestruct(Node * root)
{
	if(root)
	{
		selfDestruct(root->left);
		selfDestruct(root->right);
		delete root;
	}
}

template<typename Key, typename Value>
size_t MyAVLTree<Key, Value>::size() const noexcept
{
	return this->avl_size;
}

template<typename Key, typename Value>
bool MyAVLTree<Key, Value>::isEmpty() const noexcept
{
	if (root == nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template<typename Key, typename Value>
int  MyAVLTree<Key, Value>::height(const Node * curr) const
{
	if(curr == nullptr)
		return 0;
	return curr->height;
}

template<typename Key, typename Value>
int MyAVLTree<Key, Value>::getBalance(const Node * curr) const {
	if (curr == nullptr)
		return 0;

	return height(curr->left) - height(curr->right);
}

template<typename Key, typename Value>
typename MyAVLTree<Key, Value>::Node * MyAVLTree<Key, Value>::rightRotation(Node * x) {
	Node * temp_x = x;
	Node * y = x->left;
	//Node * z = y->left;

	temp_x->left = y->right;		// so that node doesn't point to previous right anymore after rotation, poinmt to y left node or nullptr
	x = y;
	x->right = temp_x;

	//include height change
	//x->left->height = max(height(x->left->left), height(x->left->right)) + 1;
	x->right->height = max(height(x->right->left), height(x->right->right)) + 1;
	x->height = max(height(x->left), height(x->right)) + 1;

	return x;
}

template<typename Key, typename Value>
typename MyAVLTree<Key, Value>::Node * MyAVLTree<Key, Value>::leftRotation(Node * x) {
	Node * temp_x = x;
	Node * y = x->right;

	temp_x->right = y->left;		// so that node doesn't point to previous right anymore after rotation, poinmt to y left node or nullptr
	x = y;
	x->left = temp_x;

	//update height
	x->left->height = max(height(x->left->left), height(x->left->right)) + 1;
	x->height = max(height(x->left), height(x->right)) + 1;


	return x;
}

template<typename Key, typename Value>
bool MyAVLTree<Key, Value>::contains(const Key &k) const
{
	bool foundKey = false; 
	Node *curr_temp = root; 

	while (!foundKey) {
		if (curr_temp == nullptr) {
			return false; 
		}
		else if (curr_temp->key_ == k) {
			foundKey = true;
			return true;
		}
		else if (k < curr_temp->key_) {
			curr_temp = curr_temp->left;
		}
		else if (k > curr_temp->key_) {
			curr_temp = curr_temp->right;
		}
	}
	return false;
}

template<typename Key, typename Value>
Value & MyAVLTree<Key, Value>::find(const Key & k)
{
	bool foundKey = false;
	Node *curr_temp = root;

	while (!foundKey) {
		if (curr_temp == nullptr) {
			throw ElementNotFoundException("No key found!");
		}
		else if (curr_temp->key_ == k) {
			foundKey = true;
			return curr_temp->value_;
		}
		else if (k < curr_temp->key_) {
			curr_temp = curr_temp->left;
		}
		else if (k > curr_temp->key_) {
			curr_temp = curr_temp->right;
		}
	}
	return curr_temp->value_;
}

template<typename Key, typename Value>
const Value & MyAVLTree<Key, Value>::find(const Key & k) const
{
	bool foundKey = false;
	Node *curr_temp = root;

	while (!foundKey) {
		if (curr_temp == nullptr) {
			throw ElementNotFoundException("No key found!");
			return;
		}
		else if (curr_temp->key_ == k) {
			foundKey = true;
			return curr_temp->value_;
		}
		else if (k < curr_temp->key_) {
			curr_temp = curr_temp->left;
		}
		else if (k > curr_temp->key_) {
			curr_temp = curr_temp->right;
		}
	}
}

template<typename Key, typename Value>
void MyAVLTree<Key, Value>::insert(const Key & k, const Value & v)
{
	this->temp = new Node;
	this->temp->key_ = k;
	this->temp->value_ = v;
	this->temp->left = nullptr;
	this->temp->right = nullptr;
	this->temp->height = 1;
	vector <Key> parentMap;

	if (isEmpty())
	{
		this->root = this->temp;
		avl_size++;
	}
	else
	{
		curr = root; 
		bool insertedKey = false;
		parentMap.push_back(root->key_);

		while (!insertedKey) {
			if (k < curr->key_) {
				if (curr->left == nullptr) {
					curr->left = temp;
					curr->height = max(height(curr->left), height(curr->right)) + 1; 
					avl_size++;
					insertedKey = true;
				}
				else if (curr->left != nullptr) {
					parentMap.push_back(curr->left->key_);
					curr = curr->left;
				}
			}
			else if (k > curr->key_) {
				if (curr->right == nullptr) {
					curr->right = temp;
					curr->height = max(height(curr->left), height(curr->right)) + 1;
					avl_size++;
					insertedKey = true;
				}
				else if (curr->right != nullptr) {
					curr->height = max(height(curr->left), height(curr->right)) + 1;
					parentMap.push_back(curr->right->key_);
					curr = curr->right;
				}
			}
		}
	}

	
	for (int i = parentMap.size() - 1; i >= 0; i--) { 
		bool foundKey = false;
		Node *curr_temp = root;

		while (!foundKey) {
			if (curr_temp->key_ == parentMap[i]) {
				foundKey = true;

				// Balance occurs here
				// rotate  left
				if (getBalance(curr_temp) < -1 && k > curr_temp->right->key_) {
					//cout << "left balancing the tree..........................." << endl;
					Node * rotated_temp = leftRotation(curr_temp);

					// parents parent need to point to new rotated nodes, not the old nodes
					if (i != 0) {								
						bool foundParent = false;
						Node *curr_temp_parent = root;

						while (!foundParent) {
							if (curr_temp_parent->key_ == parentMap[i - 1]) {
								if (k > curr_temp_parent->key_) {
									curr_temp_parent->right = rotated_temp;
									break;
								}
								else if (k < curr_temp_parent->key_) {
									curr_temp_parent->left = rotated_temp;
									break;
								}
							}
							else if (parentMap[i] < curr_temp_parent->key_) {
								curr_temp_parent = curr_temp_parent->left;
							}
							else if (parentMap[i] > curr_temp_parent->key_) {
								curr_temp_parent = curr_temp_parent->right;
							}
						}
					}
					// original root is replaced during rotation
					else if (i == 0) {
						root = rotated_temp;
					}
					/////////////////////////////////////////////////////////////////////////
				}

				// right left
				else if (getBalance(curr_temp) < -1 && k < curr_temp->right->key_) {
					//cout << "right left balancing the tree..........................." << endl;
					Node * rotated_temp = rightRotation(curr_temp->right);
					curr_temp->right = rotated_temp;

					rotated_temp = leftRotation(curr_temp);

					// parents parent need to point to new rotated nodes, not the old nodes
					if (i != 0) {
						bool foundParent = false;
						Node *curr_temp_parent = root;

						while (!foundParent) {
							if (curr_temp_parent->key_ == parentMap[i - 1]) {
								if (k > curr_temp_parent->key_) {									
									curr_temp_parent->right = rotated_temp;
									break;
								}
								else if (k < curr_temp_parent->key_) {									
									curr_temp_parent->left = rotated_temp;
									break;
								}
							}
							else if (parentMap[i] < curr_temp_parent->key_) {
								curr_temp_parent = curr_temp_parent->left;
							}
							else if (parentMap[i] > curr_temp_parent->key_) {
								curr_temp_parent = curr_temp_parent->right;
							}
						}
					}
					// original root is replaced during rotation
					else if (i == 0) {
						root = rotated_temp;
					}
					/////////////////////////////////////////////////////////////////////////

				}


				// right rotation
				else if (getBalance(curr_temp) > 1 && k < curr_temp->left->key_) {
					//cout << "right balancing the tree..........................." << endl; // left rotation
					Node * rotated_temp = rightRotation(curr_temp);

					// parents parent need to point to new rotated nodes, not the old nodes
					if (i != 0) {
						bool foundParent = false;
						Node *curr_temp_parent = root;

						while (!foundParent) {
							if (curr_temp_parent->key_ == parentMap[i - 1]) {
								if (k > curr_temp_parent->key_) {
									curr_temp_parent->right = rotated_temp;
									break;
								}
								else if (k < curr_temp_parent->key_) {
									curr_temp_parent->left = rotated_temp;
									break;
								}
							}
							else if (parentMap[i] < curr_temp_parent->key_) {
								curr_temp_parent = curr_temp_parent->left;
							}
							else if (parentMap[i] > curr_temp_parent->key_) {
								curr_temp_parent = curr_temp_parent->right;
							}
						}
					}
					// original root is replaced during rotation
					else if (i == 0) {
						root = rotated_temp;
					}
					/////////////////////////////////////////////////////////////////////////
				}

				// left right rotation
				else if (getBalance(curr_temp) > 1 && k > curr_temp->left->key_) {
					//cout << "left right balancing the tree..........................." << endl;
					Node * rotated_temp = leftRotation(curr_temp->left);
					curr_temp->left = rotated_temp;

					rotated_temp = rightRotation(curr_temp);

					// parents parent need to point to new rotated nodes, not the old nodes
					if (i != 0) {
						bool foundParent = false;
						Node *curr_temp_parent = root;

						while (!foundParent) {
							if (curr_temp_parent->key_ == parentMap[i - 1]) {
								if (k > curr_temp_parent->key_) {
									curr_temp_parent->right = rotated_temp;
									break;
								}
								else if (k < curr_temp_parent->key_) {
									curr_temp_parent->left = rotated_temp;
									break;
								}
							}
							else if (parentMap[i] < curr_temp_parent->key_) {
								curr_temp_parent = curr_temp_parent->left;
							}
							else if (parentMap[i] > curr_temp_parent->key_) {
								curr_temp_parent = curr_temp_parent->right;
							}
						}
					}
					// original root is replaced during rotation
					else if (i == 0) {
						root = rotated_temp;
					}
					/////////////////////////////////////////////////////////////////////////
				}
			}
			else if (parentMap[i] < curr_temp->key_) {
				curr_temp->height = max(height(curr_temp->left), height(curr_temp->right)) + 1;	////???????????
				curr_temp = curr_temp->left;
			}
			else if (parentMap[i] > curr_temp->key_) {
				curr_temp->height = max(height(curr_temp->left), height(curr_temp->right)) + 1;		//?????????????????
				curr_temp = curr_temp->right;
			}
		}
	}
}

template<typename Key, typename Value>
std::vector<Key>  MyAVLTree<Key, Value>::preOrderHelper(Node* root) const
{
	std::vector<Key> preOrder;
	if (root == nullptr) 
	{
		return preOrder;
	}
	std::vector<Key> visted;

	preOrder.push_back(root->key_);
	
	if (root->left != nullptr) 
	{
		visted = preOrderHelper(root->left);
		preOrder.insert(preOrder.end(), visted.begin(), visted.end());
	}

	if (root->right != nullptr) 
	{
		visted = preOrderHelper(root->right);
		preOrder.insert(preOrder.end(), visted.begin(), visted.end());
	}

	return preOrder;
}

template<typename Key, typename Value>
std::vector<Key> MyAVLTree<Key, Value>::inOrderHelper(Node* root) const
{
	std::vector<Key> inOrder;
	if (root == nullptr) 
	{
		return inOrder;
	}

	std::vector<Key> visted;

	if (root->left != nullptr) 
	{
		visted = inOrderHelper(root->left);
		inOrder.insert(inOrder.end(), visted.begin(), visted.end());
	}

	inOrder.push_back(root->key_);

	if (root->right != nullptr) 
	{
		visted = inOrderHelper(root->right);
		inOrder.insert(inOrder.end(), visted.begin(), visted.end());
	}

	return inOrder;
}

template<typename Key, typename Value>
std::vector<Key> MyAVLTree<Key, Value>::postOrderHelper(Node* root) const
{
	std::vector<Key> postOrder;
	if (root == nullptr) 
	{
		return postOrder;
	}

	std::vector<Key> visted;

	if (root->left != nullptr) 
	{
		visted = postOrderHelper(root->left);
		postOrder.insert(postOrder.end(), visted.begin(), visted.end());
	}

	if (root->right != nullptr) 
	{
		visted = postOrderHelper(root->right);
		postOrder.insert(postOrder.end(), visted.begin(), visted.end());
	}

	postOrder.push_back(root->key_);

	return postOrder;
}

template<typename Key, typename Value>
std::vector<Key> MyAVLTree<Key, Value>::inOrder() const
{
	std::vector<Key> inO = inOrderHelper(root);

 	return inOrderHelper(root);
}


template<typename Key, typename Value>
std::vector<Key> MyAVLTree<Key, Value>::preOrder() const
{
	std::vector<Key> preOr = preOrderHelper(root);

	return preOr;
}


template<typename Key, typename Value>
std::vector<Key> MyAVLTree<Key, Value>::postOrder() const
{
	std::vector<Key> postOr = postOrderHelper(root);

	return postOr; 
}







#endif 