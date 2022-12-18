
class Solution{
public:
    int findMin(int n, char a[]){
        int red=0;
        int blue=0;
        int green=0;
        for(int i=0;i<n;i++)
        {
           if(a[i]=='R') red++;
           if(a[i]=='G') green++;
           if(a[i]=='B') blue++;
        }
        if(red==n and green==n and blue==n) return n;
        if((red%2==0 and green%2==0 and blue%2==0)||(red%2==1 and green%2==1 and blue%2==1))
         return 2;
        else
         return 1;
    }
};
