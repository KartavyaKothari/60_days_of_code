#include<bits/stdc++.h>
using namespace std;

bool isBadVersion(int n){
    if(n==4)return true;
    return false;
}

int firstBadVersion(int n) {
    int m;
    int start = 1, end = n;
    while(1){
        if(end-start<2){
            cout<<start<<" "<<end<<endl;
            while(!isBadVersion(start))start++;
            return start;
        }
        m = (end-start)/2+start;
        if(isBadVersion(m)==false){
            //It is a good version
            start = m+1;
        }else{
            //Bad version
            end = m-1;
        }
    }
}

int main(){
    cout<<firstBadVersion(5);
}