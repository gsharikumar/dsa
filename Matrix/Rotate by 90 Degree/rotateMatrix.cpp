class Solution {
  public:
    void swap(int &a, int &b)
    {
        int tmp = a;
        a = b;
        b = tmp;
    }
    void rotateMatrix(vector<vector<int>>& mat) {
        // code here
        int s;
        int row = mat.size();
        int col = mat[0].size();
        int i=0;
        int r = 0;
        int c = 0;
        vector<vector<int>> out(row,vector<int>(col));
        
        
        for(r = 0; r < row; r++ )
        {
            for(c = 0; c < col; c++ )
            {
                out[col-c-1][r] = mat[r][c];       
            }
        }
        
        for(r = 0; r < row; r++ )
        {
            for(c = 0; c < col; c++ )
            {
                mat[r][c] = out[r][c];
            }
        }
#if 0        
        while(r<row && c<col )
        {
            
        }
        
        
        while(r<row && c<col )
        {
            int ct=c;
            while(c<col)
            {
                swap(mat[r][c],mat[col-c-1][r]);
                c++;
            }
            r++;
            c=ct+1;
        }
#endif
    }

};