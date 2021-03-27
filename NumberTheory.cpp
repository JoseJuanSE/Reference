#include<bits/stdc++.h>
using namespace std;

//--------------interger numbers-----------------

//int       ->  | x | < 2^31 o 2.1*10^9 
//ll        ->  | x | < 2^63 o 9.2*10^18 
//shr       ->  | x | < 2^15 o 32768 
//chr       ->  | x | < 128 
//__int128  ->  | x | < 2^127 o 1.7*10^38
//__uint128 ->  0 < x  < 2^128 o 3.4*10^38

// a | b -> b = aq + r

// double x = (double)a/b with a and b int 

//to round a number
// round(x) with x float then x+=0.5

int roun(double x){ return x+0.5;}

int divRound(int a,int b){ return (2*a+b)/(2*b);}

//--------------divisors and prime numbers-----------------
// 1 is not prime and neither composite

vector<int> getDivisors(int n){//O(sqrt(n)) -> n<= 10^14
    //all b such that n = b*k with k that belongs to int
    vector<int> divisor;// divisor.size() = 2^primefatorization.size()
    for(int i=1;i*i<=n;i++){
        if(n % i == 0){
            int b = n/i;
            divisor.push_back(i);
            if(i!=b)divisor.push_back(b);
        }
    }
    //sort(begin(divisor),end(divisor));
    return divisor;
}

bool isPrime(int x){// use long long int if n>=10^9, O(sqrt(n))
    if(x==2)return true;
    if(x%2==0)return false;
    for(int i=3;i*i<=x;i+=2){
        if(x%i==0)
            return false;
    }
    return true;
}

//--------------Sieve of Erastotenes-----------------
// it give us all primes between 1 and n
//if we make a sieve using isprime, we got O(n sqrt(n)) n <= 1e5
//but if we make a sieve using the clasical method we get O(nlog(log(n))) n<= 1e7
//that one is the following
//negative part, now we are using O(n) in memory
vector<bool> sieve(int n){//O(nlog(log(n)))
    vector<bool> is_prime(n+1,true);
    is_prime[0] = is_prime[1] = false;
    for(int i=2;i<=n;i++){
        if(is_prime[i]){ 
            for(int j=2*i;j<=n;j+=i){
                is_prime[j]=false;
            }
        }
    }
    return is_prime;
}
//sieve optimization
//using the same idea we used in isPrime, we have the following
vector<bool> sieveOp(int n){
    vector<bool> is_prime(n+1,true);
    is_prime[0] = is_prime[1] = false;
    for(int i=4;i<=n;i+=2){
        is_prime[i]=false;
    }
    for(int i=3;i*i<=n;i+=2){
        if(is_prime[i]){
            //primes.push_back(i) if we wanna finish with an array of primes factors
            if((long long)i*i <= n)
                for(int j=i*i;j<=n;j+=2*i){
                    is_prime[j]=false;
                }
        }
    }
    return is_prime;
}

//divisor sieve
// this sieve tell us in O(1) how many divisors we have in div[i]
vector<int> sieveDiv(int n){//O(nlog(n))
    vector<int> div(n+1,0);
    for(int i=1;i*i<=n;i++){
        for(int j=i;j<=n;j+=i){
            div[j]++;//to get the divisor insead of how many, we just need to do div[i].push_back(i)
        }
    }
    return div;
}

//--------------Number factorization-----------------
// 1 -> empty product

map<int,int> primeFactorization(int n){//O(sqrt(n)) n<=1e14
    //first -> prime factor
    //second -> how many of this there is
    map<int,int> fact;
    for(int i=2;i*i<=n;i++){
        while(n % i == 0){
            n/=i;
            fact[i]++;
        }
    }
    if(n>1){
        fact[n]=1;
    }
    return fact;
}


int main(){
    cout<<divRound(7,3)<<endl;
    vector<int> ar;
    ar = getDivisors(101*3*7*2);
    for(int i:ar)
        cout<<i<<" ";
    cout<<endl;
    cout<<"-------"<<endl;
    vector<int> d = sieveDiv(26);
    for(int i:d)    
        cout<<i<<" ";
    cout<<endl;
    return 0;
}
