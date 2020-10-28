#include<bits/stdc++.h>

using namespace std;

struct UFDS{
	vector<int>p,r;
	int ns;
	UFDS(int n){
		ns=n;
		n++;
		p.assign(n,0);
		r.assign(n,1);
		for(int i=0;i<n;i++)p[i]=i;
	}
	int FindSet(int i){return p[i]==i?i:p[i]=FindSet(p[i]);}
	bool IsSameSet(int i,int j){return FindSet(i)==FindSet(j);}
	int NumSet(){return ns;}
	bool UnionSet(int i,int j){
		int x=FindSet(i),y=FindSet(j);
		if(x==y)
            return false;
		ns--;
		if(r[x]<r[y])
			swap(x,y);
		if(r[x]==r[y])
			r[x]++;
		p[y]=x;
		return true;
	}
};
struct edge{
    int x,y,w;
    edge(int a,int b,int g):x(a),y(b),w(g){};
};
bool cmp(edge &a,edge &b){return a.w<b.w;}

int kruskal(int &n,vector<edge> &arr){
    UFDS uf(n);
    sort(begin(arr),end(arr),cmp);
    int mini=0;
    for(edge e:arr){
        if(!uf.IsSameSet(e.y,e.x)){
            mini+=e.w;
            uf.UnionSet(e.y,e.x);
        }
        if(uf.NumSet()==2)break;
    }
    return mini;
}

void read(){
    int n;//number of vertex
    cin>>n;
    int m;
    cin>>m;//number of edges
    vector<edge>arr;
    for(int i=0;i<m;i++){
        int a,b,w;
        cin>>a>>b>>w;
        arr.push_back(edge(a,b,w));
    }
    int minimumweith = kruskal(n,arr);
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