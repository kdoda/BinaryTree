#include "stdafx.h"
#include "BinaryTree.h"
#include <iostream>
#include <climits>
#include <algorithm>
#include <stack>

using namespace std;
BinaryTree::BinaryTree()
{
	root = NULL;
}

BinaryTree::~BinaryTree()
{
	Clear(root);
}


void BinaryTree::preOrder(Node* root)
{
	if (root == NULL)
		return;
	
	cout << root->Key << ", ";
	preOrder(root->left);
	preOrder(root->right);
}

void BinaryTree::inOrder(Node* root)
{
	if (root == NULL)
		return;

	preOrder(root->left);
	cout << root->Key << ", ";
	preOrder(root->right);
}

void BinaryTree::postOrder(Node* root)
{
	if (root == NULL)
		return;

	preOrder(root->left);
	cout << root->Key << ", ";
	preOrder(root->right);
}


void BinaryTree::Clear(Node *T)
{
	if (T == NULL)
		return;

	Clear(T->left);
	Clear(T->right);

	delete T;
	return;
}

bool BinaryTree::isEmpty()
{
	return(root == NULL);
}

Node* BinaryTree::KopjoNyje(Node *T)
{
	Node *kopje;
	kopje = new Node();
	*kopje = *T; // kopjon strukturen,sepse i kemi bere dereference 

				 //pse e beme kte kur prap i vum null mund tkishim kopjuar vetem value 
				 //behet dhe kshu kopje->Key = T->Key;
	kopje->left = NULL;
	kopje->right = NULL;

	return kopje;//kthejme pointer
}

Node* BinaryTree::search(int Key) //kthejme nje kopje te nyjes te krijuar ne heap prandaj e fshime ne main 
{ //e kemi per per prov se di
	Node *temp;
	temp = root;

	while ((temp != NULL) && (temp->Key != Key)) //kur duam te ecim ne rresht ne pem me while ,rekursiv perdorim  kur duam te vizitojme gjithe pemen
	{
		if (Key < temp->Key)
			temp = temp->left;
		else
			temp = temp->right;
	}

	if (temp == NULL)
		return temp; //do te thot qe se kemi gjet ,kthejme null
	else
		return(KopjoNyje(temp)); //nqs e kemi gjet krijojme ne kopje te saj ne heap dhe e kthejme
}

//e kam ndryshuar funksionin sepse kthente gjithmon true edhe shtonte dublikata
bool BinaryTree::Insert(Node *newNode) //merr pointer e nyjes qe do shtojme 
{ //kthen true kur shtohet dhe false nqs ka qen me pare 

	if (this->isEmpty()) //nqs eshte bosh
	{
		root = newNode; //ja vejme root 
		return true;  //kthejme true sepse e shtuam 
	}

	Node *temp;
	Node *p;
	temp = root;
	p = temp; //nuk eshte e nevojshme por se merrte compilatori

	while (temp != NULL)
	{
		p = temp;
		if (newNode->Key == temp->Key)
			return false; //sepse eshte tashme skemi ca shtojme 
		else if (newNode->Key < temp->Key)
			temp = temp->left;
		else
			temp = temp->right;
	} //gjejme pozicionin ku duhet ta shtojme ,temp eshte null ne kete pike prandaj na duhet p


	if (newNode->Key < p->Key)
		p->left = newNode; //nqs eshte me e vogel e shotjme majtas ne te kundert djathtas 
	else
		p->right = newNode;

	return true;
}

bool BinaryTree::Insert(int Key) //duke e shtuar me vlere 
{
	Node *nyje;
	nyje = new Node();
	nyje->Key = Key;
	nyje->left = nyje->right = NULL;

	return(Insert(nyje)); //prap kthen false nqs ka qen me pare 
}

