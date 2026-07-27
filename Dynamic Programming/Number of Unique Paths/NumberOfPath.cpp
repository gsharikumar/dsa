//User function template in C++

class Solution
{
public:
    //Function to find total number of unique paths.
    int ta;
    int tb;

    int NumberOfPathRecur(int a, int b) {
        if (a == 0 && b == 0) {
            return 1;
        }
        if (a < 0 || b < 0) {
            return 0;
        }
        return (NumberOfPathRecur(a - 1, b) + NumberOfPathRecur(a, b - 1));
    }

    int NumberOfPathMemoRecur(int a, int b, vector<vector<int>>& dp) {
        if (a == 0 && b == 0) {
            dp[0][0] = 1;
            return 1;
        }
        if (a < 0 || b < 0) {
            if (a >= 0) {
                dp[a][0] = 0;
            }
            if (b >= 0) {
                dp[0][b] = 0;
            }
            return 0;
        }
        if (dp[a][b] == -1) {
            dp[a][b] = (NumberOfPathMemoRecur(a - 1, b, dp) + NumberOfPathMemoRecur(a, b - 1, dp));
        }
        return dp[a][b];
    }

    int NumberOfPathMemo(int a, int b) {
        //return NumberOfPathRecur(a,b);
        vector<vector<int>> dp(a + 1, vector<int>(b + 1, -1));
        return NumberOfPathMemoRecur(a, b, dp);
    }


    int NumberOfPath(int a, int b)
    {
        //code here
        ta = a;
        tb = b;
        return NumberOfPathMemo(a - 1, b - 1);
    }
};