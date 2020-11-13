#include<bits/stdc++.h>

using namespace std;
//no detecta ciclos negativos de forma correcta
struct edge{
    int x,y,w;
    edge(int a,int b,int g):x(a),y(b),w(g){};
};

vector<int> BF(int so,int v,vector<edge> &graph){
    vector<int> d(v,INT_MAX);
    d[so]=0;
    for(int i=0;i<v-1;i++){
        for(edge j:graph){
            if(d[j.x] < INT_MAX)
                d[j.y] = min(d[j.y],d[j.x]+j.w);
        }
    }
    //mark negative cycle
    for(int i=0;i<v-1;i++){
        for(edge j:graph){
            if(d[j.x] < INT_MAX and d[j.x]+j.w<d[j.y])
                d[j.y] = INT_MIN;
        }
    }
    return d;
}

void read(){
    int n;//number of vertex
    cin>>n;
    int m;//number of edges
    cin>>m;
    vector<edge>graph;
    for(int i=0;i<m;i++){
        int a,b,w;
        cin>>a>>b>>w;
        graph.push_back(edge(a,b,w));
    }
    vector<int> d = BF(0,n,graph);
    for(int i:d)
        cout<<i<<" ";
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

output:
0 3 2 4 3 8

-------
9 10
0 1 1
1 2 1
2 4 1
4 3 -3
3 2 1
1 5 4
1 6 4
5 6 5
6 7 4
5 7 3

0 1 -inf -inf -inf 5 5 8 inf
*/
