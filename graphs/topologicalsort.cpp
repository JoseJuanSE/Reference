#include<bits/stdc++.h>
using namespace std;

void topo(int at,vector<bool> &vis,vector<int> &ans,vector<vector<int> > &G){
    vis[at]=1;
    for(int i:G[at])
        if(!vis[i])
            topo(i,vis,ans,G);
    ans.push_back(at);
}
vector<int> topological_sort(vector<vector<int > > &G){
    vector<bool>vis(G.size(),0);
    vector<int> ans;
    for(int i=0;i<G.size();i++)
        if(!vis[i])
            topo(i,vis,ans,G);
    reverse(ans.begin(),ans.end());
    return ans;   
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int> > graph(n);
    while(m--){
        int x,y;
        cin>>x>>y;
        graph[x].push_back(y);
    }
    vector<int> ans = topological_sort(graph);
    for(int i:ans)
        cout<<i<<" ";
    cout<<endl;
    return 0;
}
/*
6 6

5 0
2 3
5 2
3 1
4 0
4 1
*/