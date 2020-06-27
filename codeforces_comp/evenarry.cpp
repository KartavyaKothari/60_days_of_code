#include<bits/stdc++.h>
using namespace std;

static int speed = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Case{
    public:
    vector<int> arr;
};

void solve(vector<int> arr){
    int even_parity = 0;
    int odd_parity = 0;

    for(int i = 0 ; i < arr.size() ; i+=2){
        if(arr[i]%2==1)even_parity++;   
    }

    for(int i = 1 ; i < arr.size() ; i+=2){
        if(arr[i]%2==0)odd_parity++;
    }

    cout<<(even_parity==odd_parity?even_parity:-1);
}

int main(){
    int t;
    cin>>t;

    vector<Case> cases(t);

    int a,b;
    for(int i = 0 ; i < t ; i++){
        cin>>a;
        vector<int> arr(a);
        for(int j = 0 ; j < a ; j++){
            cin>>arr[j];
        }
        cases[i].arr = arr;
    }

    for(int i = 0 ; i < t ; i++){
        solve(cases[i].arr);
        cout<<endl;
    }

    return 0;
}