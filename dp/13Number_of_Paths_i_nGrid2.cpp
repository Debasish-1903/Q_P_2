/*Number of Paths in Grid - 2

Time-Limit: 4 sec Score: 0.00/100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

Given a grid of size n*m, you need to find the total number of different paths from (1, 1) to (n, m). You are allowed to move from (x, y) to (x+1, y) and (x, y) to (x, y+1). The grid may have some blocked cells, represented by 1, and it is not allowed to move to a blocked cell. An empty cell is represented by 0. You are also given an integer k and you can convert at most k blocked cells into unblocked cells.


Input Format

The first line of the input contains one integer t - the number of test cases. Then t test cases follow.

The first line of each test case contains three space-separated integers n, m, k - the size of the grid and the number of cells you can convert.

Each of the following n lines contains m space-separated integers, aij - the number at that cell.


Output Format

For each test case, print the number of paths modulo 10^9 + 7.


Constraints

1 ≤ t ≤ 105

1 ≤ n, m ≤ 200

0 ≤ k ≤ 400

0 ≤ aij ≤ 1

It is guaranteed that the sum of nmk over all test cases does not exceed 108.


Sample Input 1

3
3 3 2
0 1 1
1 1 0
1 0 0
3 3 1
0 1 1
1 1 0
1 0 0
2 3 0
1 0 0
0 1 0

Sample Output 1

6
0
0

Note

For the first test case, any path from (1,1) to (n,m) has 2 blocked cells, which can be unblocked.

For the third test case, no cells can be unblocked and the first cell is blocked, so there are
 no paths from (1,1) to (n,m). */





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




 

ll n,m,k;
ll grid[210][210];
ll dp[210][210][410];


ll rec(ll r, ll c, ll k){
	
	// pruning 
	if(r<0||c<0)return 0;
	if(grid[r][c]==1){
		if(k<=0)return 0;
		else k--;
		
	}
	
	// base case 
	
	if(r==0&&c==0)return 1;
	// cache check 
	
	if(dp[r][c][k]!=-1)return dp[r][c][k];
	
	// compute 
	
	ll ans=0;
	ans=(rec(r-1,c,k)%mod);
	
	ans=(ans+(rec(r,c-1,k))%mod)%mod;
	
	
	// save and return 
	
	return dp[r][c][k]=ans;
	
	
	
	
	
	
}


void solve(){
	
	cin>>n>>m>>k;
	
	for(ll i=0;i<n;i++){
		
		
		for(ll j=0;j<m;j++){
			
			cin>>grid[i][j];
			
			for(ll l=0;l<=k;l++){
			dp[i][j][l]=-1;}
		}
	}
	
	cout<<rec(n-1,m-1,k)%mod<<nl;
	
	
	
	
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	 int _t; cin>>_t;while(_t--)
		solve();
	
	
	//cerr<<"Time elapsed: "<< 1.0*clock()/ CLOCKS_PER_SEC << "s.\n\n";
	
	
	
	
}