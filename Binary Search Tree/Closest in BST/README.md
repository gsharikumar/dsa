Closest in BST
Difficulty: MediumAccuracy: 47.51%Submissions: 89K+Points: 4Average Time: 30m
Given a BST and an integer. Find the least absolute difference between any node value of the BST and the given integer.

Example 1:

Input:
        10
      /   \
     2    11
   /  \ 
  1    5
      /  \
     3    6
      \
       4
K = 13
Output: 2
Explanation: K=13. The node that has value nearest to K is 11. so the answer is 2
Example 2:

Input:
      8
    /   \
   1     9
    \     \
     4    10
    /
   3
K = 9
Output: 0
Explanation: K=9. The node that has value nearest to K is 9. so the answer is 0.
Constraints:
1 <= Number of nodes <= 105
1 <= Value stored at nodes(data), K <= 105

