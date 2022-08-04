//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class TrieNode {

    public: 
        char data;
        TrieNode* children[26];
        bool isTerminal;

        TrieNode(char ch) {
            data = ch;
            for(int i=0; i<26; i++) {
                children[i] = NULL;
            }
            isTerminal = false;
        }
};

class Trie {

    public:
        TrieNode* root;    

        Trie() {
            root = new TrieNode('\0');
        }

        void insertUtil(TrieNode* root, string word) {
            // base case
            if(word.length() == 0) {
                root->isTerminal = true;
                return;
            }

            //assumption: word will be in all CAPS.
            int index = word[0] - 'a';
            TrieNode* child;

            if(root->children[index] != NULL) { //present
                child = root->children[index];

            } else { //absent
                child = new TrieNode(word[0]);
                root->children[index] = child;

            }

            //Revursive calls
            insertUtil(child, word.substr(1));
        }

        void insertWord(string word) {
            insertUtil(root, word);
        }
        
        
        void printsuggestion(TrieNode* curr, vector<string>& temp,string prefix){
            
            if(curr->isTerminal){
                temp.push_back(prefix);
            }
            
            for(char ch='a';ch<='z';ch++){
                TrieNode* next = curr->children[ch-'a'];
                
                if(next!=NULL){
                    prefix.push_back(ch);
                    printsuggestion(next,temp,prefix);
                    prefix.pop_back();
                }
            }
        }
        
        
        vector<vector<string>> getsuggestions(string ch){
            TrieNode* prev = root;
            vector<vector<string>> output;
            
            string prefix="";
            
            for(int i=0;i<ch.length();i++){
                char last = ch[i];
                prefix.push_back(last);
                
                //check for last
                TrieNode* curr= prev->children[last-'a'];
                //absent
                
                if(curr==NULL){
                    break;
                }
                
                else{
                    vector<string> temp;
                    printsuggestion(curr,temp,prefix);
                    output.push_back(temp);
                    temp.clear();
                    prev=curr;
                }
            }
            return output;
        }
        
};


vector<vector<string>> phoneDirectory(vector<string>&contactList, string &queryStr)
{
    //    Write your code here.
 Trie* T = new Trie();
        
        for(int i=0;i<contactList.size();i++){
        string str = contactList[i];
        T->insertWord(str);
    }
    
    return T->getsuggestions(queryStr);

    
}