#include<bits/stdc++.h>
using namespace std;

class Heap{
    private:
    vector<int> heap;
    
    int par(int a){
        return (a-1)/2;
    }

    public:
    Heap(){}

    void insert(int ele){
        if(heap.empty()){
            heap.push_back(ele);
            return;
        }

        heap.push_back(ele);
        int index = heap.size()-1;
        int temp;

        while(index && heap[par(index)]>heap[index]){
            temp = heap[par(index)];
            heap[par(index)] = heap[index];
            heap[index] = temp;
            index = par(index);
        }

        return;
    }

    int get_min(){
        return heap[0];
    }

    void delete_ele(int ele){
        int i;

        for(i = 0 ; i < heap.size() ; i++){
            if(ele==heap[i])break;
        }

        heap[i]=heap.back();
        heap.resize(heap.size()-1);

        int temp;

        while(i*2+1<heap.size()){
            if(i && heap[i]<=heap[par(i)]){
                temp = heap[par(i)];
                heap[par(i)] = heap[i];
                heap[i] = temp;
                i = par(i);
            }else if(heap[i]>=heap[i*2+1]){
                temp = heap[i*2+1];
                heap[i*2+1] = heap[i];
                heap[i] = temp;
                i = i*2+1;
            }else break;
        }
    }

    void print_heap(){
        for(int i : heap){
            cout<<i<<" ";
        }cout<<endl;
    }
};

int main(){
    Heap h;

    int n,res,num;

    cin>>n;

    while(n--){
        h.print_heap();
        cin>>res;

        switch(res){
            case 1:
                cin>>num;
                h.insert(num);
                break;
            case 2:
                cin>>num;
                h.delete_ele(num);
                break;
            case 3:
                // cout<<h.get_min()<<endl;
                break;
        }
    }

    return 0;
}
