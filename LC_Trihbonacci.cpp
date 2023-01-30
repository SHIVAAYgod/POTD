class Solution {
public:
    int v[38]{0,1,1};
    // this vector v will store the tribonacci values as fasten up the process, it is special property of DP
    int tribonacci(int n) {
        if (n==0) return 0;
        if (v[n]) return v[n];
        // If value already calculated and stored we use it
        else return v[n] = tribonacci(n-1) + tribonacci(n-2) + tribonacci(n-3);
        // we store the value as we go on calculating
    }
};
