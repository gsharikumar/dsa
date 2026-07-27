Fibonacci Numbers - Bottom Up DP
Difficulty: EasyAccuracy: 58.47%Submissions: 23K+Points: 2
One of the rudimentary problems to understand DP is finding the nth Fibonacci number. Here, we will solve the problem using a bottom-up approach.
You are given a number N. You need to find the Nth Fibonacci number.
Note: The first two number of the series are 0 and 1 i.e 0th fibonacci number is 0, 1st Fibonacci number is 1.

Example 1:

Input: N = 5
Output: 5
Explanation: Some of the numbers of the Fibonacci numbers are 0, 1, 1, 2, 3, 5, ..... So, starting the count from the 0th index, the 5th one is 5.
Example 2:

Input: N = 7
Output: 13
Explanation: Some of the numbers of the Fibonacci numbers are 0, 1, 1, 2, 3, 5, 8, 13 ..... So, starting the count from the 0th index, the 7th one is 13.
Your Task:
You don't need to take any input. You have to complete the function findNthFibonacci() which takes single argument(number N) and returns the answer.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)

Constraints:
1 <= N <= 92