#include<bits/stdc++.h>
using namespace std;

bool give_ice_cream(vector<int> &coins, int p){
    if(p==15){
        if(coins[1]>0){
            coins[1]--;
            coins[2]++;
            return true;
        }else if(coins[0]>1){
            coins[0]-=2;
            coins[2]++;
            return true;
        }else return false;
    }else if(p==10){
        if(coins[0]>0){
            coins[0]--;
            coins[1]++;
            return true;
        }else return false;
    }else return false;
}

bool solve(vector<int> people){
    vector<int> coins(3,0);

    for(int i: people){
        if(i==5){
            coins[0]++;
            continue;
        }
        if(give_ice_cream(coins,i)==false)return false;
    }

    return true;
}

int main(){
    int t;
    cin>>t;
    int n;
    vector<vector<int>> cases(t);
    // vector<int> price(t);
    for(int i = 0 ; i < t ; i++){
        cin>>n;
        
        vector<int> case_(n);
        for(int j = 0 ; j < n ; j++){
            cin>>case_[j];
        }

        cases[i] = case_;
    }

    for(int i = 0 ; i < t ; i++){
        cout<<(solve(cases[i])?"YES":"NO")<<endl;
    }
}