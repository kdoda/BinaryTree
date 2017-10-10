// main.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include <iostream>
#include <string.h>
#include "BinaryTree.h"
//#include "BinaryTree.cpp"

using namespace std;
int main(void)
{

	BinaryTree *pema;
	Node *nyjeBosh;
	// inicializimi
	pema = new BinaryTree(); 
	// Adding in this order
	// 8, 4, 12, 2, 6, 10, 14, 1, 3, 5, 7, 9, 11, 13, 15
	// pese nyjet e para shtohen me Insert1(), pjesa tjeter me Insert2()

	nyjeBosh = new Node();
	nyjeBosh->Key = 8;
	nyjeBosh->left = nyjeBosh->right = NULL;
	pema->Insert(nyjeBosh);

	nyjeBosh = new Node();
	nyjeBosh->Key = 4;
	nyjeBosh->left = nyjeBosh->right = NULL;
	pema->Insert(nyjeBosh);

	nyjeBosh = new Node();
	nyjeBosh->Key = 12;
	nyjeBosh->left = nyjeBosh->right = NULL;
	pema->Insert(nyjeBosh);

	nyjeBosh = new Node();
	nyjeBosh->Key = 2;
	nyjeBosh->left = nyjeBosh->right = NULL;
	pema->Insert(nyjeBosh);

	nyjeBosh = new Node();
	nyjeBosh->Key = 6;
	nyjeBosh->left = nyjeBosh->right = NULL;
	pema->Insert(nyjeBosh);

	pema->Insert(10);
	pema->Insert(14);
	pema->Insert(1);
	pema->Insert(3);
	pema->Insert(5);
	pema->Insert(7);
	pema->Insert(9);
	pema->Insert(11);
	pema->Insert(13);
	pema->Insert(15);
	if (!pema->Insert(15)) //nqs ka kthyer false
		cout << endl<<"Nuk mund te shtohet dublikate" << endl;
	cout << endl<< "Nr nodes:  "<<pema->nrNodes(pema->getRoot());
	cout << endl << "Nr nrLeaves:  " << pema->nrLeaves(pema->getRoot());
	cout << endl << "Nr nrFullNodes:  " << pema->nrFullNodes(pema->getRoot());
	cout << endl << "Nr nrFullNodes2:  " << pema->nrFullNodes2(pema->getRoot());
	cout << endl << "Eshte apo jo BST: " << pema->IsBST(); 
	//cout << endl << "Fshi nyjen me vler 4 me prind 8:  " << pema->fshiNyjenMePrind(pema->getRoot(), 4, 8);
	cout << endl << "Printo between 1 dhe 7" << endl;
	pema->printBetween(pema->getRoot(), 1, 7);
	//cout << endl << "Midis 1 dhe 7 jane :" << pema->nrBetween(pema->getRoot(), 1, 7,0) << "  vlera";

	//NyjePeme* newRoot=pema->removeLeaves(pema->getRoot()); //shum i sakte!!!,e kam provuar



	cout <<endl<< "Nyjet u shtuan\n";
	cout << "-----------------------------------------------------\n";
	pema->inOrder(pema->getRoot());
	cout << "-----------------------------------------------------\n";

	cout << "Testim i funksionit te kerkimit\n";
	nyjeBosh = pema->search(13);

	if (nyjeBosh != NULL)
	{
		pema->PrintNyje(nyjeBosh);
		delete nyjeBosh; //nyjeBosh eshte dublikate e nyjes ne peme prandaj duhet fshire ketu
	}
	else
		cout << "Elementi nuk gjendet\n";

	nyjeBosh = pema->search(6);

	if (nyjeBosh != NULL)
	{
		pema->PrintNyje(nyjeBosh);
		delete nyjeBosh;
	}
	else
		cout << "Elementi nuk gjendet\n";

	nyjeBosh = pema->search(1);

	if (nyjeBosh != NULL)
	{
		pema->PrintNyje(nyjeBosh);
		delete nyjeBosh;
	}
	else
		cout << "Elementi nuk gjendet\n";

	nyjeBosh = pema->search(25); //ky celes nuk ndodhet ne peme

	if (nyjeBosh != NULL)
	{
		pema->PrintNyje(nyjeBosh);
		delete nyjeBosh;
	}
	else
		cout << "Elementi nuk gjendet\n";

	cout << "-----------------------------------------------------\n";
	cout << "Testimi i funksionit te fshirje per te gjitha rastet\n";
	cout << "-----------------------------------------------------\n";
	cout << "Fshirje e nje gjetheje.\n";
	pema->Delete(7);
	pema->inOrder(pema->getRoot());

	cout << "-----------------------------------------------------\n";
	cout << "Fshirje e nje nyjeje me 2 femije.\n";
	pema->Delete(12);
	pema->inOrder(pema->getRoot());

	cout << "-----------------------------------------------------\n";
	cout << "Fshirje e nje nyjeje me 1 femije.\n";
	pema->Delete(6);
	pema->inOrder(pema->getRoot());

	cout << "-----------------------------------------------------\n";
	cout << "Fshirja e nje nyjeje qe nuk ndodhet ne peme.\n";
	pema->Delete(7);
	pema->inOrder(pema->getRoot());

	cout << "-----------------------------------------------------\n";
	cout << "Fshirja e rrenjes\n";
	pema->Delete(8);
	pema->inOrder(pema->getRoot());
	cout << "-----------------------------------------------------\n";

	return 0;
}
