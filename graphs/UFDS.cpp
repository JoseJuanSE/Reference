#include<bits/stdc++.h>
using namespace std;
//Union Find Disjoint Set
struct UFDS{
	vector<int>p,r,s;
	int ns;
	UFDS(int n){
		n++;
		ns=n-1;
		p.assign(n,0);
		r.assign(n,0);
		s.assign(n,1);
		for(int i=0;i<n;i++)p[i]=i;
	}
	int FindSet(int i){return p[i]==i?i:FindSet(p[i]);}
	bool IsSameSet(int i,int j){return FindSet(i)==FindSet(j);}
	int Size(int i){return s[FindSet(i)];}
	int NumSet(){return ns;}
	void UnionSet(int i,int j){
		int x=FindSet(i),y=FindSet(j);
		if(!IsSameSet(x,y)){
			ns--;
			if(r[x]>r[y]){
				p[y]=x;
				s[x]+=s[y];
			}
			else{
				p[x]=y;
				s[y]+=s[x];
				if(r[x]==r[y])r[y]++;
			}
		}
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
	cout<<"size of set where is 1 is: "<<a.Size(1)<<endl;
	cout<<"size of set where is 4 is: "<<a.Size(4)<<endl;
	cout<<"size of set where is 6 is: "<<a.Size(6)<<endl;
	cout<<"size of set where is 9 is: "<<a.Size(9)<<endl;
	cout<<"num of sets"<<a.NumSet()<<endl;
	return 0;
}

