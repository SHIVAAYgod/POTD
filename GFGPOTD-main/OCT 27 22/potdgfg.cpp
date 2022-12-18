class Node{
    public:
        int data;
        Node* left;
        Node* right;
    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};
class Solution {
    Node* Creation(Node* root,int val){
        if(root == NULL){
            root = new Node(val);
            return root;
        }
        
        if(root->data > val){
            root->left = Creation(root->left,val);
            return root;
        }else{
            root->right = Creation(root->right,val);
            return root;
        }
    }
    void LeafNode(Node* root,vector<int>& arr){
        if(root == NULL){
            return;
        }
        
        if(root->left == NULL && root->right == NULL){
            arr.push_back(root->data);
        }
        
        LeafNode(root->left,arr); 
        LeafNode(root->right,arr); 
    }
  public:
    vector<int> leafNodes(int arr[],int N) {
        Node* root = NULL;
        
        for(int i = 0 ; i < N ; i++){
            root = Creation(root,arr[i]);
        }
        
        vector<int> ans;
        LeafNode(root,ans);
        
        return ans;
    }
};
