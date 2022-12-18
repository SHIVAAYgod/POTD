//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    int n=grid.size();
	    int m=grid[0].size();
	    vector<vector<int>> ans(n,vector<int>(m,INT_MAX));
	    for(int i=0;i<n;i++)
	    {
	       for(int j=0;j<m;j++)
	       {
	           queue<pair<int,int>> q;
	           q.push({i,j});
	           while(!q.empty())
	           {
	               int i1=q.front().first;
	               int j1=q.front().second;
	               q.pop();
	               if(grid[i1][j1]==1)
	               { 
	                   ans[i][j]=abs(i-i1)+abs(j-j1);
	                   break;
	               }
	               if(j1+1<m ) q.push({i1,j1+1});
	               if(i1+1<n) q.push({i1+1,j1});
	               if(j1>=1) q.push({i1,j1-1});
	               if(i1>=1) q.push({i1-1,j1});
	           }
	          
	       }
	    }
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends
