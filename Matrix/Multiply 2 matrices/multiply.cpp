class Solution {
  public:
    bool multiplyMatrix(int mat1[4][4], int mat2[4][4], int result[4][4]) {
        // code here
        int row = 4;
        int col = 4;
        
        int mat3[4][4]={{0}};
        bool bRes = true;
        for(int r=0;r<row;r++){
            for(int c=0;c<col;c++){
                for(int i=0;i<row;i++){
                    mat3[r][c] += mat1[r][i] * mat2[i][c];
                }
                if(result[r][c] != mat3[r][c])
                {
                    bRes = false;
                    return bRes;
                }
            }
        }
        return bRes;
    }
};