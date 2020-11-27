#include<bits/stdc++.h>
using namespace std;
void KMP(string a,string b){
    vector<int> lps(a.size(),0);
    int beg=0;
    for(int i=1;i<a.size();i++){
        if(a[beg]==a[i]){beg++;lps[i]=beg;}
        else if(beg!=0){beg = lps[beg-1];i--;}
    }
    for(int i=0;i<b.size();i++){
        if(a[0]==b[i])
        for(int j=0;j<a.size();j++){
            
            if(j-i+1==a.size())cout<<
        }
    }
}
int main(){
    string a,b;
    cin>>a>>b;
    KMP(a,b);
    return 0;
}