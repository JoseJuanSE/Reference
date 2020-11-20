#include<bits/stdc++.h>
using namespace std;
bool Is_Prime(long long num){
    if((num!=2 and num%2==0) or num==1)return false;
    for(long long i=3;i*i<num;i+=2)
        if(num%i==0)
            return false;
    return true;
}
int main(){
    if(Is_Prime((1e9)+7)){
        cout<<"Es primo"<<endl;
    }else{
        cout<<"No es primo"<<endl;
    }
    return 0;
}