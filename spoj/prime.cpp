#include <bits/stdc++.h>
using namespace std;

void printPrimes(int a, int b){
    bool isPrime = true;

    if(a==1){
        a=a+1;
    }

    if(b==2){
        cout<<2<<endl;
        return;
    }
    
    for(int i = a ; i <= b ; i++){
        isPrime = true;
        for(int j = 2; j <= pow(i,0.5) ; j ++){
            if(i%j==0){
                isPrime=false;
                break;
            }
        }
        if(isPrime){
            cout<<i<<endl;
        }
    }
}

void printPrimesMoreEfficiently(int a , int b){
    vector<int> num(b-1);
    vector<bool> num_mask(b-1);

    iota(num.begin(),num.end(),2);

    int p = 2;
    bool stopSearch = false;

    while(!stopSearch){
        for(int i = p*p ; i <= b ; i+=p){
            num_mask[i-2]=true;
        }
        stopSearch = true;
        for(int i = p+1 ; i <= b ; i++){
            if(!num_mask[i-2]){
                p=i;
                stopSearch = false;
                break;
            }
        }
    }

    if(a<=2)a=2;

    for(int i = a-2 ; i < num.size() ; i++){
        if(num_mask[i]==false){
            cout<<num[i]<<endl;
        }
    }
}

int main(int argc, char const *argv[])
{
    int n;
    cin>>n;

    int a,b;

    for(int i = 0 ; i < n ; i++){
        cin>>a>>b;
        printPrimes(a,b);
        cout<<endl;
    }

    return 0;
}
