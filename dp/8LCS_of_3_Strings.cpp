/*LCS of 3 Strings

Time-Limit: 5 sec Score: 0/100
Difficulty : **
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

Given 
3
 strings 
s
1
, 
s
2
 and 
s
3
, the task is to find the length of the longest common sub-sequence in all three given strings.


Input Format

First-line contains 
T
 - the number of test cases.
Each test case contains 
3
 strings in a single line.


Output Format

For each test case, print the length of the longest common subsequence in all the 
3
 given strings, in a new line.


Constraints

1
≤
T
≤
100

1
≤
|
s
1
|
≤
100

1
≤
|
s
2
|
≤
100

1
≤
|
s
3
|
≤
100

Sample Input 1

3
abc abc bbc
algozenith algo algorithm
algo zenith zen

Sample Output 1

2
4
0   */



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



string s1,s2,s3;

 ll n,m,p;
 
 ll dp[110][110][110];
 
 ll rec(ll i,ll j,ll k){  // lcs from [i...n-1],[j.....m-1], [k....p-1]
 	
  // pruning 
 	
 	// base case 
 	
 	if(i>=n||j>=m||k>=p){
 		
 		return 0;
 		
 	}
 	
 	
 	
 	// cache check
 	 
 	if(dp[i][j][k]!=-1){
 		return dp[i][j][k];
 	}
 	
 	// compute
 	
 	ll ans=0;
 	
 	ans=max(ans,rec(i,j,k+1));
 	ans=max(ans,rec(i,j+1,k)) ;
 	
 	ans=max(ans,rec(i+1,j,k));
 	
 	if(s1[i]==s2[j]&&s2[j]==s3[k]){
 		
 		ans=max(ans,1+rec(i+1,j+1,k+1));
 	}
 	
 	
 	// return and save
 	
 	
 	return dp[i][j][k]=ans;
 	
 }


void solve(){
	
	
	cin>>s1>>s2>>s3;
	
	n=s1.size();
	m=s2.size();
	
	p=s3.size();
	
	memset(dp,-1,sizeof(dp));
	
	cout<<rec(0,0,0)<<nl;
	
	
	
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	 int _t; cin>>_t;while(_t--)
		solve();
	
	
	//cerr<<"Time elapsed: "<< 1.0*clock()/ CLOCKS_PER_SEC << "s.\n\n";
	
	
	
	
}

