#include <bits/stdc++.h>
using namespace std;

class Graph {
public:
    int vertices;
    list<int> *adjList;

    Graph(int v) {
        vertices = v;
        adjList = new list <int> [vertices];
    }

    void addEdge(int u, int v, bool bidir = true) {
        adjList[u].push_back(v);
        if (bidir)
            adjList[v].push_back(u);
    }

    void printAdj() {
        for (int i = 0; i < vertices; i++)
        {
            cout << i << "->";
            for (int ele : adjList[i])
                cout << ele << ",";
            cout << endl;
        }
    }

    void BFS(int src) {
        cout << "BFS::";
        queue<int> q;
        bool visited[vertices] = {0};
        visited[src] = true;
        q.push(src);

        while (!q.empty())
        {
            int node = q.front();
            cout << node << "->";
            q.pop();

            for (int nbr : adjList[node])
            {
                if (!visited[nbr])
                {
                    q.push(nbr);
                    visited[nbr] = true;
                }
            }
        }
        cout << endl;

    }

    void dfs(int src, bool *visited) {
        cout << src << "->";
        visited[src] = true;
        for (int nbr : adjList[src])
            if (!visited[nbr])
                dfs(nbr, visited);
    }

    void DFS(int src) {
        cout << "DFS::";
        bool visited[vertices] = {0};
        dfs(src, visited);
        cout << endl;
    }

    bool cycle(int src, bool *visited, int parent) {
        visited[src] = true;
        list<int>::iterator i;

        for (i = adjList[src].begin(); i != adjList[src].end(); i++)
        {
            if (!visited[*i])
            {
                if (cycle(*i, visited, src))
                    return true;
            }
            else if (*i != parent)
                return true;
        }
        return false;
    }

    bool isCyclic() {
        cout << "Checking if cyclic ? ::" << endl;
        bool visited[vertices] = {0};
        for (int i = 0; i < vertices; i++)
            if (!visited[i])
                if (cycle(i, visited, -1))
                    return true;

        return false;
    }

    bool cycle_d(bool *visited, bool *call_stack, int src) {
        if (!visited[src])
        {
            visited[src] = true;
            call_stack[src] = true;

            list<int>::iterator i;
            for (i = adjList[src].begin(); i != adjList[src].end(); i++)
            {
                if (!visited[*i] && cycle_d(visited, call_stack, *i))
                    return true;
                else if (call_stack[*i])
                    return true;
            }
        }
        call_stack[src] = false;
        return false;
    }

    bool isCyclic_d() {
        cout << "Checking if cyclic in directed graph...::" << endl;
        bool visited[vertices] = {0};
        bool call_stack[vertices] = {0};

        for (int i = 0; i < vertices; i++)
            if (cycle_d(visited, call_stack, i))
                return true;
        return false;
    }

    void topological_utility(bool *visited, int src, stack<int> &st) {
        visited[src] = true;

        for (auto itr = adjList[src].begin(); itr != adjList[src].end(); itr++)
            if (!visited[*itr])
                topological_utility(visited, *itr, st);
        st.push(src);
    }

    void topoSort() {

        bool visited[vertices] = {0};
        stack<int> st;

        for (int i = 0; i < vertices; i++)
            if (!visited[i])
                topological_utility(visited, i, st);
        cout << "Topological Sort :" << endl;
        while (!st.empty())
        {
            cout << st.top() << "->";
            st.pop();
        }
    }
};

int main()
{
    Graph g(6);
    g.addEdge(0, 1, false);
    g.addEdge(2, 1, false);
    g.addEdge(2, 3, false);
    g.addEdge(3, 4, false);
    g.addEdge(4, 5, false);
    // g.addEdge(5, 3);
    g.printAdj();
    g.BFS(0);
    g.DFS(0);
    // g.isCyclic() ? cout << "Graph contains cycle\n" :
    //                     cout << "Graph doesn't contain cycle\n";

    g.isCyclic_d() ? cout << "Graph contains cycle\n" :
                          cout << "Graph doesn't contain cycle\n";
    cout << endl;
    g.topoSort();

    return 0;
}
