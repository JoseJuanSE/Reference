#include<bits/stdc++.h>
using namespace std;
//log nos da el msb
struct SP{
    vector<vector<int> > t;
    vector<int> log;

    int f(int x){
        return x;
    }
    int f(int x,int y){
        return x+y; // operation
    }

    SP(vector<int>  a):t(floor(log2(a.size()))+1),log(a.size()+1){ //Nlog(N)
        int n = a.size(),k = floor(log2(a.size()))+1;
        log[1]=0;
        for(int i=2;i<=n;i++)
            log[i] = log[i/2]+1;
        for(auto &i:t)
            i.assign(n,-1);
        for(int i=0;i<n;i++)
            t[0][i]=f(a[i]);
        
        for(int j=1;j<k;j++)
            for(int i=0;i+(1<<(j))<=n;i++)
                t[j][i] = f(t[j-1][i],t[j-1][i+(1<<(j-1))]);
    }
    // no updates
    int querie(int i,int j){
        int s = j-i+1;
        int ans = 0; // neutral for the operation
        while(s){
            int k = log[s];
            ans = f(ans,t[k][i]);
            i+= (1<<k);
            s-= (1<<k);
        }
        return ans;
    }
    int consquery(int i,int j){ // podemos hacer esto cuando el translapar las respuestas
        int k = log[j-i+1];//no es un problema, como min, max, gcd (idempotent functions)
        return f(t[k][i],t[k][j-(1<<k)+1]);//O(1)
    }
};
int main(){
    vector<int> a = {10,1,3,20,25,-5,6,-10,11,8};
    SP g(a);
    for(int j=0;j<g.t.size();j++){
        for(int i=0;i<g.t[0].size();i++){
            cout<<fixed<<g.t[j][i]<<" ";
        }
        cout<<endl;
    }
    cout<<g.querie(0,7)<<endl; // ans = 50
}