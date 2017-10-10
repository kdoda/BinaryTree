#pragma once
#include <iostream>

using namespace std;

struct Node
{
	int Key;
	Node *left;
	Node *right;
};

class BinaryTree
{
private:
	Node *root; //pointer ne rrenj te tree
 	//funksione
	void Clear(Node *T);
	Node *KopjoNyje(Node * T);
	bool isBST(Node*, int, int); //4.32 O(n) komplesikteti,is called by IsBST
public:
	void preOrder(Node*);
	void inOrder(Node*);
	void postOrder(Node*);
	//void inOrderIt(Node* root);
	BinaryTree();
	~BinaryTree();
	bool isEmpty();
	Node *search(int Key);
	bool Insert(Node *newNode);
	bool Insert(int Key);
	bool Delete(int Key);
	Node* Delete2(Node*, int); //returns root
	Node* DeleteNode(Node*); //pass the node
	void PrintNyje(Node *T);
	int  nrNodes(Node*); 
	int  nrLeaves(Node*);
	int  nrFullNodes(Node*);
	int nrFullNodes2(Node*); //e kam bere vet kot per prov
	Node* getRoot(); //just to try a function in main (user should never get the root)
	bool IsBST(); //there isBST
	Node* removeLeaves(Node*); //returns root
	bool isSame(Node* a, Node*b); //returns true if two tree are the same
	bool deleteNodeWithParent(Node*, int, int);
	int getHeight(Node*);
	void printBetween(Node*, int, int); //U 4.37 (efficient)
	int nrBetween(Node* temp, int k1, int k2, int nr);
};
