#include<bits/stdc++.h>
using namespace std;

static int speed = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Case{
    public:
    int n,x;
    vector<pair<int, int>> ops;
};

void solve(vector<pair<int,int>> ops, int n, int x){
    int k_cnt = 0;
    // set<int> nums;
    vector<bool> is_one(n+1,0);
    is_one[x] = true;
    int max_int = INT_MIN;
    int min_int = INT_MAX;

    int i = 0;
    while(i<ops.size()&&(x<ops[i].first||x>ops[i].second))i++;

    bool is_first_run = true;

    min_int = ops[i].first;
    max_int = ops[i].second;

    bool has_one = false;
    while(i<ops.size()){
        has_one = false;
        // cout<<min_int<<" "<<max_int<<endl;
        // cout<<ops[i].first<<" "<<ops[i].second<<endl<<endl;
        if(is_first_run==false)
            if(min_int<=ops[i].first&&max_int>=ops[i].second){
                i++;
                continue;}

            if(min_int>=ops[i].first&&max_int<=ops[i].second)
                min_int = ops[i].first,max_int = ops[i].second;
            
            if(min_int<=ops[i].first&&max_int<=ops[i].second)ops[i].first = max_int,max_int=ops[i].second;
            else if(min_int>=ops[i].first&&max_int>=ops[i].second) ops[i].second = min_int,min_int=ops[i].first;
        else is_first_run = false;

        // for(int j = ops[i].first ; j <= ops[i].second ; j++){
        //     nums.insert(j);
        // }
        
        for(int j = ops[i].first ; j <= ops[i].second ; j++){
            if(is_one[j]==true){
                has_one=true;
                break;
            }
        }

        if(has_one){
            for(int j = ops[i].first ; j <= ops[i].second ; j++){
                if(is_one[j]==false){
                    is_one[j]=true;
                    k_cnt++;
                }
            }
        }

        i++;
    }

    cout<<k_cnt+1;
    // cout<<nums.size();
    return;

    // for(auto row: ops){
    //     cout<<row.first<<" "<<row.second<<endl;
    // }
}

int main(){
    int t;
    cin>>t;

    vector<Case> cases(t);

    int n,x,m;
    int a,b;
    for(int i = 0 ; i < t ; i++){
        cin>>n>>x>>m;
        vector<pair<int, int>> case_(m);
        for(int j = 0 ; j < m ; j++){
            cin>>a>>b;
            case_[j] = {a,b};
        }
        cases[i].ops = case_;
        cases[i].n = n;
        cases[i].x = x;
    }

    for(int i = 0 ; i < t ; i++){
        solve(cases[i].ops,cases[i].n,cases[i].x);
        cout<<endl;
    }

    return 0;
}