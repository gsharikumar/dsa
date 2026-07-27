

//User function tempate for C++
ll countRecur(ll n, int m, int scores[])
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

    ll res = 0;

    res += countRecur(n, m - 1, scores) + countRecur(n - scores[m - 1], m, scores);

    return res;
}

ll countMemoRecur(ll n, int m, int scores[], vector<vector<ll>>& dp)
{
    if (n == 0) {
        dp[n][m] = 1;
        return 1;
    }
    if (n < 0) {
        return 0;
    }
    if (m <= 0) {
        return 0;
    }
    if (dp[n][m] == -1) {
        dp[n][m] = countMemoRecur(n, m - 1, scores, dp) + countMemoRecur(n - scores[m - 1], m, scores, dp);
    }
    return dp[n][m];
}

ll countMemo(ll n, int m, int scores[])
{
    vector<vector<ll>> dp(n + 1, vector<ll>(m + 1, -1));
    return countMemoRecur(n, m, scores, dp);
}

ll countTab(ll n, int m, int scores[])
{
    vector<vector<ll>> dp(n + 1, vector<ll>(m + 1, 0));
    for (int i = 0; i <= m; i++) {
        dp[0][i] = 1;
    }
    for (int i = 1; i <= n; i++) {
        dp[i][0] = 0;
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            dp[i][j] = dp[i][j - 1];
            if ((i - scores[j - 1]) >= 0) {
                dp[i][j] += dp[i - scores[j - 1]][j];
            }
        }
    }
    return dp[n][m];
}

//Function to find the number of distinct combinations to reach the given score.
ll count(ll n)
{
    //code here
    int scores[] = { 3,5,10 };
    int m = 3;
    //memoization T O(n*m) S O(2*n)
    return countMemo(n, m, scores);


    //naive T = O(m^n) S =O(n)
    return countRecur(n, m, scores);

}