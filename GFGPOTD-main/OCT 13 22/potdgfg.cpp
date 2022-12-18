class Solution
{
   public:
    int findSum(int A[], int N)
    {
        int m=INT_MAX;
        int M=INT_MIN;
    	for(int i=0;i<N;i++)
    	{
    	    m=min(A[i],m);
    	    M=max(A[i],M);
    	}
    	return m+M;
    }

};
