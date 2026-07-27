

class Solution
{
public:
    //Function to find minimum number of jumps to reach the end of the array.
    int N;

#if 0
    int minimumJumpsRecur(int arr[], int n)
    {
        if (n == N - 1) {
            return 0;
        }

        if (n >= N) {
            return -1;
        }

        int res = INT_MAX;

        for (int i = arr[n]; i > 0; i--) {
            int subRes = minimumJumpsRecur(arr, n + i);
            if (subRes != -1) {
                res = min(res, subRes + 1);
            }
        }

        return (res == INT_MAX) ? -1 : res;

    }


    int minimumJumpsMemoRecurUnconventionalFails(int arr[], int n, vector<int>& dp)
    {
        if (n == N - 1) {
            return 0;
        }

        if (n >= N) {
            return -1;
        }

        if (dp[n] == -1) {
            int res = INT_MAX;
            for (int i = 1; i <= arr[n]; i++) {
                int subRes = minimumJumpsMemoRecur(arr, n + i, dp);
                if (subRes != -1) {
                    res = min(res, subRes + 1);
                }
            }
            if (res != INT_MAX) {
                dp[n] = res;
            }
        }
        return dp[n];

    }

    int minimumJumpsMemoRecur(int arr[], int n, vector<int>& dp)
    {
        if (n == 0) {
            dp[n] = 0;
            return 0;
        }

        if (n < 0) {
            return -1;
        }
        int res = INT_MAX;
        if (dp[n] == -1) {
            for (int i = n - 2; i <= (n + arr[n]); i--) {
                int subRes = minimumJumpsMemoRecur(arr, i, dp);
                if (subRes != -1) {
                    res = min(subRes + 1, res);
                }
            }
            dp[n] = res;
        }
        return dp[n];
    }

    int minimumJumpsMemo(int arr[], int n)
    {
        vector<int> dp(n + 1, -1);
        minimumJumpsMemoRecur(arr, 0, dp);
        return (dp[0] == INT_MAX) ? -1 : dp[0];
    }

    int minimumJumpsTab(int arr[], int n)
    {
        vector<int> dp(n + 1);
        dp[0] = 0;

        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= arr[i]; j++) {

                dp[i] = min(dp[i], 1 + dp[i + j]);
            }
        }



        return dp[n];
    }
    int jump(vector<int>& nums) {
        int l = 0, r = 0, jumps = 0;
        int n = nums.size();
        while (r < n - 1) {
            int maxReach = 0;
            for (int i = l; i < r + 1; i++)
                maxReach = max(maxReach, nums[i] + i);
            l = r + 1;
            r = maxReach;
            jumps += 1;
        }
        return jumps;
    }
#endif
#if 0
    int minimumJumpsGreedy(int arr[], int n) {

        int l;
        int r;
        l = r = 0;
        int res = 0;
        int farthest = -1;
        while (r < (n - 1)) {
            farthest = -1;
            for (int i = l; i <= r; i++) {
                farthest = max(farthest, i + arr[i]);
            }
            l = r + 1;
            r = farthest;
            res++;
        }
        return res;
    }

    int minJumpMemoRecur(int arr[], int n, vector<int>& dp)
    {
        if (n > (N - 1)) {
            return -1;
        }
        if (n == (N - 1)) {
            dp[n] = 0;
            return 0;
        }

        if (dp[n] == -1) {
            int jump = INT_MAX;
            for (int i = 1; i <= arr[n]; i++) {
                int res = minJumpMemoRecur(arr, n + i, dp);
                if (res != -1) {
                    jump = min(jump, 1 + res);
                }
            }
            if (jump != INT_MAX) {
                dp[n] = jump;
            }
        }
        return dp[n];
    }

    int minJumpMemo(int arr[], int n)
    {
        vector<int> dp(n, -1);
        return minJumpMemoRecur(arr, 0, dp);
    }

    int minJumpTabu(int arr[], int n)
    {
        vector<int> dp(n + 1, 0);
        dp[n] = 0;
        for (int i = n - 2; i >= 0; i--) {
            dp[i] = INT_MAX;
            for (int j = i + 1; j <= (i + arr[i]); j++) {
                if (j <= n) {
                    dp[i] = min(dp[i], 1 + dp[j]);
                }
            }
        }
        return (dp[0] == INT_MAX) ? -1 : dp[0];
    }
#endif

    int minimumJumpsNaiveRecur(int arr[], int n) {

        if (n == 1) {
            return 0;
        }

        int res = INT_MAX;
        for (int i = 0; i <= (n - 2); i++) {
            int subRes = INT_MAX;
            if ((arr[i] + i) >= (n - 1)) {
                subRes = minimumJumpsNaiveRecur(arr, i + 1); //i+1 because we are passing size
                if (subRes != INT_MAX) {
                    res = min(res, subRes + 1);
                }
            }
        }
        return (res == INT_MAX) ? -1 : res;
    }

    int minimumJumpsMemoRecur(int arr[], int n, vector<int>& dp) {
        if (n == 1) {
            dp[n - 1] = 0; //or dp[0]=0;
            return 0;
        }
        int res = INT_MAX;
        if (dp[n - 1] == INT_MAX) {
            for (int i = 0; i <= (n - 2); i++) {
                //dp[i] is the minimum number of jumps to reach the index i
                int subRes = INT_MAX;
                if ((arr[i] + i) >= (n - 1)) {
                    subRes = minimumJumpsMemoRecur(arr, i + 1, dp); //i+1 because we are passing size
                    if (subRes != INT_MAX) {
                        res = min(res, subRes + 1);
                    }
                }
            }
            dp[n - 1] = res;
        }
        return dp[n - 1];
    }

    int minimumJumpsMemo(int arr[], int n) {
        vector<int> dp(n, INT_MAX);
        int res = minimumJumpsMemoRecur(arr, n, dp);
        return (res == INT_MAX) ? -1 : res;
    }

    int minimumJumpsTabu(int arr[], int n) {
        vector<int> dp(n, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if ((arr[j] + j) >= i) {
                    //solution possible or not
                    if (dp[j] != INT_MAX) {
                        dp[i] = min(dp[i], dp[j] + 1);
                    }
                }

            }
        }
        return (dp[n - 1] == INT_MAX) ? -1 : dp[n - 1];
    }

    int minimumJumpsGreedy(int arr[], int n) {

        int res = 0;
        int l;
        int r;

        l = r = 0;
        while (r < (n - 1)) {
            int maxReach = -1;
            for (int i = l; i <= r; i++) {
                maxReach = max(maxReach, i + arr[i]);
            }
            l = r + 1;
            r = maxReach;
            if (l > r) {
                res = -1;
                break;
            }
            res++;
        }
        return res;
    }

    int minimumJumps(int arr[], int n) {

        // your code here

        return minimumJumpsGreedy(arr, n);
        return minimumJumpsTabu(arr, n);
        return minimumJumpsMemo(arr, n);
        return minimumJumpsNaiveRecur(arr, n);


#if 0
        N = n;
        return minimumJumpsGreedy(arr, n);

        return minJumpMemo(arr, n); //fails 236/246 - time limit exceeded
        return minJumpTabu(arr, n); //fails - first
#endif        


        //DP solution not working - TC: O(n^2)     
       // return minimumJumpsMemo(arr,0);

       // return minimumJumpsRecur(arr,0);


    }
};