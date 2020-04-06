#include <bits/stdc++.h>

using namespace std;

enum Priority {add,sub,mul,division,power};
stack<char> operands;

int priority(char op){
    switch(op){
        case '+':return add;
        case '-':return sub;
        case '*':return mul;
        case '/':return division;
        case '^':return power;
    }
}

void solve(string exp){
    char op_old;
    char op_new;
    // string exp;
    // cin>>exp;
    // vector<char> infix(exp.begin(),exp.end());

    for(auto i : exp){
        // cout<<i;
        op_new = i;
        if(i=='('){
            operands.push('(');
            continue;
        }
        
        if(i==')'){
            while(!operands.empty()){
                if(operands.top()=='('){operands.pop();break;}
                cout<<operands.top();
                operands.pop();
            }
            continue;
        }
        
        if(isalpha(op_new)){
            // cout<<"[print "<<op_new<<"]";
            cout<<op_new;
            continue;
        }

        if(operands.empty()){
            // cout<<"[Pushing "<<op_new<<"]";
            operands.push(op_new);
            continue;
        }

        op_old = operands.top();
        
        while(priority(op_new)<priority(op_old)){
            // cout<<"["<<op_new<<" lower than "<<op_old<<" popping "<<op_old<<"]";
            cout<<operands.top();
            operands.pop();
            if(operands.empty())break;
            op_old = operands.top();
        }

        // cout<<"[ pushing "<<op_new<<"]";
        operands.push(op_new);
    }

    while(!operands.empty()){
        // cout<<"[Popping .. "<<operands.top()<<"]";
        cout<<operands.top();
        operands.pop();
    }
}

int main(int argc, char const *argv[])
{
    int n;

    cin>>n;
    vector<string> exps;
    string temp;

    for(int i = 0 ; i < n ; i++){
        cin>>temp;
        exps.push_back(temp);
    }

    for(auto i : exps){
        solve(i);
        cout<<endl;
    }

    return 0;
}