#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
//binary exponentiation
ull b_e(ull n,ull k){
	ull x=1;
	while(k){
		if(k&1)
			x*=n;
		n*=n;
		k>>=1;
	}
	return x;
}
int main(){
	ull n,m;
	cin>>n>>m;
	cout<<b_e(n,m);
	return 0;
}
