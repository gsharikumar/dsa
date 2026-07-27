class Solution
{
public:
    //Function to count number of ways to reach the nth stair.
    int countWaysRecur(int n)
    {
        if (n == 0) {
            return 1;
        }
        if (n < 0) {
            return 0;
        }

        return countWaysRecur(n - 1) + countWaysRecur(n - 2);
    }

    int maxVal;
    int countWaysMemo(int n, vector<int>& dp)
    {
        if (n == 0) {
            dp[n] = 1;
            return 1;
        }
        if (n < 0) {
            return 0;
        }

        if (dp[n] == maxVal) {
            dp[n] = (countWaysMemo(n - 1, dp) + countWaysMemo(n - 2, dp)) % 1000000007;

        }
        return dp[n];
    }

    int countWays(int n)
    {
        // your code here
        //return countWaysRecur(n);
        //memoization
        maxVal = -1;
        vector<int> dp(n + 1, maxVal);
        return countWaysMemo(n, dp);

    }
};
