//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct val{
	int first;
	int second;
};


// } Driver Code Ends
/*
The structure to use is as follows
struct val{
	int first;
	int second;
};*/

class Solution{
public:
    /*You are required to complete this method*/
int maxChainLen(struct val vp[],int n){
    sort(vp, vp + n, [](auto a, auto b){
        return a.second < b.second;
    });
    int prev = INT_MIN, res = 0;
    for(int x = 0; x < n; x++){
        if(vp[x].first > prev){
            prev = vp[x].second;
            res++;
        }
    }
    return res;
}
};

//{ Driver Code Starts.

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		val p[n];
		for(int i=0;i<n;i++)
		{
			cin>>p[i].first>>p[i].second;
		}
		Solution ob;
		cout<<ob.maxChainLen(p,n)<<endl;
	}
	return 0;
}
// } Driver Code Ends
