#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;
ll b_e(ll a,ll e,ll m){
    ll ans = 1;
    while(e){
        if(e&1) 
            ans = ((ans%m)*(a%m))%m;
        a*=a;
        a%=m;
        e>>=1;
    }
    return ans;
}
int main(){
    ll a,b,m;
    cin>>a>>b>>m;
    cout<<b_e(a,b,m);
}