//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
string buildLowestNumber(string num, int k);
// Driver program to test above function
int main()
{
    int t,n;
    string str;
    cin>>t;
    while(t--)
    {
    cin>>n;
    cin>>str;
    cout << buildLowestNumber(str, n)<<endl;
    }
    return 0;
}

// } Driver Code Ends


string buildLowestNumber(string num, int k)
{
    deque<char> s;
    for(char ch:num)
    {
        if(s.empty() || s.back()<ch)
         s.push_back(ch);
        else
        {
         while(k>0 and !s.empty() and s.back()>ch )
         {
             s.pop_back();
             k--;
         }
         s.push_back(ch);
        } 
    }
    while(k>0 || (s.size()>1 && s.front()=='0'))
    {
     if(k>0)    
      s.pop_back();
     else
      s.pop_front();
     k--; 
    }
    return string(s.begin(),s.end());
}
