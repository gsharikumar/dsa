BST Keys in a Range
Difficulty: Easy
Given the root of a Binary Search Tree (BST) and two integers low and high, return all node values that lie in the inclusive range [low, high] in ascending order.

Examples :

Input: root = [17, 4, 18, 2, 9, N, N], l = 4, h = 17
 
Output: [4, 9, 17]
Explanation: The BST nodes whose values lie in the range [4, 17] are 4, 9, and 17. Hence the result is returned as [4, 9, 17].
Input: root = [16, 7, 20, 1, 10, N, N], l = 13, h = 23
 
Output: [16, 20]
Explanation: The nodes in the range [13, 23] are 16 and 20. Hence the result is returned as [16, 20].
Constraints:
1 ≤ Number of nodes ≤ 105
1 ≤ l ≤ h ≤ 106