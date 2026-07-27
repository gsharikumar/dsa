The Modified String
Difficulty: Easy
Ishaan is playing with strings these days. He has found a new string. He wants to modify it as per the following rules to make it valid:

The string should not have three consecutive same characters.
He can add any number of characters anywhere in the string. 
Find the minimum number of characters which Ishaan must insert in the string to make it valid.

Examples:

Input: s = "aabbbcc"
Output: 1
Explanation: In "aabbbcc" 3 b's occur consecutively, we add a 'd',and Hence, output will be "aabbdbcc".
Input: s = "aaaaa"
Output: 2
Explanation: In "aaaaa" 5 a's occur consecutively,we need to add 2 'b', and Hence, the output will be "aababaa".
Constraints : 
1 ≤ |s|≤ 105