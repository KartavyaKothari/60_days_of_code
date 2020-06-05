#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<bool> seive(10000);
    vector<int> primes;
    primes.reserve(5000);

    int j = 0;

    for(int i = 2 ; i < seive.size() ; i++){
        if(seive[i]){continue;}
        j = i;
        while(j*i<seive.size()){
            seive[j*i]=true;
            j++;
        }
    }

    for(int i = 2 ; i < seive.size() ; i++){
        if(!seive[i]){
            primes.push_back(i);
        }
    }

    cout<<primes.size();

    // for(int i : primes){
    //     cout<<i<<" ";
    // }
}