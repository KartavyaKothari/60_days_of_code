#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> arr,int k){
    int count = 0;
    bool is_rundown = false;
    
    for(int i = 0 ; i <= arr.size()-k ; i++){
        if(arr[i]==k&&arr[i+k-1]==1){
            is_rundown = true;
            for(int j = 0 ; j < k ; j++){
                if(arr[i+j]!=k-j){
                    is_rundown = false;
                    break;
                }
            }
            if(is_rundown)count++;
        }
    }
    
    return count;
}

int main(){
    int t;
    cin>>t;
    
    int n,k;
    
    vector<pair<vector<int>,int>> cases(t);
    
    for(int i = 0 ; i < t ; i++){
        cin>>n>>k;
        vector<int> case_i(n);
        for(int j = 0 ; j < n ; j++){
            cin>>case_i[j];
        }
        cases[i] = make_pair(case_i,k);
    }
    
    for(int i = 0 ; i < t ; i++){
        cout<<"Case #"<<i<<": "<<solve(cases[i].first,cases[i].second)<<endl;
    }
    
    return 0;
}