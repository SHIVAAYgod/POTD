class Solution{
public:	
	// Converts arr[0..n-1] to reduced form.
void convert(int arr[], int n) {
     // code here
     vector<int>ans;
     for(int i=0;i<n;i++){
         ans.push_back(arr[i]);
     }
     sort(ans.begin(),ans.end());
     map<int,int>mp;
     for(int i=0;i<n;i++){
         mp[ans[i]]=i;
     }
     for(int i=0;i<n;i++){
         arr[i]=mp[arr[i]];
 
     }

};
