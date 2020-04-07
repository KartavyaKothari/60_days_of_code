#include <bits/stdc++.h>

using namespace std;

enum Priority {add,sub,mul,division,power};
stack<char> operands;

int priority(char op){
    switch(op){
        case '+':return add;
        case '-':return sub;
        case '*':return mul;
        case '/':return division;
        case '^':return power;
    }
}

void solve(string exp){
    char op_old;
    char op_new;
    // string exp;
    // cin>>exp;
    // vector<char> infix(exp.begin(),exp.end());

    for(auto i : exp){
        // cout<<i;
        op_new = i;
        if(i=='('){
            operands.push('(');
            continue;
        }
        
        if(i==')'){
            while(!operands.empty()){
                if(operands.top()=='('){operands.pop();break;}
                cout<<operands.top();
                operands.pop();
            }
            continue;
        }
        
        if(isalpha(op_new)){
            // cout<<"[print "<<op_new<<"]";
            cout<<op_new;
            continue;
        }

        if(operands.empty()){
            // cout<<"[Pushing "<<op_new<<"]";
            operands.push(op_new);
            continue;
        }

        op_old = operands.top();
        
        while(priority(op_new)<priority(op_old)){
            // cout<<"["<<op_new<<" lower than "<<op_old<<" popping "<<op_old<<"]";
            cout<<operands.top();
            operands.pop();
            if(operands.empty())break;
            op_old = operands.top();
        }

        // cout<<"[ pushing "<<op_new<<"]";
        operands.push(op_new);
    }

    while(!operands.empty()){
        // cout<<"[Popping .. "<<operands.top()<<"]";
        cout<<operands.top();
        operands.pop();
    }
}

struct Node{
    char op;
    bool isAlpha;
    Node* left;
    Node* right;

    Node(char c,bool isAlpha):op(c),isAlpha(isAlpha),left(NULL),right(NULL){};
    Node(Node *n){
        op = n->op;
        isAlpha = n->isAlpha;
        left = n->left;
        right = n->right;
    }
    Node(char c,bool isAlpha,Node *left, Node *right):op(c),isAlpha(isAlpha),left(left),right(right){};
};

class Tree{
    public:
    Node *head;

    Tree(){
        head=NULL;
    }

    bool isEmpty(){
        if(head==NULL){
            return true;
        }else return false;
    }

    int precedence(Node *n){
        char op = n->op;

        return priority(op);
    }

    void swap(Node *one, Node *two){
        Node *temp = new Node(one);

        one->op = two->op;
        one->isAlpha = two->isAlpha;
        one->left = two->left;
        one->right = two->right;

        two->op = temp->op;
        two->isAlpha = temp->isAlpha;
        two->left = temp->left;
        two->right = temp->right;
    }

    void addNode(Node *n){
        if(isEmpty()){
            head = n;
            return;
        }

        if(n->isAlpha){
            addAlphaNode(head,n);
        }else addOperatorNode(head,n);
    }

    void addAlphaNode(Node *treeN, Node *newN){
        if(treeN->left==NULL){
            treeN->left = newN;
        }else if(treeN -> right == NULL){
            treeN->right = newN;
        }else addAlphaNode(treeN->right,newN);
    }

    void addOperatorNode(Node *treeN, Node *newN){
        if(treeN->isAlpha){
            swap(treeN,newN);
            treeN->left=newN;
            // return newN;
        }else if(precedence(newN)<precedence(treeN)){
            swap(treeN,newN);
            treeN->left=newN;
            // return newN;
        }else addOperatorNode(treeN->right,newN);
    }

    void postorder(Node *n){
        if(n==NULL)return;
        postorder(n->left);
        postorder(n->right);
        cout<<n->op;
    }

    void printPostorder(){
        if(!isEmpty()){
            postorder(head);
        }
    }
};

void solveUsingTrees(string exp){
    Tree *tree = new Tree();
    
    for(auto i : exp){
        Node *n = new Node(i,isalpha(i));
        tree->addNode(n);
    }

    tree->printPostorder();
}

int main(int argc, char const *argv[])
{
    int n;

    cin>>n;
    vector<string> exps;
    string temp;

    for(int i = 0 ; i < n ; i++){
        cin>>temp;
        exps.push_back(temp);
    }

    for(auto i : exps){
        // solve(i);
        solveUsingTrees(i);
        cout<<endl;
    }

    return 0;
}