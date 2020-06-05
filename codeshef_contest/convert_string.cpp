#include<bits/stdc++.h>
using namespace std;

int solve(string A, string B){
    // vector<int> a_count(26,0);
    // vector<int> b_count(26,0);

    // for(char i: A){
    //     a_count[i-'a']++;
    // }

    // for(char i: B){
    //     b_count[i-'a']++;
    // }
    char max = 0;
    for(int i = 0 ; i < A.size() ; i++){
        
    }

}

int main(){
    int n;
    cin>>n;

    vector<pair<string,string>> cases(n);
    // vector<int> wfh_hour(n);
    string t1,t2;
    int t;

    for(int i = 0 ; i < n ; i++){
        cin>>t;
        cin>>t1>>t2;
        
        cases[i] = {t1,t2};
    }

    for(int i = 0 ; i < n ; i++){
        cout<<solve()<<endl;
    }

    return 0;
}