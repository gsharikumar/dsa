
class Solution
{
public:
    //Function to find the maximum number of cuts.
    int maximizeTheCutsRecur(int n, int x, int y, int z) {
        if (n == 0) {
            return 0;
        }
        if (n < 0) {
            return -1;
        }

        int rx = maximizeTheCutsRecur(n - x, x, y, z);
        int ry = maximizeTheCutsRecur(n - y, x, y, z);
        int rz = maximizeTheCutsRecur(n - z, x, y, z);
        if (rx >= 0) {
            rx++;
        }
        if (ry >= 0) {
            ry++;
        }
        if (rz >= 0) {
            rz++;
        }
        return max(rz, max(rx, ry));
    }

    int maximizeTheCutsMemoRecur(int n, int x, int y, int z, vector<int>& dp) {
        if (n == 0) {
            return 0;
        }
        if (n < 0) {
            return -1;
        }
        if (dp[n] == -1) {
            int rx = maximizeTheCutsMemoRecur(n - x, x, y, z, dp);
            int ry = maximizeTheCutsMemoRecur(n - y, x, y, z, dp);
            int rz = maximizeTheCutsMemoRecur(n - z, x, y, z, dp);
            if (rx >= 0) {
                rx++;
            }
            if (ry >= 0) {
                ry++;
            }
            if (rz >= 0) {
                rz++;
            }
            dp[n] = max(rz, max(rx, ry));
        }
        return dp[n];
    }

    int maximizeTheCutsTabu(int n, int x, int y, int z) {

        vector<int> dp(n + 1, 0);

        dp[0] = 0;

        for (int i = 1; i <= n; i++) {
            int rx = -1;
            int ry = -1;
            int rz = -1;
            if ((i - x) >= 0) { rx = dp[i - x]; }
            if ((i - y) >= 0) { ry = dp[i - y]; }
            if ((i - z) >= 0) { rz = dp[i - z]; }

            if (rx >= 0) {
                rx++;
            }
            if (ry >= 0) {
                ry++;
            }
            if (rz >= 0) {
                rz++;
            }
            dp[i] = max(rz, max(rx, ry));
        }
        return dp[n];
    }

    int maximizeTheCutsMemo(int n, int x, int y, int z) {
        vector<int> dp(n + 1, -1);
        return maximizeTheCutsMemoRecur(n, x, y, z, dp);
    }

    int maximizeTheCuts(int n, int x, int y, int z)
    {
        //Your code here

        int ret = maximizeTheCutsTabu(n, x, y, z); return (ret == -1) ? 0 : ret;
        return maximizeTheCutsMemo(n, x, y, z);
        return maximizeTheCutsRecur(n, x, y, z);
    }
};