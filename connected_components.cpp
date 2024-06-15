
#include<iostream>
#include<vector>
using namespace std;

void dfs(int node, vector<int>&visited, vector<int>adjList[]){
      
      visited[node]=1;
      
      for(auto it: adjList[node]){
          if(!visited[it]){
              dfs(it, visited, adjList);
          }
      }
  }

    int ConnectedComponents(vector<vector<int>> adj, int V) {
        
        vector<int> adjList[V];
        
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(adj[i][j]==1 && i!=j ){
                    adjList[i].push_back(j);
                }
            }
        }
        
        
        vector <int> visited(V,0);
        int count=0;
        
        for(int i=0;i<V;i++){
            if(!visited[i]){
                count++;
                dfs(i,visited,adjList);
            }
        }
        
        return count;
    }

    int main(){

    return 0;

    }