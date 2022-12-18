class Solution {
  public:
    vector<int> reverseSpiral(int R, int C, vector<vector<int>>&a)  {
       int i=0;
       int j=0;
       vector<int> v;
       while(i<R and j<C and a[i][j]!=-1)
       {
           while(j<C and a[i][j]!=-1)
           {
                  v.push_back(a[i][j]);
                  a[i][j]=-1;
                  j++;
           }
           i++;
           j--;
           while(i<R and a[i][j]!=-1)
           {
               v.push_back(a[i][j]);
               a[i][j]=-1;
               i++;
           }
           i--;
           j--;
           while(j>=0 and a[i][j]!=-1)
           {
               v.push_back(a[i][j]);
               a[i][j]=-1;
               j--;
           }
           j++;
           i--;
           while(i>=0 and a[i][j]!=-1)
           {
               v.push_back(a[i][j]);
               a[i][j]=-1;
               i--;
           }
           i++;
           j++;
       }
       reverse(v.begin(),v.end());
       return v;
    }
};
