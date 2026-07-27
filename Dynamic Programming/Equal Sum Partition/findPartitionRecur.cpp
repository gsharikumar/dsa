// User function template in C++


class Solution
{
public:
    //Function to check whether a set of numbers can be partitioned into 
    //two subsets such that the sum of elements in both subsets is same.
    bool findPartitionRecur(int a[], int n, int s1, int s2) {
        if (s1 == s2) {
            return true;
        }
        if (n < 2) {
            return false;
        }

        return (findPartitionRecur(a, n - 1, s1 + a[n - 2], s2 - a[n - 2]) || \
            findPartitionRecur(a, n - 1, s1, s2));
    }

    bool findPartitionRecur(int a[], int n) {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += a[i];
        }
        return findPartitionRecur(a, n, 0, sum);
    }

    bool findPartitionMemoRecur(int a[], int n, int s1, int s2, vector<vector<int8_t>>& dp) {
        //changing n not accounted?????? led to wrong implementation in tabulation method
        if (s1 == s2) {
            return 1;
        }
        if (n < 2) {
            return 0;
        }
        if (dp[s1][s2] == -1) {
            dp[s1][s2] = (findPartitionMemoRecur(a, n - 1, s1 + a[n - 2], s2 - a[n - 2], dp) || \
                findPartitionMemoRecur(a, n - 1, s1, s2, dp));
        }
        return dp[s1][s2];
    }

    bool findPartitionMemo(int a[], int n) {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += a[i];
        }
        vector<vector<int8_t>> dp(sum + 1, vector<int8_t>(sum + 1, -1));
        return findPartitionMemoRecur(a, n, 0, sum, dp);
    }

    bool findPartitionMemoRecurOpt(int a[], int n, int sum, vector<vector<int8_t>>& dp) {
        if (sum == 0) {
            return 1;
        }
        if (sum < 0) {
            return 0;
        }
        if (n < 1) {
            return 0;
        }
        if (dp[n][sum] == -1) {
            dp[n][sum] = (findPartitionMemoRecurOpt(a, n - 1, sum - a[n - 1], dp) || \
                findPartitionMemoRecurOpt(a, n - 1, sum, dp));
        }
        return dp[n][sum];
    }

    bool findPartitionMemoOpt(int a[], int n) {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += a[i];
        }
        if (sum & 1) {
            //test for even. if even set can be split in to two equal sum, otherwise not possible
            return 0;
        }
        vector<vector<int8_t>> dp(n + 1, vector<int8_t>(sum + 1, -1));
        return findPartitionMemoRecurOpt(a, n, sum / 2, dp);
    }

    bool findPartition(int a[], int n)
    {
        // code here
        return findPartitionMemoOpt(a, n);
        return findPartitionMemo(a, n);
        return findPartition(a, n);

    }

    bool findPartitionTabu(int a[], int n) {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += a[i];
        }
        vector<vector<vector<int8_t>>> dp(sum + 1, vector<vector<int8_t>>(sum + 1, vector<int8_t>(n, 0)));

        for (int i = 1; i <= sum; i++) {
            for (int j = 1; j <= sum; j++) {
                for (int k = 2; k < n; k++) {
                    int si = (i + a[k - 2]);
                    int sj = (j - a[k - 2]);
                    int8_t curr = 0;
                    if ((si <= n) && (sj >= 0)) {
                        dp[i][j][k] = dp[si][sj][k - 1];
                    }
                    dp[i][j][k] |= dp[i][j][k - 1];
                }
            }
        }
        return dp[sum][sum][n - 1];
    }
};