//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
long long int dp[10001];
    long long int solve(int n){
        if(n == 0){
            return 1;
        }
        if(n<0){
            return 0;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        long long int a = solve(n-1);
        long long int b = (n-1)*solve(n-2);
        return dp[n] = (a+b)%1000000007;
    }
    
    int countFriendsPairings(int n) 
    { 
        // code here
        memset(dp,-1,sizeof(dp));
        return solve(n);
    }
};    
 

//{ Driver Code Starts.
int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	Solution ob;
    	cout <<ob.countFriendsPairings(n); 
    	cout<<endl;
    }
} 

// } Driver Code Ends
