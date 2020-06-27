#include<bits/stdc++.h>
using namespace std;

static int speed = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Case{
    public:
    vector<vector<bool>> arr;
};

void solve(vector<vector<bool>> &tab){
    int c_1 = 0;
    int c_2 = 0;

    for(auto row: tab){
        for(bool i: row){
            if(i) c_1++;
            else 
        }
    }
}

int main(){
    int t;
    cin>>t;

    vector<Case> cases(t);

    int a,b;
    // Case c;
    
    for(int i = 0 ; i < t ; i++){
        cin>>a>>b;
        vector<vector<bool>> case_(a,vector<bool>(b,0));
        for(int j = 0 ; j < a ; j++){
            for(int k = 0 ; k < b ; k++){
                cin>>case_[j][k];
            }
        }
        cases[i].arr = case_;
    }

    for(int i = 0 ; i < t ; i++){
        solve(cases[i].arr);
        cout<<endl;
    }

    return 0;
}