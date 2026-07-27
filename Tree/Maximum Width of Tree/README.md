Maximum Width of Tree
Difficulty: Easy
Given a Binary Tree, find the maximum width of it. Maximum width is defined as the maximum number of nodes at any level.

Examples:

Input: root = [1, 2, 3, 4, 5, 6, 7]
          
Output: 4
Explanation: On the first level there is only one node [1]. On the second level there are two nodes [2, 3]. On the third level there are 4 nodes [4, 5, 6, 7], clearly it is the maximum number of nodes at any level.
Input: root = [10, 20, 30, 40, 60]
  
            
Output: 2
Explanation: There is one node on level 1(10) There is two node on level 2(20, 30) There is two node on level 3(40, 60) Hence the answer is 2
Constraints:
1 ≤ number of nodes ≤ 105
0 ≤ node->data ≤ 105