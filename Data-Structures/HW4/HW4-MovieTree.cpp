/*
 * Bryan Heiser
 * Homework 4
 * Boese
 */

#include <iostream>
#include <string>
#include <cstdlib>
#include "HW4-MovieTree.hpp"
using namespace std;

MovieTree::MovieTree()
{
	root = NULL;
}

MovieTree::~MovieTree()
{
	
}

void MovieTree::printMovieInventory()
{
	printMovieInventory(root);
}

void MovieTree::addMovieNode(int ranking, std::string title, int releaseYear, int quantity)
{
	MovieNode *temp;
	MovieNode *tempParent;
	if(root == NULL)                                                   //adds first node in the tree
	{
		root = new MovieNode(ranking, title, releaseYear, quantity);          //creates new node w/ correct parameters       
		root->parent = NULL;
		root->leftChild = NULL;
		root->rightChild = NULL;
	}
	else
	{
		temp = root;
		while(temp != NULL)    // runs thru tree until temp is NULL
		{
			if(title.compare(temp->title) < 0)        //checks if title is less than the title its looking at
			{
				tempParent = temp;
				temp = temp->leftChild;             //increments thru tree
			}
			else if(title.compare(temp->title) > 0)     //checks if title is less than the title its looking at
			{
				tempParent = temp;
				temp = temp->rightChild;             //increments thru tree
			}
		}
		MovieNode *newMovie = new MovieNode(ranking, title, releaseYear, quantity);      //creates new node w/ correct parameters
		newMovie->parent = tempParent;
		newMovie->rightChild = NULL;
		newMovie->leftChild = NULL;
		
		if(title.compare(tempParent->title) < 0)      
			tempParent->leftChild = newMovie;
		else if(title.compare(tempParent->title) > 0)          //adds new node to either right or left of parent
			tempParent->rightChild = newMovie;
	}
}

void MovieTree::findMovie(std::string title)
{
	MovieNode *temp = search(title);
	if(temp == 0) {
		cout << "Movie not found." << endl;
		return;
	}
	cout << "Movie Info:" << endl;
	cout << "===========" << endl;
	cout << "Ranking:" << temp->ranking << endl;
	cout << "Title:" << temp->title << endl;
	cout << "Year:" << temp->year << endl;
	cout << "Quantity:" << temp->quantity << endl;
}

void MovieTree::rentMovie(std::string title)
{
	MovieNode *foundMovie = root;
	if(foundMovie == NULL) {
		cout << "Movie not found." << endl;
	}
	else {
		foundMovie = search(title);
		if(foundMovie == 0) {
			cout << "Movie not found." << endl;
			return;
		}
		if(foundMovie->quantity == 0) {
			cout << "Movie out of stock." << endl;
		}
		else {
			foundMovie->quantity--;
			cout << "Movie has been rented." << endl;
			cout << "Movie Info:" << endl;
			cout << "===========" << endl;
			cout << "Ranking:" << foundMovie->ranking << endl;
			cout << "Title:" << foundMovie->title << endl;
			cout << "Year:" << foundMovie->year << endl;
			cout << "Quantity:" << foundMovie->quantity << endl;
		}
	}
}

void MovieTree::printMovieInventory(MovieNode * node)
{
	if(node == NULL) return;
	if(node->leftChild != NULL)
		printMovieInventory(node->leftChild);	
		
	cout << "Movie: " << node->title << " " << node->quantity << endl;
	
	if(node->rightChild != NULL)
		printMovieInventory(node->rightChild);
}

MovieNode* MovieTree::search(std::string title)
{
	MovieNode *temp;
	temp = root;
	if(temp == NULL) {
		cout << "Movie not found." << endl;
		return 0;
	}
	else {
		while(temp != NULL){
			if(title.compare(temp->title) < 0) {
				temp = temp->leftChild;
			}
			else if(title.compare(temp->title) > 0) {
				temp = temp->rightChild;
			}
			else if(title.compare(temp->title) == 0) return temp;
			else return 0;
		}
	}
}


