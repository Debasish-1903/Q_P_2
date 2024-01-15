Travel Optimisation

Time-Limit: 3 sec Score: 0.00/100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

Vivek wants to travel from city 
1 to N, He can travel across each consecutive city i.e i→ i+1
 using Bus by paying cost A[i]
, and can also travel from city i to a different city j. at most k cities away from i
 i.e abs(i−j)≤k through a Flight by paying B[i]+B[j] charges, but he cannot take more than 
M flights during his travel.

Find the minimum cost to reach from city 
1 to N.


Input Format

First-line contains 
T
 - the number of test cases.
The First Line of each test case contains 
N, M ,and k.
The second line of each test case contains 
N elements of cost array A
.
The third line of each test case contains 
N elements of cost array B
.


Output Format

For each test case, Output the minimum cost to reach from city 1
to N
.


Constraints
1≤T≤1000

1≤k≤N≤106
0≤M≤N
1≤A[i],B[i]≤106
Sum of N∗M
over all test cases 
≤
10
8
.


Sample Input 1

1
5 3 2
1 2 3 4 5
1 1 2 1 7

Sample Output 1

7

Note

Travel from 1 to 2 using Bus -> 1
Travel from 2 to 4 using Flight -> 1 + 1 = 2
Travel From 4 to 5 using Bus -> 4
Total Cost = 7



//complete approachj 


Naive 
O(N∗K∗M)DP :State : dp[i][f]→ min cost to reach ith city from 1st
 city using 
f
 flights.

Transition: 
dp[i][f]=min(dp[i−1][f]+A[i−1],Z)where 
Z=min(dp[i−j][f−1]+B[i]+B[i−j])
 , over all 1≤i−k≤j<i.
→ O(k)
 in transition, 
O(N∗k∗M)
 overall complexity.

Transition Optimisations: ( Only applicable to Bottom up approach )

1.O(logK)Time transition and O(N∗M∗logK) overall time solution using multiset to store 
min(dp[i−j][f−1]+B[i−j])of previous k size window.
2. O(1) Time transition ,  O(N∗M) overall Time and O(N∗M) Space overall solution using min deque to store 
min(dp[i−j][f−1]+B[i−j])of previous k size window.

Further Memory Optimisations : ( O(N) Space Reduction )
Transitions of the current state only depend on the last state of flight count, so store only 
2 rows of memory.

Note -:
Expected Complexity per test case for this problem is -
Time : O(N∗M).
Space : O(N).


#include <bits/stdc++.h>
using namespace std;

#define ll int64_t
#define endl '\n'

vector<vector<ll>> dp;
vector<int> a, b;
int n, m, k;

void solve() { // O(N*M) Time, O(N) space.
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++)cin >> a[i];
    for (int i = 1; i <= n; i++)cin >> b[i];
    vector<vector<ll>> dp(n + 1, vector<ll>(2, 1e18));
    dp[1][0] = 0;
    ll ans = 1e18;
    for (int j = 0; j <= m; j++) {
        deque<int> dq;
        dq.push_front(1);
        for (int i = 2; i <= n; i++) {
            dp[i][j & 1] = min(dp[i][j & 1], dp[i - 1][j & 1] + a[i - 1]);
            if (j == 0)continue;
            while (!dq.empty() && dq.front() < i - k)dq.pop_front();
            dp[i][j & 1] = min(dp[i][j & 1], dp[dq.front()][(j - 1) & 1] + b[dq.front()] + b[i]);
            while (!dq.empty() && dp[dq.back()][(j - 1) & 1] + b[dq.back()] >= dp[i][(j - 1) & 1] + b[i])dq.pop_back();
            dq.push_back(i);
        }
        ans = min(ans, dp[n][j & 1]);
    }
    cout << ans << endl;
}
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);

#ifdef Mastermind_
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#endif
    int t = 1;
    // int i = 1;
    cin >> t;
    while (t--) {
        // cout << "Case #" << i << ": ";
        solve();
        // i++;
    }
    return 0;
}


//arsh agarwal solution 

#include <bits/stdc++.h> 
using namespace std;
#define int long long

void solve(){
    int n, m, k; cin>>n>>m>>k;
    int a[n], b[n]; for(int i = 0; i < n; i++) cin>>a[i];
    for(int i = 0 ; i < n; i++) cin>>b[i];
    int dp[2][n]; for(int i = 0; i < n; i++) dp[1][i] = 1e18;
    dp[0][0] = 0; for(int i = 1; i < n; i++) dp[0][i] = dp[0][i-1] + a[i-1];

    int ans = dp[0][n-1];
    for(int i = 1; i <= m; i++){
        deque<int> q; q.push_back(dp[(i-1)&1][0] + b[0]);
        for(int j = 1; j < n; j++){
            dp[i&1][j] = min(dp[i&1][j-1]+a[j-1], q.front() + b[j]);
            while(!q.empty() and q.back()>dp[(i-1)&1][j]+b[j]) q.pop_back();
            q.push_back(dp[(i-1)&1][j] + b[j]);
            if(j>=k and q.front()==dp[(i-1)&1][j-k]+b[j-k]) q.pop_front();
        }
        ans = min(ans, dp[i&1][n-1]);
    }
    cout << ans << '\n';
}   

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //solve();
    int t; cin >> t; for(int i = 0; i < t; i++) solve();
    return 0;
}


