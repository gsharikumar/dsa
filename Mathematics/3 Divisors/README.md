3 Divisors
Difficulty: Medium
You are given an integer array queries[], where each element represents a query value n. For every n in the array, determine how many numbers less than or equal to n have exactly 3 divisors.

Examples:

Input: queries[] = [6]
Output: [1]
Explanation: There is only one number 4 which has exactly three divisors 1, 2 and 4 and less than equal to 6.
Input: query[] = [3, 10]
Output: [0, 2]
Explanation: For query[0], the answer is 0. For query[1], there are two numbers 4 and 9 having exactly 3 divisors.
Constraints : 
1 ≤ q ≤ 103, where q is number of elements in the queries.
1 ≤ queries[i] ≤ 109 