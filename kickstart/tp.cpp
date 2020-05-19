#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int sign[2] = {1,-1};

    int t;
    cin>>t;
    
    int n,k;
    
    vector<pair<vector<int>,vector<tuple<char,int,int>>>> cases(t);
    
    for(int i = 0 ; i < t ; i++){
        cin>>n>>k;
        vector<int> case_i(n);
        vector<tuple<char,int,int>> queries(k);
        for(int j = 0 ; j < n ; j++){
            cin>>case_i[j];
        }
        for(int j = 0 ; j < k ; j++){
            cin>>get<0>(queries[j])>>get<1>(queries[j])>>get<2>(queries[j]);
        }
        cases[i].first = case_i;
        cases[i].second = queries;
    }
    int sum = 0;
    int sum_temp = 0;

    vector<int> arr;
    vector<tuple<char,int,int>> queries;

    for(int q = 0 ; q < t ; q++){
        arr = cases[q].first;
        queries = cases[q].second;

        sum = 0;
        sum_temp = 0;

        for(int i = 0 ; i <= queries.size() ; i++){
            char op = get<0>(queries[i]);
            int a = get<1>(queries[i]);
            int b = get<2>(queries[i]);

            switch(op){
                case 'U':
                    arr[a-1]=b;
                    break;
                case 'Q':
                    sum_temp = 0;

                    for(int i = 0 ; i <= b-a ; i++){
                        sum_temp+=arr[a+i-1]*sign[i%2]*(i+1);
                    }
                    
                    sum+=sum_temp;
                    break;
            }
        }

        cout<<"Case #"<<(q+1)<<": "<<sum<<endl;
    }
    
    return 0;
}