#include<bits/stdc++.h>
using namespace std;
vector<int>arre;
int n;
struct ura{
    int de,iz,val;
};
vector<ura>st;
int cons(int i,int j,int po){
    st[po].de=j;
    st[po].iz=i;
    if(st[po].de==st[po].iz){
        if(i>n)st[po].val=0;
        else    st[po].val=arre[i];    
        return st[po].val;    
    }
    return st[po].val=cons(i,(i+j)/2,po*2)+cons((i+j)/2+1,j,po*2+1);
}
int search(int i, int ac){
    if(st[ac].iz==st[ac].de and st[ac].iz==i)    return ac;
    if(st[ac].iz<=i and st[ac].de>=i){
        search(i,ac*2);
        search(i,ac*2+1);
    }
}
void actu(int p,int k){
    if(p){
        st[p].val+=k;
        actu(p/2,k);
    }
}
void update(int i,int k){
    int po=    search(i,1);
    actu(po,k);
}
int query(int i,int j,int po){
    if(st[po].de<=j and st[po].iz>=i)return st[po].val;        
    if(st[po].de<i or st[po].iz>j)return 0;
    return query(i,j,po*2)+query(i,j,po*2+1);
}
int main(){
    cin>>n;
    arre.resize(n+2);
    for(int i=1;i<=n;i++)
        cin>>arre[i];
    int x=pow(2,ceil(log2(n)));
    st.resize(4*n);
    cons(1,x,1);
    int q;
    cin>>q;
    for(int i=0;i<q;i++){
        int a,b;
        cin>>a>>b;
        cout<<query(a,b,1)<<endl;
    }
    return 0;
}