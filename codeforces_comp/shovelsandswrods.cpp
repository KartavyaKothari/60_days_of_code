#include<bits/stdc++.h>
using namespace std;

class Case{
    public:
    int a,b;
};

void solve(int sticks, int diamonds){
    int max1 = max(sticks,diamonds);
    int min1 = sticks+diamonds-max1;
// cout<<max1<<" "<<min1;
    int diff = max1-min1;
    int em = 0;

    if(diff<min1){
        max1 = max1 - diff*2;
        min1 = min1 - diff;
        em+=diff;
    }else{
        cout<<min1;
        return;
    }

    em += (min1/3)*2;
    min1=min1%3;
    max1=max1%3;

    min1 = min(min1,max1);

    switch(min1){
        case 1:
            if(max1>=2)em++;
            break;
        case 2:
            em++;
            break;
    }

    cout<<em;
}

int main(){
    int t;
    cin>>t;

    vector<Case> cases(t);

    int a,b;
    Case c;
    for(int i = 0 ; i < t ; i++){
        cin>>c.a>>c.b;
        cases[i]=c;
    }

    for(int i = 0 ; i < t ; i++){
        solve(cases[i].a,cases[i].b);
        cout<<endl;
    }

    return 0;
}