#include<bits/stdc++.h>
using namespace std;

void solve(vector<pair<long long,long long>> c){
    long long ans = 0;
    long long prev_floor = 0;
    
    for(auto request : c){
        ans=ans+abs(prev_floor-request.first)+abs(request.first-request.second);
        prev_floor=request.second;
    }
    cout<<ans;
}

int main(int argc, char const *argv[])
{
    long long n_cases;
    cin>>n_cases;
    vector<vector<pair<long long,long long>>> cases(n_cases);

    for(long long i = 0 ; i < n_cases ; i++){
        long long n,q;
        cin>>n>>q;
        vector<pair<long long , long long>> c(q); 
        for(long long j = 0 ; j < q ; j ++){
            long long a, b;
            cin>>a>>b;
            c[j]=make_pair(a,b);
        }
        cases[i]=c;
    }

    for(auto c : cases){
        solve(c);
        cout<<endl;
    }

    return 0;
}
