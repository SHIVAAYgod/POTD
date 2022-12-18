//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

long long numOfWays(int n, int m);

int main() {
    // code
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        cout << numOfWays(n, m) << endl;
    }
    return 0;
}
// } Driver Code Ends


//Function to find out the number of ways we can place a black and a 
//white Knight on this chessboard such that they cannot attack each other.
int m,n;
vector<int> row={-1,-2,-2,-1,1,2,2,1};
vector<int> col={-2,-1,1,2,2,1,-1,-2};
long long mod=1e9+7;
long long sum(int i,int j)
{
    long long count=m*n-1;
    for(int k=0;k<8;k++)
    {
        if(i+row[k]<0 || i+row[k]>=n || j+col[k]<0 || j+col[k]>=m)
         continue;
        else
         count--;
    }
    return count%mod;
}
long long numOfWays(int N, int M)
{
  m=M;
  n=N;
  long long total_sum=0;
  for(int i=0;i<n;i++)
  {
      for(int j=0;j<m;j++)
      {
          total_sum=(total_sum+sum(i,j))%mod;
      }
  }
  return total_sum;
}
