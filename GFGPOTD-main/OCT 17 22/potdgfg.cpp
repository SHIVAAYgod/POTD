class Solution{
    public:
    vector<int> findLeastGreater(vector<int>& arr, int n) {
        vector<int> v;
        set<int> s;
        for(int i=n-1;i>=0;i--)
        {
            auto upper=s.upper_bound(arr[i]);
            if(upper==s.end())
             v.push_back(-1);
            else
             v.push_back(*upper);
            s.insert(arr[i]); 
        }
        reverse(v.begin(),v.end());
        return v;
    }
};
