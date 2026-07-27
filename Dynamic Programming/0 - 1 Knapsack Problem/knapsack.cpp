class Solution
{
public:
    //Function to return max value that can be put in knapsack of capacity W.


    int knapSackRecur(int W, int wt[], int val[], int n) {

        if ((W - wt[n - 1]) < 0) {
            return knapSackRecur(W, wt, val, n - 1);
        }
        if ((n < 1) || (W == 0)) {
            return 0;
        }

        return max(knapSackRecur(W, wt, val, n - 1), val[n - 1] + knapSackRecur(W - wt[n - 1], wt, val, n - 1));
    }

    int knapSackMemoRecur(int W, int wt[], int val[], int n, vector<vector<int>>& dp) {

        if ((n < 1) || (W == 0)) {
            return 0;
        }

        if (dp[n][W] == -1) {
            int maxVal = 0;
            if ((W - wt[n - 1]) >= 0) {
                maxVal = val[n - 1] + knapSackMemoRecur(W - wt[n - 1], wt, val, n - 1, dp);
            }
            maxVal = max(maxVal, knapSackMemoRecur(W, wt, val, n - 1, dp));
            dp[n][W] = maxVal;
        }
        return dp[n][W];
    }

    int knapSackMemo(int W, int wt[], int val[], int n)
    {
        // Your code here
        vector<vector<int>> dp(n + 1, vector<int>(W + 1, -1));
        return knapSackMemoRecur(W, wt, val, n, dp);
    }


    int knapSack(int W, int wt[], int val[], int n)
    {
        // Your code here
        return knapSackMemo(W, wt, val, n);
        return knapSackRecur(W, wt, val, n);
    }

    /*
    Tooo many arguments
    */
    int knapSackRecurWrongFirstAttempt(int W, int wt[], int val[], int n, int totV, int totW) {

        if (W > totW) {
            return 0;
        }
        if (n < 1) {
            return totV;
        }
        int maxVal = knapSackRecurWrongFirstAttempt(W, wt, val, n - 1, totV + val[n - 1], totW + wt[n - 1]);
        maxVal = max(maxVal, knapSackRecurWrongFirstAttempt(W, wt, val, n - 1, totV, totW));
        return maxVal;
    }

};