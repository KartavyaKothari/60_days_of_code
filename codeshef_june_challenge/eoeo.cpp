#include<bits/stdc++.h>
using namespace std;

long long solve(long long ts){
    if(ts%2==1)return (ts-1)/2;

    long long ts_odd = ts;

    while(ts_odd%2==0)ts_odd/=2;

    return (ts_odd-1)/2;
}

int main(){
    int t;
    cin>>t;
    int n;
    vector<long long> cases(t);
    // vector<int> price(t);
    for(int i = 0 ; i < t ; i++){
        cin>>cases[i];
    }

    for(int i = 0 ; i < t ; i++){
        cout<<solve(cases[i])<<endl;
    }
}