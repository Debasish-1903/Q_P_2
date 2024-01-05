/*Round and Round

Time-Limit: 2 sec Score: 1.00/100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

Bob is standing in a park at (0,0) facing north. He is given a series of instructions to move around the park. The instructions can be:

‘W’: go straight 1 unit
‘L’: turn 90 degrees left
‘R’: turn 90 degrees right
Bob has to perform the given instructions forever. If he is going in a circle forever, print ‘YES’. Otherwise, print ‘NO’ (without the quotes).


Input Format

The first line of the input contains one integer T - the number of test cases. Then T test cases follow.
The first line of each test case contains N - the length of the input string of instructions.
The second line of each test case contains one string S - the series of instructions to move around the park.


Output Format

For each test case, print ‘YES’ if Bob is going in a circle forever. Otherwise, print ‘NO’. (without the quotes)


Constraints

1≤ T ≤ 100
1≤ |S| ≤ 105 where |S| denotes the length of the given series of instructions.


Sample Input 1

3

3

WWW

2

LW

4

WLLW


Sample Output 1

NO

YES

YES


Note

In the first sample test case, Bob moves north indefinitely.

In the second sample test case, Bob moves as follows: (0,0) => (-1,0) => (-1,-1) => (0,-1) => (0,0). So, Bob goes in a circle forever


In the third sample test case, Bob moves from (0,0) to (0,1) turns 180 degress and returns to (0,0). So, Bob goes in a circle foreve*/



//approach

/*

We use two variables x and y to represent the current position of Bob. Initially, both are set to 
0
, as Bob starts at the origin 
(
0
,
0
)
.
We also use a variable direction to keep track of the direction in which Bob is facing. Initially, Bob is facing north (direction = 
0
).
If the current instruction is 'L', we turn 
90
 degrees to the left by decrementing the direction by 
1
 and taking the modulo by 
4
.
If the current instruction is 'R', we turn 
90
 degrees to the right by incrementing the direction by 
1
 and taking the modulo by 
4
.
If the current instruction is 'W', we move forward by 
1
 unit in the direction that Bob is facing. We do this by updating the values of x and y based on the current direction.

Finally, if Bob returns to origin or the direction is not 0 (i.e., Bob is not facing north), then we print "YES", otherwise, we print "NO".

Time Complexity:
The time complexity of this solution is 
O
(
N
)
, where 
N
 is the length of the input string S. This is because we are processing each instruction in the string only once.

*/

#include <bits/stdc++.h>
using namespace std;

#define IOS                \
  ios::sync_with_stdio(0); \
  cin.tie(0);              \
  cout.tie(0);

int main() {
  IOS int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int x = 0, y = 0;
    int direction = 0;  // 0-north, 1-west, 2-south, 3-east
    bool flag = false;
    for (int i = 0; i < n; i++) {
      if (s[i] == 'L')
        direction = (direction + 3) % 4;
      else if (s[i] == 'R')
        direction = (direction + 1) % 4;
      else {
        if (direction == 0)
          y++;
        else if (direction == 1)
          x--;
        else if (direction == 2)
          y--;
        else
          x++;
      }
    }
    if ((x == 0 && y == 0) || direction != 0)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
