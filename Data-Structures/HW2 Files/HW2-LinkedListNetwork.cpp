// ==========================================
// File: student starter code
// Author: Matt Bubernak
// Date: 1/29/2015
// Modified: Fall 2016 E.S.Boese
// Description: Linked List Fun
// 
// Bryan Heiser
// HW 2
// Boese
// ==========================================

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

struct city
{
    string 	name; 			// name of the city
    city 	*next; 			// pointer to the next city
	int 	numberMessages;	// how many messages passed through this city
    string 	message; 		// message we are sending accross
};

city* addCity(city *head, city *previous, string cityName );
city* deleteCity(city *head, string cityName);
city* deleteEntireNetwork(city *head);
city* searchNetwork(city *head, string cityName);
city* loadDefaultSetup(city *head);
void transmitMsg(city *head, string receiver, string filename);
void printPath(city *head);
void displayMenu();
city* handleUserInput(city *head);

/* Do NOT modify main function */
int main(int argc, char* argv[])
{
    // pointer to the head of our network of cities
    city *head = NULL;

	head = handleUserInput(head);
	printPath(head);
	head = deleteEntireNetwork(head);
	if (head == NULL)
		cout << "Path cleaned" << endl;
	else
		printPath(head);

	cout << "Goodbye!" << endl;
    return 0;
}

/*
 * Purpose: handle the interaction with the user
 * @param head the start of the linked list
 * @return the start of the linked list
 * Do NOT modify
 */
city* handleUserInput(city *head)
{
    bool quit = false;
    string s_input;
    int input;

    // loop until the user quits
    while (!quit)
    {
        displayMenu();

		// read in input, assuming a number comes in
        getline(cin, s_input);
		input = stoi(s_input);

        switch (input)
        {
            // print all nodes
            case 1: 	//rebuild network
                head = loadDefaultSetup(head);
                printPath(head);
                break;

            case 2:		// print path
                printPath(head);
                break;

            case 3: //message is read in from file
			  {
        		string cityReceiver;
				cout << "Enter name of the city to receive the message: " << endl;
				getline(cin, cityReceiver);

				cout << "Enter the message to send: " << endl;
				string message;
				getline(cin, message);

                transmitMsg(head, cityReceiver, message);
			  }
                break;

            case 4:
			  {
        		string newCityName;
        		string prevCityName;
                cout << "Enter a new city name: " << endl;
                getline(cin, newCityName);

                cout << "Enter the previous city name (or First): " << endl;
                getline(cin, prevCityName);

                // find the node containing prevCity
    			city *tmp = NULL;
                if(prevCityName !="First")
                    tmp = searchNetwork(head, prevCityName);
                // add the new node
                head = addCity(head, tmp, newCityName);
                printPath(head);
			  }
                break;

            case 5: 	// delete city
			  {
        		string city;
                cout << "Enter a city name: " << endl;
                getline(cin, city);
                head = deleteCity(head, city);
                printPath(head);
			  }
                break;

            case 6: 	// delete network
                head = deleteEntireNetwork(head);
                break;

            case 7: 	// quit
                quit = true;
				cout << "Quitting... cleaning up path: " << endl;
                break;

            default: 	// invalid input
                cout << "Invalid Input" << endl;
                break;
        }
    }
	return head;
}

/* 
 * Purpose: Add a new city to the network 
 *   between the city *previous and the city that follows it in the network. 
 * @param head pointer to start of the list
 * @param previous name of the city that comes before the new city
 * @param cityName name of the new city
 * @return pointer to first node in list
 */
city* addCity(city *head, city *previous, string cityName )
{
	city *newCity = new city;
	if(previous == NULL)    //checks if city is being added to start of list
	{
		newCity->name = cityName;
		newCity->next = NULL;
		head = newCity;
		cout << "new: " << cityName << endl;
	}
	else if(previous->next == NULL)   //checks if city is being added to end of list
	{
		newCity->next = NULL;
		newCity->name = cityName;
		city *temp;                    
		temp = head;
		while(temp->next != NULL)     //searches for the last item in the list
		{
			temp = temp->next;
		}
		temp->next = newCity;
		previous->next = temp->next;
		cout << "prev: " << previous->name << "  new: " << cityName << endl;
		
	}
	else
	{
		newCity->name = cityName;
		city *temp;
		temp = head;
		while(temp->next != previous)
		{
			temp = temp->next;						//finds the previous city
		}
		temp = temp->next;
		newCity->next = temp->next;
		previous->next = newCity;
		cout << "prev: " << previous->name << "  new: " << cityName << endl;
	}

    return head;
}


