#include<bits/stdc++.h>
using namespace std;

// struct TrieNode{
//     // char c;
    
//     // next.fill()
//     TrieNode():next(26,nullptr){};
// };

class Trie {
private:
    vector<Trie *> root;
    bool is_end;
public:
    /** Initialize your data structure here. */
    
    Trie():root(26,nullptr),is_end(false){}
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie *q = this;
        for(char i: word){
            if(q->root[i-'a']==nullptr){
                q->root[i-'a'] = new Trie();
            }
            q = q->root[i-'a'];
        }
        if(q->is_end==false)q->is_end=true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie *q = this;
        for(char i: word){
            if(q->root[i-'a']==nullptr){
                return false;
            }
            q = q->root[i-'a'];
        }
        
        return q->is_end;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie *q = this;
        for(char i: prefix){
            if(q->root[i-'a']==nullptr){
                return false;
            }
            q = q->root[i-'a'];
        }
        return true;
        // return find_if(s.begin(),s.end(),[=](string str){return str.rfind(prefix,0)==0;})!=s.end();
    }
};

int main(){
    
    Trie* obj = new Trie();

    string word = "apple";
    string prefix = "appl";

    obj->insert(word);
    bool param_2 = obj->search(word);
    bool param_3 = obj->startsWith(prefix);

    cout<<param_2<<" "<<param_3;

    return 0;
}