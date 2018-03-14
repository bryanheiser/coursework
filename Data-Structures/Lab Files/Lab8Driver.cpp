#include "Lab8.cpp"
using namespace std;

int main()
{
	int size = 10;
	HashTab hash(size);
	hash.Insert(3);
	hash.Insert(5);
	hash.Insert(8);
	hash.display();
	hash.Delete(8);
	hash.display();
	
	return 0;
}
