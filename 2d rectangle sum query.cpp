/*Rectangle Sum Query

Time-Limit: 4 sec Score: 1.00/100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

Given a 2d-array of dimension N*M and Q queries. In each query four integers x1, y1, x2, y2 is given, you have to find the sum of submatrix with (x1,y1) be the leftmost corner and (x2,y2) be the rightmost corner %10^9+7.


Input Format

The first line contains three space-separated integers N, M, Q where 1<=N, M<=10^3, 1<=Q<=10^6.

Next N lines contains M space-separated integers (-1e9<=Aij<=1e9).

Next Q lines contains four space separated integers x1, y1, x2, y2 where 1<=x1<=x2<=N, 1<=y1<=y2<=M.


Output Format

For each query print, the sum of submatrix with (x1,y1) be the leftmost corner and (x2,y2) be the rightmost corner in a new line %10^9+7.


Sample Input 1

5 5 5
-1 2 3 -4 2
0 0 0 0 4
1 2 4 3 5
-1 -5 -2 3 4
0 -3 -5 3 -6
1 1 2 2
1 2 3 4
2 3 3 3
4 4 4 4
2 3 2 4

Sample Output 1

1
10
4
3
0  */

#include <bits/stdc++.h>

using namespace std;
int mod = 1e9 + 7;
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, m, q;
  cin >> n >> m >> q;
  long long arr[n + 1][m + 1];
  memset(arr, 0, sizeof(arr));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> arr[i][j];
      arr[i][j] += arr[i - 1][j] + arr[i][j - 1] - arr[i - 1][j - 1];
    }
  }
  while (q--) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    long long ans =
        arr[x2][y2] - arr[x1 - 1][y2] - arr[x2][y1 - 1] + arr[x1 - 1][y1 - 1];
    ans %= mod;
    if (ans < 0) ans += mod;
    cout << ans << '\n';
  }
  return 0;
}