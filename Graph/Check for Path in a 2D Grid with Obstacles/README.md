Check for Path in a 2D Grid with Obstacles

Difficulty: Medium

Given a grid mat[][] of size n × n containing integers 0, 1, 2, and 3 having the following meanings

1 represents the source cell
2 represents the destination cell
3 represents a blank cell through which movement is allowed
0 represents a wall that cannot be traversed
There is exactly one source and one destination in the grid. 

Find whether a path exists from the source cell to the destination cell. 
Movement is allowed in four directions: up, down, left, and right.
Examples :

Input: mat[][] = {{0,3,1,0}, {3,0,3,3}, {2,3,0,3}, {0,3,3,3}}; 
Output: true
Explanation: A path exists from source 1 to destination 2 through valid cells 3.

Input: mat[][] = {{1,0,3}, {0,0,0}, {3,3,2}};
Output: false
Explanation: No path exists as the source 1 is blocked and cannot reach destination 2.
 
Constraints:
1 ≤ n ≤ 500