/*Convex Polygon Triangulation

Time-Limit: 1 sec Score: 0.00/100
Difficulty : ***
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

You have a convex 
n
-sided convex polygon where each vertex has an integer value of
vi. You are given an integer array values where 
v[i]
 is the value of the ith
 vertex (i.e., clockwise order).

You will triangulate the convex polygon into n−2
 triangles. For each triangle, the value of that triangle is the product of the values of its vertices, 
 and the total score of the triangulation is the sum of these values over all 
 n−2
 triangles in the triangulation.

Output the smallest possible total score that you can achieve with some triangulation of the polygon.


Input Format

First Line contains 
T
 - the number of test cases.
The First Line of each test case contains 
n
 - the number of vertices of the convex polygon.
The second line of each test case contains 
n
 space-separated values 
v
[
i
]
 of the vertices in clockwise order.


Output Format

For each test case, Output the smallest possible total score that you can achieve with some triangulation of the polygon.


Constraints

1≤T≤103
3≤n≤100
1≤v[i]≤104

Sum of n over all test cases is ≤5000
.


Sample Input 1

3
6
1 3 1 4 1 5
3 
1 2 3
4
1 1 1 1

Sample Output 1

13
6
2

Note

For 1st test case, The minimum score triangulation has score 
1∗1∗3+1∗1∗4+1∗1∗5+1∗1∗1=13 */


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
#define v vector<long long int>
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
ll arr[110];
ll dp[110][110];

ll rec(ll l,ll r){
	
	// base case
	
	if(l+1==r)return 0;
	
	// cache and check
	
	if(dp[l][r]!=-1)return dp[l][r];
	
	// computing
	
	ll ans=1e18; 
	for(ll x=l+1;x<r;x++){
		
		ans=min(ans,rec(l,x)+rec(x,r)+(arr[x]*arr[l]*arr[r]));
		
		
	}
	
	
	
	// save and return 

	return dp[l][r]=ans;
}


void solve(){
	
	cin>>n;

	
	for(ll i=0;i<n;i++){
		
		cin>>arr[i];
	}
	
	memset(dp,-1,sizeof(dp));
	cout<<rec(0,n-1)<<nl;
	
	
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	 int _t; cin>>_t;while(_t--)
		solve();
	
	
	//cerr<<"Time elapsed: "<< 1.0*clock()/ CLOCKS_PER_SEC << "s.\n\n";
	
	
	
	
}