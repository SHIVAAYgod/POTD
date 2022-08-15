//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
      
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
          
        // Get the current node's value from the string
        string currVal = ip[i];
          
        // If the left child is not null
        if(currVal != "N") {
            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }
          
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
          
        // If the right child is not null
        if(currVal != "N") {
            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function template for C++
/*
Structure of the node of the tree is as follows 
struct Node {
    struct Node* left, *right;
    int data;
};
*/
class Solution{
  public:
    // function should return the number of turns required to go from first node to second node 
    int NumberOFTurns(struct Node* root, int first, int second)
    {
      Node *lca = LCA(root, first , second  ); 
      
        // When two Nodes will be having a common ancestor then the two might be in a straight line 
        if(lca->data == first || lca->data == second ) {
            pair<int,char> t;
            if(lca->data == first ){
                t = helper(lca , second, -1);
            }
            else{
                t = helper(lca ,first ,-1);
            }
            if(t.first == 0) return -1;
            return t.first;
            
      }
       pair<int,char> turnL = helper(lca , first ,-1);
      pair<int,char> turnR = helper(lca , second ,-1);
     return turnL.first + turnR.first + 1;
           
    }
    Node *LCA (Node *root ,int first , int second ){
        if(root == NULL  )return NULL;
        
        Node *L = LCA(root->left , first , second);
        Node *R = LCA(root->right , first , second);
        
        
        if(L && R) return root;
        
        if(root->data == first || root->data == second) return root;
        if(L) return L;
        return R;
     }
    
    pair<int,char> helper(Node *root , int key1 , int key2 ){
        if( root == NULL ) return {-1,'x'};
        if(root->data == key1 || root->data == key2  ) return { 0, 'o'};
        
        pair<int, char> L = helper(root->left , key1 ,key2);
        pair<int, char> R = helper(root->right , key1 ,key2);
        
        if(L.second == 'o' || L.second == 'l'){
            return {L.first , 'l'};
        }
        else if(L.second == 'r'){
            return {L.first + 1 , 'l'};
        }
        else if(R.second == 'o' || R.second == 'r'){
            return {R.first , 'r'};
        }
        else if(R.second == 'l' ){
            return {R.first + 1 , 'r'};
        }
        return {-1, 'x'};
    } 
};

//{ Driver Code Starts.

int main()
{
    int t;
    struct Node *child;
    scanf("%d ", &t);
    while (t--)
    {
        string s;
        getline(cin,s);
        Node* root = buildTree(s);
        int turn, first, second;
        cin>>first>>second;
        Solution ob;
        if ((turn = ob.NumberOFTurns(root, first, second) ))
            cout<<turn<<endl;
        else 
            cout<<"-1\n";
        cin.ignore();
    }
    return 0;
}

// } Driver Code Ends
