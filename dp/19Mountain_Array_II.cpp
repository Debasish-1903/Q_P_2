/*Mountain Array II

Time-Limit: 1 sec Score: 0.00/100
Difficulty : ***
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

You may recall that an array 
a
r
r
 is a mountain array if and only if:

a
r
r
.
l
e
n
g
t
h
≥
3
There exists some index 
i
 (
0
-indexed) with 
0
<
i
<
a
r
r
.
l
e
n
g
t
h
−
1
 such that:
a
r
r
[
0
]
<
a
r
r
[
1
]
<
.
.
.
<
a
r
r
[
i
−
1
]
<
a
r
r
[
i
]

a
r
r
[
i
]
>
a
r
r
[
i
+
1
]
>
.
.
.
>
a
r
r
[
a
r
r
.
l
e
n
g
t
h
−
1
]
Given an integer array​​​, output the minimum number of elements to remove to make 
a
r
r
​​​ a mountain array.
If mountain array is not possible, output -1.


Input Format

First-line contains 
T
 - the number of test cases.
First-line of each test case contains 
n
 - the length of the array 
a
r
r
.
Second-line of each test case contains 
n
 elements of array 
a
r
r
.


Output Format

For each test case, output the minimum number of elements to remove to make 
a
r
r
​​​ a mountain array.
If mountain array is not possible, output -1.


Constraints

1
≤
T
≤
1000

1
≤
n
≤
10
4

1
≤
a
r
r
[
i
]
≤
10
6

Sample Input 1

3
3
1 5 1
8
2 1 1 5 6 2 3 1
5
1 2 3 4 5

Sample Output 1

0
3
-1  */


#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define ull unsigned long long int
#define mod 1000000007
#define inf 1e9
#define mt make_tuple
#define pb push_back
#define eb emplace_back
#define pob pop_back
#define f first
#define s second
#define nl "\n"
#define pi pair<int,int>
#define vp vector<pair<int,int>>
#define vvl vector<vector<long long int>>
#define rep(n) for(int i=0 ; i<n ; i++)
#define rei(i) for(int i=n ; i>0 ; i--)
#define prio priority_queue
#define np next_permutation
#define N 200100

#define yes "YES"
#define no "NO"

ll n;

ll arr[10100];

ll lis_lr[10100], lis_rl[10100];

void solve(){
	cin>>n;
	for(ll i=0;i<n;i++){
		cin>>arr[i];
	}

	vector<ll> temp;
	for(ll i=0;i<n;i++){
		auto it = lower_bound(temp.begin(), temp.end(), arr[i]);
		if(it == temp.end())
			temp.pb(arr[i]);
		else
			*it = arr[i];
		lis_lr[i] = temp.size();
	}

	temp.clear();
	for(ll i=n-1;i>=0;i--){
		auto it = lower_bound(temp.begin(), temp.end(), arr[i]);
		if(it == temp.end())
			temp.pb(arr[i]);
		else
			*it = arr[i];
		lis_rl[i] = temp.size();
	}

	ll ans = 0;
	for(ll i=0;i<n;i++){
		if(lis_lr[i] > 1 && lis_rl[i] > 1)
			ans = max(ans, lis_lr[i] + lis_rl[i] - 1);
	}

	if(ans >= 3)
		cout<<n-ans<<nl;
	else
		cout<<-1<<nl;
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	 int _t; cin>>_t;while(_t--)
		solve();
}
