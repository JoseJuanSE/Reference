#include<bits/stdc++.h>
using namespace std;
//not working 
int Prim(int ori,vector<vector<pair<int,int> > >&graph){
    priority_queue<pair<int,int> >pq;
    pq.push(make_pair(0,ori));
    vector<bool> vis(graph.size()+1,false);
    int mini=0;
    while(!pq.empty()){
        pair<int,int> curr = pq.top();
        pq.pop();
        if(vis[curr.second])continue;
        vis[curr.second]=1;
        mini-=curr.first;
        for(pair<int,int> i:graph[curr.second]){
            pq.push(i);
        }
    }
    return mini;
}

void read(){
    int n;//number of vertex
    cin>>n;
    int m;
    cin>>m;//number of edges
    vector<vector<pair<int,int> > >graph;
    graph.resize(n+1);
    for(int i=0;i<m;i++){
        int a,b,w;
        cin>>a>>b>>w;
        graph[a].push_back(make_pair(-1*w,b));
    }
    int ori=1;
    for(int i=0;i<=n;i++){
        if(!graph[i].empty()){
            ori=i;
            break;
        }
    }
    int minimumweith = Prim(ori,graph);
    cout<<minimumweith<<endl;
}
int main(){
    read();
    return 0;
}
/*
6
7
1 2 3
1 3 2
2 4 3
3 4 2
3 5 1 
4 6 4
5 6 5
*/