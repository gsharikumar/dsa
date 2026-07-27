// function to find longest common subsequence

class Solution
{
public:
    //Function to find the length of longest common subsequence in two strings.

    int lcsDPNaiveRecur(int x, int y, string s1, string s2)
    {
        if (x == 0 && y == 0) {
            return 0;
        }
        int res = 0;
        if ((s1[x - 1] == s2[y - 1]) && (x > 0 && y > 0)) {
            //match found
            res = 1 + lcsDPNaiveRecur(x - 1, y - 1, s1, s2);
        }
        else {
            int res1 = 0;
            int res2 = 0;
            if (x > 0) {
                res1 = lcsDPNaiveRecur(x - 1, y, s1, s2);
            }
            if (y > 0) {
                res2 = lcsDPNaiveRecur(x, y - 1, s1, s2);
            }
            res = max(res1, res2);
        }

        return res;
    }

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

    int lcsDPMemo(int x, int y, string s1, string s2)
    {
        vector<vector<int>> dp(x + 1, vector<int>(y + 1, INT_MIN));

        return lcsDPMemoRecur(x, y, s1, s2, dp);
    }

    int lcsDPTabu(int x, int y, string s1, string s2)
    {
        vector<vector<int>> dp(x + 1, vector<int>(y + 1, 0));

        for (int i = 0; i <= x; i++) {
            dp[i][0] = 0;
        }

        for (int i = 0; i <= y; i++) {
            dp[0][i] = 0;
        }

        for (int i = 1; i <= x; i++) {
            for (int j = 1; j <= y; j++) {
                if (s1[i - 1] == s2[i - 1]) {
                    dp[i][j] = 1 + dp[i][j];
                }
                else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[x][y];
    }

    int lcs(int x, int y, string s1, string s2)
    {
        // your code here
        //return lcsDPTabu(x, y, s1, s2);
        return lcsDPMemo(x, y, s1, s2);

        return lcsDPNaiveRecur(x, y, s1, s2);
    }
};