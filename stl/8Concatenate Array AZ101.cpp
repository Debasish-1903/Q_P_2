Concatenate Array AZ101

Time-Limit: 1 sec Score: 50.00/100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Description

You are given an array A of N integers. Find the length of the largest increasing subsequence if the array A is concatenated to itself N times. A sequence A is a subsequence of an array B if A can be obtained from B by deletion of several (possibly, zero or all) elements. The longest increasing subsequence should be strictly increasing.


Input Format

The first line of the input contains one integer T - the number of test cases. Then T test cases follow.

The first line of each test case contains one integer N - the length of the array. 

The second line of each test case contains N space-separated integers.


Output Format

For each test case, print the length of the largest increasing subsequence if the array A is concatenated to itself N times. 


Constraints

1≤ T ≤ 2*105

1≤ N ≤ 106

1≤ Ai ≤ 109

It is guaranteed that the sum of N over all test cases does not exceed 106.


Sample Input 1

3
3
2 1 3
5
3 1 1 1 4
4
3 2 1 4

Sample Output 1

3
3
4

Note

For the first test case, 2 1 3 2 1 3 2 1 3

For the second test case, 3 1 1 1 4 3 1 1 1 4 3 1 1 1 4 3 1 1 1 4 3 1 1 1 4

For the third test case, 3 2 1 4 3 2 1 4 3 2 1 4 3 2 1 4