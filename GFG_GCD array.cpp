class Solution {
  public:
int solve(int n, int k, vector<int> &arr) {
        // Calculate presum
        int preSum[n];
        preSum[0] = arr[0];
        for(int i=1;i<n;i++) preSum[i] = arr[i] + preSum[i-1];
        
        // Find all factors of entire arr sum
        vector<int> factors;
        int sum = preSum[n-1];
        
        for(int i=1;i<=sqrt(sum);i++) {
            if(sum%i == 0) {
                factors.push_back(i);
                // if divisors are not equal add them
                if(i != sum/i) factors.push_back(sum/i);
            }
        }
        
        // Iterate thorugh factors of preSum and check whether the factor divides the k subarrays
        int maxi = INT_MIN;
        for(auto i: factors) {
            int c = 0;
            
            for(int j=0;j<n;j++) {
                if(preSum[j] % i == 0) c++;
            }
            
            if(c >= k) {
                maxi = max(maxi, i);
                c = 0;
            }
        }
        
        return maxi;
    }
};
