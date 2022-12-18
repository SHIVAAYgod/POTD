bool hamiltonpath(int i,vector<int> adj[],vector<int> &vis,vector<int> &ans)
    {
        if(ans.size()==vis.size()) return true;
        vis[i]=1;
        for(int j:adj[i])
        {
            if(!vis[j])
            {
                ans.push_back(j);
                if(hamiltonpath(j,adj,vis,ans)) return true;
                ans.pop_back();
            }
        }
        vis[i]=0;
        return false;
    }
    bool check(int N,int M,vector<vector<int>> Edges)
    {
      vector<int> adj[N];
      vector<int> vis(N,0);
      for(int i=0;i<M;i++)
      {
          int u=Edges[i][0]-1;
          int v=Edges[i][1]-1;
          adj[u].push_back(v);
          adj[v].push_back(u);
      }
      
      for(int i=0;i<N;i++)
      {
        vector<int> ans;      
       ans.push_back(i);
       if(hamiltonpath(i,adj,vis,ans)) return true;
       
      }
      return false;
        
    }
