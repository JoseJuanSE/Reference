#include<bits/stdc++.h>
using namespace std;

vector<int> topological_sort(vector<vector<int > > &G){
    vector<int>inde(G.size(),0);
    vector<int> ans;
    for(vector<int> i:G)
        for(int j:i)
            inde[j]++;
    queue<int> q;
    for(int i=0;i<G.size();i++)
        if(inde[i]==0)
            q.push(i);
    while(!q.empty()){
        int cnode=q.front();
        q.pop();
        ans.push_back(cnode);
        for(int i:G[cnode]){
            inde[i]--;
            if(inde[i]==0)
                q.push(i);
        }
    }
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