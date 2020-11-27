#include<bits/stdc++.h>
using namespace std;
typedef struct trienode{
    unordered_map<char,trienode*> children;
    bool isWord;
    trienode(){
        isWord = false;
    }
    void insert(string a){
        trienode *curr = this;
        for(int i=0;i<a.size();i++){
            if(curr->children.find(a[i])==curr->children.end())
                curr->children[a[i]] = new trienode();
            curr = curr->children[a[i]];
        }
        curr->isWord = true;
    }
    bool count(string a){
        trienode * curr = this;
        for(int i=0;i<a.size();i++){
            if(curr->children.find(a[i])==curr->children.end())
                return false;
            curr = curr->children[a[i]];
        }
        return curr->isWord;
    }
}*trie;
int main(){
    int t;
    cin>>t; 
    trie mytrie = new trienode();
    while(t--){
        int n;
        cin>>n;
        while(n--){
            string x;
            cin>>x;
            mytrie->insert(x);
        }
        cin>>n;
        while(n--){
            string g;
            cin>>g;
            cout<<mytrie->count(g)<<endl;
        }
    }
    return 0;
}