bool BinaryTree::Delete(int Key) //kthen true nqs eshte fshire dhe false nqs nuk ka qen ajo vlere ne peme 
{
	Node *back;
	Node *temp;
	Node *delPrind; //per te mbajtur parardhesin e asaj qe duhet fshire 
	Node *delNyje; //per te mbajtur ate qe duhet fshire
	temp = root;
	back = NULL;

	while ((temp != NULL) && (Key != temp->Key))
	{
		back = temp; //mban gjithmon nje nyje siper temp
		if (Key < temp->Key)
			temp = temp->left;
		else
			temp = temp->right;
	}
	if (temp == NULL) //do te thote qw ska qen ajo vlere
		return false;
	else
	{
		if (temp == root) //nqs duhet fshire rrenja
		{
			delNyje = root;
			delPrind = NULL; //rreja ska prind 
		}
		else
		{
			delNyje = temp; //nyja qe duhet fshire
			delPrind = back; //nyja siper saj
		}
	}
	// Rasti 1: fshin nyjen me 1 ose 0 femije
	if (delNyje->right == NULL)
	{
		if (delPrind == NULL) // nqs po fshijme rrenjen
		{
			root = delNyje->left; //edhe sikur ajo majtas te jet null nyja merr null
			delete delNyje;

			return true;
		}
		else
		{
			if (delPrind->left == delNyje) //nqs ka qene ne te majte te prindit 
				delPrind->left = delNyje->left;
			else //nqs ka qen ne te djathte i ve nyjen majtas asej qe fshime per child 
				delPrind->right = delNyje->left;
			delete delNyje;

			return true;
		}
	}
	else // ka te pakten nje femije
	{
		if (delNyje->left == NULL) //ka vetem nje femije dhe eshte i djathte
		{
			if (delPrind == NULL) // nqs po fshihet rrenja
			{
				root = delNyje->right;
				delete delNyje;

				return true;
			}
			else
			{
				if (delPrind->left == delNyje) //nqs eshte ne te majten i vejme te djathten sepse ajo nuk eshte null
					delPrind->left = delNyje->right;
				else
					delPrind->right = delNyje->right;
				delete delNyje;

				return true;
			}
		}
		else // Rasti 2 po fshijem nyje me 2 femije
		{ //temp mban nyjen qe do fshihet ne kte pik
			temp = delNyje->left;
			back = delNyje; //back e mban tani nyjen qe do fshihet

			while (temp->right != NULL) //do gjejme max ne pemen majtas 
			{
				back = temp;
				temp = temp->right;
			} //temp mban nyjen e fundit ktu 
			delNyje->Key = temp->Key; // ja japim nyjes 

			if (back == delNyje) //sepse nyja mund te kete vetem nje nyje majtas (kjo mund te ket prap majtas) ,kshu qe eshte vet ajo nyje direkt 
				back->left = temp->left; //i japim null nqs kjo nyj nuk ka majtas ose nyjen e saj majtas 
			else
				back->right = temp->left; //rasti kur nyja e fundit djathtas mund te ket prap nyje majtas ose jo dhe duhet tja japim prindit te saj
			delete temp;

			return true;
		}
	}
}
//kjo eshte metoda me e mir, i jep root dhe data
Node* BinaryTree::Delete2(Node*root, int data)
{

	if (root == NULL) return root;
	else if (data < root->Key) root->left = Delete2(root->left, data); //behet lidhja kur kthehet 
	else if (data > root->Key) root->right = Delete2(root->right, data);
	// Wohoo... I found you, Get ready to be deleted	
	else {
		// Case 1:  No child
		if (root->left == NULL && root->right == NULL) {
			delete root;
			root = NULL;
		}
		//Case 2: One child 
		else if (root->left == NULL) {
			Node* temp = root;
			root = root->right;
			delete temp;
		}
		else if (root->right == NULL) {
			Node* temp = root;
			root = root->left;
			delete temp;
		}
		// case 3: 2 children
		else {
			Node* temp = root->right;
			Node* back = root;

			while (temp->right != NULL) //do gjejme min ne pemen djathtas 
			{
				back = temp;
				temp = temp->right;
			} //temp mban nyjen e fundit ktu 
			root->Key = temp->Key;

			if (back->right == temp) //sepse nyja mund te kete vetem nje nyje djathtas (kjo mund te ket prap djathtas) ,kshu qe eshte vet ajo nyje direkt 
				back->right = temp->right; //i japim null nqs kjo nyj nuk ka majtas ose nyjen e saj djathtas(majtas nuk ka) 
			else
				back->left = temp->right; //rasti kur nyja e fundit majtas mund te ket prap nyje djathtas ose jo dhe duhet tja japim prindit te saj
			delete temp;
		}
	}
	return root;
}
//i jep node direkt dhe e fshin 
Node* BinaryTree::DeleteNode(Node*root)
{
	// Case 1:  No child
	if (root->left == NULL && root->right == NULL) {
		delete root;
		root = NULL;
	}
	//Case 2: One child 
	else if (root->left == NULL) {
		Node* temp = root;
		root = root->right;
		delete temp;
	}
	else if (root->right == NULL) {
		Node* temp = root;
		root = root->left;
		delete temp;
	}
	// case 3: 2 children
	else {
		Node* temp = root->right;
		Node* back = root;

		while (temp->left != NULL) //do gjejme min ne pemen djathtas 
		{
			back = temp;
			temp = temp->left;
		} //temp mban nyjen e fundit ktu 
		root->Key = temp->Key;

		if (back->right == temp) //sepse nyja mund te kete vetem nje nyje djathtas (kjo mund te ket prap djathtas) ,kshu qe eshte vet ajo nyje direkt 
			back->right = temp->right; //i japim null nqs kjo nyj nuk ka majtas ose nyjen e saj djathtas(majtas nuk ka) 
		else
			back->left = temp->right; //rasti kur nyja e fundit majtas mund te ket prap nyje djathtas ose jo dhe duhet tja japim prindit te saj
		delete temp;
	}

	return root;
}

