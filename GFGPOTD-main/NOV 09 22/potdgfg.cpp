//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
	int mini=INT_MAX;
    // void f(int i,int arr[],int n,int sum,int targetsum)
    // {
    //     if(i==n)
    //     {
    //      mindiff=min(abs(2*sum-targetsum),mindiff);
    //      return;
    //     }
    //     f(i+1,arr,n,sum+arr[i],targetsum);
    //     f(i+1,arr,n,sum,targetsum);
    // }
	int minDifference(int arr[], int n)  { 
	    int targetsum=0;
	     for(int i=0;i<n;i++)
	     targetsum+=arr[i];
	    vector<vector<int>> dp(n,vector<int> (targetsum+1,0));
	    for(int i=0;i<n;i++)
	     dp[i][0]=1;
	    if(arr[0]<=targetsum)
	     dp[0][arr[0]]=1;
	     
	    for(int i=1;i<n;i++)
	    {
	       for(int target=1;target<=targetsum;target++)
	       {
	           bool take=false;
	           bool notake=dp[i-1][target];
	           if(arr[i]<=target)
	            take=dp[i-1][target-arr[i]];
	           dp[i][target]=take|notake;
	       }
	    }
	    for(int i=0;i<=targetsum/2;i++)
	    {
	        if(dp[n-1][i]==true)
	        {
	            mini=min(mini,abs(2*i-targetsum));
	        }
	    }
	    
	    return mini;

	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends
