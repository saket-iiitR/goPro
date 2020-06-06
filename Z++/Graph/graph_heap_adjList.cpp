#include <iostream>
#include <map>
#include <list>
#include <cstring>

using namespace std;

template<typename T>

class Graph
{
    // generic map data type and list of data type
    map<T, list<T>> adjList;
public:
    Graph() {}

    void addEdge(T u, T v, bool bidir = true)
    {
        adjList[u].push_back(v);
        if (bidir)
            adjList[v].push_back(u);
    }

    void printAdjList()
    {
        for (auto everyRow : adjList)
        {
            T key = everyRow.first;
            cout << key << "->";

            for (T element : everyRow.second)
                cout << element << ",";
            cout << endl;
        }
    }

};

int main()
{
    Graph <string> g;
    g.addEdge("Amritsar", "Delhi");
    g.addEdge("Amritsar", "Jaipur");
    g.addEdge("Delhi", "Siachen");
    g.addEdge("Delhi", "Banglore");
    g.addEdge("Delhi", "Agra");
    g.addEdge("Amritsar", "Siachen");

    g.printAdjList();
}