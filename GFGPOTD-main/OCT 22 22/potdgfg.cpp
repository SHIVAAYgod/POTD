//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    long long int mod=1e8;
  public:
    /**********************MEMOIZATION*************************/
    //long long int f(int w,vector<long long int> &dp)
    //{
    //    if(w==0 || w==1) return w;
    //    if(dp[w]!=-1) return dp[w];
    //    long long int take=0,notake=0;
    //    
    //    take=f(w-1,dp)%mod;
    //    notake=f(w-2,dp)%mod;
    //    return dp[w]=(take+notake)%mod;
    //}
    /*******************TABULATION*********************************/
    long long int fillingBucket(int N) {
        vector<long long int> dp(N+1,-1);
        dp[0]=0;
        dp[1]=1;
        dp[2]=2;
        for(int i=3;i<=N;i++)
        {
            dp[i]=(dp[i-1]+dp[i-2])%mod;
        }
        return dp[N];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;

        Solution ob;
        cout << ob.fillingBucket(N) << endl;
    }
    return 0;
}
// } Driver Code Ends
