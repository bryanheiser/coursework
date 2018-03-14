/*
 * Bryan Heiser
 * Homework 4 Driver
 * Boese
 */

#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include "MovieTree.cpp"
using namespace std;

int main(int argc, char* argv[])
{
    string arg1 = argv[1];
    ifstream inFile;
    inFile.open(arg1);
    
    if(!inFile.is_open()){
		cout << "file not found" << endl;
		return 0;
	}
	
	int ranking;
	string title;
	int year;
	int quantity;
	
	MovieTree tree = MovieTree();
	
    string line;
    string value;
    while(getline(inFile, line)){
		stringstream ss(line);
		getline(ss, value, ',');
		ranking = stoi(value);
		getline(ss, title, ',');
		getline(ss, value, ',');
		year = stoi(value);
		getline(ss, value, ',');
		quantity = stoi(value);
		tree.addMovieNode(ranking, title, year, quantity);
	}
	inFile.close();
    
    bool quit = false;
    string s_input;
    string movieTitle;
    int input;

    // loop until the user quits
    while (!quit)
    {
        cout << "======Main Menu======" << endl;
		cout << "1. Find a movie" << endl;
		cout << "2. Rent a movie" << endl;
		cout << "3. Print the inventory" << endl;
		cout << "4. Quit" << endl;

		// read in input, assuming a number comes in
        getline(cin, s_input);
		input = stoi(s_input);

        switch (input)
        {
            case 1: 	
                cout << "Enter title: " << endl;
                getline(cin, movieTitle);
                tree.findMovie(movieTitle);
                break;

            case 2:		
                cout << "Enter title: " << endl;
                getline(cin, movieTitle);
                tree.rentMovie(movieTitle);
                break;

            case 3: 
				tree.printMovieInventory();
                break;

            case 4: 	// quit
                quit = true;
				cout << "Goodbye!" << endl;
                break;

            default: 	// invalid input
                cout << "Invalid Input" << endl;
                break;
        }
    }
	return 0;
}
