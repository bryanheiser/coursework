#ifndef EXAMPLEGRAPH_HPP
#define EXAMPLEGRAPH_HPP

#include<vector>
#include<iostream>

struct vertex;

struct adjVertex
{
    vertex *v;
    int weight;
};

struct vertex
{
    std::string name;
    std::vector<adjVertex> adj;
};

class ExampleGraph
{
    public:
        ExampleGraph();
        ~ExampleGraph();
        void addEdge(std::string v1, std::string v2, int weight);
        void addVertex(std::string name);
        void displayEdges();
    protected:
    private:
        std::vector<vertex> vertices;
};

#endif // EXAMPLEGRAPH_HPP
