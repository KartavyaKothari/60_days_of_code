#include<bits/stdc++.h>
using namespace std;

// vecotr

int lcs(string str1,string str2){
    if(str1.length()==0||str2.length()==0){
        return 0;
    }

    if(str1.back()==str2.back()){
        return 1 + lcs(string(str1.begin(),str1.end()-1),string(str2.begin(),str2.end()-1));
    }

    int res1 = lcs(string(str1.begin(),str1.end()),string(str2.begin(),str2.end()-1));
    int res2 = lcs(string(str1.begin(),str1.end()-1),string(str2.begin(),str2.end()));

    return res1>res2?res1:res2;
}

void createSimilarityTable(string str1,string str2,vector<vector<int>> &table){
    // cout<<table[0][0]<<endl;
    // table[0][0] = 1;
    for(int i = 1 ; i < table.size() ; i ++){
        for( int j = 1 ; j < table[i].size() ; j++){
            if(str1[i-1]==str2[j-1]){
                table[i][j]=table[i-1][j-1]+1;
            }else table[i][j] = table[i][j-1]>table[i-1][j]?table[i][j-1]:table[i-1][j];
        }
    }
}

void solve(pair<string,string> seq){
    string str1 = seq.first;
    string str2 = seq.second;
    
    vector<vector<int>> table(str1.length()+1,vector<int> (str2.length()+1,0));
    // cout<<table[0][0]<<endl;
    createSimilarityTable(str1,str2,table);
    // cout<<table[0][0]<<endl;
    // cout<<lcs(str1,str2);
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
