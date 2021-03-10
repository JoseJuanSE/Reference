#include<bits/stdc++.h>
using namespace std;
struct BIT{
    vector<long long> a;
    BIT(int x):a(x,0){}
    BIT():a(1000005,0){}
    void update(int n,long long c){
        if(n>a.size())return ;
        a[n]+=c;
        update(n+(n&(-n)),c);
    }
    long long q(int c){
        if(!c)return 0;
        return a[c]+q(c-(c&(-c)));
    }
};
int main(){
    int n = 10;
    BIT a(n);
    for(int i=1;i<n;i++)
        a.update(i,i);
    cout<<a.q(5)<<endl;
    cout<<a.q(6)-a.q(5)<<endl;
    cout<<a.q(7)<<endl;
    return 0;
}
