#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
//Binary Exponentiation
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
bool Is_Prime(long long x){
	if(x%2==0)return false;
	for(int i=3;i*i<=x;i+=2)
		if(x%i==0)return false;
	return true;
}
int main(){
	ull n,m;
	cin>>n>>m;
	cout<<b_e(n,m)<<endl;
	cout<<Is_Prime(n);
	return 0;
}
