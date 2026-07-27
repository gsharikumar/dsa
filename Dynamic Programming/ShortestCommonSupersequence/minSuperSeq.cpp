//User function template for C++


class Solution
{
public:
    //Function to find length of shortest common supersequence of two strings.

    int lcsDPMemoRecur(int x, int y, string s1, string s2, vector<vector<int>>& dp)
    {
        if (x == 0 && y == 0) {
            dp[x][y] = 0;
            return 0;
        }

        if (dp[x][y] == INT_MIN)
        {
            int res = 0;
            if ((s1[x - 1] == s2[y - 1]) && (x > 0 && y > 0)) {
                //match found
                res = 1 + lcsDPMemoRecur(x - 1, y - 1, s1, s2, dp);
            }
            else {
                int res1 = 0;
                int res2 = 0;
                if (x > 0) {
                    res1 = lcsDPMemoRecur(x - 1, y, s1, s2, dp);
                }
                if (y > 0) {
                    res2 = lcsDPMemoRecur(x, y - 1, s1, s2, dp);
                }
                res = max(res1, res2);
            }
            dp[x][y] = res;
        }
        return dp[x][y];
    }

    int shortestCommonSupersequenceDPMemo(int x, int y, string s1, string s2)
    {
        vector<vector<int>> dp(x + 1, vector<int>(y + 1, INT_MIN));

        return lcsDPMemoRecur(x, y, s1, s2, dp);
    }

    int shortestCommonSupersequence(string X, string Y, int m, int n)
    {
        //code here
        int lcs = shortestCommonSupersequenceDPMemo(m, n, X, Y);
        return (lcs + m - lcs + n - lcs);

    }
};