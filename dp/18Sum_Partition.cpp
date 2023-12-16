/*Sum Partition

Time-Limit: 2 sec Score: 0.00/100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

Find the number of unordered ways, 
N
 can be partitioned into 
K
 positive integers (i.e 
>
0
 ), i.e sum of all 
K
 numbers must be 
N
.

Print the answer 
m
o
d
 
10
9
+
7
.

For eg. 
N
=
7
, 
K
=
3
, then the number of unordered ways are 
4
.
Explanation : { 1, 5, 1 }, { 2, 2, 3 }, { 4, 2, 1 }, and { 3, 1, 3 }.
Note : { 1, 5, 1 }, { 1, 1, 5 } and { 5, 1, 1 } are treated as same combination, i.e order doesn't matter.


Input Format

First-line contains 
T
 - the number of test cases.
The first line of each test case contains two integers - 
N
 and 
K
.


Output Format

For each test case, Output the number of unordered ways, 
N
 can be partitioned into 
K
 positive integers .


Constraints

1
≤
T
≤
10
6

1
≤
N
≤
5000

1
≤
K
≤
5000

Sample Input 1

3
1 1
7 3
4 5

Sample Output 1

1
4
0  */


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





ll n,k;

ll dp[5100][5100];


ll rec(ll n,ll k){
//cout<<"n :"<<n<<" k :"<<k<<" ans:"<<ans<<nl;
	// pruning 
	if(n<k||n<0||k<0)return 0;
	
	
	// basecase 
	if(k==1){
		if(n>=1)return 1;
	}
	
	
	// cache checking 
	if(dp[n][k]!=-1)return dp[n][k];
	
	
	// compute 
	
   	ll ans=0;
	
	ans=(rec(n-1,k-1)%mod);
//	cout<<"n :"<<n<<" k :"<<k<<" ans:"<<ans<<nl;
	ans+=((rec(n-k,k)%mod))%mod;  // move to kth position without any partition and ther explore +take 1 with one partiion and explore everything from their
	
	// save and return 
//	cout<<"n :"<<n<<" k :"<<k<<" ans:"<<ans<<nl;
	
	return dp[n][k]=ans;
	
	
	
	
	
	
	
	
}

void solve(){
	cin>>n>>k;
	
	memset(dp,-1,sizeof(dp));
	//	cout<<"n :"<<n<<" k :"<<k<<nl;
	cout<<rec(n,k)<<nl;
	
	
	
	
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	int _t; cin>>_t;while(_t--)
		solve();
	
	
	//cerr<<"Time elapsed: "<< 1.0*clock()/ CLOCKS_PER_SEC << "s.\n\n";
	
	
	
	
}