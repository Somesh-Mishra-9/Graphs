#include<iostream>
using namespace std;
#include <vector>


int main(){

int n,m;    // m is the no. of edges and n is the number of nodes.
cin>>m>>n;

//Matrix Representation of Graph
int adj[n+1][n+1];
for(int i=0;i<m;i++){

    int u,v;
    cin>>u>>v;
    adj[u][v]=1;
    adj[v][u]=1;
}

// List representaion of a graph

vector<int> adjc(n);

for(int i=0;i<m;i++){
  int x,y;
  cin>>x>>y;
  adjc[x]=y;
  adjc[y]=x;
}

return 0;

}