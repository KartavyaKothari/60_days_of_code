#include <bits/stdc++.h>

using namespace std;

enum Priority {power,division,mul,sub,add};
stack<char> operands;

int priority(char op){
    switch(op){
        case '^':return power;
        case '/':return division;
        case '*':return mul;
        case '-':return sub;
        case '+':return add;
    }
}

void solve(){
    char op_old;
    char op_new;
    string exp;
    cin>>exp;
    // vector<char> infix(exp.begin(),exp.end());

    for(auto i : exp){
        // cout<<i;
        op_new = i;
        if(i=='('){
            operands.push('(');
            continue;
        }
        if(i==')'){
            while(true){
                if(operands.empty())break;
                if(operands.top()=='('){operands.pop();break;}
                cout<<operands.top();
                operands.pop();
            }
            continue;
        }
        if(isalpha(op_new)){
            cout<<op_new;
        }else{
            if(operands.empty()){
                operands.push(op_new);
            }else{
                op_old = operands.top();
                if(priority(op_new)<priority(op_old)){
                    operands.push(op_new);
                }else{
                    while(priority(op_new)>=priority(op_old)){
                        cout<<operands.top();
                        operands.pop();
                        if(operands.empty())break;
                        op_old = operands.top();
                    }
                    operands.push(op_new);
                }
            }
        }
    }

    while(!operands.empty()){
        cout<<operands.top();
        operands.pop();
    }
}

int main(int argc, char const *argv[])
{
    int n;

    cin>>n;

    while(n--){
        solve();
        cout<<endl;
    }

    return 0;
}
