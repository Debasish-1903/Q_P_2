/* Inefficient Program

Time-Limit: 1 sec Score: 1.00/100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

Consider the following function.

long long get(long long L, long long R, long long m) {
    long long sum = 0;
    for(long long i = L; i <= R; i++) {
        sum += (i % m);
        sum %= 1000000007;
    }
    return sum;
}
The above program is very inefficient for larger values of L, R, m.
Your challenge is to write an efficient program, that will find the value of get function in very less time.


Input Format

The first line of input contains one integer T — the number of test cases. Then T test cases follow.
The only line of each test case contains three space-separated numbers L, R, and m.


Output Format

For each test case, print a number on a new line denoting the answer return by get function in the above program.


Constraints

1 ≤ T ≤ 105
1 ≤ L ≤ R ≤ 1018
1 ≤ m ≤ 1018


Sample Input 1

3

4 5 6

4 10 9

1 10000000000000000 93464156618


Sample Output 1

9

31

14972415


Note

Explanation 1:
Sum = (4 % 6 + 5 % 6) % 1000000007 = 9

Explanation 2:
Sum = (4 % 9 + 5 % 9 + 6 % 9 + 7 % 9 + 8 % 9 + 9 % 9 + 10 % 9) % 1000000007 = 4 + 5 + 6 + 7 + 8 + 0 + 1 = 31  */

/*
Let's try to solve the problem when 'l' is always 1. Let's denote mod = 109 + 7 and rm = R % m;

Let F(n, m) = get(1, n, m). Now get(l, r, m) = (F(r, m) - F(l - 1, m)) % mod. Now how to calculate F(n, m) efficiently?

Observe the pattern:
F(n, m) = (0+1+2+3..+(m-1)+0+1+...+(m-1)+0+1+...+(m-1)+...+0+1+2+...+(rm)) % mod.

We can see that the sum 0+1+2+3..+(m-1) is repeating (R+1)/m times. And yes, now we can solve the problem.

If rm == 0: F(n, m) = (m * (m - 1) / 2 * (R / m)) % mod
Else F(n, m) = (m * (m - 1) / 2 * (R / m) + rm * (rm + 1) / 2) % mod

Now the challenge is that we have to take mod properly so that we can avoid overflow. You can refer through Solution Code to learn how to avoid overflow.

Time Complexity: O(1)
Space Complexity: O(1) extra space




*/


#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define LD long double

const int N = 100010;

int inf = 1e9;
int mod = 1e9 + 7;

ll cal(ll n) {
    ll x = n, y = n + 1;
    if(x % 2 == 0) x /= 2;
    else y /= 2;
    x %= mod; y %= mod;
    ll ans = x * y % mod;
    if(ans < 0) ans += mod;
    return ans;
}

ll get(ll n, ll m) {
    ll t = (n + 1) / m;
    t %= mod;
    ll ans = cal(m - 1) * t % mod;
    n %= m;
    if(n < 0) n += m;
    if(n < m - 1) ans += cal(n);
    ans %= mod;
    if(ans < 0) ans += mod;
    return ans;
}

signed main()
{
    //freopen("IN", "r", stdin);
    //freopen("OUT", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int T = 1; cin >> T;
    assert(T > 0 && T <= 100000);
    while(T--) {
        ll L, R, M;
        cin >> L >> R >> M;
        assert(L > 0 && R > 0 && L <= R && M > 0 && M <= 1e18);
        ll ans = get(R, M) - get(L - 1, M);
        ans %= mod;
        if(ans < 0) ans += mod;
        cout << ans << "\n";
    }
    return 0;
}