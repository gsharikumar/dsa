//User function Template for C++

class Solution
{
public:
    //Function to return the maximum sum without adding adjacent elements.
    long long maximumSum(int arr[], int sizeOfArray)
    {
        //Your code here
        long long maxSum;
        long long localMax[sizeOfArray];
        localMax[0] = arr[0];
        maxSum = localMax[1] = max(arr[0], arr[1]);
        for (int i = 2; i < sizeOfArray; i++) {
            if ((arr[i] + localMax[i - 2]) > arr[i]) {
                localMax[i] = arr[i] + localMax[i - 2];
            }
            else {
                localMax[i] = arr[i];
            }
            localMax[i - 1] = max(localMax[i - 1], localMax[i - 2]);
            //cout<<localMax[i-1]<<" ";
            maxSum = max(maxSum, localMax[i]);
        }
        return maxSum;
    }
};