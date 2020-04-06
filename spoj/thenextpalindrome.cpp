#include <bits/stdc++.h>
using namespace std;

bool isPalin(string str){
    return str==string(str.rbegin(),str.rend());
}

string incre_string(string s){
    bool carry = true;
    int num;

    for(auto i = s.rbegin() ; carry && i != s.rend() ; i++){
        num = *i-'0';
        if(++num>9){
            *i='0';
        }else{
            *i='0'+num;
            carry = false;
        }
    }

    if(carry){
        return '1'+s;
    } else return s;
}

bool isOdd(string input){
    if(input.length() % 2 == 0 ) return false;
    else return true;
}

bool isAllNines(string input){
    for(auto i = input.begin() ; i != input.end() ; i++){
        if(*i=='9'){
            continue;
        }else{
            return false;
        }
    }

    return true;
}

void solveBetter(string input){
    string firstHalf = string(input.begin(),input.begin() + (input.length()-1)/2+1);

    if(isAllNines(input)){
        cout<<'1';
        for(int i = 0 ; i < input.length() -1 ; i++){
            cout<<'0';
        }
        cout<<'1';
        return;
    }

    if(isPalin(input)){
        firstHalf = incre_string(firstHalf);

        if(isOdd(input)){
            cout<<firstHalf+string(firstHalf.rbegin()+1,firstHalf.rend());
        }else{
            cout<<firstHalf+string(firstHalf.rbegin(),firstHalf.rend());
        }
    }else{
        if(isOdd(input)){
            int i;
            for(i = 0 ; i < firstHalf.length()-1 ; i++){
                if(input[firstHalf.length()-1-i]==input[firstHalf.length()-1+i]){
                    continue;
                }else break;
            }

            if(input[firstHalf.length()-1-i]<input[firstHalf.length()-1+i]){
                firstHalf = incre_string(string(firstHalf.begin(),firstHalf.end()));
                cout<<firstHalf+string(firstHalf.rbegin()+1,firstHalf.rend());
            }else{
                cout<<firstHalf+string(firstHalf.rbegin()+1,firstHalf.rend());
            }
        }else{
            int i;
            for(i = 0 ; i < firstHalf.length() ; i++){
                if(input[firstHalf.length()-1-i]==input[firstHalf.length()+i]){
                    continue;
                }else break;
            }

            if(input[firstHalf.length()-1-i]<input[firstHalf.length()+i]){
                firstHalf = incre_string(firstHalf);
            }

            cout<<firstHalf+string(firstHalf.rbegin(),firstHalf.rend());
        }
    }
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
        solveBetter(input[i]);
        cout<<endl;
    }

    return 0;
}