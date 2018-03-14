/*
 * Bryan Heiser
 * 12/01/16
 * Social Network
 * I would like this to replace my lowest assignment score
 */

#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
#include <algorithm>

#include "Graph.hpp"

using namespace std;

Graph::Graph() 
{ 
	for(int i = 0; i < HASHMAP_SIZE; i++)
		hobbies[i] = NULL;
}

Graph::~Graph() 
{ 
	// Free hash table
	for(int i = 0; i < HASHMAP_SIZE; i++)    
		delete hobbies[i];
}

void Graph::addEdge(string v1, string v2)
{
	if(v1 == v2) 	// don't add self 
		return;

	vertex *vertex1 = findVertex(v1);
	vertex *vertex2 = findVertex(v2);

	// make sure not already in the list
	bool found = false;
	for(int i = 0; i < vertex1->friends.size(); i++)
	{
		if(vertex1->friends[i].v == vertex2)
			found = true;
	}

	if(!found)	// add edge to both vertices
	{		
		adjVertex temp;
		temp.v = vertex1;
		adjVertex temp1;
		temp1.v = vertex2;
		vertex1->friends.push_back(temp1);   //can only push type adjVertex
		vertex2->friends.push_back(temp);
    }
}

/* add the person to the graph */
void Graph::addVertex(string id)
{
	//loop thru vertices to make sure vertex doesnt already exist
	for(int i = 0; i < vertices.size(); i++) 
	{
		if(vertices[i].id == id)
		{
			cout << "This person has already been added" << endl;
			return;
		}
	} 
	
	//add new vertex
	vertex newPerson;
	newPerson.id = id;
	vertices.push_back(newPerson);
}

void Graph::displayEdges()
{
	//loop thru vertices
	for(int i = 0; i < vertices.size(); i++)
	{
        cout << vertices[i].networkID << ": [" << vertices[i].id << "] " << vertices[i].name << "-->";
        for(int j = 0; j < vertices[i].friends.size(); j++)
        {
			if(j != vertices[i].friends.size()-1) 
				cout << vertices[i].friends[j].v->name << "***";   //menu aesthetic
			else
				cout << vertices[i].friends[j].v->name;
		}
		cout << endl;
	}
}

int Graph::addUserToHobby(std::string hobby, std::string id)
{
	//cout << "Adding to hobby: " << hobby << " user: " << id << endl;
	vertex *user = findVertex(id);
	// initial key is based on the first 2 characters of the hobby name
	int key = (hobby[0] + hobby[1]) % HASHMAP_SIZE;
	int collisions = 0;
	
	bool added = false;
	
	while(!added)
	{
		if(hobbies[key] == NULL) //adds hobby if it hasnt been added
		{
			hobbylist *newhobby = new hobbylist;
			hobbies[key] = newhobby;
			hobbies[key]->hobby = hobby;
			hobbies[key]->list.push_back(user);
			added = true;
		}
		else
		{
			if(hobbies[key]->hobby == hobby) //adds user to correct hobby
			{
				for(int i = 0; i < hobbies[key]->list.size(); i++)
				{
					if(hobbies[key]->list[i]->id == id)
					{
						added = true;
					}
					else if(i == hobbies[key]->list.size()-1)
					{
						hobbies[key]->list.push_back(user);
						added = true;
					}
				}
			}
			else //handles collisions
			{
				collisions++;
				key++;
				if(key >= HASHMAP_SIZE)
					key = key % HASHMAP_SIZE;
			}
		}
	}

	return collisions;
}

void Graph::displayHobbies()
{
	cout << "========================================\n";
	cout << "DISPLAYING HOBBY INTERESTS =============" << endl;
	for( int i=0; i<HASHMAP_SIZE; i++)
	{
		if(hobbies[i] != NULL)
		{
			cout << hobbies[i]->hobby << ": ";
			for(int j = 0; j < hobbies[i]->list.size(); j++)
			{
				if(j == hobbies[i]->list.size()-1)
					cout << hobbies[i]->list[j]->name;
				else
					cout << hobbies[i]->list[j]->name << ", ";
			}
			cout << endl;
		}
	}
}

/* return pointer to the correct vertex (person)  */
vertex * Graph::findVertex(std::string id)
{
	for(int i = 0; i < vertices.size(); i++)
	{
		if(vertices[i].id == id)
		{
			vertex *v = &vertices[i];
			return v;
		}
	}
	return NULL;
}

void Graph::assignSocialCircles()
{
	int socialNetwork = 1;
	
	//loop thru vertices and assign social networks to all users
	for(int i = 0; i < vertices.size(); i++)
	{
		if(vertices[i].networkID == -1)
		{
			BFTraversalLabel(vertices[i].id, socialNetwork);
			socialNetwork++;
		}
	}
}

void Graph::BFTraversalLabel(std::string userid, int groupID)
{
	queue<vertex*> q;
	
	//mark all as unvisited
	for(int i = 0; i < vertices.size(); i++)
	{
		vertices[i].visited = false;
	}
	
	//find starting user
	for(int i = 0; i < vertices.size(); i++)
	{
		if(vertices[i].id == userid)
		{
			vertices[i].visited = true;
			vertices[i].networkID = groupID;
			q.push(&vertices[i]);
		}
	}
	
	//loop thru queue and assign all to same social network
	while(!q.empty())
	{
		vertex *user = q.front();
		q.pop();
		
		for(int i = 0; i < user->friends.size(); i++)
		{
			if(!user->friends[i].v->visited)
			{
				user->friends[i].v->visited = true;
				user->friends[i].v->networkID = groupID;
				q.push(user->friends[i].v);
			}
		}
	}
}

