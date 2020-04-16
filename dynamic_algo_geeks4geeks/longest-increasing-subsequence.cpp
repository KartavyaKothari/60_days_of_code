#include<bits/stdc++.h>
using namespace std;

int overall_max = 0;
vector<int> lis_n(3000);

int lis(vector<int> seq, int index){
    // vector<int> indices;
    // if(index = 0)return 1;

    int max = 0;
    int temp = 0;
    int max_index;

    for(int i = index - 1 ; i >= 0 ; i--){
        if(lis_n[i]==-1){
            temp = lis(seq,i);
            lis_n[i]=temp;
        }else temp = lis_n[i];
        
        if(seq[i]<seq[index]&&temp>max){ 
            max = temp;
            max_index = i;
        }
    }

    if(max+1>overall_max){
        overall_max=max+1;
    }

    return 1+max;
    // return lis()
}

void solve(vector<int> seq){
    vector<bool> lis_subseq(seq.size());

    fill(lis_n.begin(),lis_n.end(),-1);

    lis(seq,seq.size()-1);

    cout<<overall_max;
    // return seq;
}

void print_seq(vector<int> seq){
    for(auto ele: seq){
        cout<<ele<<" ";
    }
}

int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    fill(lis_n.begin(),lis_n.end(),-1);
    vector<vector<int>> sequences(n);

    for(int i = 0 ; i < n ; i++){
        int k;
        cin>>k;
        vector<int> seq(k);
        for(int j = 0 ; j < k ; j++){
            cin>>seq[j];
        }
        
        sequences[i] = seq;
    }

    for(auto seq: sequences){
        overall_max=0;
        solve(seq);
        cout<<endl;
    }

    return 0;
}