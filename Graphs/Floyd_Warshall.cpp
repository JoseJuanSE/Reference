#include<bits/stdc++.h>
using namespace std;
const int inf = int(1e7);
int graph[502][502];
int nex[502][502];

void negativeCicles(int v){
    for(int k=0;k<v;k++)
        for(int i=0;i<v;i++)
            for(int j=0;j<v;j++)
                if(graph[i][j]>graph[i][k]+graph[k][j]){
                    graph[i][j] = INT_MIN;
                    nex[i][j]=-1;
                }
}

void buildPath(int a, int b){
    int ini=a;
    if(graph[a][b]==inf)return;
    vector<int> path;
    while(a!=b){
        if(a==-1)return;
        path.push_back(a);
        a=nex[a][b];
    }
    if(nex[a][b]==-1)return;
    path.push_back(b);
    cout<<graph[ini][b]<<"\n";
    for(int i:path)
        cout<<i<<" ";
}

void Floyd_Warshall(int v){
    for(int k=0;k<v;k++)
        for(int i=0;i<v;i++)
            for(int j=0;j<v;j++){
                if(graph[i][j]>graph[i][k]+graph[k][j]){
                    graph[i][j] = graph[i][k]+graph[k][j];
                    nex[i][j]=nex[i][k];
                }
            }
    negativeCicles(v);
}

void clear(int v){
    for(int i=0;i<v;i++)
        for(int j=0;j<v;j++)
            if(i!=j)graph[i][j] = inf;
}

int main(){
    int v,e;
    cin>>v>>e;
    clear(v);
    while(e--){
        int x,y,w;
        cin>>x>>y>>w;
        graph[x][y]=w;
        nex[x][y]=y;
    }
    Floyd_Warshall(v);
    buildPath(1,5);
    return 0;
}
/*
CASE:
7 8
0 2 1
2 3 2
2 4 1 
4 5 1
3 6 0
6 1 10
5 1 2
1 0 10

ans:
13
1 0 2 4 5
*/