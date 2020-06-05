#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> prices, int k){
    int sum = 0;

    for(int i: prices){
        sum+=i>k?i-k:0;
    }

    return sum;
}

int main(){
    int t;
    cin>>t;
    int n;
    vector<vector<int>> cases(t);
    vector<int> price(t);
    for(int i = 0 ; i < t ; i++){
        cin>>n>>price[i];
        
        vector<int> case_(n);
        for(int j = 0 ; j < n ; j++){
            cin>>case_[j];
        }

        cases[i] = case_;
    }

    for(int i = 0 ; i < t ; i++){
        cout<<solve(cases[i],price[i])<<endl;
    }
}