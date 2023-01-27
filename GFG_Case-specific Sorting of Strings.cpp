class Solution
{
    public:
    //Function to perform case-specific sorting of strings.
  string caseSort(string str, int n)
    {
        string up = "";
        string lo = "";
        string res = "";
        for(int i = 0;i < n;i++){
            if(str[i] >= 'a' && str[i] <= 'z')
                lo += str[i];
            else
                up+= str[i];
        }
        sort(up.begin(),up.end());
        sort(lo.begin(),lo.end());
        int u = 0;
        int l = 0;
        for(int i = 0;i < n;i++){
            if(str[i] >= 'a' && str[i] <= 'z')
                res += lo[l++];
            else
                res += up[u++];
        }
        return res;
    }
};
