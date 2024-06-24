#include <bits/stdc++.h>
using namespace std;

// Function to detect a cycle starting from a given node using BFS
bool detect(int node, vector<int> adj[], int visited[]){
    visited[node] = 1; // Mark the current node as visited
    queue<pair<int, int>> q; // Queue to store (node, parent) pairs
    q.push({node, -1}); // Initialize the queue with the starting node and no parent

    while(!q.empty()){
        int currNode = q.front().first; // Current node
        int parentNode = q.front().second; // Parent of the current node
        q.pop(); // Remove the front element from the queue

        // Traverse all adjacent nodes
        for(auto it: adj[currNode]){
            if(!visited[it]){
                visited[it] = 1; // Mark the adjacent node as visited
                q.push({it, currNode}); // Push the adjacent node with current node as its parent
            }
            else{
                // If an adjacent node is visited and is not the parent, a cycle is detected
                if(it != parentNode) return true;
            }
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
            if(detect(i, adj, visited)) return true;
        }
    }

    return false; // No cycle found in any component
}
