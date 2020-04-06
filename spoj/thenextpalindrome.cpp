#include <bits/stdc++.h>
using namespace std;

bool isPalin(string str){
    return str==string(str.rbegin(),str.rend());
}

string incre_string(string s){
    bool carry = true;
    char a;
    int num;

    for(auto i = s.rbegin() ; carry && i != s.rend() ; i++){
        a = *i;
        num = atoi(&a);
        if(++num>9){
            *i='0';
        }else{
            *i='0'+num;
            carry = false;
        }
    }

    if(carry){
        s='1'+s;
    }

    return s;
}

void solve(string input){
    do{
        input = incre_string(input);
    }while(!isPalin(input));

    cout<<input;
}

int main(int argc, char const *argv[])
{
    int k;
    cin>>k;

    vector<string> input(k);

    for(int i = 0 ; i < k ; i++){
        cin>>input[i];
    }

    for(int i = 0 ; i < k ; i++){
        solve(input[i]);
        cout<<endl;
    }

    return 0;
}