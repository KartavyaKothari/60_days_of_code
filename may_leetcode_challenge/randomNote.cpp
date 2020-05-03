#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        // unordered_map<char,int> magzineDict;
        vector<int> mag(26,0);
        for(char i : magazine){
            mag[i-'a']+=1;
        }
        
        for(char i: ransomNote){
            if(mag[i-'a']==0){
                // cout<<"ola"<<mag[i];
                return false;
            }
            mag[i]-=1;
        }
        
        return true;
    }
};

int main(){
    Solution sol;

    cout<<sol.canConstruct("aa","ab");

    return 0;
}