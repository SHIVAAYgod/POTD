//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    /******************PEGION HOLE PRINCIPLE**************************/
    bool canPair(vector<int> nums, int k) {
       vector<int> res(k,0);
       for(int i=0;i<nums.size();i++)
       {
          res[nums[i]%k]+=1;
       }
       if(res[0]%2!=0) return false; 
       int i=1;
       int j=k-1;
       while(i<=j)
       {
           if(res[i]!=res[j]) return false;
           i++;
           j--;
       }
       return true;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++) cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}
// } Driver Code Ends
