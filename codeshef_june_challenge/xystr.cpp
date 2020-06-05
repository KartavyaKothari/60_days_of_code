#include<bits/stdc++.h>
using namespace std;

int solve(string s){
    int pairs = 0;

    for(int i = 0 ; i < s.size() - 1 ; i++){
        if(s[i]!=s[i+1]){
            pairs++;
            i+=1;
        }
    }

    return pairs;
}

int main(){
    int t;
    cin>>t;
    int n;
    vector<string> cases(t);
    // vector<int> price(t);
    for(int i = 0 ; i < t ; i++){
        cin>>cases[i];
    }

    for(int i = 0 ; i < t ; i++){
        cout<<solve(cases[i])<<endl;
    }
}