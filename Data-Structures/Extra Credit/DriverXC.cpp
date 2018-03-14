/*
 * Bryan Heiser
 * 12/01/16
 * Social Network
 * I would like this to replace my lowest assignment score
 */

#include <iostream>
#include <fstream>  //allows istream/ostream
#include <string>
#include <cstdlib> 
#include <vector>
#include <array>
#include <queue>
#include <sstream>      // std::stringstream, std::stringbuf

#include "Graph.hpp"

using namespace std;

void readUsersIntoGraph(Graph &g, char* fileName);
void readFilesIntoGraph(Graph &g, char* directoryName);

int main(int argc, char*argv[])
{
	if (argc != 3)
	{
		cout << "Usage: " << argv[0] << " datasetDirectoryName idlistFilename" << endl;
		return -1;
	}

    // Create a graph
    Graph graph;

    // Read file into graph
	readUsersIntoGraph(graph, argv[2]);	// file is just a list of all userids
    readFilesIntoGraph(graph, argv[1]); // each userid's detailed info

	graph.assignSocialCircles();

	cout << "========================================\n";
	cout << "GRAPH CONNECTIONS ====================== " << endl;
	graph.displayEdges();

	graph.displayHobbies();

    return 0;
}

/* Function to read in all the ids in the social network.
  Does not have access to their name and hobbies, just a list of ids
  Reads in from the filename listed in command-line arguments
  @param network the graph data structure of the social network
  @param fileName is the file with a list of IDs in the social network
  */
void readUsersIntoGraph(Graph &g, char* fileName)
{
	cout << "Creating graph of social network ids from file: " << fileName << endl;
	ifstream in_stream;
	in_stream.open(fileName);
	if(!in_stream)
	{
		cout << "Could not open " << fileName << endl;
		return;
	}
	
	string id;
	while(getline(in_stream, id))
		g.addVertex(id);
	in_stream.close();
}

/*
 * reads all files (one at a time) from the dataset into the graph
 * @param directoryName name of the directory with all the dataset files
 * @param fileName name of file with a list of IDs needed to process in directory
 */
void readFilesIntoGraph(Graph &g, char* directoryName)
{
    cout << "Processing dataset: " << directoryName << " (" << g.vertices.size() << " files)" << endl;
	int numCollisions = 0;

	// loop through each vertex and read in its detailed information
	//	each vertex in the graph has the userid which you can create the filename to read
	// hint: create a string with directoryname/userid.txt to open each file
	
	for(int i = 0; i < g.vertices.size(); i++)
	{
		ifstream file_stream;
		string fileName = string(directoryName) + "/" + g.vertices[i].id + ".txt";
		file_stream.open(fileName);
		if(!file_stream)
		{
			cout << "Could not open " << fileName << endl;
			return;
		}
		
		string line, data;
		int count = 1;
		
		//loops thru file line by line
		while(getline(file_stream, line))
		{
			//adds contents of line into vertices
			stringstream ss(line);
			while(getline(ss, data, ','))
			{
				if(count == 1)
					g.vertices[i].id = data;
				else if(count == 2)
					g.vertices[i].name = data;
				else if(count == 3)
				{
					numCollisions += g.addUserToHobby(data, g.vertices[i].id);
				}
				else
					g.addEdge(g.vertices[i].id, data);
			}
			count++;
		}
		g.vertices[i].networkID = -1;
		file_stream.close();
	}


	// close files when done with each!!
	cout << "========================================\n";
	cout << " NUMBER OF COLLISIONS ON ADDING HOBBIES: " << numCollisions << endl;
}

