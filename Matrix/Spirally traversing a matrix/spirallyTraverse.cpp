class Solution {
  public:
    vector<int> spirallyTraverse(vector<vector<int>> &mat) {
        // code here
        int row = mat.size();
        int col = mat[0].size();
        int tot = row*col;
        vector<int> out=vector<int>(tot);
        int r = 0;
        int c = 0;
        
        int top = 0;
        int bottom=row-1;
        int left = 0;
        int right = col-1;
        int i = 0;
        int j = 0;
        
        while(left<=right && top<=bottom)
        {
            for(c = left; c <= right ;c++ )
            {
                out[i] = mat[top][c];
                i++;
            }
            top++;
            for(r = top ;r <= bottom ;r++ )
            {
                out[i] = mat[r][right];
                i++;
            }
        
            right--;
            if(top <= bottom)
            {
                for(c = right; c >= left ;c-- )
                {
                    out[i] = mat[bottom][c];
                    i++;
                }
            }
            bottom--;
            if(left<=right)
            {
                for(r = bottom; r >= top ;r-- )
                {
                    out[i] = mat[r][left];
                    i++;
                }
            }
            left++;
        }
        return out;
    }
};