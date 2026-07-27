
class Solution
{
public:
    //Function to count the number of ways in which frog can reach the top.
    long long countWaysRecur(int n, int m, int steps[])
    {
        if (n == 0) {
            return 1;
        }

        if (n < 0) {
            return 0;
        }

        if (m < 0) {
            return 0;
        }
        return countWaysRecur(n - steps[m - 1], m, steps) + countWaysRecur(n, m - 1, steps);
    }

    long long countWaysMemoRecur(int n, int m, int steps[], vector<vector<long long>>& dp)
    {
        if (n == 0) {
            return 1;
        }

        if (n < 0) {
            return 0;
        }

        if (m <= 0) {
            return 0;
        }

        if (dp[n][m] == -1) {
            dp[n][m] = 0;
            for (int i = 0; i < m; i++) {
                dp[n][m] = (dp[n][m] + countWaysMemoRecur(n - steps[i], m, steps, dp)) % 1000000007;
            }
        }
        return dp[n][m];
    }

    long long countWaysMemo(int n, int m, int steps[])
    {
        vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, -1));

        return countWaysMemoRecur(n, m, steps, dp);
    }

    long long countWays(int n)
    {
        // your code here
        int steps[] = { 1,2,3 };
        //memoi time O(n*m) O(n*m)
        return countWaysMemo(n, 3, steps);
        //navie time O(3^n) O(n)
        return countWaysRecur(n, 3, steps);
    }
};