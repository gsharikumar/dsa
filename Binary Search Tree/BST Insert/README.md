BST Insert
Difficulty: Easy

Given the root of a binary search tree and a value key. Insert a new node with a value equal to key into the tree and return the root of the modified tree after inserting the value. 

Note: All the nodes have distinct values in the BST and the new value to be inserted is not present in the BST.

Examples :

Input: root = [2, 1, 3], key = 4

Output: [2, 1, 3, N, N, N, 4]
Explanation: After inserting the node 4, the new tree will be [2, 1, 3, N, N, N, 4].
Input: root = [2, 1, 3, N, N, N, 6], key = 4

Output: [2, 1, 3, N, N, N, 4, N, 6]
Explanation: After inserting the node 4, the new tree will be [2, 1, 3, N, N, N, 4, N, 6].
Constraints:
1 ≤ number of nodes ≤ 105
1 ≤ node->data ≤ 109
1 ≤ key ≤ 109

