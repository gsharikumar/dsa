Nth Catalan Number

Difficulty: Medium

Given a number n, the task is to find the nth catalan number.  Catalan Number for n is equal to the number of expressions containing n pairs of parenthesis that are correctly matched, i.e., for each of the n(' there exist n ')' on there right and vice versa. 

The first few Catalan numbers for n = 0, 1, 2, 3, … are 1, 1, 2, 5, 14, 42, 132, 429, 1430, 4862, …

Examples:

Input: n = 3
Output: 5
Explanation: Possible expressions are, ((())), (()()), ()(()), (())(), ()()()
Input: n = 4
Output: 14
Explantions: There are total 14 valid combinations which can be formed using 4 parenthesis.
Constraints:
1 <= n <= 19