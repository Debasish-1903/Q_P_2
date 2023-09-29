Good Sequence AZ101

Time-Limit: 1 sec Score: 100.00/100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Description

You are given an array A of N integers. A sequence is called good if the value x occurs x times in the array. Find the minimum number of integers you need to delete from A to make it good.


Input Format

The first line of the input contains one integer T - the number of test cases. Then T test cases follow.

The first line of each test case contains one integer N - the length of the array. 

The second line of each test case contains N space-separated integers.


Output Format

For each test case, print the minimum number of integers you need to delete from A to make it good.


Constraints

1≤ T ≤ 105

1≤ N ≤ 105

1≤ Ai ≤ 109

It is guaranteed that the sum of N over all test cases does not exceed 106.


Sample Input 1

3
5
3 2 3 3 1
4
3 2 2 4
5
6 6 1 1 2

Sample Output 1

1
2
4

Note

For the first test case, remove 2

For the second test case, remove 3 and 4

For the third test case, remove 6, 6, 1 and 2