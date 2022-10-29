#include <bits/stdc++.h>

using namespace std;

class Solution{
public:
    class Node{
        
        vector<Node*> links;
        vector<string> prefix;
        
        public:
        
        Node()
        {
            links.resize(26, nullptr);
        }
        
        Node* get(char ch)
        {
            return links[ch - 'a'];
        }
        
        void put(char ch, Node* node)
        {
            links[ch - 'a'] = node;
        }
        
        bool isPresent(char ch)
        {
            if(links[ch - 'a'] == nullptr)
            {
                return false;
            }
            
            return true;
        }
        
      //for every prefix the word will be inserted.
        void insertWord(string str)
        {
            prefix.push_back(str);
        }
        
        vector<string> getWord()
        {
            return prefix;
        }
        
    };
    
    class Trie{
        
        Node* root;
        
        public:
        
        Trie()
        {
            root = new Node();
        }
        
        void insert(string s)
        {
            Node* curr = root;
            
            for(int i=0; i<s.length(); i++)
            {
                if(!curr->isPresent(s[i]))
                {
                    curr->put(s[i], new Node());
                }
                
                curr = curr->get(s[i]);
                curr->insertWord(s);
            }
            
        }
        
        vector<vector<string>> find(string str)
        {
            Node* curr = root;
            vector<vector<string>> ans;
            int i=0;
            
            for(i=0; i<str.length(); i++)
            {
                if(!curr->isPresent(str[i]))
                {
                    break;
                }
                else
                {
                    curr = curr->get(str[i]);
                    
                    vector<string> pre = curr->getWord();
                    
                    sort(pre.begin(), pre.end());
                    ans.push_back(pre);
                }
            }
            
            while(i<(str.length()))
            {
                ans.push_back({"0"});
                i++;
            }
            
            return ans;
            
        }
        
    };
//     vector<vector<string>> displayContacts(int n, string contact[], string s)
//     {
//         // code here
        
//         Trie* trie = new Trie();
//         set<string> st;
        
//         for(int i=0; i<n; i++)
//         {
//             st.insert(contact[i]);
//         }
        
//         for(auto x: st)
//         {
//             trie->insert(x);
//         }
        
//         return trie->find(s);
//     }
};

int main(){
    
    return 0;
}
