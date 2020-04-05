#include<iostream>
#include <math.h>
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
