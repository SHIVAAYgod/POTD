//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	long long int NoOfChicks(int n){
	    if(n==1) return 1;
	    long long int prev=1;
	    long long int curr;
	    int x=0;
	    
	    vector<long long int> v;
	    v.push_back(0);
	    v.push_back(1);
	    for(int i=2;i<=n;i++)
	    {
	        if(i<7) 
	        {
	            curr=prev*3;
	        }
	        else if(i==7) 
	        {
	            curr=(prev-1)*3;
	        }
	        else
	        {
	            curr=3*prev-2*v[i-6];
	        }
	        prev=curr;
	        v.push_back(prev);
	    }
	    int res=v.size()-1;
	    return v[res];
	    
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution obj;
		long long int ans = obj.NoOfChicks(N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends
