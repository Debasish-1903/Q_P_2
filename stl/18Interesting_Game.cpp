/*Interesting Game

Time-Limit: 1 sec Score: 1.00/100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

Alice and Bob are playing a new game, which is very interesting and fun. The game is as follows:

The game starts with two n-sized integer arrays, A and B, and is played by two players, P1 and P2.
The players move in alternating turns, with P1 always moving first. During each move, the current player must choose an integer, i, such that 0 ≤ i ≤ n - 1. If the current player is P1, then  P1 receives Ai points; if the current player is P2, then P2 receives Bi points.
Each value of i can be chosen only once. That is, if a value of i is already chosen by some player, none of the players can re-use it. So, the game always ends after n moves.
The player with the maximum number of points wins.
The arrays A and B are accessible to both the players P1 and P2. So the players make an optimal move at every turn.
Given the values of n, A, and B, can you determine the outcome of the game? P1 is Alice and P2 is Bob.
Print ‘Alice’ if Alice will win, 'Bob' if Bob will win, or 'Tie' if they will tie. Assume both players always move optimally.


Input Format

The first line of input contains one integer T (1 ≤ T ≤ 10) — the number of test cases. Then T test cases follow.
The first line of each test case contains N (2 ≤ N ≤ 1000), the number of elements in arrays A and B.
The second line contains N space-separated integers A1, A2, ..., AN - the elements of array A.
The third line contains N space-separated integers B1, B2, ..., BN - the elements of array B.


Output Format

For each test case, print one of the following predicted outcomes of the game on a new line:

Print 'Alice' if Alice will win.
Print 'Bob' if Bob will win.
Print 'Tie' if the two players will tie.

Constraints

1 ≤ T ≤ 10
2 ≤ N ≤ 1000
1 ≤ Ai, Bi ≤ 105


Sample Input 1

3

3

1 3 4

5 3 1

2

1 1

1 1

2

2 2

3 3


Sample Output 1

Alice

Tie

Bob


Note

Explanation 1:
The players make the following 3 moves:

Alice chooses i = 2 and receives 4 coins.
Bob chooses i = 0 and receives 5 coins. Notice that Bob won't choose i = 1, because this would cause Alice to win.
Alice chooses i = 1 (the only remaining move) and receives 3 coins.
The total score of Alice is 7, while the total score of Bob is 5. Hence, Alice wins.

Explanation 2:
Both players will only make 1 move and all possible point values are 1, the players will end the game with equal scores.

Explanation 3:
Both players will only make 1 move and all the possible point values for Bob are greater than all the possible point values for Alice, Bob will win the game. */

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define F first
#define S second

using ii = pair<int, int>;

bool comp(ii a, ii b) { return a.F + a.S > b.F + b.S; }

void solve() {
  int n;
  cin >> n;
  int a[n], b[n];
  vector<ii> arr;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) cin >> b[i];
  for (int i = 0; i < n; i++) arr.push_back({a[i], b[i]});

  sort(arr.begin(), arr.end(), comp);
  int asc = 0, bsc = 0, turn = 0;
  for (int i = 0; i < n; i++) {
    if (turn == 0) {
      asc += arr[i].F;
      turn++;
    } else {
      bsc += arr[i].S;
      turn--;
    }
  }

  if (asc > bsc)
    cout << "Alice" << endl;
  else if (asc == bsc)
    cout << "Tie" << endl;
  else
    cout << "Bob" << endl;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int _t = 1;
  cin >> _t;
  // string s; getline(cin, s);//

  while (_t--) {
    solve();
  }
}


/*
Approach

Optimal play is to make your score > opponent's score, NOT to maximize your score.
An optimal move isn't always to choose the maximum available element
Sometimes, optimal move is to choose smaller element which blocks a big element on the opponent's side.


Lets take an example : A = [ a , x ] B = [ b , y ]
If I am player 
1
: if I pick the first , my score is a , my opponents score is y
If I pick the second , my score is x , my opponents score is b
Condition for first choice to be better than second choice is that 
if I score better than my opponents score in first choice
a−y>x−b

a+b>x+y
After some thinking one may conclude, that in an optimal play the 
sequence of cards must have descending values.


It can be proven that the optimal move for the current player is to 
always choose the first unused element having the maximal value for 
Ai+Bi
, as the player will either add the largest number of points to their
 own score or block the opposing player from ever receiving a large number of points.

So now that we've established we must both maintain paired values and 
choose the first available index i having a maximal value for 
Ai+Bi
, we have to consider the most efficient way to find which index i to choose.
 The best way to do this is to sort each pair of values in descending order of the maximum sum of 
Ai and Bi.

Next, we simply need to traverse the sorted array from 
0 to 
n−1
, adding the appropriate number of points at index i (i.e., the paired value
 at i associated with the current player) to the current player's score.
  This means that in the ith move, the current player will make an optimal 
  move by choosing the ith element in the sorted array.

Once we've finished summing the scores, we simply compare them and print the appropriate result.

Time Complexity: 
O(NlogN)

Space Complexity: 
O(N)
 extra space */