Levelorder traversal of a BST
Difficulty: Easy
Levelorder traversal means traversing through the tree level by level, from left to right.
Given a BST, find its level-order traversal. 


Example 1:

Input:
      5
    /   \
   2     7
   \      \
    3      8
Output: 5 2 7 3 8
Explanation: Move top to down and then left to right and keep printing elements.
Example 2:

Input:
    30
   /
 10
   \ 
   20
Output: 30 10 20

Your Task:
You don't need to read input or print anything. Complete the function levelOrder() that takes the root of the BST as input parameter and returns a list of integers containing the level-order traversal of the BST.


Expected Time Complexity: O(N), where N = number of nodes in BST.
Expected Auxiliary Space: O(N).


Constraints:
1 <= Number of nodes <= 105
1 <= Value of a node <= 105