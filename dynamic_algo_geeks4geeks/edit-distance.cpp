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

int calculate_cost(string str1, string str2){
    if(str1.length()==0){
        return str2.length();
    }

    if(str2.length()==0){
        return str1.length();
    }

    if(str1.back()==str2.back()){
        return calculate_cost(string(str1.begin(),str1.end()-1),string(str2.begin(),str2.end()-1));
    }

    return 1 + min(
        calculate_cost(string(str1.begin(),str1.end()),string(str2.begin(),str2.end()-1)), // insert ele
        calculate_cost(string(str1.begin(),str1.end()-1),string(str2.begin(),str2.end()-1)), // replace ele
        calculate_cost(string(str1.begin(),str1.end()-1),string(str2.begin(),str2.end())) // remove ele
    );
}

void createCostTable(string str1, string str2, vector<vector<int>> &table){
    for(int i = 0 ; i <= str1.length() ; i++){
        for(int j = 0 ; j <= str2.length() ; j++){
            if(i==0){
                table[i][j]=j;
                continue;
            }
            if(j==0){
                table[i][j]=i;
                continue;
            }
            if(str1[i-1]==str2[j-1]){
                table[i][j]=table[i-1][j-1];
                continue;
            }
            
            table[i][j]=1+min(table[i-1][j-1],table[i][j-1],table[i-1][j]);
        }
    }
}

void solve(pair<string,string> seq){
    string str1 = seq.first;
    string str2 = seq.second;

    vector<vector<int>> table(str1.length()+1,vector<int> (str2.length()+1,0));

    createCostTable(str1,str2,table);

    cout<<table.back().back();
    // cout<<calculate_cost(str1,str2);
}

int main(int argc, char const *argv[])
{
    int n;
    cin>>n;

    vector<pair<string,string>> sequences(n);

    for(int i = 0 ; i < n ; i++){   
        string str1,str2;
        cin>>str1>>str2;
        sequences[i] = make_pair(str1,str2);
    }

    for(int i = 0 ; i < n ; i++){
        solve(sequences[i]);
        cout<<endl;
    }

    return 0;
}
