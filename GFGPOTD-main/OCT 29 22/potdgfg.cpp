//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
// struct Trie
// {
//     struct Trie *link[26];
//     bool flag=false;
//     bool containskey(char ch)
//     {
//         return (ch-'a'!=NULL);
//     }
//     void put(char ch,Node *node)
//     {
//         link[ch-'a']=node;
//     }
//     Trie* get(char ch)
//     {
//         return link[ch-'a'];
//     }
//     void endofword(Trie *node)
//     {
//         node->flag=true;
//     }
    
    
// }

class Solution{
    // Trie *root;
public:
    // Solution()
    // {
    //     root=new Trie();
    // }
    // void insert(string s)
    // {
    //     Node* node=new Trie();
        
    //     for(int i=0;i<s.size();i++)
    //     {
    //         if(!node->containskey(s[i]))
    //         {
    //             node->put(s[i],new Trie());
                
    //         }
    //         node->get(s[i]);
    //     }
    //     node->endofword(node);
    // }
    bool search(string s,int i,string t)
    {
        for(int k=0;k<=i;k++)
        {
            if(s[k]!=t[k]) return false;
         }
         return true;
    }
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
     int m=s.size();
    //  for(int i=0;i<n;i++)
    //  {
    //      insert(contact[i]);
    //  }
     
     vector<vector<string>> ans;
     for(int i=0;i<s.size();i++)
     {
         vector<string> store;
         unordered_set<string> m;
         for(int j=0;j<n;j++)
         {
           if(m.find(contact[j])==m.end() and search(s,i,contact[j])){ store.push_back(contact[j]);
              m.insert(contact[j]);
           }
         }
         if(store.size()==0){ store.push_back("0");}
         else sort(store.begin(),store.end());
         ans.push_back(store);
     }
     return ans;
     
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string contact[n], s;
        for(int i = 0;i < n;i++)
            cin>>contact[i];
        cin>>s;
        
        Solution ob;
        vector<vector<string>> ans = ob.displayContacts(n, contact, s);
        for(int i = 0;i < s.size();i++){
            for(auto u: ans[i])
                cout<<u<<" ";
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends
