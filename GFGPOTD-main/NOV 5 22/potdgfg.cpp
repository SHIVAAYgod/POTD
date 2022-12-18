/***************PEGION HOLE PRINCIPLE**********************************/

//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int maxGroupSize(int arr[], int N, int K) {
        vector<int> rem(K,0);
        for(int i=0;i<N;i++)
        rem[arr[i]%K]++;
        
        int i=1,j=K-1,ans=0;
        while(i<j){
            ans+=max(rem[i],rem[j]);
            i++;
            j--;
        }
        if(i==j && rem[i]>0)
        ans+=1;
        
        if(rem[0]>0)
        ans+=1;
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,K;
        
        cin>>N>>K;
        int arr[N];
        
        for(int i=0; i<N; i++)
            cin>>arr[i];

        Solution ob;
        cout << ob.maxGroupSize(arr,N,K) << endl;
    }
    return 0;
}
// } Driver Code Ends
