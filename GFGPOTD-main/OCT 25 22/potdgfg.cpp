class Solution
{
  public:
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        vector<int> ans;
        deque<int> dq;
        for(int i=0;i<n;i++)
        {
           if(!dq.empty() and dq.front()==i-k) dq.pop_front();
           while(!dq.empty() and arr[dq.back()]<=arr[i])
           {
               dq.pop_back();
           }
           dq.push_back(i);
           if(i>=k-1) ans.push_back(arr[dq.front()]);
        }
        return ans;
    }
};
