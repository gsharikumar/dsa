class Solution {
  public:
    vector<vector<int>> transpose(vector<vector<int>>& mat) {
        // code here

        int row = mat.size();
        int col = mat[0].size();
        vector<vector<int>> result(col,vector<int>(row));
        for(int r = 0;r<row;r++)
        {
            for(int c = 0;c<col;c++)
            {
                result[c][r] = mat[r][c];
            }
        }
        return result;
    }
};