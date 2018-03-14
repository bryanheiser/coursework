#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

struct carData
{
	string make;
	string model;
	string year;
};

int main(int argc, char* argv[])
{
	ifstream inFile;
	string data;
	inFile.open(argv[1]);
	carData carArray[10];
	if(inFile.is_open())
	{
		cout << "opened successfully" << endl;
		for(int i = 0; i < 10; i++)
		{
			getline(inFile, data);
			stringstream ss(data);
			ss >> carArray[i].make;
			ss >> carArray[i].model;
			ss >> carArray[i].year;
			cout << "make: " << carArray[i].make << " model: " << carArray[i].model << " year: " << carArray[i].year << endl;
		}
		inFile.close();
	}
	else
	{
		cout << "file unsuccessfully opened" << endl;
	}
	return 0;
}
