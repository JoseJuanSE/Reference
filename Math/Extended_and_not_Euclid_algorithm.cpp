#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b){
    if(b==0)return a;
    return a>b?gcd(b,a%b):gcd(a,b%a);
}
//d = ax + by
//x = x0 + b/gcd *k
//y = y0 + a/gcd *k
void extenea(int a,int b,int &x,int &y){
    if(a<b)swap(a,b);
    if(b==0){x=1;y=0;return ;}
    extenea(b,a%b,x,y);
    int x1=y;
    int y1=x-(a/b)*y;
    x=x1;y=y1;
}
int main(){
    int a,b;
    cin>>a>>b;
    int x,y;
    cout<<gcd(a,b)<<endl;
    extenea(a,b,x,y);
    cout<<x<<" "<<y<<endl;
}