#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> bfs(int V, vector<int> adj[])
{

    vector<int> bfsList;
    vector<int> visited(V, 0);
    queue<int> q;

    q.push(0);
    visited[0] = 1;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        bfsList.push_back(node);

        for (auto it : adj[node])
        {

            if (!visited[it])
            {
                q.push(it);
                visited[it] = 1;
            }
        }
    }

    return bfsList;
}

int main()
{

    vector<int> adj[] = {{1}, {0, 2, 3}, {0}, {1, 0}};
    int V = 4;

    vector<int> bfsList = bfs(V, adj);

    for (auto it : bfsList)
    {
        cout << it << " ";
    }
    

    return 0;
}