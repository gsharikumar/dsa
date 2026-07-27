Linked List to Binary Tree
Difficulty: Medium
Given a head  Linked List . Construct the complete binary tree from the given Linked List and return the root of the tree. The result will be judged by printing the level order traversal of the binary tree.
Note: The complete binary tree is represented as a linked list in a way where if the root node is stored at position i, its left, and right children are stored at position 2*i+1, and 2*i+2 respectively. H is the height of the tree and this space is used implicitly for the recursion stack.

Examples:

Input: head : 1 -> 2 -> 3 -> 4 -> 5 

Output: [1, 2, 3, 4, 5]
Explanation: The tree would look like 

Now, the level order traversal of the above tree is 1 2 3 4 5.
Input: head: 5 -> 4 -> 3 -> 2 -> 1

Output: [5, 4, 3, 2, 1]
Explanation: The tree would look like
 
Now, the level order traversal of the above tree is 5 4 3 2 1.
Constraints:
1 ≤ numbers of nodes ≤ 106
1 ≤ node->data ≤ 104

