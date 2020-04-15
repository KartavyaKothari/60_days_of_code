#include<bits/stdc++.h>
using namespace std;

vector<long long> fibo_n;

int fibo_tabulated(int n){
    long long fibo_arr[n+1];

    fibo_arr[0] = 0;
    fibo_arr[1] = 1;

    for(int i = 2 ; i <= n ; i++){
        fibo_arr[i]=fibo_arr[i-1]+fibo_arr[i-2];
        // cout<<"^";
    }

    return fibo_arr[n];
}

long long fibo_memoized(int n){
    if(n==0 || n==1) return n;
    if(fibo_n[n]==0) fibo_n[n] = fibo_memoized(n-1)+fibo_memoized(n-2);

    return fibo_n[n];
}

long long fibo(int n){
    if(n==0 || n==1) return n;
    return fibo(n-1)+fibo(n-2);
}

void print(int n){
    for(int i = 0 ; i < n ; i++){
        cout<<fibo_n[i]<<" ";
    }
}

int main(int argc, char const *argv[])
{
    fibo_n.resize(1000);
    fill(fibo_n.begin(),fibo_n.end(),0);
    cout<<"Enter number to calculate fibo of: ";
    int n;
    cin>>n;
    for(int i = 0 ; i < n ; i++)
        cout<<fibo_tabulated(i)<<" ";
    // print(10);
    return 0;
}
