Equal Sum Partition

Difficulty: Medium

Given a set of numbers, check whether it can be partitioned into two subsets such that the sum of elements in both subsets is same or not.

Example 1:

Input:
N = 4
arr[] = {1,5,11,5}
Output: YES
Explanation: There exists two subsets
such that {1, 5, 5} and {11}.
Example 2:

Input:
N = 3
arr[] = {1,3,5}
Output: NO
Your Task:
Your task is to complete the findPartition() function which takes an array a[] and N as input parameter and return true if the given set can be partitioned into two subsets such that the sum of elements in both subsets is equal, else return false.
Note: The output will be YES or NO depending upon the value returned by your code. The printing is done by the driver's code.

Expected Time Complexity: O(N*S).
Expected Auxiliary Space: O(S) where S is the sum of the given Array.

Constraints:
1 <= N <= 100
0 <= arr[i] <= 1000