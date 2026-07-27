//Complete this function

class Solution
{
public:
    //Function to find the minimum number of coins to make the change 
    //for value using the coins of given denominations.

    long long minNumCoinsRecur(int coins[], int numberOfCoins, int value)
    {
        if (numberOfCoins == 0 || value < 0) {
            return -1;
        }
        if (value == 0) {
            return 0;
        }
        long long resInclude;
        long long resNotInclude;
        long long res;
        resInclude = minNumCoinsRecur(coins, numberOfCoins, value - coins[numberOfCoins - 1]);
        resNotInclude = minNumCoinsRecur(coins, numberOfCoins - 1, value);
        if (resInclude == -1 && resNotInclude != -1) {
            res = resNotInclude + 1;
        }
        else if (resNotInclude == -1 && resInclude != -1) {
            res = resInclude + 1;
        }
        else if (resNotInclude == -1 && resInclude == -1) {
            res = -1;
        }
        else {
            res = 1 + min(resNotInclude, resInclude);
        }
        return res;
    }

    long long minNumCoinsMemoWrongDirection(int coins[], int numberOfCoins, int value, long long dp[])
    {
        if (numberOfCoins == 0 || value < 0) {
            return -1;
        }
        int idx = numberOfCoins * value;
        if (value == 0) {
            dp[idx] = 0;
            return 0;
        }
        if (dp[idx] == -1)
        {
            long long resInclude;
            long long resNotInclude;
            long long res;
            resInclude = minNumCoinsMemo(coins, numberOfCoins, value - coins[numberOfCoins - 1], dp);
            resNotInclude = minNumCoinsMemo(coins, numberOfCoins - 1, value, dp);
            if (resInclude == -1 && resNotInclude != -1) {
                res = resNotInclude + 1;
            }
            else if (resNotInclude == -1 && resInclude != -1) {
                res = resInclude + 1;
            }
            else if (resNotInclude == -1 && resInclude == -1) {
                res = -1;
            }
            else {
                res = 1 + min(resNotInclude, resInclude);
            }
            dp[idx] = res;
        }
        return dp[idx];
    }

    long long minNumCoinsMemo(int coins[], int numberOfCoins, int value, long long dp[])
    {
        if (numberOfCoins == 0 || value < 0) {
            return INT_MAX;
        }

        if (value == 0) {
            dp[value] = 0;
            return 0;
        }
        if (dp[value] == INT_MAX)
        {
            long long res = INT_MAX;

            for (int i = 0; i < numberOfCoins; i++) {
                res = minNumCoinsMemo(coins, numberOfCoins, value - coins[i], dp);
                if (res != INT_MAX) {
                    dp[value] = min(res + 1, dp[value]);
                }
            }
        }
        return dp[value];
    }


    long long minimumNumberOfCoins(int coins[], int numberOfCoins, int value)
    {
        // your code here

        //memoization
        long long dp[value + 1] = { -1 };
        for (int i = 0; i <= value; i++) {
            dp[i] = INT_MAX;
        }
        //dp[0] = 0;
        long long res = minNumCoinsMemo(coins, numberOfCoins, value, dp);
        if (res == INT_MAX) {
            return -1;
        }
        else {
            return res;
        }
        //naive approach
        return minNumCoinsRecur(coins, numberOfCoins, value);


    }
};