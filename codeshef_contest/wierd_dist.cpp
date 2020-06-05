#include<bits/stdc++.h>
using namespace std;

auto speed = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

int solve(vector<int> A, vector<int> B){
    int dist = 0;
    int sum_a = 0;
    int sum_b = 0;

    for(int i = 0 ; i < A.size() ; i++){
        sum_a+=A[i];
        sum_b+=B[i];

        if(sum_a==sum_b){
            dist+=A[i]==B[i]?A[i]:0;
        }
    }

    return dist;
}

int main(){
    int n;
    cin>>n;

    vector<pair<vector<int>,vector<int>>> cases(n);
    int t;

    for(int i = 0 ; i < n ; i++){
        cin>>t;
        vector<int> A(t);
        vector<int> B(t);
    
        for(int j = 0 ; j < t ; j++){
            cin>>A[j];
        }
        for(int j = 0 ; j < t ; j++){
            cin>>B[j];
        }
        cases[i] = {A,B};
    }

    for(int i = 0 ; i < n ; i++){
        cout<<solve(cases[i].first,cases[i].second)<<endl;
    }

    return 0;
}