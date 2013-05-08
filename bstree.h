#ifndef BSTREE_H
#define BSTREE_H

#include <iostream>
using namespace std;

//Binary Tree Item
template <typename T>
struct BTItem
{
	T val;
	BTItem<T>* left;
	BTItem<T>* right;
	//BTItem<T>* parent;
	
	BTItem() {val=NULL; left=NULL; right=(NULL);}
	BTItem(const T& v){val=v;left=NULL; right=NULL;}
	~BTItem() {delete this;}
};

//Binary Search Tree
template <typename T>
class BST
{
	public:
	  BST();
	  ~BST();
	  bool find(const T& v);
	  bool empty();
	  int  size();
	  void insert(const T& v);
	  void findNode(const T& v); 
	  void inOrder(BTItem<T>*);
	  void preOrder(BTItem<T>*);
	  T getMin();
	  BTItem<T>* getRoot();
	private:
	  int size_;
	  bool empty_;
	  BTItem<T>* temp;
	  BTItem<T>* root;
};

//Member Functions

template <typename T>
BST<T>::BST() : size_(0), empty_(true), root(NULL) {   }

template <typename T>
BST<T>::~BST() {   }

template <typename T>
bool BST<T>::empty() {return empty_;}

template <typename T>
int BST<T>::size() {return size_;}

template <typename T>
BTItem<T>* BST<T>::getRoot()  {return root;}

template <typename T>
bool BST<T>::find(const T& v)
{
	if(empty_)
		return false;
	temp=root;
	while(temp!=NULL)
	{
		if(temp->val==v)
			return true;
		if(v>temp->val)
			temp=temp->right;
		else
			temp=temp->left;
	}
	return false;
}

template <typename T>
void BST<T>::insert(const T& v)
{
	if(empty_)
	{
		empty_ = false;
		BTItem<T>* rand = new BTItem<T>(v);
		root = rand;
	}
	else
	{
		temp=root;
		findNode(v);
		BTItem<T>* rand=new BTItem<T>(v);
		if(v>temp->val)
			temp->right=rand;
		else
			temp->left=rand;
		temp=NULL;
	}
	size_++;
}

template <typename T>
void BST<T>::findNode(const T& v)
{
	if(v>temp->val)
	{
		if(temp->right==NULL)
			return;
		temp = temp->right;
	}
	else
	{
		if(temp->left==NULL)
			return;
		temp = temp->left;
	}
	findNode(v);	//correct usage of recursion?
}

template <typename T>
void BST<T>::inOrder(BTItem<T>* t)
{
	//if(empty) return;
	if(t==NULL)
		return;
	inOrder(t->left);
	cout<<t->val<<" ";
	inOrder(t->right);
}

template <typename T>
void BST<T>::preOrder(BTItem<T>* t)
{
	//if(empty) return;
	if(t==NULL)
		return;
	cout<<t->val<<" ";
	preOrder(t->left);
	preOrder(t->right);
}

template <typename T>
T BST<T>::getMin()
{
	if(empty_)
		return NULL;
	temp = root;
	while(temp->left!=NULL)
	{
		temp=temp->left;
	}
	return temp->val;
}

#endif
