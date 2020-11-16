#include<bits/stdc++.h>
#define INF 1e9
using namespace std;

struct edge{
    int x,y,w;
    edge(int a,int b,int g):x(a),y(b),w(g){};
};

vector<int> BF(int so,int v,vector<edge> &graph){
    vector<int> d(v,INF);
    d[so]=0;
    for(int i=0;i<v-1;i++){
        bool any = true;
        for(edge j:graph){
            if(d[j.x] < INF){
                if(d[j.y] > d[j.x]+j.w){
                    d[j.y] = d[j.x]+j.w;
                    any = false;
                }
            }
        }
        if(any)break;
    }
    //mark negative cycle
    for(int i=0;i<v-1;i++){
        for(edge j:graph){
            if(d[j.x] < INF and d[j.x]+j.w<d[j.y])
                d[j.y] = -1 * INF;
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
0 1 3
0 2 2
1 3 3
2 3 2
2 4 1 
3 5 4
4 5 5

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
