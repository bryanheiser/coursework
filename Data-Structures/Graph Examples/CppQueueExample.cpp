#include <iostream>
/*Example code showing how to use the queue class built into the standard template
library. We'll use the queue to enqueue and dequeue a vector, adding something to the
vector each time it is dequeued, and then adding it back to the queue.*/

#include <queue> //include from the STL

using namespace std;

/*node contains two members, an integer sum and a vector of integers.*/
struct node
{
    vector<int> integers;
};

int main()
{
    std::queue<node> myQueue;
    //create a node
    node ints;
    int i = 0;
    while(i < 10)
	{
        ints.integers.push_back(i); //add a 0 to the integer vector
        //add integer vector to the queue
        myQueue.push(ints);
        i++;
    }
    while(!myQueue.empty())
	{
        node temp = myQueue.front(); //this is the STL version of dequeue
        myQueue.pop(); //need to pop to remove the item at the head
        /*The size of the temp vector increased each time we added one integer
        to the vector. Each time we dequeue, we need to loop over everything in the
        vector that was dequeued.*/
        for(int i = 0; i < temp.integers.size(); i++)
            cout << temp.integers[i];
        cout << endl;
    }

    /*This next example is similar to the one above, except that we're going
    to enqueue multiple integers each time an integer is dequeued. We're not using
    a vector of ints this time, just a single int.*/

    /*In this algorithm, we'll enqueue an integer. Then, when we dequeue it, we'll
    multiply it by 2, 3, and 5 then add each of these integers to the queue. We continue
    this process until the value dequeued is greater than some value. From there, we
    just dequeue everything that's left.*/
    i = 0;
    std::queue<int> intQueue;
    intQueue.push(1); //start with a 1 on the queue
    while(!intQueue.empty())
	{
        int temp = intQueue.front(); //dequeue
        intQueue.pop();
        cout << "popping " << temp << endl;
        if(temp < 10)
		{
            //enqueue each, so there should be 3 enqueues
            int newValue = temp * 2;
            intQueue.push(newValue);
            cout << "pushing " << newValue << endl;
            newValue = temp * 3;
            intQueue.push(newValue);
            cout << "pushing " << newValue << endl;
            newValue = temp * 5;
            intQueue.push(newValue);
            cout << "pushing " << newValue << endl;
        }
    }
    return 0;
}
