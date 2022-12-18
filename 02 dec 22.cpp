//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
     int isItPossible(string s, string t, int m, int n) {
        int i = 0, j = 0;
        if(m != n) return false;
        
        while(i < m || j < n) {
            while(s[i] == '#') i++;
            while(t[j] == '#') j++;
            
            if((i < m && j >= n) || (i >= m && j < n)) return false;
            if(s[i] == 'A') {
                if(i < j || t[j] == 'B') return false;
            }
            else if(s[i] == 'B') {
                if(i > j || t[j] == 'A') return false;
            }
            i++, j++;
        }
        return true;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S, T;
        cin >> S >> T;
        int M = S.length(), N = T.length();
        Solution ob;
        cout << ob.isItPossible(S, T, M, N);
        cout << "\n";
    }
}
// } Driver Code Ends
