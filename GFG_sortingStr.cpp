//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to perform case-specific sorting of strings.
    string caseSort(string str, int n)
    {
        // your code here
        string low="";
        string hig="";
        string res="";
        for(int i=0;i<n;i++)
        {
            if(islower(str[i]))
            {
                low+=str[i];
            }
            else 
            {
                hig+=str[i];
            }
        }
        sort(low.begin(),low.end());
        sort(hig.begin(),hig.end());
        int i=0,j=0;
        for(int k=0;k<n;k++)
        {
            if(islower(str[k]))
            {
                res+=low[i];
                i++;
            }
            else 
            {
                res+=hig[j];
                j++;
            }
        }
        return res;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		string str;
		cin>>str;
		Solution obj;
		cout<<obj.caseSort (str, n)<<endl;
	}
}
// } Driver Code Ends
