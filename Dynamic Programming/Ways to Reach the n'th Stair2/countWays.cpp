

class Solution
{
public:
    //Function to count number of ways to reach the nth stair 
    //when order does not matter.
    long long countWaysRecur(int m, int n, int steps[])
    {
        if (m == 0)
        {
            return 1;
        }
        if (m < 0)
        {
            return 0;
        }
        if (n < 0) {
            return 0;
        }

        long long res = 0;
        res = countWaysRecur(m - steps[n - 1], n, steps) + countWaysRecur(m, n - 1, steps);
        return res;
    }

    long long countWaysMemoRecur(int m, int n, int steps[], vector<vector<long long>>& dp)
    {
        if (m == 0)
        {
            dp[m][n] = 1;
            return 1;
        }
        if (m < 0)
        {
            return 0;
        }
        if (n < 0) {
            return 0;
        }

        if (dp[m][n] == -1) {
            dp[m][n] = countWaysMemoRecur(m - steps[n - 1], n, steps, dp) + countWaysMemoRecur(m, n - 1, steps, dp);
        }
        return dp[m][n];
    }

    long long countWaysMemo(int m, int n, int steps[])
    {
        vector<vector<long long>> dp(m + 1, vector<long long>(n + 1, -1));

        return countWaysMemoRecur(m, n, steps, dp);
    }


    long long countWays(int m)
    {
        // your code here
        int steps[] = { 1,2 };

        return countWaysMemo(m, 2, steps);
        //naive time - 2^m
        //return countWaysRecur(m,2,steps);
    }
};