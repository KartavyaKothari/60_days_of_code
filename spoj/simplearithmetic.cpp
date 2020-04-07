#include <bits/stdc++.h>

using namespace std;

int max(initializer_list<int> list){
    int max = 0;

    for(auto i : list){
        if(i>max){
            max=i;
        }
    }

    return max;
}

string generateDashes(int n){
    string s = "";

    s.insert(0,n,'-');

    return s;
}

string trimPrefixZeros(string input){
    for(int i = 0 ; i < input.length() ; i++){
        if(input[i]=='0'){
            continue;
        }else return string(input.begin()+i,input.end());
    }
    
    return "0";
}

bool isBlank(char ch){
    if(ch==' ')return true;
    return false;
}

string add(string exp1, string exp2){
    int exp1_len = exp1.length();
    int exp2_len = exp2.length();
    string result;

    replace_if(exp1.begin(),exp1.end(),isBlank,'0');
    replace_if(exp2.begin(),exp2.end(),isBlank,'0');

    if(exp1_len>exp2_len){
        exp2.insert(0,exp1_len-exp2_len,'0');
    }else{
        exp1.insert(0,exp2_len-exp1_len,'0');
    }

    result = exp1;

    int carry = 0;
    int t_sum = 0;

    for( int i = exp1.length() - 1 ; i >= 0 ; i-- ){
        t_sum = exp1[i] - '0' + exp2[i] - '0' + carry;
        carry = t_sum/10;
        result[i] = t_sum%10 + '0';
    }

    if(carry != 0){
        char prefix = carry+'0';
        return prefix+result;
    }

    return trimPrefixZeros(result);
}

string sub(string exp1, string exp2){
    int exp1_len = exp1.length();
    int exp2_len = exp2.length();
    string result;

    if(exp1_len>exp2_len){
        exp2.insert(0,exp1_len-exp2_len,'0');
    }else{
        exp1.insert(0,exp2_len-exp1_len,'0');
    }

    result = exp1;

    int t_sub = 0;

    for( int i = exp1.length() - 1 ; i >= 0 ; i-- ){
        if(exp1[i]>exp2[i]){
            t_sub = (exp1[i] - '0') - (exp2[i] - '0');
            result[i]=t_sub+'0';
        }else if(exp1[i]<exp2[i]){
            t_sub = (exp1[i] - '0') - (exp2[i] - '0') + 10;
            result[i]=t_sub+'0';

            // Decrement preceeding string as we borrowed

            for(int j = i-1 ; j >= 0 ; j--){
                if(exp1[j]=='0'){
                    exp1[j]='9';
                    continue;
                }else{
                    exp1[j]=exp1[j]-1;
                    break;
                }
            }
        }else result[i]='0';
    }

    return trimPrefixZeros(result);
}

vector<string> mul(string exp1, string exp2){
    vector<string> intermediate_res;
    int exp1_len = exp1.length();
    int exp2_len = exp2.length();
    string temp_result;

    for(int i = exp2.length() - 1 ; i >= 0 ; i--){
        temp_result = exp1;
        int carry = 0;
        int t_mul = 0;
        int b = exp2[i]-'0';

        for( int j = exp1.length() - 1 ; j >= 0 ; j-- ){
            t_mul = ((exp1[j] - '0') * b) + carry;
            carry = t_mul/10;
            temp_result[j] = t_mul%10 + '0';
        }

        if(carry > 0){
            char a = carry + '0';
            intermediate_res.push_back(a+temp_result);
        } else intermediate_res.push_back(trimPrefixZeros(temp_result));
    }

    return intermediate_res;
}

string pad(int n, string s){
    return s.insert(0,n-s.length(),' ');
}

void subRepresentation(string exp1,string exp2){
    int exp1_len = exp1.length();
    int exp2_len = exp2.length();

    string result = sub(exp1,exp2);
    int result_len = result.length();
    exp2='-'+exp2;
    int m = max({exp1_len,exp2_len+1,result_len});
    cout
        <<pad(m,exp1)<<endl
        <<pad(m,exp2)<<endl
        <<generateDashes(max({exp2_len+1,result_len}))<<endl
        <<pad(m,result)<<endl;
}

void addRepresentation(string exp1,string exp2){
    int exp1_len = exp1.length();
    int exp2_len = exp2.length();

    string result = add(exp1,exp2);
    int result_len = result.length();
    exp2='+'+exp2;
    int m = max({exp1_len,exp2_len+1,result_len});
    cout
        <<pad(m,exp1)<<endl
        <<pad(m,exp2)<<endl
        <<generateDashes(max({exp2_len+1,result_len}))<<endl
        <<pad(m,result)<<endl;
}

void mulRepresentation(string exp1,string exp2){
    vector<string> intermediate_res = mul(exp1,exp2);

    string prev = "0";

    int exp1_len = exp1.length();
    int exp2_len = exp2.length();

    int res_len = intermediate_res[0].length();

    intermediate_res.insert(intermediate_res.begin(),generateDashes(max({exp2_len+1,res_len})));
    intermediate_res.insert(intermediate_res.begin(),"*"+exp2);
    intermediate_res.insert(intermediate_res.begin(),exp1);

    if(exp2.length()>1){
        for(int i = 3 ; i < intermediate_res.size() ; i++){
            prev = add(prev,intermediate_res[i].insert(intermediate_res[i].length(),i-3,' '));
        }

        int end_len = intermediate_res.back().length();
        int prev_len = prev.length();

        intermediate_res.insert(intermediate_res.end(),generateDashes(max({end_len,prev_len})));
        intermediate_res.insert(intermediate_res.end(),prev);
    }

    int m = 0;
    int l = 0;

    for(int i = 0 ; i < intermediate_res.size() ; i++){
        // intermediate_res[i]=trimPrefixZeros(intermediate_res[i]);
        l=intermediate_res[i].length();
        m = max({m,l});
    }

    for(int i = 0 ; i < intermediate_res.size() ; i++){
        cout<<pad(m,intermediate_res[i])<<endl;
    }
}

void solve(string exp){
    char op;
    int index;
    string exp1;
    string exp2;
    
    for(int i = 0 ; i < exp.length() ; i ++){
        if(exp[i]=='*'||exp[i]=='-'||exp[i]=='+'){
            op = exp[i];
            exp1 = string(exp.begin(),exp.begin()+i);
            exp2 = string(exp.begin()+i+1,exp.end());
            break;
        }
    }

    switch(op){
        case '+': 
            addRepresentation(exp1,exp2);
            break;
        case '-':
            subRepresentation(exp1,exp2);
            break;
        case '*':
            mulRepresentation(exp1,exp2);
            break;
    }
}

int main(int argc, char const *argv[])
{
    int n;
    cin>>n;

    vector<string> exps(n);

    for(int i = 0 ; i < n ; i++){
        cin>>exps[i];
    }

    for(int i = 0 ; i < n ; i++){
        solve(exps[i]);
        cout<<endl;
    }

    return 0;
}