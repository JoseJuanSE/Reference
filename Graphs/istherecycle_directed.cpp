#include<bits/stdc++.h>
using namespace std;
bool dfs(int at,vector<int> &state,vector<vector<int> > &graph){
    state[at]=1;
    for(int i:graph[at]){
        if(state[i]==1)return true;
        if(state[i]==0 and dfs(i,state,graph))
                return true;
    }
    state[at]=2;
    return false;
}
bool HasCycle(vector<vector<int> > &graph){
    vector<int> state(graph.size(),0);
    for(int i=0;i<graph.size();i++)
        if(state[i]==0 and dfs(i,state,graph))
                return true;
    return false;
}
void read(){
    vector<vector<int> > graph;//diredted graph
    int v,e;
    cin>>v>>e;
    graph.resize(v+2);
    for(int i=0;i<e;i++){
        int x,y;
        cin>>x>>y;
        graph[x].push_back(y);
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