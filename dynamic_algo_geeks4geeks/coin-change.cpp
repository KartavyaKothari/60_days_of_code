#include<bits/stdc++.h>
using namespace std;

int noOfWaysOfChange(vector<vector<int>> &sol, vector<int> coins, int last_index ,int change){
    if(last_index < 0){
        return 0;
    }

    if(change == 0){
        return 1;
    }

    if(change<0){
        return 0;
    }

    if(sol[last_index][change] == -1)
        sol[last_index][change] = noOfWaysOfChange(sol ,coins, last_index, change - coins[last_index]) + noOfWaysOfChange(sol, coins, last_index -1 , change);
    
    return sol[last_index][change];
}

void solve(vector<int> coins, int change){
    vector<vector<int>> sol(coins.size(),vector<int>(change+1,-1));

    cout<<noOfWaysOfChange(sol, coins, coins.size() - 1 ,change);
}

int main(){
    vector<int> coins = {1, 2, 3}; 
    int change = 4;

    solve(coins,change);

    return 0;
}