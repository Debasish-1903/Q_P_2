/*Sort the strings

Time-Limit: 2 sec Score: 0.00/100
Difficulty : *
 Memory: 256 MB Accepted Submissions: 100
Description

You are given N strings. You are allowed to reverse the i-th string with a cost c[i]. You have to find the minimum cost needed to sort the strings in lexicographical order.

String A is lexicographically smaller than string B if it is shorter than B (|A| < |B|) and is its prefix, or if none of them is a prefix of the other and at the first position where they differ character in A is smaller than the character in B.


Input Format

The first line of the input contains one integer T - the number of test cases. Then T test cases follow.

The first line of each test case contains one integer N.

The second line of each test case contains N space-separated integers - the cost.

Each of the next N lines contains a string.


Output Format

For each test case, print the minimum cost needed to sort the strings in lexicographical order. If it is impossible to sort the strings print -1.


Constraints

1≤ T ≤ 100

1≤ N ≤ 105

0≤ Ci ≤ 109

1≤ |S| ≤ 105

It is guaranteed that the total length of these strings doesn't exceed 106.


Sample Input 1

3
3
2 6 7
aca
aad
fba
3
5 1 1
pbc
cbe
qbf
2
4 5
baa
aaa

Sample Output 1

6
6
-1

Note

For the first test case, reverse the second string to get: [aca, daa, fba]

For the second test case, reverse the first and second strings to get: [cbp, ebc, qbf]

For the third test case, there is no way to make the strings in lexicographical order.*/


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
vector<string>str;
vector<string>rev;
ll cost[100100];

ll dp[100100][2];

ll rec(ll level,ll state){  // minimum cost to make first i strings sorted 
	
	
	//pruning 
	
	
	// base case
	
	if(level==n-1){
		
		
		if(state==0)return 0;
		else return cost[level];
	}
	
	// cache check
	
	if(dp[level][state]!=-1)return dp[level][state];
	
	
	
	// compute 
	
	ll ans=1e18;
	
	if(state==0){
	if(str[level]<=str[level+1]){
		
		ans=min(ans,rec(level+1,0));
	}
	
	if(str[level]<=rev[level+1]){
		
		ans=min(ans,rec(level+1,1));
	}}else if(state==1){
	
	if(rev[level]<=str[level+1]){
		
		ans=min(ans,rec(level+1,0)+cost[level]);
	}
	
	if(rev[level]<=rev[level+1]){
		
		ans=min(ans,rec(level+1,1)+cost[level]);
	}}
	// save and return 
	
	
	return dp[level][state]=ans;
	
	
	
}



void solve(){
	
	cin>>n;
	
	for(ll i=0;i<n;i++){
		
		
		cin>>cost[i];
	}
	
	
	str.resize(n);
	rev.resize(n);
	
	 str.clear();
	 rev.clear();
	
	
	
	for(ll i=0;i<n;i++){
		
		cin>>str[i];
		
		rev[i]=str[i];
		reverse(rev[i].begin(),rev[i].end());
	}
	
	
	
	
	memset(dp,-1,sizeof(dp));
	
	ll ans= rec(0,0);
	
	ans=min(ans,rec(0,1));
	
	if(ans<1e18) cout<<ans<<nl;

else cout<<-1<<nl;
	
	
	
	
	
	
	
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	 int _t; cin>>_t;while(_t--)
		solve();
	
	
	//cerr<<"Time elapsed: "<< 1.0*clock()/ CLOCKS_PER_SEC << "s.\n\n";
	
	
	
	
}