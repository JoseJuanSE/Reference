#include<bits/stdc++.h>

#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define pub push_back

using namespace std;

typedef vector<int> vi;
typedef vector<vector<int> > vvi;

vvi graph;

vi low,dt;
vector<bool> onstack;
stack<int> pila;
vvi sc;
int id;

void SCC(int p){
    pila.push(p);
    onstack[p] = true;
    dt[p] = low[p] = id++;
    for(int i:graph[p]){
        if(dt[i]==-1)SCC(i);
        if(onstack[i])low[p] = min(low[p],low[i]);
    }
    if(dt[p]==low[p]){
        vi temp;
        while(!pila.empty()){
            int node = pila.top();
            pila.pop();
            onstack[node] = false;
            low[node] = dt[p];
            temp.pub(node);
            if(node == p)break;
        }
        sc.pub(temp);
    }
}
void read(){
    int n,m;
    cin>>n>>m;
    graph.resize(n+2);
    low.assign(n+2,0);
    dt.assign(n+2,-1);
    onstack.assign(n+2,0);
    while(m--){
        int x,y;
        cin>>x>>y;
        graph[x].push_back(y);
    }
    id = 0;
    forr(i,1,n){
        if(dt[i]==-1)
            SCC(i); 
    }
    int j=1;
    for(auto i:sc){
        cout<<"SCC:"<<j++<<endl;
        for(int k:i)
            cout<<k<<" ";
        cout<<endl;
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