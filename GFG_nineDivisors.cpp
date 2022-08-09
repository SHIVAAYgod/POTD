//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends

#define ll long long
class Solution{   
public:
    long long int nineDivisors(long long int n){
        ll m = sqrt(n);
        vector<int> isPrime(m+1, true);
        for(ll i=2; i*i<=m; i++)
            for(ll j=i*i; j<=m; j+=i)
                isPrime[j] = false;
        
        vector<ll> primes;
        for(int i=2; i<=m; i++)
            if(isPrime[i]) 
                primes.push_back(i);
                
        ll fac1 = sqrt(sqrt(sqrt(n)));
        ll ans = upper_bound(primes.begin(), primes.end(), fac1) - primes.begin() ;
        
        ans = max(ans, 0ll);
        
        for(ll i=0; i<primes.size(); i++)
        {
            for(ll j=i+1; j<primes.size(); j++)
            {
                if(primes[i]*primes[j] > m) break;
                ans++;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        long long int N;
        cin>>N;
        Solution ob;
        cout << ob.nineDivisors(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends
