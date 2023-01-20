class Solution
{
  public:
  int maxWeightCell(int N, vector<int> edge)
  {
      int u=0,k=0;
      unordered_map<int,int>m;
      for(int i=0; i<N; i++){
       if(edge[i]==-1)
       continue;
          m[edge[i]]+=i;
          if(u<m[edge[i]]){
             u=m[edge[i]];
             k=edge[i];
          }
          
      }
      return k;
  }
};
