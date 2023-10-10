/*N-Queens Revisited

Time-Limit: 3 sec Score: 1.00/100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

An S-Queen is a chess piece that combines the power of a knight and a queen. 
Find the number of ways to place N S-Queens on N x N chessboard.



Input Format

The input contains only single integer N denoting the side of the chessboard. 


Output Format

Print the number of ways to place N S-Queens on the N x N chessboard.


Constraints

2 ≤ N ≤ 14


Sample Input 1

3

Sample Output 1

0

Sample Input 2

10

Sample Output 2

4
*/


/*Try to think in the track of N-Queens problems.


You only have to maintain one more condition for the knight.


Change the N-Queens solution discussed in the session. */

#include<bits/stdc++.h>
using namespace std;
#define int long long int
int n;
int ans = 0;
vector<int> v;

int checker(int x, int y) {
  for (int i = 0; i < x; i++) {
    if (v[i] == y || (v[i] + i) == (x + y) || (v[i] - i) == (y - x)) return 0;
  }
  if ((x - 1) >= 0) {
    if (v[x - 1] == y - 2 || v[x - 1] == y + 2) return 0;
  }
  if ((x - 2) >= 0) {
    if (v[x - 2] == y - 1 || v[x - 2] == y + 1) return 0;
  }
  return 1;
}

void back_tracking(int level) {
  if (level == n) {
    ans++;
    return;
  }
  for (int i = 0; i < n; i++) {
    if (checker(level, i)) {
      v.push_back(i);
      back_tracking(level + 1);
      v.pop_back();
    }
  }
}

void solve() {
  cin >> n;
  back_tracking(0);
  cout << ans << "\n";
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  // int t;cin>>t;while(t--)
  solve();
}