/*
 * Purpose: Search the network for the specified city and return a pointer to that node
 * @param ptr head of the list
 * @param cityName name of the city to look for in network
 * @return pointer to node of cityName, or NULL if not found
 * @see addCity, deleteCity
 */
city *searchNetwork(city *ptr, string cityName)
{
    if(ptr == NULL)                               //checks if list is empty
    {
		cout << "list empty" << endl;
		return ptr;
	}
    while(ptr != NULL)
    {
		if(ptr->name != cityName)              //goes thru list checking names
		{
			ptr = ptr->next;
		}
		else
		{
			return ptr;
		}
	}
    return ptr;
}

/*
 * Purpose: deletes all cities in the network starting at the head city. 
 * @param ptr head of list
 * @return NULL as the list is empty
 */
city* deleteEntireNetwork(city *ptr)
{
	city *temp = new city;
	while(ptr != NULL)                                      //goes thru list
	{
		cout << "deleting: " << ptr->name << endl;
		temp = ptr;
		ptr = ptr->next;
		delete temp;											//deletes each pointer individually	
	}

	cout << "Deleted network" << endl;
    // return head, which should be NULL
    return ptr;
}

/* sends messages from file */
void transmitMsg(city *head, string receiver, string message)
{
    if(head == NULL)
	{
        cout << "Empty list" << endl;
        return;
    }
	
	city *sender;
	sender = head;
	int check = 0;
	while(sender != NULL)       //goes thru list until it finds name of receiver
	{
		if(sender->name != receiver && check == 0)
		{
			sender->numberMessages += 1;
		}
		else if(sender->name == receiver)                      //counts messages passed until receiving city
		{
			sender->numberMessages += 1;
			check = 1;
		}
		sender->message = message;
    	cout << sender->name << " [# messages passed: " << sender->numberMessages << "] received: " << sender->message << endl;
    	sender = sender->next;
	}
}


/* 
 * Purpose: delete the city in the network with the specified name. 
 * @param head first node in list
 * @param cityName name of the city to delete in the network
 * @return head node of list 
 */
city* deleteCity(city *head, string cityName)
{
	// if the city dosn't exist, nothing we can do.
	// 		use this output statement
	if(head == NULL)
	{
        cout << "City does not exist." << endl;
        return head;
	}
	
	int check = 0;
	city *temp = new city;
	city *prev = new city;
	temp = head;
	while(temp != NULL && temp->name != cityName)        //goes thru list to find the city to delete
	{
		prev = temp;
		temp = temp->next;
		check = 1;
	}
	if(check == 0)
	{	
		prev = temp;
		temp = temp->next;
		prev = temp->next;
	}
	else
	{
		prev->next = temp->next;
		temp->next = NULL;
	}
	delete temp;
	
    return head;
}


/*
 * Purpose: prints the current list nicely
 * @param ptr head of list
 */
void printPath(city *ptr)
{
    cout << "== CURRENT PATH ==" << endl;

    // If the head is NULL
    if (ptr == NULL)
    {
        cout << "nothing in path" << endl;
        cout << "==================" << endl;
        return;
	}
	
	while(ptr != NULL)
	{
		cout << ptr->name << " -> ";           //goes thru list and prints each city
		ptr = ptr->next;
	}
	cout << "NULL" << endl;
    cout << "==================" << endl;
}

/* 
 * Purpose: populates the network with the predetermined cities 
 * @param head start of list
 * @return head of list
 */
city* loadDefaultSetup(city *head)
{
    head = deleteEntireNetwork(head);
    head = addCity(head,NULL,"Los Angeles");
    
    return head;
}

/*
 * Purpose; displays a menu with options
 */
void displayMenu()
{
	cout << "Select a numerical option:" << endl;
    cout << "======Main Menu=====" << endl;
    cout << "1. Build Network" << endl;
    cout << "2. Print Network Path" << endl;
    cout << "3. Transmit Message" << endl;
    cout << "4. Add City" << endl;
    cout << "5. Delete City" << endl;
    cout << "6. Clear Network" << endl;
    cout << "7. Quit" << endl;
}

