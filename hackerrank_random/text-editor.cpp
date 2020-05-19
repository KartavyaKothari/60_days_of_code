#include<bits/stdc++.h>
using namespace std;

class TextFile{
    private:
    string text;
    stack<string> undo_stack;
    public:
    TextFile():text(""){}

    void append(string s){
        undo_stack.insert(text);
        text = text+s;
    }

    void delete_end(int k){
        undo_stack.insert(text);
        text = string(text.begin(),text.end()-k);
    }

    void print(int k){
        cout<<text[k-1]<<endl;
    }

    void undo(){
        text = undo_stack.top();
        undo_stack.pop();
    }
}

int main(){
    int num_operations;
    cin>>num_operations;

    TextFile text = new TextFile();
    
    int op;

    while(num_operations--){
        cin>>op;
        switch(op){
            case 1:
                string s;
                text.append(s);
                break;
            case 2:
                int k;
                cin>>k;
                text.delete_end(k);
                break;
            case 3:
                int k;
                cin>>k;
                text.print(k);
                break;
            case 4:
                text.undo();
                break;

        }
    }

    return 0;
}