#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,q;
    cin>>n>>q;

    int x,y;
    vector<int,unordered_map<int>> tree(n);
    for(int i = 0 ; i < n-1 ; i++){
        cin>>x>>y;
        tree[x-1][y-1]=1;
        tree[y-1][x-1]=1;
    }

    int a,b;
    vector<set<int>> sets(q);
    for(int i = 0 ; i < q ; i++){
        set<int> s;
        cin>>a;
        while(a--){
            cin>>b;
            s.insert(b-1);
        }
        sets[i]=s;
    }

    vector<int,unordered_map<int>> tree(n);

    for(auto i : edges){

    }    

    return 0;
}