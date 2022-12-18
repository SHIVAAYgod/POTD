//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> satisfyEqn(int A[], int N) {
       map<int,pair<int,int>> m;
       vector<int> ans(4,-1);
       vector<vector<int>> res;
       for(int i=0;i<N;i++)
       {
           for(int j=i+1;j<N;j++)
           {
               int pair_sum=A[i]+A[j];
               if(m.find(pair_sum)==m.end())
               {
                   m[pair_sum]={i,j};
               }
               else
               {
                   if(m[pair_sum].first==i || m[pair_sum].first==j || m[pair_sum].second==i || m[pair_sum].second==j) continue;
                   else{
                    ans[2]=i;
                    ans[3]=j;
                    ans[0]=m[pair_sum].first;
                    ans[1]=m[pair_sum].second;
                    res.push_back(ans);
                   }
               }
           }
       }
       if(res.size()==0) return {-1,-1,-1,-1};
       sort(res.begin(),res.end());
       return res[0];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        int A[N];
        
        for(int i=0; i<N; i++)
            cin>>A[i];

        Solution ob;
        vector<int> ptr = ob.satisfyEqn(A,N);
        
        cout<<ptr[0]<<" "<<ptr[1]<<" "<<ptr[2]<<" "<<ptr[3]<<endl;
    }
    return 0;
}
// } Driver Code Ends
