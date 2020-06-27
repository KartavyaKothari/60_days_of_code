#include<bits/stdc++.h>
using namespace std;

static int speed = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Case{
    public:
    string seats;
    int k;
};

int find_seats(int gap, int k){
    if(gap<(2*k+1))return 0;
    return (gap-(2*k+1))/(k+1)+1;
}

void solve(string seats, int k){
    int gap = 0;
    bool last_occu = false;
    int sol = 0;

    int st = 0;
    while(seats[st]=='0'&&st<seats.size())st++;
    if(st>k)sol++;
    sol+=find_seats(st-1,k);

    if(st>=seats.size()){
        if(sol == 0)cout<<1;
        else cout<<sol;
        return;
    }

    for(int i = st ; i < seats.size() ; i++){
        if(last_occu){
            gap = 0;
            if(seats[i]=='0'){
                gap++;
                last_occu=false;
            }
        }else{
            if(seats[i]=='0'){
                gap++;
            }else{
                last_occu=true;
                sol += find_seats(gap,k);
            }
        }
    }

    if(gap>k)sol++;
    sol+=find_seats(gap-1,k);

    cout<<sol;
}

int main(){
    int t;
    cin>>t;

    vector<Case> cases(t);

    int a,b;
    for(int i = 0 ; i < t ; i++){
        cin>>a>>b;
        cin>>cases[i].seats;
        cases[i].k=b;
    }

    for(int i = 0 ; i < t ; i++){
        solve(cases[i].seats,cases[i].k);
        cout<<endl;
    }

    return 0;
}