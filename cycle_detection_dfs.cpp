#include <bits/stdc++.h>
using namespace std;

// Function to perform DFS and detect a cycle in the graph
bool dfs(int node, int parent, vector<int> adj[], int visited[]){
    visited[node] = 1; // Mark the current node as visited

    // Traverse all adjacent nodes
    for(auto it: adj[node]){
        if(!visited[it]){
            // If the adjacent node is not visited, recursively call DFS
            if(dfs(it, node, adj, visited) == true) return true;
        }
        else{
            // If the adjacent node is visited and is not the parent, a cycle is detected
            if(it != parent) return true;
        }
    }

    return false; // No cycle detected
}

// Function to check if there is a cycle in the graph
bool isCycle(int v, vector<int> adj[]){
    int visited[v] = {0}; // Initialize visited array with 0

    // Check each vertex to ensure all disconnected parts of the graph are covered
    for(int i = 0; i < v; i++){
        if(!visited[i]){
            // If the component containing this vertex has a cycle, return true
            if(dfs(i, -1, adj, visited) == true) return true;
        }
    }

    return false; // No cycle found in any component
}


