class Solution{
    public:
    //Function to count the frequency of all elements from 1 to N in the array.
 void frequencyCount(vector<int>& arr,int n, int p)
    { 
      //actually p is the max possible number present in array    
      for(int i=0;i<n;i++)
      {
          arr[i]--;//since its 1 based indexing therfore on getting k as arr[i] ,count for aarr[k-1] must be incremented
          if(arr[i]%p<n) // since max possible element can be p therefore taking modulus p will get us the original number-1 at that index
          //we only update at indexes<n and ignore rest of the elements
          {
              int original_index_to_be_incremented=arr[i]%p;
              arr[ original_index_to_be_incremented] += p; //number of times we add p to the element of that index will be the frequency of that index 
          }
      }
      //to get the frequency we find the number of times p was added to the element at that index
      for(int i=0;i<n;i++)
      {
          arr[i]/=p;
      }
    }
};
