Support Queries I

Time-Limit: 1 sec Score: 100.00/100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

Design a Data Structure which can support the following queries:

1 x: Add x in structure
2 x: Remove x from the structure if present in the structure. If x doesn't present in the structure, do nothing. If there are multiple occurrences of x, delete only one occurrence of x.
3 ?: Print the minimum number present in the structure. If the structure is empty, print -1.
4 ?: Print the maximum number present in the structure. If the structure is empty, print -1.
5 ?: Print the sum of all numbers present in the structure. If the structure is empty, print 0.

Initially, the structure is empty.


Input Format

The first line of input contains Q - the number of queries.
Next, Q lines contain queries of the format specified in the statement.


Output Format

For queries of type 3, 4 and 5, print the answer in a new line.


Constraints

1 ≤ Q ≤ 105
0 ≤ x ≤ 109


Sample Input 1

18

1 5

1 4

1 4

3 ?

4 ?

5 ?

2 4

3 ?

4 ?

5 ?

2 4

3 ?

4 ?

5 ?

2 5

3 ?

4 ?

5 ?


Sample Output 1

4

5

13

4

5

9

5

5

5

-1

-1

0