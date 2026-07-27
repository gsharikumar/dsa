

class Solution {
  public:
    // Function to search a given number in row-column sorted matrix.
    bool searchMatrix(vector<vector<int>> &mat, int x) {
        // code here
        int col = mat[0].size();
        int row = mat.size();
        bool bFound = false;
        //find the row where the element could be present
        int r = 0;
        int c = col-1;

        while( r < row && c >= 0)
        {
            if(mat[r][c] == x)
            {
                bFound = true;
                break;
            }
            else if(mat[r][c] > x)
            {
                c--;
            }
            else 
            {
                r++;
            }
        }

#if 0
        for(;r<row;r++)
        {
            if((x >= mat[r][0]) && (x <= mat[r][col-1]))
            {
                break;
            }
        }
        for(;c<col;c++)
        {
            if(x == mat[r][c])
            {
                bFound = true;
                break;
            }
        }
#endif
        return bFound;
        
    }
};