Inorder traversal of a BST
Difficulty: Easy
Inorder traversal means traversing through the tree in a Left, Node, Right manner. We first traverse left, then print the current node, and then traverse right. This is done recursively for each node.
Given a BST, find its in-order traversal.

Example 1:

Input:
       5
    /    \
   2      7
    \       \
    3        8
Output: 2 3 5 7 8

Example 2:

Input:
     30
     /
   10
     \
     20
Output: 10 20 30
Your Task:
You don't need to read input or print anything. Complete the function inOrder() that takes the root of the BST as input parameter and returns a list of integers containing the in-order traversal of the BST.

Expected Time Complexity: O(N), where N = Number of nodes in BST
Expected Auxiliary Space: O(Height of the BST).

Constraints:
1 <= Number of nodes <= 100
1 <= Value of a node <= 100