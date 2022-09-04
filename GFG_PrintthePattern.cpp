class Solution{
public:
vector<string> pattern(int n){
       // code here
       int count = 1;
       vector<string> ans;
       for(int i = 1;i<=n;i++){
           string temp = "";
           for(int j = 1;j<=n;j++){
               if(j<i){
                   temp+="--";
               }
               else{
               temp+=to_string(count);
               if(j!=n)temp+="*";
               count++;
               }
           }
           ans.push_back(temp);
       }
       for(int i = n-1;i>=0;i--){
           string temp = ans[i];
           for(int j = 0;j<n-i;j++){
               temp += "*";
               temp+=to_string(count);
               count++;
           }
           ans[i] = temp;
       }
       return ans;
   }
};
