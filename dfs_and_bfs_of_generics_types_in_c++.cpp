//breath first search (BFS)
#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Graph
{
    map<T, list<T>> adjList;

public:
    Graph()
    {
    }
    void addEdge(T u, T v, bool bidir = false)
    {
        adjList[u].push_back(v);
        if (bidir)
        {
            adjList[v].push_back(u);
        }
    }

    void bfs(T src)
    {
        // int count= adjList.size();
        map<T, bool> visited;

        queue<T> q;
        q.push(src);
        visited[src] = true;

        while (!q.empty())
        {
            T node = q.front();
            cout << node << " ";
            q.pop();

            // neighbour of current node
            for (T neighbour : adjList[node])
            {
                if (!visited[neighbour])
                {
                    q.push(neighbour);
                    visited[neighbour] = true;
                }
            }
        }
        cout << endl
             << endl;
    }

private:
    void dfsHelper(T node, map<T, bool> &visited)
    {
        // whenever to come to a node marke it visited
        visited[node] = true;
        cout << node << " ";
        //try to find out a node which is neighbour of
        //current node and not yet visited
        for (T entry : adjList[node])
        {
            if (!visited[entry])
            {
                dfsHelper(entry, visited);
            }
        }
    }

public:
    void dfs(T src)
    {
        map<T, bool> visited;
        dfsHelper(src, visited);
        //for others nodes which are not been visited yet
        for (auto element : adjList)
        {
            if (visited.find(element.first) == visited.end())
                dfsHelper(element.first, visited);
        }

        cout << endl;
    }
    void print()
    {
        for (auto obj : adjList)
        {
            cout << obj.first << "->";
            for (auto entry : obj.second)
            {
                cout << entry << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    Graph<string> g;
    g.addEdge("putin", "trump", false);
    g.addEdge("putin", "modi", false);
    g.addEdge("putin", "pope", false);
    g.addEdge("modi", "trump");
    g.addEdge("prabhu", "modi", false);
    g.addEdge("yogi", "modi");
    g.addEdge("yogi", "prabhu", false);
    g.bfs("putin");
    //	g.print();
    Graph<int> g2;
    g2.addEdge(0, 1);
    g2.addEdge(1, 2);
    g2.addEdge(0, 4);
    g2.addEdge(2, 4);
    g2.addEdge(2, 3);
    g2.addEdge(3, 5);
    g2.addEdge(3, 4);
    g2.bfs(0);
    cout << endl;
    g2.dfs(3);
    Graph<char> g3;
    g3.addEdge('A', 'B', true);
    g3.addEdge('B', 'C', true);
    g3.addEdge('B', 'H', true);
    g3.addEdge('C', 'D', true);
    g3.addEdge('C', 'E', true);
    g3.addEdge('E', 'F', true);
    g3.addEdge('E', 'H', true);
    g3.addEdge('E', 'G', true);
    g3.dfs('A');
    Graph<int> g4;
    g4.addEdge(1, 2);
    g4.addEdge(4, 1);
    g4.addEdge(4, 5);
    g4.addEdge(5, 6);
    g4.addEdge(6, 4);
    g4.addEdge(7, 8);
    g4.addEdge(8, 9);
    g4.addEdge(9, 7);
    g4.dfs(1);
    g4.dfs(4);
    Graph<int> g5;
    g5.addEdge(1, 3);
    g5.addEdge(1, 2);
    g5.addEdge(2, 3);
    g5.dfs(1);

    return 0;
}
