#include<bits/stdc++.h>
using namespace std;

static int speed = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Case{
    public:
    string s;
    vector<vector<int>> arr;
};

void solve(string &a, vector<vector<int>> &arr){
    sort(a.begin(),a.end());
    vector<char> sol(arr.size());
    sort(arr.begin(),arr.end(),[](auto &i, auto &j){return i[0]<j[0];});
    
    int end = arr.size()-1;

    while(end>=0){
        sol[arr[arr.size()-1-end][1]]=a[end];
        end--;
    }

    for(char c: sol)cout<<c;
}

int main(){
    int t;
    cin>>t;

    vector<Case> cases(t);

    int a,b;
    for(int i = 0 ; i < t ; i++){
        cin>>cases[i].s;
        cin>>b;
        vector<vector<int>> arr(b,vector<int>(2,0));
        for(int j = 0 ; j < b ; j++){
            cin>>arr[j][0];
            arr[j][1] = j;
        }
        cases[i].arr = arr;
    }

    for(int i = 0 ; i < t ; i++){
        solve(cases[i].s,cases[i].arr);
        cout<<endl;
    }

    return 0;
}