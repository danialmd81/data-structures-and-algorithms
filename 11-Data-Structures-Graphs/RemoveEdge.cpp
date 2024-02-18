#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Graph
{
private:
    unordered_map<string, unordered_set<string>> adjList; // adjacency list

public:
    void printGraph()
    {
        unordered_map<string, unordered_set<string>>::iterator kvPair = adjList.begin();
        while (kvPair != adjList.end())
        {
            cout << kvPair->first << ": [ "; // print the vertex
            unordered_set<string>::iterator edge = kvPair->second.begin();
            while (edge != kvPair->second.end())
            {
                cout << edge->data() << " "; // print edges
                edge++;
            }
            cout << "]" << endl;
            kvPair++;
        }
    }

    bool addVertex(string vertex)
    {
        if (adjList.count(vertex) == 0)
        {
            adjList[vertex];
            return true;
        }
        return false;
    }
    bool addEdge(string vertex1, string vertex2)
    {
        if (adjList.count(vertex1) != 0 && adjList.count(vertex2) != 0)
        {
            adjList.at(vertex1).insert(vertex2);
            adjList.at(vertex2).insert(vertex1);
            return true;
        }
        return false;
    }
    bool removeEdge(string vertex1, string vertex2)
    {
        if (adjList.count(vertex1) != 0 && adjList.count(vertex2) != 0)
        {
            adjList.at(vertex1).erase(vertex2);
            adjList.at(vertex2).erase(vertex1);
            return true;
        }
        return false;
    }
};

int main()
{

    Graph *myGraph = new Graph();

    myGraph->addVertex("A");
    myGraph->addVertex("B");
    myGraph->addVertex("C");

    myGraph->addEdge("A", "B");
    myGraph->addEdge("A", "C");
    myGraph->addEdge("B", "C");

    cout << "Graph before removeEdge(): \n";
    myGraph->printGraph();

    myGraph->removeEdge("A", "B");

    cout << "\n\nGraph after removeEdge(): \n";
    myGraph->printGraph();
}
