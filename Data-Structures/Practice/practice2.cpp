#include <iostream>

#include <vector>

using namespace std;

int main()

{

vector<int> scores;

scores.push_back(99);

scores.push_back(85);

scores.push_back(70);

scores.push_back(82);

scores.push_back(91);

cout << "The size of scores vector is: " << scores.size() << endl;

scores.pop_back();

cout << "The size of scores vector after pop_back is: "

<< scores.size() << endl;

cout << scores[0] << endl;

cout << scores.at(0) << endl;

cout << "capacity is " << scores.capacity() << endl;

// insert/delete ... we cover this later

}
