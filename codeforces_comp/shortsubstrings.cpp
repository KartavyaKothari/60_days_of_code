#include<bits/stdc++.h>
using namespace std;

static int speed = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Case{
    public:
    string a;
};

void solve(string a){
    if(a.size()==2){
        cout<<a;
        return;
    }

    string b = "";

    for(int i = 1; i < a.size()-1 ; i+=2){
        b+=a[i];
    }

    cout<<a[0]<<b<<a.back();
}

int main(){
    int t;
    cin>>t;

    vector<string> cases(t);

    int a,b;
    for(int i = 0 ; i < t ; i++){
        cin>>cases[i];
    }

    for(int i = 0 ; i < t ; i++){
        solve(cases[i]);
        cout<<endl;
    }

    return 0;
}