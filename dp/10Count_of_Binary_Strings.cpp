


/*Find the number of binary strings of length n where “0100” is not present as a substring.


Input Format

The first line of the input contains one integer t - the number of test cases. Then t test cases follow.

The first and only line of each test case contains an integer n.


Output Format

For each test case, print the number of binary strings of length n where “0100” is not present as a substring mod 10^9+7.


Constraints

1 ≤ t ≤ 106

1 ≤ n ≤ 106 where n is the length of the string.


Sample Input 1

3
3
4
5

Sample Output 1

8
15
28

Note

For the first test case, n = 3, so “0100” cannot be a substring.

For the second test case, there are total 24 = 16 substrings out of which “0100” is a substring. So, the answer is 16-1 = 15.


1
*/




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

string str="0100";

ll n;

ll dp[100100][5];

ll rec(ll level,ll match){
	
	//pruning
	
	if(match==4)return 0;
	
	// basecase
	
	if(level==0)return 1;
	
	//cache check
	if(dp[level][match]!=-1)return dp[level][match];
	
	
	// compute
	
	ll ans=0;
	
	if(match==0){
		
		ans=rec(level-1,0)+rec(level-1,1);
		
	}else if(match==1){
		
		ans=rec(level-1,1)+rec(level-1,2);
		
	}else if(match==2){
		
		ans=rec(level-1,3)+rec(level-1,0);
		
	}else if(match==3){
		
		ans=rec(level-1,4)+rec(level-1,2);
		
	}
	
	
	// save and return
	
	return dp[level][match]=ans;
	
	
	
	
}

void solve(){
	
	cin>>n;
	
	
	cout<<rec(n,0)<<nl;
	
	
	
	
	
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	memset(dp,-1,sizeof(dp));
	
	int _t; cin>>_t;while(_t--)
		solve();
	
	
	//cerr<<"Time elapsed: "<< 1.0*clock()/ CLOCKS_PER_SEC << "s.\n\n";
	
	
	
	
}