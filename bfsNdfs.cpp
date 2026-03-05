#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfs(int start, vector<int> graph[], int n){

    vector<int> vis(n,0);
    queue<int> q;

    q.push(start);
    vis[start]=1;

    while(!q.empty()){

        int node=q.front();
        q.pop();

        cout<<node<<" ";

        for(int x:graph[node]){
            if(!vis[x]){
                vis[x]=1;
                q.push(x);
            }
        }
    }
}

void dfs(int node, vector<int> graph[], vector<int>& vis){

    vis[node]=1;
    cout<<node<<" ";

    for(int x:graph[node]){
        if(!vis[x])
        dfs(x,graph,vis);
    }
}

int main(){

    int n=5;

    vector<int> graph[5];

    graph[0]={1,2};
    graph[1]={0,3};
    graph[2]={0,4};
    graph[3]={1};
    graph[4]={2};

    cout<<"BFS: ";
    bfs(0,graph,n);

    cout<<"\nDFS: ";

    vector<int> vis(n,0);
    dfs(0,graph,vis);
}