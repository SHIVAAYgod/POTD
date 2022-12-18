class Solution{
	
	public:
	vector<int> downwardDigonal(int n, vector<vector<int>> A)
	{
		vector<int> v;
		int i=0;
		int j=0;
		int col=0;
	    while(col<n)
	    {
	        i=0;
	        j=col;
	        while(j>=0 and i<n)
	        {
	            v.push_back(A[i][j]);
	            i++;
	            j--;
	        }
	        col++;
	    }
	    int row=1;
	    while(row<n)
	    {
	        i=row;
	        j=n-1;
	        while(j>=0 and i<n)
	        {
	            v.push_back(A[i][j]);
	            i++;
	            j--;
	        }
	        row++;
	    }
		return v;
	}

};
