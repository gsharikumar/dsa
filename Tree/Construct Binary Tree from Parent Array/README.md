Construct Binary Tree from Parent Array
Difficulty: Medium
Given an array parent[] where each index represents a node and parent[i] gives the parent’s index, with -1 indicating the root. Your task is to construct the binary tree in standard linked-node form (each node having left and right pointers) based on this parent–child relationship and return the root node.

Note: If two elements have the same parent, the one that appears first in the array will be the left child and the other is the right child. You don't need to print anything, the driver code will print the level order traversal of the returned root node to verify the output.

Examples:

Input: parent[] = [-1, 0, 0, 1, 1, 3, 5]
Output: [0, 1, 2, 3, 4, N, N, 5, N, N, N, 6]
Explanation: the tree generated will have a structure like

Input: parent[] = [2, 0, -1]
Output: [2, 0, N, 1]
Explanation: the tree generated will have a structure like

Constraints:
1 ≤ parent.size() ≤ 103