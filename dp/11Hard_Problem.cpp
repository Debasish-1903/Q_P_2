/*Hard Problem

Time-Limit: 6 sec Score: 0.00/100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Description

You are given a string S with length N. Each character is assigned a cost for removing it. Find the minimum cost for removing characters such that it does not contain any subsequence ‘hard’.


Input Format

The first line of the input contains one integer T - the number of test cases. Then T test cases follow.

The first line of each test case contains one integer N - the length of the array. 

The second line of each test case contains a string S.

The third line of each test case contains N space-separated integers - the cost of removing a character.


Output Format

For each test case, print the minimum cost for removing characters such that it does not contain any subsequence ‘hard’.


Constraints

1≤ T ≤ 1000

1≤ N ≤ 10^5

1≤ Ai ≤ 10^9


Sample Input 1

3
4
abcd
1 2 3 4
10
hhhaaarrdd
1 2 3 4 1 2 3 4 2 3
4
hard
2 1 4 6


Sample Output 1

0
5
1  */



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
string str;
ll cost[100100];

ll dp[100100][5];

string t="hard";    // form 1
ll rec(ll level,ll match){  // matching and removing  characters of "hard" from [level,......n-1] with min cost;
	
	// pruning
	
	if(match==4)return 1e15;
	 
	// basecase
		
		if(level==n){
			return 0;
			
		}
	
	// cache checked
		if(dp[level][match]!=-1)return dp[level][match];
	
	// compute
		
		ll ans=1e15;
		
	
		
		if(str[level]==t[match]){
				ans=min(ans,cost[level]+rec(level+1,match));
			
			ans=min(ans,rec(level+1,match+1));
		}else ans=min(ans,rec(level+1,match));
	
	// save and return 
	return dp[level][match]=ans;
	
	
	
	
	
}

 
void solve(){
	
	cin>>n;
	
	cin>>str;
	memset(dp,-1,sizeof(dp));
	
	for(ll i=0;i<n;i++){
		cin>>cost[i];
	}
	
	
	cout<<rec(0,0)<<nl;
	
	
	
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	 //int _t; cin>>_t;while(_t--)
		solve();
	
	
	//cerr<<"Time elapsed: "<< 1.0*clock()/ CLOCKS_PER_SEC << "s.\n\n";
	
	
	
	
}