#include<bits/stdc++.h>
using namespace std;

int min(int a, int b, int c){
    if(a<b){
        if(a<c){
            return a;
        }else return c;
    }else{
        if(b<c){
            return b;
        }else return c;
    }
}

// int min_cost_path(int i , int j, vector<vector<int>> cost_table){
//     if(j==0){
//         int sum = 0;
//         for(int index = i ; index >= 0 ; index--){
//             sum += cost_table[index][j];
//         }
//         return sum;
//     }

//     if(i==0){
//         int sum = 0;
//         for(int index = j ; index >= 0 ; index--){
//             sum += cost_table[i][index];
//         }
//         return sum;
//     }
//     // if(i>=cost_table.size()||j>=cost_table[0].size())return 9999;
    
//     return cost_table[i][j] + min(
//         min_cost_path(i-1,j,cost_table),
//         min_cost_path(i,j-1,cost_table),
//         min_cost_path(i-1,j-1,cost_table)
//     );
// }

int min_cost_path(int i , int j, vector<vector<int>> cost_table){
    if(j==cost_table[0].size()-1){
        int sum = 0;
        for(int index = i ; index < cost_table.size() ; index++){
            sum += cost_table[index][j];
        }
        return sum;
    }

    if(i==cost_table.size()-1){
        int sum = 0;
        for(int index = j ; index < cost_table[0].size() ; index++){
            sum += cost_table[i][index];
        }
        return sum;
    }
    // if(i>=cost_table.size()||j>=cost_table[0].size())return 9999;
    
    return cost_table[i][j] + min(
        min_cost_path(i+1,j,cost_table),
        min_cost_path(i,j+1,cost_table),
        min_cost_path(i+1,j+1,cost_table)
    );
}

void createCumulativeCostTable(vector<vector<int>> &table, vector<vector<int>> cost_table){
    table[0][0]=0;
    table[0][1]=table[1][0]=cost_table[0][0];

    // cout<<table[0].size()<<endl;

    for(int i = 1 ; i < table.size() ; i++){
        for(int j = 1 ; j < table[0].size() ; j++){
            table[i][j]=cost_table[i-1][j-1] + min(
                table[i-1][j],
                table[i][j-1],
                table[i-1][j-1]
            );
        }
    }
}

void solve(vector<vector<int>> cost_table){
    // cout<<min_cost_path(cost_table.size()-1,cost_table[0].size()-1,cost_table);
    vector<vector<int>> table(cost_table.size()+1,vector<int> (cost_table[0].size()+1,INT_MAX));
    createCumulativeCostTable(table,cost_table);
    // for(auto row : table){
    //     for(auto ele : row){
    //         cout<<ele<<" ";
    //     }cout<<endl;
    // }
    cout<<table.back().back();
}

int main(int argc, char const *argv[])
{
    int n;
    cin>>n;

    vector<vector<vector<int>>> cases(n);

    for(int i = 0 ; i < n ; i++){
        int a,b;
        cin>>a>>b;
        vector<vector<int>> vec(a,vector<int>(b,0));
        for(int j = 0 ; j < a ; j++){
            for(int k = 0 ; k < b ; k++){
                cin>>vec[j][k];
            }
        }
        cases[i]=vec;
    }

    for(int i = 0 ; i < n ; i++){
        solve(cases[i]);
        cout<<endl;
    }

    return 0;
}