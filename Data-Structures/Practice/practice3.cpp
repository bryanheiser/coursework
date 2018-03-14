#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int main(int argc, char* argv[])
{
	ifstream inFile;
	string data;
	string elementOne;
	inFile.open(argv[1]);
	if(inFile.is_open())
	{
		cout << "opened successfully" << endl;
		for(int i = 0; i < 10; i++)
		{
			getline(inFile, data, ' ');
			stringstream ss(data);
			ss >> elementOne;
			cout << elementOne << endl;
		}
		inFile.close();
	}
	else
	{
		cout << "file unsuccessfully opened" << endl;
	}
	return 0;
}
