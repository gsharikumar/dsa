Count ways with 3 moves

Difficulty: Easy

A child is running up a staircase with n steps and can hop either 1 step, 2 steps, or 3 steps at a time. Return the of count how many possible ways the child can run up the stairs.

Examples:

Input: n = 3
Output: 4
Explanation: The following are 4 different ways
1 step + 1 step + 1 step 
1 step + 2 steps 
2 steps + 1 step 
3 steps
Input: n = 4
Output: 7
Explanation: Below are the 7 ways to reach 4th step:
1 step + 1 step + 1 step + 1 step
1 step + 2 steps + 1 step
2 step + 1 step + 1 step
1 step + 1 step + 2 steps
2 steps + 2 steps
3 steps + 1 step
1 step + 3 steps
Input: n = 1
Output: 1
Constraints:
1 ≤ n ≤ 30