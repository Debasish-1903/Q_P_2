Indexed Set

Time-Limit: 1 sec Score: 1.00/100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Description

You are given Q queries and have to perform the following operations:

add x - if x doesn't present in the set, add element x in the set. Otherwise do nothing.
remove x - remove element x from the set, if it exists. Otherwise do nothing.
find x - find the value at position x (0-indexing) if it exists. Otherwise print -1.
findpos x - find the position (0-indexing) of the element with value x if it exists. Otherwise, find the position that the element would have in the set
The set is ordered in the non-decreasing order of the elements.


Input Format

The first line of the input contains one integer T - the number of test cases. Then T test cases follow.
The first line of each test case contains one integer Q - the number of queries.
Each of the next Q lines contains queries.


Output Format

For each test case, print the required queries.


Constraints

1≤ T ≤ 105
1≤ Q ≤ 105
1≤ x ≤ 105

It is guaranteed that the sum of Q over all test cases does not exceed 106.


Sample Input 1

1
6
add 4
add 1
add 6
find 1
findpos 7
findpos 6

Sample Output 1

4
3
2

Note

Set becomes: [4]
Set becomes: [1, 4]
Set becomes: [1, 4, 6]
S[1] = 4
7 doesn’t exist in set, but if it did set would be: [1, 4, 6, 7] and S[3] = 7
S[3] = 6;