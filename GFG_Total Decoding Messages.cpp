class Solution {
	public:
	const int mod=1e9+7;
	 int solve(string &s,int i,vector<int>&dp)
    {
        if(s[i]=='0')return 0;
        if(i==s.size())return 1;
        if(dp[i]!=-1)return dp[i];
        int res=solve(s,i+1,dp);
        if(i<s.size()-1&&(s[i]=='1'||s[i]=='2'&&s[i+1]<'7'))res=(res+solve(s,i+2,dp))%mod;
        return dp[i]= res%mod;
        
    }
		int CountWays(string s){
		    // Code here
		  //  int n=s.size();
		   
		   vector<int>dp(s.size()+1,-1);
		   
        return solve(s,0,dp);
        
        
		}

};
