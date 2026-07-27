Largest Region of 1's in a Binary Matrix

Difficulty: Medium

Given a grid of dimensions nxm containing 0's and 1's. Find the count of 1's in the largest region of 1's. A region of 1's is a group of 1's where two 1s can be adjacent to each other in any of the 8 directions ( 2 horizontal, 2 vertical and 4 diagonal). 

Examples :

Input: grid[][] = [[1, 1, 1, 0], [0, 0, 1, 0], [0, 0, 0, 1], [1, 1, 0, 0]]
Output: 5
Explanation: 

The largest region has five 1s 
Input: grid[][] = [[0,1]]
Output: 1
Explanation: The largest region of 1's is 1.
Constraints:
1 ≤ n, m ≤ 500