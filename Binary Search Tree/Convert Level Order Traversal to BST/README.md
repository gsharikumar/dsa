Convert Level Order Traversal to BST
Difficulty: Medium

Given an array arr[] of size n containing unique elements and representing the level order traversal of a Binary Search Tree, construct the Binary Search Tree from the given level order traversal.

Examples:

Input: arr[] = [7,4,12,3,6,8,1,5,10]
Output: 7 4 3 1 6 5 12 8 10
Explanation:

The preorder traversal of the constructed BST is 7 4 3 1 6 5 12 8 10.
Input: arr[] = [1,3,4,6,7,8]
Output: 1 3 4 6 7 8
Explanation: 

The preorder traversal of the constructed BST is 1 3 4 6 7 8.
Constraints:

1 ≤ N ≤ 103
1 ≤ arr[i] ≤ 106