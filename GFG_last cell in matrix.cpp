class Solution{
    public:
    // 4 direction that can move
    int dx[4] = {0,1,0,-1};
    int dy[4] = {1,0,-1,0};
    
    pair<int,int> endPoints(vector<vector<int>> matrix, int R, int C){
       int m = matrix.size(), n = matrix[0].size();
       int cur_idx =0;
       int x=0,y=0, temp_x =0, temp_y=0;
       
       while(x>=0 and x<m and y>=0 and y<n)
       {
           temp_x = x;
           temp_y = y;
           
           if(matrix[x][y] == 0) // move in right/same direction
           {
               x += dx[cur_idx];
               y += dy[cur_idx];
           }
           // change direction found 1
           else
           {
               cur_idx = (cur_idx+1)%4;
               matrix[x][y] =0;
               x += dx[cur_idx];
               y += dy[cur_idx];
           }
       }
       return {temp_x, temp_y};
        
    }
};
