#include<bits/stdc++.h>
using namespace std;

void fill_queue(stack<int> &q_front, stack<int> &q_back){
    while(!q_back.empty()){
        q_front.push(q_back.top());
        q_back.pop();
    }
}

int main(){
    int q;
    cin>>q;

    stack<int> q_front;
    stack<int> q_back;

    int op;
    int val;

    while(q--){
        cin>>op;

        switch(op){
            case 1:
                cin>>val;
                q_back.push(val);
                break;
            case 2:
                if(q_front.empty())fill_queue(q_front,q_back);
                // cout<<q_front.top();
                q_front.pop();
                break;
            case 3:
                if(q_front.empty())fill_queue(q_front,q_back);
                cout<<q_front.top()<<endl;
                break;
        }
    }
} 