#include<bits/stdc++.h>

#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define pub push_back

using namespace std;

typedef vector<int> vi;
typedef vector<vector<int> > vvi;

void SCC(int p,int &id,stack<int> &pila,vvi &sc,vi &low,vi &dt,vector<bool> &onstack,vvi &graph){
    pila.push(p);
    onstack[p] = true;
    dt[p] = low[p] = id++;
    for(int i:graph[p]){
        if(dt[i]==-1)SCC(i,id,pila,sc,low,dt,onstack,graph);
        if(onstack[i])low[p] = min(low[p],low[i]);
    }
    if(dt[p]==low[p]){
        vi temp;
        while(!pila.empty()){
            int node = pila.top();
            pila.pop();
            onstack[node] = false;
            temp.pub(node);
            if(node == p)break;
        }
        sc.pub(temp);
    }
}

vvi SCCinit(vvi &graph){
    int n = graph.size();
    vi low(n,0),dt(n,-1);
    vector<bool> onstack(n,false);
    stack<int> pila;
    vvi sc;
    int id = 0;

    forr(i,1,n-2)
        if(dt[i]==-1)
            SCC(i,id,pila,sc,low,dt,onstack,graph);

    return sc;
}

void read(){
    int n,m;
    cin>>n>>m;
    vvi graph(n+2);
    
    while(m--){
        int x,y;
        cin>>x>>y;
        graph[x].push_back(y);
    }

    vvi sc = SCCinit(graph);

    int j=1;
    for(auto i:sc){
        cout<<"\nSCC: "<<j++<<endl;
        for(int k:i)
            cout<<k<<" ";
    }
}

int main(){
    read();
    return 0;
}
/*
6 7
0 1
1 2
2 3
3 4
4 5
5 1
4 2
*/
/*
9 17
1 2
2 1
2 3
1 5
5 1
5 3
4 3
3 4
6 4
6 2
6 7
7 4
7 8
8 6
9 7
9 8
9 9
*/