/*
Solve the Equation

Time-Limit: 1 sec Score: 1.00/100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

You have given an equation of the form  (a op1 b op2 c) mod p
op1, op2 are operators which can be {+, -, *, /}.
Consider the example: (a * b / c) mod p. Here op1 = * and op2 = /.
It is guaranteed that (a, p) = (b, p) = (c, p) = 1 and p is a prime number.
Compute the value of the equation.

Note: 

(a, b) = 1, means a and b are coprime numbers.
Operators follow the same precedence rules as in mathematics.

Input Format

The first line contains T (1 ≤ T ≤ 100000), the number of test cases.
Each of the next T lines contains an equation in the form (a op1 b op2 c) mod p (1 ≤ a, b, c, p ≤ 109).
It is guaranteed that (a, p) = (b, p) = (c, p) = 1 and p is a prime number.


Output Format

For each test case, print a single number denoting the value of the equation. Since it is mod p, the value must belong to 0 to p - 1.


Sample Input 1

2

(1 + 2 / 1) mod 3

(2 * 3 - 8) mod 5


Sample Output 1

0

3


Note

Explanation 1:
(1 + 2 / 1) mod 3 = 3 mod 3 = 0.

Explanatino 2:
(2 * 3 - 8) mod 5 = -2 mod 5 = 3.

*/


#include <bits/stdc++.h>
using namespace std;
#define IOS                \
  ios::sync_with_stdio(0); \
  cin.tie(0);              \
  cout.tie(0);
#define ll long long

ll mod = 1000000007;

ll add(ll a, ll b) { return ((a % mod) + (b % mod)) % mod; }
ll sub(ll a, ll b) {
  ll ans = ((a % mod) - (b % mod)) % mod;
  ans %= mod;
  ans = (ans + mod) % mod;
  return ans;
}
ll mul(ll a, ll b) { return ((a % mod) * (b % mod)) % mod; }
ll power(ll a, ll b) {
  ll ans = 1;
  while (b) {
    if (b % 2) {
      ans = ((ans % mod) * (a % mod)) % mod;
    }
    a = ((a % mod) * (a % mod)) % mod;
    b /= 2;
  }
  return ans;
}
ll res(char op, ll a, ll b) {
  if (op == '+')
    return add(a, b);
  else if (op == '-')
    return sub(a, b);
  else if (op == '*')
    return mul(a, b);
  else
    return mul(a, power(b, mod - 2));
}

signed main() {
  IOS ll t;
  cin >> t;
  ll a, b, c;
  string s;
  getline(cin, s);
  while (t--) {
    char op1, op2;
    string s1, s2, s3;
    cin >> s1 >> op1 >> b >> op2 >> s2 >> s3 >> mod;
    a = stoi(s1.substr(1));
    s2.pop_back();
    c = stoi(s2);
    ll ans = 0;
    if ((op1 == '+') || (op1 == '-')) {
      if ((op2 == '+') || (op2 == '-')) {
        ans = res(op1, a, b);
        ans = res(op2, ans, c);
      } else {
        ans = res(op2, b, c);
        ans = res(op1, a, ans);
      }
    } else {
      ans = res(op1, a, b);
      ans = res(op2, ans, c);
    }
    cout << ans << "\n";
  }
  return 0;
}