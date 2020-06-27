#include<bits/stdc++.h>
using namespace std;

bool solve(vector<vector<bool>> &tab){
    int r = 0,c = 0;
    vector<bool> is_r_claimed(tab.size(),false);
    vector<bool> is_c_claimed(tab.size(),false);

    for(int j = 0 ; j < tab.size() ; j++){
        for(int k = 0 ; k < tab[0].size() ; k++){
            if(tab[j][k]){
                is_r_claimed[j] = true;
                is_c_claimed[k] = true;
            }
        }
    }

    for(bool i: is_c_claimed){
        if(i==false)c++;
    }

    for(bool i: is_r_claimed){
        if(i==false)r++;
    }

    return min(r,c)%2;
}

int main(){
    int t;
    cin>>t;
    int l;

    vector<vector<vector<bool>>> cases(t);

    for(int i = 0 ; i < t ; i++){
        int row,col;
        cin>>row>>col;
        vector<vector<bool>> case_(row,vector<bool> (col,false));

        for(int j = 0 ; j < row ; j++){
            for(int k = 0 ; k < col ; k++){
                cin>>l;
                case_[j][k] = l;
            }
        }

        cases[i] = case_;
    }

    for(int i = 0 ; i < t ; i++){
        cout<<(solve(cases[i])?"Ashish":"Vivek")<<endl;
    }
}