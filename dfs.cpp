#include <iostream>
#include <vector>
using namespace std;

void dfs(int node, vector<int> adj[], vector<int> &list, int visited[])
{

    visited[node] = 1;
    list.push_back(node);

    for (auto it : adj[node])
    {

        if (!visited[it])
        {
            dfs(it, adj, list, visited);
        }
    }
}

vector<int> dfsOfGraph(int V, vector<int> adj[])
{

    vector<int> list;
    int visited[V] = {0};

    dfs(0, adj, list, visited);

    return list;
}

int main()
{

    int V = 5;
    vector<int> adj[] = {{2, 3, 1}, {0}, {0, 4}, {0}, {2}};

    vector<int> ans = dfsOfGraph(V, adj);

    for (auto it : ans)
    {
        cout << it << " ";
    }

    return 0;
}