#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode():val(-1),right(nullptr),left(nullptr){}
    TreeNode(int val):val(val),right(nullptr),left(nullptr){}
    TreeNode(int val, TreeNode *left, TreeNode *right):val(val),right(right),left(left){}
};

class Tree{
private:
    TreeNode *root;
    int nodes;

    void traverse_inorder(TreeNode *head,int k,int depth = 1){
        if(head==nullptr)return;

        if(depth%k==0)swap_children(head);

        traverse_inorder(head->left, k, depth + 1);
        traverse_inorder(head->right, k, depth + 1);
    }

    void print_inorder(TreeNode *head){
        if(head==nullptr)return;

        print_inorder(head->left);
        cout<<head->val<<" ";
        print_inorder(head->right);
    }

    void swap_children(TreeNode *node){
        TreeNode *temp = node->left;
        node->left = node->right;
        node->right = temp;
    }
public:
    Tree(vector<vector<int>> &index){
        queue<TreeNode *> tree;
        int i = 0;

        root = new TreeNode(1);
        tree.push(root);
        
        while(!tree.empty()){
            TreeNode *node = tree.front();
            tree.pop();

            if(index[i][0]!=-1){
                node->left = new TreeNode(index[i][0]);
                tree.push(node->left);
            }

            if(index[i][1]!=-1){
                node->right = new TreeNode(index[i][1]);
                tree.push(node->right);
            }

            i++;
        }
    }

    void swap_queries(vector<int> q){
        for(int i:q){
            traverse_inorder(root,i);
            print_inorder(root);
            cout<<endl;
        }
    }
};

int main(){
    int n;
    cin>>n;
    vector<vector<int>> index(n,vector<int>(2,0));
    for(int i = 0 ; i < n ;i++ ){
        cin>>index[i][0]>>index[i][1];
    }

    int q;
    cin>>q;
    vector<int> query(q);
    for(int i = 0 ; i < q ; i++){
        cin>>query[i];
    }

    Tree t(index);

    t.swap_queries(query);
}