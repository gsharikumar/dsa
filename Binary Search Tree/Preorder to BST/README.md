Preorder to BST
Difficulty: Medium

Given an array arr[] representing preorder traversal of a BST. You have to build the BST  from the given preorder.

Examples:

Input: arr[] = [40, 30, 35, 80, 100]
Output: [35, 30, 100, 80, 40]
Explanation: PreOrder: 40 30 35 80 100
The corresponding BST is:
 
The output postOrder traversal is: 35 30 100 80 40
Input: arr[] = [40, 30, 32, 35, 80, 90, 100, 120]
Output: [35, 32, 30, 120, 100, 90, 80, 40]
Constraints:
1 ≤ arr.size() ≤ 103
1 ≤ arr[i] ≤ 104