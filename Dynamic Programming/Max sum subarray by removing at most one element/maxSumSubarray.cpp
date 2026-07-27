


class Solution
{
public:
    //Function to return maximum sum subarray by removing at most one element.
    int maxSumSubarrayClueless(int A[], int n)
    {
        int globalMaxSum = INT_MIN;
        int dp[n];
        for (int i = 0; i < n; i++) {
            int minElement = INT_MAX;
            int prevMaxSum;
            int currMaxSum;
            currMaxSum = prevMaxSum = dp[i] = A[i];
            for (int j = i + 1; j < n; j++) {
                currMaxSum = dp[j] = dp[j - 1] + A[j];
                //                cout <<"("maxSum<<","<<prevMaxSum<<") ";
                if (currMaxSum < prevMaxSum) {
                    //add the element causing data to reduce in value, so ignoring the update
                    minElement = min(minElement, A[j]);
                    //cout<<"upd<"<<minElement<<">";
                }
                prevMaxSum = currMaxSum;
            }
            //cout<<endl;
            if (minElement != INT_MAX) {
                currMaxSum = currMaxSum - minElement;
            }
            globalMaxSum = max(globalMaxSum, currMaxSum);
        }
        return globalMaxSum;
    }

    int maxSumSubarrayOpt(int A[], int n)
    {
        //forward & backward kanade approach will not work if all number of negative        
        //in which case we find the highest negative element, if all number are negative
        int high = INT_MIN;
        for (int i = 0; i < n; i++) {
            high = max(high, A[i]);
        }
        if (high < 0) {
            return high;
        }

        int fw[n];
        int bw[n];
        int maxSoFar;
        //kadane forward
        maxSoFar = fw[0] = A[0];
        //cout<<fw[0]<<" ";
        for (int i = 1; i < n; i++) {
            if ((fw[i - 1] + A[i]) > A[i]) {
                fw[i] = fw[i - 1] + A[i];
            }
            else {
                fw[i] = A[i];
            }
            maxSoFar = max(maxSoFar, fw[i]);
            //cout<<fw[i]<<" ";
        }
        //kadane backward
        bw[n - 1] = A[n - 1];
        //cout<<endl;
        //cout <<bw[n-1]<<" ";
        for (int i = n - 2; i >= 0; i--) {
            if ((bw[i + 1] + A[i]) > A[i]) {
                bw[i] = bw[i + 1] + A[i];
            }
            else {
                bw[i] = A[i];
            }
            maxSoFar = max(maxSoFar, bw[i]);
            // cout<<bw[i]<<" ";
        }
        int maxSumWithDel = maxSoFar;
        for (int i = 1; i < n - 1; i++) {
            //if i the element where to be ignored
            maxSumWithDel = max(maxSumWithDel, fw[i - 1] + bw[i + 1]);
        }
        maxSumWithDel == max(maxSumWithDel, fw[n - 1]);
        return maxSumWithDel;
    }

    int maxSumSubarray(int A[], int n)
    {
        //Your code here
        return maxSumSubarrayOpt(A, n);
    }
};