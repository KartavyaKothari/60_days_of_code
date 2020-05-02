#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_map<char,int> table;
        for(char i : S){
            table[i] = table[i]+1;
        }

        int sum = 0;

        for(char i : J){
            sum += table[i];
        }

        return sum;
    }
};

int main(){
    Solution sol;

    cout<<sol.numJewelsInStones("aA","aAAbbbb");

    return 0;
}