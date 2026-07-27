Connect Nodes of Levels
Difficulty: Medium
Given the root of a binary tree, connect all nodes at the same level using an additional nextRight pointer for each node. Initially, all nextRight pointers contain garbage values (or null). Your function should set each node’s nextRight pointer to point to its immediate neighbor on the same level. The driver code will print the level-order traversal .

Examples:

Input: root = [1, 2, 3, 4, 5, N, 6]

Output: [1, #, 2, 3, #, 4, 5, 6, #]
Explanation:The connected tree is:

Constraints:
1 ≤ number of nodes ≤ 105
0 ≤ node->data ≤ 105

