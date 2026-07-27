

class Solution {
  public:
    // Function to return list of integers visited in snake pattern in matrix.
    vector<int> snakePattern(vector<vector<int> > matrix) {
        // code here
        int row = matrix.size();
        int col = matrix[0].size();
        vector<int> result(row*col);
        int p=0;
        int r=0;
        int c=0;
        while(p<row*col)
        {
            for(int i=0;i<col;i++)
            {
                result[p]=matrix[r][i];
                p++;
            }
            r++;
            if(p >= (row*col))
                break;
            for(int i=col-1;i>=0;i--)
            {
                result[p]=matrix[r][i];
                p++;
            }
            r++;
        }
        return result;
    }
    
};