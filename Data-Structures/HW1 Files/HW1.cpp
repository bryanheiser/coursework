#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

struct wordItem
{
	string word;
	int count;
};
	
void getStopWords(char *ignoreWordFileName, vector<string>& vecIgnoreWords);

bool isCommonWord(string word, vector<string>& vecIgnoreWords);

void printTopN(wordItem wordItemList[], int topN);

const int STOPWORD_LIST_SIZE = 50;

int main(int argc, char* argv[])
{
	vector<string> vecIgnoreWords(STOPWORD_LIST_SIZE);
	
	if(argc != 4)
	{
		cout << "Usage: ";
		cout << argv[0] << " <number of words> <filename.txt> <ignorefilename.txt>";
		cout << endl;
		return 0;
	}
	
	int numWords = *argv[1];     //reads in the number of common words to process
	string txtFile = "";
	txtFile = *argv[2];                     //reads in the name of the text file  
	getStopWords(argv[3], vecIgnoreWords);   //reads the common words file and stores it in vecIgnoreWords
	
	int numArrDoubled;
	ifstream inFile;
	string data;
	wordItem uniqueWord[100]; 
	vector<string> words;       
	inFile.open(txtFile);        
	if(inFile.is_open())
	{
		cout << "file opened successfully" << endl;
		while(inFile.eof() == 0)                             //checks if its at the end of the file
		{
			getline(inFile, data);
			stringstream ss(data);                        //gets line from text file
			string test;
			while(ss >> words)
			{
				ss >> test;
				if(isCommonWord(test, vecIgnoreWords) == 0)       //checks if its common and stores it in a vector
				{
					words.push_back(ss);
				}
			}
		}
		
	}
	else
	{
		cout << "file unsuccessfully opened" << endl;
	}
	
	if(words.size() > ((sizeof(uniqueWord))/4))        //divide by 4 here because each element is 4 bytes
	{
		int vecSize = ((sizeof(uniqueWord))/4);
		temp = new wordItem [vecSize * 2];                      //double the size of the array
		numArrDoubled += 1;
		for(int i = 0; i < words.size(); i++)				
		{
			if(i < vecSize)
			{
				temp[i].word = uniqueWord[i].word;
				temp[i].count = uniqueWord[i].count;        
			}
			else
			{
				temp[i].word = "";
				temp[i].count = 0;
			}
		}
		uniqueWord = temp;
		delete[] temp;
	}
	
	vector<string> check;
	for(int i = 0; i < words.size(); i++)
	{
		check.push_back(words[i]);
		int b = 1;
		for(int x = 0; x < check.size(); x++)             //finds unique words and stores them in an array of structs
		{
			if(strcmp(words[i],check[x]) == 1)
			{
				uniqueWord[x].count += 1;
				uniqueWord[x].word = words[i];
				b = 0;
			}
		}
		if(b == 1)
		{
			uniqueWord[i].word = words[i];
		}
	 }
	 
	 printTopN(uniqueWord, numWords);
	 cout << "#" << endl;
	 cout << "Array doubled: " << numArrDoubled << endl;
	 cout << "#" << endl;
	 cout << "Unique non-common words: ";
	 cout << getTotalNumberNonCommonWords(uniqueWord) << endl;
	 cout << "#" << endl;
	 cout << "Total non-common words: " << words.size() <<endl;
	
	return 0;
}

int getTotalNumberNonCommonWords(wordItem array)
{
	int a = sizeof(array)/sizeof(array[0]);
	return a;
	
}

void printTopN(wordItem wordItemList[], int topN)
{
	vector<string> temp;
	int num = 0;
	int a = 0;
	for(int i = 0; i < (sizeof(uniqueWord)/sizeof(uniqueWord[0])); i++)
	{
		temp.push_back(uniqueWord[i].count);
	}
	for(int k = 0; k < topN; k++)
	{
		num = 0;
		for(int i = 0; i < temp.size(); i++)
		{
			if(temp[i] > num)
			{
				num = temp[i];
				a = i;
			}
		}
		cout << num << " - " << uniqueWord[a].word << endl;
		temp[a] = 0;
	}
	
	return;
}

bool isCommonWord(string word, vector<string>& vecIgnoreWords)
{
	for(int i = 0; i < 50; i++)
	{
		if(strcmp(test, vecIgnoreWords[i]) == 1)                    //compares word to list of common words
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
}

void getStopWords(char *ignoreWordFileName, vector<string>& vecIgnoreWords)
{
	ifstream inFile;
	string data;
	inFile.open(ignoreWordFileName);
	if(inFile.is_open())
	{
		cout << "file opened successfully" <<endl;
		for(int i = 0; i < 50; i++)
		{
			getline(inFile, data);
			stringstream ss(data);
			ss >> vecIgnoreWords[i];                                          //stores most common words in a vector
		}
		inFile.close();
	}
	else
	{
		cout << "file unsuccessfully opened" << endl;
	}
	return;
}
