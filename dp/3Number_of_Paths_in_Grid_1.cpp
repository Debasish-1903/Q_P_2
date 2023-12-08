
/*Number of Paths in Grid - 1

Time-Limit: 1 sec Score: 0.00/100
Difficulty : *
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

Given a grid of size n*m, you need to find the number of paths from (1, 1) to (n, m). You are allowed to move from (x, y) to (x+1, y) and (x, y) to (x, y+1). The grid may have some blocked cells, represented by 1, and it is not allowed to move to a blocked cell. An empty cell is represented by 0.


Input Format

The first line of the input contains one integer t - the number of test cases. Then t test cases follow.

The first line of each test case contains two space-separated integers n, m - the size of the grid.

Each of the following n lines contains m space-separated integers, aij - the number at that cell.


Output Format

For each test case, print the number of paths modulo 109 + 7.


Constraints

1 ≤ t ≤ 105

1 ≤ n, m ≤ 103

0 ≤ aij ≤ 1

It is guaranteed that the sum of n*m over all test cases does not exceed 106.


Sample Input 1

3
2 3
0 1 0
0 0 0
3 3
0 0 1
0 0 0
0 0 0
2 2
1 0
0 0

Sample Output 1

1
5
0

Note

For the first test case, there is only one path, (1, 1) → (2, 1) → (2, 2) → (2, 3).

For the third test case, no path can reach (2, 2) since the starting point is blocked.*/


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



ll n,m;

ll arr[1010][1010];

ll dp[1010][1010];

//bool done[1010][1010];


ll rec(ll r,ll c){ //
	
	
	// pruning 
	if(arr[r][c]==1||r<0||c<0)return 0;
	
	// base case
	
	if(r==0&&c==0)return 1;
	
	
	// cache check
	
	if(dp[r][c]!=-1)return dp[r][c];
	
	// compute 
	
	ll ans=(rec(r-1,c))%mod;
	
	ans=(ans+(rec(r,c-1))%mod);
	
	
	
	// save and retunr
	
	//done[r][c]=true;
	
	return dp[r][c]=ans;
	
	
	

}



void solve(){
	
	cin>>n>>m;
	
	
	for(int i=0;i<n;i++){
		
		for(int j=0;j<m;j++){
			
			cin>>arr[i][j];
			
			//done[i][j]=false;
			dp[i][j]=-1;
			
		}
	}
	
	//memset(dp,-1,sizeof(dp));
	
	cout<<rec(n-1,m-1)%mod<<nl;
	
	
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	 int _t; cin>>_t;while(_t--)
		solve();
	
	
	//cerr<<"Time elapsed: "<< 1.0*clock()/ CLOCKS_PER_SEC << "s.\n\n";
	
	
	
	
}