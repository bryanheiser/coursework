/*
 * Bryan Heiser
 * HW 7
 * Boese
 */ 

#include <iostream>
#include <string>
#include <cstdlib>
#include "PatientQueue.hpp"
using namespace std;

PatientQueue::PatientQueue()
{
	lastIndex = 0;
	for(int i = 0; i < 100; i++)
		waitlist[i] = new Patient(-1, "");
}

PatientQueue::~PatientQueue()
{
	int currentSize = size();                
	cout << "We're CLOSING! Deleting patient queue!" << endl;
	for(int i = 1; i <= currentSize; i++)
	{
		cout << "Removing " << waitlist[i]->name << " from the queue." << endl;
		delete waitlist[i];
	}
}

int PatientQueue::size()
{
	int count = 0;
	if(isEmpty())      			
		return 0;
	else
	{
		for(int i = 1; i < 100; i++)
		{
			if(waitlist[i]->name != "")
				count++;
		}
		return count;
	}
}

bool PatientQueue::isEmpty()
{
	int count = 0;
	for(int i = 1; i  < 100; i++)
	{
		if(waitlist[i]->name == "")
			count++;
		else 
			return false;
	}
	if(count == 100)
		return true;
}

void PatientQueue::enqueue(int priority, std::string name)
{
	if(size() >= 99)									
		cout << "cannot enqueue, queue full." << endl;
	else
	{
		lastIndex++;
		int hole = lastIndex;
		waitlist[hole]->priority = priority;
		waitlist[hole]->name = name;
		for(;hole > 1 && priority < waitlist[hole/2]->priority; hole /= 2)
		{
			waitlist[hole]->priority = waitlist[hole/2]->priority;
			waitlist[hole]->name = waitlist[hole/2]->name;
		}
		waitlist[hole]->priority = priority;
		waitlist[hole]->name = name;
		cout << "Adding " << priority << " " << name << endl;
		printList();												
	}
}

Patient* PatientQueue::dequeue()
{
	if(isEmpty())								
	{
		cout << "cannot dequeue, queue empty." << endl;
		return waitlist[1];
	}
	else
	{
		Patient *tmp = new Patient(waitlist[1]->priority, waitlist[1]->name);
		cout << "Processing " << tmp->priority << " " << tmp->name << endl;
		waitlist[1]->priority = waitlist[lastIndex]->priority;
		waitlist[1]->name = waitlist[lastIndex]->name;
		waitlist[lastIndex]->name = "";
		waitlist[lastIndex]->priority = -1;
		delete waitlist[lastIndex];
		lastIndex--;
		int child;
		int hole = 1;
		Patient *temp = waitlist[hole];
		for(;hole*2 <= lastIndex; hole = child)
		{
			child = hole*2;
			if(child != lastIndex && waitlist[child+1]->priority < waitlist[child]->priority)
				child++;
			if(waitlist[child]->priority < temp->priority)
			{
				waitlist[hole]->priority = waitlist[child]->priority;
				waitlist[hole]->name = waitlist[child]->name;
			}
			else
				break;
		}
		waitlist[hole]->priority = temp->priority;
		waitlist[hole]->name = temp->name;
		return tmp;
	}
}

void PatientQueue::printList()
{
	if(isEmpty())						
	{
		cout << "===" << endl;
		cout << "Patients Waiting" << endl;
		cout << "No one waiting!" << endl;
		cout << "===" << endl;
		return;
	}
	else
	{
		int currentSize = size();			
		cout << "===" << endl;
		cout << "Patients Waiting" << endl;
		for(int i = 1; i <= currentSize; i++)
		{
			if(waitlist[i]->priority != -1 && waitlist[i]->priority != 0)
				cout << "[" << waitlist[i]->priority << "] " << waitlist[i]->name << endl;	
		}
		cout << "===" << endl;
	}
}

void PatientQueue::swap(int index1, int index2)
{
	Patient *temp = new Patient(waitlist[index1]->priority, waitlist[index2]->name);
	waitlist[index1]->priority = waitlist[index2]->priority;
	waitlist[index1]->name = waitlist[index2]->name;
	waitlist[index2]->priority = temp->priority;
	waitlist[index2]->name = temp->name;
	delete temp;
}
