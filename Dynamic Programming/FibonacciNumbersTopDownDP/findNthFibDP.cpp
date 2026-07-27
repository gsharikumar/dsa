//User function Template for C++

//Complete this function
class Solution
{
public:
    //Function to find the nth fibonacci number using top-down approach.
    long long findNthFibDP(int number, long long int dp[]) {
        if (number < 0) {
            return 0;
        }

        if (number == 0 || number == 1) {
            dp[number] = number;
            return dp[number];
        }

        if (dp[number] != 0) {
            return dp[number];
        }

        dp[number] = findNthFibonacci(number - 2, dp) + findNthFibonacci(number - 1, dp);

        return dp[number];
    }

    long long findNthFibonacci(int number, long long int dp[])
    {
        // Your Code Here
        //for(int i = 0;i <= number;i++){
        //    dp[i] = -1;
        //}
        return findNthFibDP(number, dp);

    }

};