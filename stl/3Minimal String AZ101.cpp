Minimal String AZ101

Time-Limit: 1 sec Score: 1.00/100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Description

You are given a string S along with 2 empty strings T and U. You can make the following two moves: pop first character of S and append it to T or pop last character of T and append it to U.

You need to make the string U lexicographically minimum such that string S and T are empty.


Input Format

The first line of the input contains one integer T - the number of test cases. Then T test cases follow.

The first line of each test contains a string S.


Output Format

For each test case, print the lexicographically minimum possible string U.


Constraints

1≤ T ≤ 106

1≤ |S| ≤ 106

It is guaranteed that the sum of |S| over all test cases does not exceed 106.


Sample Input 1

3
bdab
sss
gtddb

Sample Output 1

abdb
sss
bddtg

Note

For the first test case, S = bdab

S = dab, T = b, U = 
S = ab, T = bd, U = 
S = b, T = bda, U = 
S = b, T = bd, U = a
S = , T = bd, U = ab
S = , T = b, U = abd
S = , T = , U = abdb
For the second test case, S = sss

S = ss, T = s, U = 
S = s, T = ss, U = 
S = s, T = s, U = s
S = , T = ss, U = s
S = , T = s, U = ss
S = , T = , U = sss
For the third test case, S = gtddb

S = tddb, T = g, U = 
S = ddb, T = gt, U = 
S = db, T = gtd, U = 
S = b, T = gtdd, U = 
S = , T = gtddb, U = 
S = , T = gtdd, U = b
S = , T = gtd, U = bd
S = , T = gt, U = bdd
S = , T = g, U = bddt
S = , T =, U = bddtg