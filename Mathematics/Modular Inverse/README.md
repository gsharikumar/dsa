Modular Inverse
Difficulty: Easy
Given two integers n and m, return the smallest positive integer x such that (n * x) % m = 1, i.e., the modular multiplicative inverse of n under modulo m. If no such integer exists, return -1.

Examples :

Input: n = 3, m = 11
Output: 4
Explanation: Since (4 × 3) mod 11 = 1, 4 is the modulo inverse of 3 under mod 11.
Input: n = 10, m = 17
Output: 12
Explanation: Since (12*10) mod 17 = 1, 12 is the modulo inverse of 10.
Constraints:
1 ≤ n ≤ 104
1 ≤ m ≤ 105