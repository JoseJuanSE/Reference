#include<bits/stdc++.h>
using namespace std;
//Union Find Disjoint Set
struct UFDS{
	vector<int>p,r,s;
	int ns;
	UFDS(int n){
		ns=n;
		n++;
		p.assign(n,0);
		r.assign(n,1);
		s.assign(n,1);
		for(int i=0;i<n;i++)p[i]=i;
	}
	int FindSet(int i){return p[i]==i?i:p[i]=FindSet(p[i]);}
	bool IsSameSet(int i,int j){return FindSet(i)==FindSet(j);}
	int NumSet(){return ns;}
	int Size(int n){return s[FindSet(n)];}
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
		s[x]+=s[y];//you can use s as r if you want
		return true;
	}
};
int main(){
	UFDS a(10);
	a.UnionSet(1,2);
	a.UnionSet(2,3);
	a.UnionSet(4,1);
	a.UnionSet(5,6);
	a.UnionSet(6,5);
	for(int i=1;i<=10;i++)
		cout<<"set where is "<<i<<" is "<<a.FindSet(i)<<endl;
	cout<<"num of sets "<<a.NumSet()<<endl;
	cout<<"set size of 1: "<<a.Size(1)<<endl;
	cout<<"set size of 5: "<<a.Size(5)<<endl;
	return 0;
}