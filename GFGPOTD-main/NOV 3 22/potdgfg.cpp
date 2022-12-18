//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{

    public:

    int n, res = INT_MAX;

    vector<vector<int>> dp;

    int fun(vector<int> &arr, int s, int e, int k, int ans){

        if(s >= n || e < 0){

            return INT_MAX;

        }

        if(dp[s][e] != -1){

            return min(dp[s][e], res);

        }

        if(arr[e] - arr[s] <= k){

            res = min(ans, res);

            return res;

        }

        dp[s][e] = fun(arr, s+1, e, k, ans+1);

        dp[s][e] = fun(arr, s, e-1, k, ans+1);

    }

    int removals(vector<int>& arr, int k){

        sort(begin(arr), end(arr));

        n = arr.size();

        dp.resize(n, vector<int> (n, -1));

        int minn = arr[0], maxx = arr[n-1];

        if(maxx - minn <= k){

            return 0;

        }

        fun(arr, 0, n-1, k, 0);

        return res;

    }

};


//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        
        Solution ob;
        int ans = ob.removals(arr,k);
        
        cout<<ans<<endl;
    }
}



// } Driver Code Ends
