#include <bits/stdc++.h>
using namespace std;

int ft[100000], n;

void update(int r, int c){
    if (r > n)return;
    ft[r] += c;
    update(r + (r & (-r)), c);
}

int q(int c){
    if (!c)return 0;
    return ft[c] + q(c - (c & (-c)));
}

int main(){
    n=10;
    for (int i = 1; i <= n; i++)
        update(i, i);
    
    cout << q(4) << endl; // -> 10
    cout << q(5) - q(4) << endl; // -> 5
    cout << q(3); // -> 6
}