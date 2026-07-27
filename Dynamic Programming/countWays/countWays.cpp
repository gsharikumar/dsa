

class Solution
{
    public
    Function to count the number of different ways in which n can be 
    written as a sum of two or more positive integers.
    int countWays(int n)
    {
         your code here
        vectorvectorint dp(n+1,vectorint(n,0));
        
        for(int i=0;in;i++){
            dp[0][i]=1;            
        }
        for(int i=1;i=n;i++){
            dp[i][0]=0;
        }
        
        for(int i=1;i=n;i++){
            for(int j=1;jn;j++){
                dp[i][j]=dp[i][j-1];
                if((i-j)=0){
                    dp[i][j]+=dp[i-j][j];
                }
            }
        }
        return dp[n][n-1];
    }
};