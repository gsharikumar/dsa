
class Solution {
  public:
    // Function to add two matrices.
    vector<vector<int> > sumMatrix(const vector<vector<int> >& A,
                                   const vector<vector<int> >& B) {
        // code here
        
        int rowA = A.size();
        int colA = A[0].size();
        int rowB = B.size();
        int colB = B[0].size();
        if(rowA != rowB || colA != colB)
        {
            return vector<vector<int> >(0,vector<int>(0));
        }
        int row = rowA;
        int col = colA;
        vector<vector<int>> P(row,vector<int>(col)); 
        for(int r = 0;r < row; r++)
            for(int c = 0;c < col; c++)
                P[r][c] = A[r][c] + B[r][c];
        return P;
    }
};