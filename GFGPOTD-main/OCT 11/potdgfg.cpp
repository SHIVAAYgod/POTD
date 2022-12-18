class Solution{
public:
    string decodedString(string s){
        stack<string> st;
        st.push("]");
        int i=s.size()-2;
        int flag=0;
        string result="";
        
        while(i>=0)
        {
            if(isdigit(s[i])==0) 
            {
                string a="";
                a+=s[i];
                st.push(a);
                i--;
            }
            else
            {
                int count=1;
                int x=0;
                while(i>=0 and isdigit(s[i]))
                {
                   x=x+(s[i]-'0')*count;    
                   count*=10;
                   i--;
                }
                st.pop();
                string res="";
                string ans="";
                while(st.top()!="]")
                {
                    res+=st.top();
                    st.pop();
                }
                st.pop();
                while(x>0)
                {
                    ans+=res;
                    x--;
                }
                st.push(ans);
            }
        }
        while(!st.empty()){
         result+=st.top();
         st.pop();}
        
        return result;
        
    }
};
