#include<bits/stdc++.h>
using namespace std;

bool dfs(int i,int ant,vector<vector<int> > &graph,vector<bool> &vis){
    vis[i]=true;
    for(int next:graph[i]){
        if(vis[next] and next!=ant)return true;
        if(!vis[next])
            if(dfs(next,i,graph,vis))
                return true;
    }
    return false;
}
bool HasCycle(vector<vector<int> > &graph){
    vector<bool> vis(graph.size()+1,false);
    for(int i=0;i<graph.size();i++){
        if(!vis[i])
            if(dfs(i,-1,graph,vis))
                return true;
    }
    return false;
}
void read(){
    vector<vector<int> > graph;//undirected graph
    int v,e;
    cin>>v>>e;
    graph.resize(v+1);
    for(int i=0;i<e;i++){
        int x,y;
        cin>>x>>y;
        if(x!=y){
            graph[x].push_back(y);
            graph[y].push_back(x);
        }
    }
    if(HasCycle(graph))
        cout<<"this graph has a cycle"<<endl;
    else 
        cout<<"this graph doest have a cycle"<<endl;
}
int main(){
    read();
    return 0;
}