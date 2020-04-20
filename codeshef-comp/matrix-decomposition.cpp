#include<bits/stdc++.h>
using namespace std;

long long find_modulo_power(long long x, long long y){
    // long long prod;
    // return prod%1000000007;
    long long res = 1;
    x = x%1000000007;
    if(x==0)return 0;

    while(y>0){
        if(y%2==1){
           res=(res*x)%1000000007;
           y--; 
        }
        y=y/2;
        x=(x*x)%1000000007;
    }

    return res%1000000007;
}

void solve(long long n , long long x){
    // cout<<n<<" "<<x;
    // cout<<find_answer(n,x);
    long long sum = x;
    long long prod = x;
    x = x*x;
    // vector<long long> 
// cout<<"**"<<find_modulo_power(256,2)<<"**";
    for(int i = 1 ; i < n ; i++){
        // prod = (prod+1)*(2*i+1);
        prod = find_modulo_power(x,2*i+1);
        x = (x*prod)%1000000007;
        // x = prod;
        // prod = prod;
        sum = (sum + prod)%1000000007;
        // prod = ((long long )pow(x,))%1000000007;
        cout<<sum<<" ";
    }
    cout<<sum;
}

int main(int argc, char const *argv[])
{
    long long n_cases;
    cin>>n_cases;
    vector<pair<long long,long long>> cases(n_cases);

    for(long long i = 0 ; i < n_cases ; i++){
        long long n,x;
        cin>>n>>x;
        cases[i]=make_pair(n,x);;
    }

    for(auto c : cases){
        solve(c.first,c.second);
        cout<<endl;
    }

    return 0;
}
