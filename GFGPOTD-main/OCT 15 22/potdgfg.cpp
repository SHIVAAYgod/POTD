// User function Template for C++

class Solution {
    vector<int> rows={0,-1,0,1};
    vector<int> cols={-1,0,1,0};
  public:
    // void fun(int i,int j,vector<vector<int>> &grid,vector<vector<int>> &vis,pair<int,int> destination,int &minpath,int count,int n,int m)  
    // {
    //     if(destination.first==i and destination.second==j)
    //      minpath=min(count,minpath);
    //     vis[i][j]=1; 
    //     for(int k=0;k<4;k++)
    //     {
    //         if(i+rows[k]<0 || j+cols[k]<0 || i+rows[k]>=n || j+cols[k]>=m) continue;
    //         if(vis[i+rows[k]][j+cols[k]]==0 and grid[i+rows[k]][j+cols[k]]==1)
    //           fun(i+rows[k],j+cols[k],grid,vis,destination,minpath,count+1,n,m);
    //     }
    //     vis[i][j]=0;
    //     return;
    // }
    
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
                            
       int x=source.first;
       int y=source.second;
       if(grid[x][y]==0) return -1;
       if(x==destination.first and y==destination.second) return 0;
      int m=grid[0].size();
      int N=grid.size();
    //   vector<vector<int>> vis(n,vector<int>(m,0));
    //   int minpath=INT_MAX;
       queue<vector<int>> q;
       q.push({x,y});
       grid[x][y]=0;
       int ans=0;
       while(!q.empty())
       {
           int n=q.size();
           ans++;
           while(n--)
           {
               vector<int> curr=q.front();
               q.pop();
               for(int k=0;k<4;k++)
               {
                   int i=curr[0]+rows[k];
                   int j=curr[1]+cols[k];
                   if(i>=0 and i<N and j>=0 and j<m and grid[i][j]==1)
                   {
                     if(destination.first==i and destination.second==j) return ans;
                     q.push({i,j});
                     grid[i][j]=0;
                   }
               }
           }
       }
       return -1;
    //   fun(x,y,grid,vis,destination,minpath,0,n,m);
    //   if(minpath==INT_MAX) return -1;
    //   return minpath;
    }
};
