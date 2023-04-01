class Solution {
  public:
long long int minOperations(int N) {
        long long ans;
        long long n=N/2;;
    
        if(N%2==1){
            ans=n*(n+1);
        }
        else{
            ans=n*n;
        }
        return ans;
    }
};
