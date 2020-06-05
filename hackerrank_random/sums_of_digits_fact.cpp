#include<bits/stdc++.h>
using namespace std;

vector<long long> fact;

long long sum_of_fact_of_digits(long long num){
    long long sum = 0;

    while(num){
        sum+=(fact[num%10]);
        num/=10;
    }

    return sum;
}

long long sum_of_digits(long long num){
    long long sum = 0;

    while(num){
        sum+=(num%10);
        num/=10;
    }

    return sum;
}

long long sfn(long long num){
    return sum_of_digits(sum_of_fact_of_digits(num));
}

vector<long long> GI(47,-1);

long long gi(long long num){
    long long i = 0;
    // if(num<=46){
    //     if(GI[num]!=-1)return GI[num];
    // }

    while(sfn(i)!=num){i++;}

    // if(num<=46){
    //     GI[num] = i;
    // }

    return i;
}


long long sgi(long long num){
    return sum_of_digits(gi(num));
}

long long solve(long long n, long long m){
    long long sum = 0;

    for(long long  i = 1 ; i <= n ; i++){
        sum = (sum+sgi(i)%m)%m;
    }

    return sum;
}

int main(){
    // int n;
    // cin>>n;

    fact = {1 ,1 ,2 ,6 ,24 ,120 ,720 ,5040 ,40320 ,362880};

    // vector<pair<long long,int>> queries(n);

    // for(int i = 0 ; i < n ; i ++){
    //     cin>>queries[i].first>>queries[i].second;
    // }

    // for(int i = 0 ; i < n ; i ++){
    //     cout<<solve(queries[i].first,queries[i].second)<<endl;
    // }

    for(int i = 0 ; i < 47 ; i++){
        cout<<gi(i)<<",";
    }
}