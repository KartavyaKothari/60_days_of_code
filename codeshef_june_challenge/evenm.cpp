#include<bits/stdc++.h>
using namespace std;

void solve(int n){
    int a = 1;
    
    for(int i = 0 ; i < n ; i++){
        if(i%2==0)
            for(int j = a ; j < a+n ; j++){
                cout<<j<<" ";
            }
        else for(int j = a+n-1 ; j >= a ; j--){
                cout<<j<<" ";
            }
        a+=n;
        cout<<endl;
    }
}

int main(){
    int t;
    cin>>t;
    int n;
    vector<int> cases(t);
    // vector<int> price(t);
    for(int i = 0 ; i < t ; i++){
        cin>>cases[i];
    }

    for(int i = 0 ; i < t ; i++){
        solve(cases[i]);
        cout<<endl;
    }
}