#include<bits/stdc++.h>
using namespace std;

int sweet_score(vector<int> arr, int a, int b){
    int sign[2] = {1,-1};
    int sum = 0;

    for(int i = 0 ; i <= b-a ; i++){
        sum+=arr[a+i]*sign[i%2]*(i+1);
    }

    return sum;
}

int solve(vector<int> arr,vector<tuple<char,int,int>> queries){
    int sum = 0;

    for(int i = 0 ; i <= queries.size() ; i++){
        char op = get<0>(queries[i]);
        int a = get<1>(queries[i]);
        int b = get<2>(queries[i]);

        switch(op){
            case 'U':
                arr[a-1]=b;
                break;
            case 'Q':
                sum+=sweet_score(arr,a-1,b-1);
                break;
        }
    }
    
    return sum;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int t;
    cin>>t;
    
    int n,k;
    
    // vector<pair<vector<int>,vector<tuple<char,int,int>>>> cases(t);
    
    for(int i = 0 ; i < t ; i++){
        cin>>n>>k;
        vector<int> case_i(n);
        vector<tuple<char,int,int>> queries(k);
        for(int j = 0 ; j < n ; j++){
            cin>>case_i[j];
        }
        for(int j = 0 ; j < k ; j++){
            cin>>get<0>(queries[j])>>get<1>(queries[j])>>get<2>(queries[j]);
        }
        // cases[i].first = case_i;
        // cases[i].second = queries;
        cout<<"Case #"<<(i+1)<<": "<<solve(case_i,queries)<<endl;
    }
    
    // for(int i = 0 ; i < t ; i++){
    //     cout<<"Case #"<<(i+1)<<": "<<solve(cases[i].first,cases[i].second)<<endl;
    // }
    
    return 0;
}