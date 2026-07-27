


class Solution
{
public:
    //Function to return nCr mod 10^9+7 for given n and r. 
    int nCrModpNaiveRecur(int n) {
        if (n < 2) {
            return 1;
        }
        return (n * nCrModpNaiveRecur(n - 1)) % (1000000000 + 7);
    }

    int nCrModpNaive(int n, int r) {
        int res = 0;
        if (n > r)
        {
            int numer = nCrModpNaiveRecur(n);
            int deno1 = nCrModpNaiveRecur(n - r);
            int deno2 = nCrModpNaiveRecur(r);
            int deno = (deno1 * deno2) % (1000000000 + 7);
            res = numer / deno;
        }
        return res;
    }

    int nCrModpPascal(int n, int r) {
        int res = 0;
        if (n == r) {
            return 1;
        }
        if (n == 0 || r == 0) {
            return 1;
        }
        if (n < r) {
            return 0;
        }
        return (nCrModpPascal(n - 1, r - 1) + nCrModpPascal(n - 1, r)) % (1000000000 + 7);
    }

    int nCrModpPascalMemo(int n, int r, vector<vector<int>>& dp) {
        int res = 0;
        if (n == r) {
            dp[n][r] = 1;
            return 1;
        }
        if (r == 0) {
            dp[n][r] = 1;
            return 1;
        }
        if (n < r) {
            return 0;
        }
        if (dp[n][r] == -1) {
            dp[n][r] = (nCrModpPascalMemo(n - 1, r - 1, dp) + nCrModpPascalMemo(n - 1, r, dp)) % (1000000000 + 7);
        }
        return dp[n][r];
    }

    int nCrModp(int n, int r)
    {
        // your code here
        if (n < r) {
            return 0;
        }
        if (n == r) {
            return 1;
        }

        vector<vector<int>> dp(n + 1, vector<int>(r + 1, -1));
        for (int i = 0; i <= n; i++) {
            //dp[i][0]=1;
        }

        return nCrModpPascalMemo(n, r, dp);

        return nCrModpPascal(n, r);
    }

};