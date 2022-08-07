//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#define pii pair<int,int>
class Solution
{
    public:
    //Function to find the number of 'X' total shapes.
    int xShape(vector<vector<char>>& grid) 
    {
        // Code here
        int n=grid.size();
        int m=grid[0].size();
        int shape=0;
        int dx[]={-1,1,0,0},dy[]={0,0,-1,1};
        int x,y,nx,ny;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='X'){
                    shape++;
                    queue<pii> qp;
                    qp.push({i,j});
                    while(!qp.empty()){
                        pii frnt = qp.front();
                        qp.pop();
                        x=frnt.first;
                        y=frnt.second;
                        for(int i=0;i<4;i++){
                            nx=x+dx[i];
                            ny=y+dy[i];
                            if(nx>=0 && ny>=0 && nx<n && ny<m && grid[nx][ny]=='X'){
                                qp.push({nx,ny});
                                grid[nx][ny]='O';
                            }
                        }
                    }
                }
            }
        }
        
        return shape;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m, '#'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.xShape(grid);
		cout << ans <<'\n';
	}
	return 0;
}
// } Driver Code Ends
