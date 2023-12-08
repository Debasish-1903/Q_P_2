/*Longest Common Substring   *NOTICE IT IS SUBSTRING NOT SUB SEQUENCE   SUBSTRING SHOULD BE CONTIGIOUS INTERM OF INDEXING

Time-Limit: 2 sec Score: 0.00/100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

Given two strings. The task is to find the length of the longest common substring.


Input Format

First-line contains 
T
 - the number of test cases.
Each test case contains two strings 
s
1
 and 
s
2
 in a single line.


Output Format

For each test case, output the length of the longest common substring of the two strings, in a new line.


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
1000

1
≤
|
s
2
|
≤
1000

s
1
 and 
s
2
 contains small letters only.


Sample Input 1

3
abc abc
algozenith algo
algo zenith

Sample Output 1

3
4
0*/


//****FROM 3****//

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




string s1,s2;

ll n,m;



ll dp[1010][1010];
ll rec(ll i,ll j){// lcs from [i....n-1]and [j---m-1]


// pruning
	
	// base case
	if(i>=n||j>=m)return 0;
	
	// cache check
	
	if(dp[i][j]!=-1)return dp[i][j];
	// compute 
	
	ll ans=0;
	
	
	
	// ans=max(ans,rec(i,j+1));
	// ans=max(ans,rec(i+1,j)); //   this moves are not valid in substring ... this moves are only valid in subsequence
	
	
	if(s1[i]==s2[j]){
		
		ans= max(ans,1+rec(i+1,j+1));
	}
	
	// save and return
	
	return dp[i][j]=ans;



}



void solve(){
	
	
	cin>>s1>>s2;
	
	n=s1.size();
	
	m=s2.size();
	

	memset(dp,-1,sizeof(dp));
	 ll ans = 0;
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            ans = max(ans, rec(i,j));
        }
    }
    cout<<ans<<nl;
	
	
	
	
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
		
	
	int _t; cin>>_t;while(_t--)
		solve();
	
	
	//cerr<<"Time elapsed: "<< 1.0*clock()/ CLOCKS_PER_SEC << "s.\n\n";
	
	
	
	
}