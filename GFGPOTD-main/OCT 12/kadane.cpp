class Solution{
public:
      string maxSum(string w,char x[], int b[],int n){
          map<char,int> m;
          for(int i=0;i<n;i++)
          {
              m[x[i]]=b[i];
          }
          string res="";
          int bada=0;
          int mres=INT_MIN;
          int i=0;
          int s=0;
          int start=0,end=0;
          for(char ch:w)
          {
             if(m.find(ch)!=m.end())
             {
                 bada+=m[ch];
             }
             else bada+=int(ch);
             if(mres<bada)
             {
                 mres=bada;
                 start=s;
                 end=i;
             }
             if(bada<0)
             {
                 bada=0;
                 s=i+1;
             }
             i+=1;
          }
          for(int j=start;j<=end;j++)
           res+=w[j];
          return res;
      }
};
