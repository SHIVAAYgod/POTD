struct alphanumeric {
    string name;
    int count;
};
class Solution {
  public:
    vector<alphanumeric> sortedStrings(int N, vector<string> v) {
       map<string,int> m;
       vector<alphanumeric> s;
       for(int i=0;i<N;i++)
        {
            if(m.find(v[i])==m.end())
            {
                m[v[i]]=1;
            }
            else
             m[v[i]]++;
        }
        for(auto itr=m.begin();itr!=m.end();itr++)
        {
            s.push_back({itr->first,itr->second});
        }
        return s;
    }
};
