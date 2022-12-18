class Solution {
  long long int mod=1e9+7;
  public:
    long long int f(int x,int y,int z,long long int val,vector<vector<vector<long long int>>> dp)
    {
        if(x==0 && y==0 && z==0)
         return 0;
        if(dp[x][y][z]!=-1) return dp[x][y][z]; 
        long long int m=0;
        long long int n=0;
        long long int p=0;
        if(x>=1)
        {
          long long int a=((val*10)%mod+4)%mod;
          m=a;
          m+=f(x-1,y,z,a,dp);
        }
        if(y>=1)
        {
            long long int b=((val*10)%mod+5)%mod;
            n=b;
            n+=f(x,y-1,z,b,dp);
        }
        if(z>=1)
        {
            long long int c=((val*10)%mod+6)%mod;
            p=c;
            p+=f(x,y,z-1,c,dp);
        }
        return dp[x][y][z]=(m%mod+n%mod+p%mod)%mod;
    }
    long long int getSum(int X, int Y, int Z) {
        long long int val=0;
        vector<vector<vector<long long int>>> dp(X+1,vector<vector<long long int>>(Y+1,vector<long long int> (Z+1,-1)));
        return f(X,Y,Z,val,dp)%mod;
    }
};
