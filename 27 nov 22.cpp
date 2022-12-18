//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
string addBinary(string A, string B)
	{
	   int n;
	   int m;
	   n=A.size();
	   m=B.size();
	   int i=n-1;
	   int j=m-1;
	   int c=0;
	   string ans="";
	   while(i>=0 and j>=0)
	   {
	      
	       if((A[i]=='1' and B[j]=='0') || (A[i]=='0' and B[j]=='1'))
	       {
	          if(c==1) 
	          {
	           ans+="0";
	           c=1;
	          }
	          else
	           ans+="1";
	       }
	       else if(A[i]=='1' and B[j]=='1')
	       {
	          if(c==1) 
	          {
	           ans+="1";
	           c=1;
	          }
	          else
	          {
	           ans+="0";
	           c=1;
	          }
	       }
	       else
	       {
	           if(c==1) ans+="1";
	           else ans+="0";
	           c=0;
	       }
	       i--;
	       j--;
	    }
	    while(i>=0)
	    {
	        if(c==1 and A[i]=='0')
	        {
	          c=0;
	          ans+='1';
	        }
	        else if(c==1 and A[i]=='1')
	          ans+='0';
	        else 
	        {
	          ans+=A[i];
	          c=0;
	        }
	        i--;
	    }
	    while(j>=0)
	    {
	        if(c==1 and B[j]=='0')
	        {
	          c=0;
	          ans+='1';
	        }
	        else if(c==1 and B[j]=='1')
	          ans+='0';
	        else 
	        {c==0;
	         ans+=B[j];
	        }
	        j--;
	    }
	    if(c==1)
	     ans+='1';
	    int x=ans.size()-1;
	    while(ans[x]=='0')
	    {
	       ans.erase(x,1);
	       x=ans.size()-1;
	    }
	    reverse(ans.begin(),ans.end());
	    return ans;
	}
};

//{ Driver Code Starts.

int main()
{
	int t; cin >> t;
	while (t--)
	{
		string A, B; cin >> A >> B;
		Solution ob;
		cout << ob.addBinary (A, B);
		cout << "\n";
	}
}

// Contributed By: Pranay Bansal

// } Driver Code Ends
