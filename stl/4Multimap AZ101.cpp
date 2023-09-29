Multimap AZ101

Time-Limit: 1 sec Score: 100.00/100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Description

You are given Q queries and have to perform the following operations:

add x y - add student name X (string) for marks y (integer). If it already exists, add a new entry.
erase x - erase the first current entry of student with name x
eraseall x - erase all entries of student with name x
print x - print the first entry of marks of student with name x, if entry is not there for x, print 0.

Input Format

The first line of the input contains one integer T - the number of test cases. Then T test cases follow.

The first line of each test case contains one integer Q - the number of queries.

Each of the next Q ines contains queries.


Output Format

For each test case, print the required queries.


Constraints

1≤ T ≤ 105

1≤ Q ≤ 105

1≤ X ≤ 106

It is guaranteed that the sum of Q over all test cases does not exceed 105.


Sample Input 1

1
9
add alice 24
add bob 21
add alice 23
add alice 22
print alice
erase alice
print alice
eraseall alice
print alice

Sample Output 1

24
23
0

Note

Map becomes: [alice: 24]
Map becomes: [alice: 24, bob: 21]
Map becomes: [alice: 24, bob: 21, alice: 23]
Map becomes: [alice: 24, bob: 21, alice: 23, alice: 22]
alice: 24
Map becomes: [bob: 21, alice: 23, alice: 22] (since first entry of alice is removed)
alice: 23
Map becomes: [bob: 21]
key alice doesn't exist, hence alice: 0