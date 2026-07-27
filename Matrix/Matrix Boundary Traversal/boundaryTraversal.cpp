
class Solution {
  public:
    // Function to return list of integers that form the boundary
    // traversal of the matrix in a clockwise manner.
    vector<int> boundaryTraversal(vector<vector<int> >& mat) {
        // code here
        int row = mat.size();
        int col = mat[0].size();
        int p = 0;
        vector<int> result(2*(row+col)-4);
        for(int c = 0; c < col; c++)
        {
            result[p] = mat[0][c];
            p++;
        }
        for(int r = 1; r < row; r++)
        {
            result[p] = mat[r][col-1];
            p++;
        }
        for(int c = col-2; c >=0; c--)
        {
            result[p] = mat[row-1][c];
            p++;
        }
        for(int r = row-2; r > 0; r--)
        {
            result[p] = mat[r][0];
            p++;
        }
        return result;
    }
};