Left Index
Difficulty: Basic
Given a sorted array of positive integers (elements may be repeated) and a number x. The task is to find the leftmost index of x in the given array.

Example 1:

Input: arr[] = [1, 1, 2, 2, 3, 4, 5, 5, 6, 7], x = 1
Output: 0
Explanation: 1 is present two times in the array and its leftmost index is 0.
Input: arr[] = [10, 20, 20, 20, 20, 20, 20], x = 20
Output: 1
Explanation: 20 is present 5 time, but its leftmost index is 1.
Constraints:
1 ≤ arr.size() ≤ 106
1 ≤ arr[i] ≤ 106
1 ≤ x ≤ 106