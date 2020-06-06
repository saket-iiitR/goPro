#include <iostream>
#include <list>
#include <queue>
using namespace std;

class Graph {

public:
    int v;
    list <int> *adjList;
    Graph(int V)
    {
        v = V;
        adjList = new list <int> [v];
    }

    void addEdge(int x, int y, bool bidir = true)
    {
        adjList[x].push_back(y);
        if (bidir)
            adjList[y].push_back(x);
    }

    void printAdj(int v)
    {
        for (int i = 0; i < v; i++)
        {
            cout << i << "->";
            for (int next : adjList[i])
                cout << next << ",";
            cout << endl;
        }
    }

    void bfs(int src)
    {
        bool visited[v] = {0};
        cout << "BFS :";
        queue<int>q;
        q.push(src);
        visited[src] = true;

        int dist[v] = {0};
        dist[src] = 0;

        while (!q.empty())
        {
            int node = q.front();
            cout << "->" << node;

            q.pop();
            for (int neighbor : adjList[node])
            {
                if (!visited[neighbor])
                {
                    visited[neighbor] = true;
                    q.push(neighbor);
                    dist[neighbor] = dist[node] + 1;
                }
            }
        }
        cout << endl << "Di: ";
        for (int distance : dist)
            cout << distance << " ";

    }


};

using namespace std;
int main()
{
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(0, 2);
    g.addEdge(2, 3);
    g.addEdge(1, 3);


    g.printAdj(4);
    cout << endl;
    g.bfs(0);
    return 0;
}