void BinaryTree::PrintNyje(Node *T)
{
	cout << T->Key << "\n";
}


int  BinaryTree::nrNodes(Node* temp) //duhet te marri root si input
{
	if (temp == NULL)
		return 0;

	return 1 + nrNodes(temp->left) + nrNodes(temp->right);
}

int  BinaryTree::nrLeaves(Node* temp) //duhet te marri root si input
{
	if (temp == NULL)
		return 0;
	else if (temp->left == NULL && temp->right == NULL)
		return 1;

	return nrLeaves(temp->left) + nrLeaves(temp->right);
}

int BinaryTree::nrFullNodes(Node* temp)
{
	if (temp == NULL)
		return 0;

	int tIsFull = (temp->left != NULL && temp->right != NULL) ? 1 : 0;
	return tIsFull + nrFullNodes(temp->left) + nrFullNodes(temp->right);
}

int BinaryTree::nrFullNodes2(Node* temp)
{
	if (temp == NULL)
		return 0;


	int nrnodes = nrFullNodes2(temp->left) + nrFullNodes2(temp->right);

	if (temp->left != NULL && temp->right != NULL)
		return 1 + nrnodes;
	else return 0 + nrnodes;
}

Node* BinaryTree::getRoot()
{
	return root;
}

bool BinaryTree::isBST(Node* temp, int min, int max)
{ //behet dhe ndryshe e ke te fotot
	if (temp == NULL)
		return true;

	if (temp->Key > min && temp->Key < max && isBST(temp->left, min, temp->Key) && isBST(temp->right, temp->Key, max))
		return true;
	else return false;
}

bool BinaryTree::IsBST()
{
	return isBST(root, INT_MIN, INT_MAX); //jane te librariaclimits
}

Node* BinaryTree::removeLeaves(Node* temp)
{
	if (temp == NULL)
		return NULL; //kur pema eshte bosh

	if (temp->left == NULL && temp->right == NULL) //nqs eshte leave
	{
		delete temp;
		return NULL;
	}

	temp->left = removeLeaves(temp->left);
	temp->right = removeLeaves(temp->right);

	return temp;
}

int BinaryTree::getHeight(Node* temp) //merr root
{
	if (temp == NULL)
		return -1;
	int leftHeight = getHeight(temp->left);
	int rightHeight = getHeight(temp->right);

	return max(leftHeight, rightHeight) + 1;
}

bool BinaryTree::isSame(Node* a, Node*b) //merr root e dy pemeve
{
	if (a == NULL && b == NULL)
		return  true;
	

	if (a != NULL && b != NULL && a->Key == b->Key && isSame(a->left, b->left) && isSame(a->right, b->right))
		return true;
	else return false;
}

//delete node that the key is = q and parent equal p
bool BinaryTree::deleteNodeWithParent(Node* temp, int q, int p)
{
	if (temp == NULL || temp->left == NULL || temp->right == NULL)
		return false;

	if (temp->left->Key == q && temp->Key == p)
	{
		temp->left = this->DeleteNode(temp->left); //smund te jete rrenja snjeher
		return true;
	}
	else if (temp->right->Key == q && temp->Key == p)
	{
		temp->right = this->DeleteNode(temp->right);
		return true;
	}
	bool majtas = deleteNodeWithParent(temp->left, q, p);
	bool djathtas = deleteNodeWithParent(temp->right, q, p);

	return (majtas || djathtas); //kthen true nqs te pakten njera eshte true ne te kundert false 
}

void BinaryTree::printBetween(Node* temp, int k1, int k2) //inorder i printo sipas rradhes 
{
	if (temp == NULL)
		return;

	if (temp->Key >= k1)
		printBetween(temp->left, k1, k2);//vazhdo shiko majtas
	if (temp->Key >= k1 && temp->Key <= k2)
		cout << temp->Key << "  ";
	if (temp->Key <= k2)
		printBetween(temp->right, k1, k2);//vazhdo shiko djathtas

}
//jo e sakte
int BinaryTree::nrBetween(Node* temp, int k1, int k2, int nr) //kthen nr e el midis kufinjve ,nr ne fillim duhet te jete 0 
{
	if (temp == NULL)
		return nr;
	int nrLeft = 0;
	int nrRight = 0;


	if (temp->Key >= k1)
		nrLeft = nrBetween(temp->left, k1, k2, nr);//vazhdo shiko majtas

	if (temp->Key >= k1 && temp->Key <= k2)
		nr++;

	if (temp->Key <= k2)
		nrRight = nrBetween(temp->right, k1, k2, nr);//vazhdo shiko djathtas

	return nrLeft + nrRight;

}