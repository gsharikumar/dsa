//User function template for C++


class Solution
{
public:
    //Function to find the nth catalan number.

    cpp_int catalanRecur(int n) {
        if (n <= 1) {
            return 1;
        }

        cpp_int result = 0;
        for (int i = 0; i < n; i++) {
            result += catalanRecur(i) * catalanRecur(n - i - 1);
        }

        return result;

    }

    cpp_int catalanDPMemoization(int n, cpp_int dp[]) {
        if (n <= 1) {
            dp[n] = 1;
        }
        else if (dp[n] == 0) {
            for (int i = 2; i <= n; i++) {
                dp[i] = 0;
                for (int j = 0; j < i; j++) {
                    if (dp[j] == 0) {
                        dp[i] += catalanDPMemoization(j, dp) * catalanDPMemoization(i - j - 1, dp);
                    }
                    else {
                        dp[i] += dp[j];
                    }
                }
            }
        }
        return dp[n];

    }

    cpp_int catalanDPTab(int n, cpp_int dp[]) {

        dp[0] = dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            dp[i] = 0;
            for (int j = 0; j < i; j++) {
                dp[i] += dp[j] * dp[i - j - 1];
            }
        }
        return dp[n];
    }

    cpp_int findCatalan(int n)
    {
        //code here
        cpp_int dp[n + 1] = { 0 };
        return catalanDPTab(n, dp);
    }
};