#include<bits/stdc++.h>
using namespace std;

bool is_weekend(vector<int> week, int p){
    return accumulate(week.begin(),week.end(),0)*p-(24*5)>0;
}

int main(){
    int n;
    cin>>n;

    vector<vector<int>> cases(n,vector<int>(5,0));
    vector<int> wfh_hour(n);
    int t;

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < 5 ; j++){
            cin>>cases[i][j];
        }
        cin>>wfh_hour[i];
    }

    for(int i = 0 ; i < n ; i++){
        cout<<(is_weekend(cases[i],wfh_hour[i])?"Yes":"No")<<endl;
    }

    return 0;
}