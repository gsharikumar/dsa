Kth largest element in a stream
Difficulty: MediumAccuracy: 42.21%Submissions: 22K+Points: 4Average Time: 30m
Given an input stream of n integers, find the kth largest element each time when an new element is added to the stream.

Example 1:

Input:
k = 4, n = 6
arr[] = {1,2,3,4,5,6}
Output: -1 -1 -1 1 2 3
Explanation: k = 4
For 1, the 4th largest element doesn't
exist so we print -1.
For 2, the 4th largest element doesn't
exist so we print -1.
For 3, the 4th largest element doesn't
exist so we print -1.
For 4, the 4th largest element is 1
{1, 2, 3, 4}
For 5, the 4th largest element is 2
{2, 3, 4 ,5}
For 6, the 4th largest element is 3
{3, 4, 5, 6}

Example 2:

Input:
k = 1, n = 2
arr[] = {3,4}
Output: 3 4 
Your Task:
You are required to complete the method kthLargest() which takes 3 arguments and prints kth largest element -1.

Constraints:
1 <= n <= 106
1 <= k <= n
1 <= arr[i] <= 105

Expected Time Complexity: O(n*Log(k))
Expected Auxiliary Space: O(k)