class Solution {
  public:
    void solve(string s,int &op,int &fl)
    {
        if(!s.length())return ;
            if(fl==0 && s.substr(0,s.length()/2)==s.substr(s.length()/2))
            {
                fl=1;
                op+=s.length()/2+1;
                return ;
            }
            else
            {
                op++;
                solve(s.substr(0,s.length()-1),op,fl);
            }
    }
    int minOperation(string s) {
        int op=0,fl=0;
        solve(s,op,fl);
        return op;
    }
};
