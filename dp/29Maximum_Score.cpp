/*Maximum Score

Time-Limit: 2 sec Score: 0.00/100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

You are standing on the lowest row of a chessboard and can only move, upwards and leftwards or upwards and rightwards. There is a predefined score on each cell of the chessboard. You can start from any cell in the lowest row and you have to reach the uppermost row such that your score is the maximum possible and it is divisible by K. You have to find the maximal score you can achieve.


Input Format

The first line of the input contains one integer T - the number of test cases. Then T test cases follow.

The first line of each test case contains three space-separated integers N, M, and K - the length of the array.

Each of the next N lines contains M digits from 0-9 indicating the score at that cell.


Output Format

For each test case, if it is possible, you have to find the maximal score you can achieve. If it is impossible print -1.


Constraints

1≤ T ≤ 100

1 ≤ N, M ≤ 100

1≤ K ≤ 11

 


Sample Input 1

3
4 3 11
194
707
733
633
2 4 2
3916
9593
2 2 4
15
52

Sample Output 1

22
18
-1

Note

For the first test case, we start from A[4][3] and get the score as 3+3+7+9 = 22 which is divisible by 11.

For the second test case, we start from A[2][1] and get the score as 9+9 = 18, which is divisible by 2. You can also start from A[2][3] to get the same result.

For the third test case, there is no way to reach the top row with the score as a multiple of k.*/



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
 ll arr[101][101];
 
  ll dp[101][101][20];
 
 
 
 ll rec(ll i,ll j,ll l){ // giving the max (best )at the indexi,j which is divisible by k;
 	
 	
 	//pruning 
 	
 	if(i<0||j<0||j>=m)return -1e9;
 	
 	// base case
 	
 	
 	if(i==0){
 		
 		
 		if(l==0)return arr[i][j];
 		else return -1e9;
 	}
 	
 	// cache check
 	
 	ll ans=-1e9;
 	
 	if(dp[i][j][l]!=-1)return dp[i][j][l];
 	
 	
 	// compute
 	 ans=max(ans,rec(i-1,j-1,(l+arr[i][j])%k),rec(i-1,j+1,(l+arr[i][j])%k));
 	
 	
 	
 	
 	
 	
 	// retun and save 
 	return dp[i][j][l]=ans;
 	
 	
 	
 	
 	
 	
 }

void solve(){
	
cin>>n>>m>>k;

	for(ll i=0;i<n;i++){
		
		for(ll j=0;j<m;j++){
			
			
			cin>>arr[i][j];
		}
	}
	
	memset(dp,-1,sizeof(dp));
	
	ans=-1;
    for(ll j=0;j<m;j++){
    	
    	ans=max(ans,rec(n-1,j,0));
    	
    	
    }
    
    cout<<ans<<nl;
	
	
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	// int _t; cin>>_t;while(_t--)
		solve();
	
	
	//cerr<<"Time elapsed: "<< 1.0*clock()/ CLOCKS_PER_SEC << "s.\n\n";
	
	
	
	
}