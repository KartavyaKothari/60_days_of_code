#include<bits/stdc++.h>
using namespace std;

void solve(vector<vector<char>> &wall){
    unordered_map<char,set<char>> adj;
    
    for(int i = 0 ; i < wall.size() - 1 ; i++)
        for(int j = 0 ; j < wall[0].size() ; j++)
            if(wall[i][j]!=wall[i+1][j])
                adj[wall[i+1][j]].insert(wall[i][j]);

    unordered_map<char,int> degree;
    for(auto i: adj){
        degree[i.first];
        for(auto j: i.second){
            degree[j]++;
        }
    }

    queue<char> nodes;

    for(auto i: degree){
        if(i.second==0){
            nodes.push(i.first);
            break;
        }
    }

    char node;

    vector<char> sol;sol.reserve(degree.size());

    while(!nodes.empty()){
        node = nodes.front();
        nodes.pop();
        
        sol.push_back(node);

        for(auto i: adj[node]){
            if(--degree[i]==0){
                nodes.push(i);
            }
        }
    }

    if(sol.size()==degree.size()){
        for(char i: sol){
            cout<<i;
        }
    }else cout<<-1;

    return;
}

int main(){
    int t;
    cin>>t;
    int r,c;
    
    vector<vector<vector<char>>> cases(t);
    
    for(int i = 0 ; i < t ; i++){
        cin>>r>>c;
        vector<vector<char>> case_(r,vector<char>(c,'A'));
        for(int j = 0 ; j < r ; j++)
            for(int k = 0 ; k < c ; k++)
                cin>>case_[j][k];
        cases[i] = case_;
    }
    
    for(int i = 0 ; i < t ; i++){
        cout<<"Case #"<<(i+1)<<": ";
        solve(cases[i]);
        cout<<endl;
    }
}