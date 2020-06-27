#include<bits/stdc++.h>
using namespace std;

int findCost(int r1, int c1, int r2, int c2, int n, int x){
    int A = r2-r1+1;
    int B = c2-c1+1;

    return ceil(((2*n-A)/(1.0+x))*(2*n-B));
}

void askQ(int r1,int c1, int r2, int c2){
    cout<<1<<" "<<r1<<" "<<c1<<" "<<r2<<" "<<c2;
}

void solve(int n, int p){
    int cost = 0;
    int count = 0;
    
    vector<vector<bool>> pop(n,vector<bool>(n,0));
    cout<<1<<" "<<1<<" "<<1<<" "<<n<<" "<<n;
    int target;
    cin>>target;
    // cost+=findCost(1,1,n,n,n,target);

    int temp;

    while(count!=target){
        for(int i = 1 ; i <= n ; i++){
            for(int j = 1 ; j <= n ; j++){
                askQ(i,j,i,j);
                cin>>temp;
                // cost+=findCost(i,j,i,j,n,temp);
                if(temp==1){
                    pop[i][j]=true;
                    if(++count==target){i=n;break;}
                }
            }
        }
    }

    cout<<2<<endl;
    for(auto row: pop){
        for(bool i: row)cout<<i<<" ";cout<<endl;
    }
}

int main(){
    int t;
    cin>>t;
    int n,p;

    while(t--){
        cin>>n>>p;
        solve(n,p);
    }
}