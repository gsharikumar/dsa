//User function Template for C++


class Solution
{
public:
    //Function to find out the number of ways to use the coins to
    //sum up to a certain required value.
    long long maxValue;
    long long numberOfWaysMemoRecur(int coins[], int numberOfCoins, int value, vector<vector<long long>> dp)
    {
        if (value == 0) {
            dp[0][numberOfCoins] = 1;
            return 1;
        }
        if (value > 0 && numberOfCoins == 0) {
            dp[value][0] = 0;
            return 0;
        }

        if (value < 0) {
            return 0;
        }

        if (numberOfCoins == 0) {
            return 0;
        }

        if (dp[value][numberOfCoins] == maxValue) {
            long long res = 0;
            res += numberOfWaysMemoRecur(coins, numberOfCoins, value - coins[numberOfCoins - 1], dp);
            res += numberOfWaysMemoRecur(coins, numberOfCoins - 1, value, dp);
            dp[value][numberOfCoins] = res;
        }

        return dp[value][numberOfCoins];

    }

    long long numberOfWaysMemo(int coins[], int numberOfCoins, int value)
    {
        maxValue = value + 1;
        vector<vector<long long>> dp(value + 1, std::vector<long long>(numberOfCoins + 1, maxValue));

        long long res = numberOfWaysMemoRecur(coins, numberOfCoins, value, dp);

        return res == maxValue ? -1 : res;

    }

    long long numberOfWaysTabu(int coins[], int numberOfCoins, int value)
    {
        vector<vector<long long>> dp(value + 1, std::vector<long long>(numberOfCoins + 1, 0));

        for (int i = 0; i <= value; i++) {
            dp[i][0] = 0;
        }

        for (int i = 0; i <= numberOfCoins; i++) {
            dp[0][i] = 1;
        }

        for (int i = 1; i <= value; i++) {
            for (int j = 1; j <= numberOfCoins; j++) {
                dp[i][j] = dp[i][j - 1];
                if (i >= coins[j - 1]) {
                    dp[i][j] += dp[i - coins[j - 1]][j];
                }
            }
        }
        return dp[value][numberOfCoins];
    }

    long long numberOfWays(int coins[], int numberOfCoins, int value)
    {
        //return numberOfWaysMemo(coins,numberOfCoins,value); 
        return numberOfWaysTabu(coins, numberOfCoins, value);
    }
};