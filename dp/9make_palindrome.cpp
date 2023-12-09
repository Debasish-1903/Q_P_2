/*Make Palindrome

Time-Limit: 2 sec Score: 50.00/100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

Given a string 
s
, find the minimum number of characters that need to be inserted into the string to make it a palindrome.


Input Format

First line contains 
T
 - the number of test cases.
First line of each test case contains the string 
s
.


Output Format

For each test case, output the minimum number of characters that need to be inserted into the string to make it a palindrome.


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
|
≤
1000

Sample Input 1

4
algozenith
abba
goomgle
fft

Sample Output 1

9
0
3
1*/

// approach 

/*very good technique ---> first make inverse of the original array(L) and then calculate lcs of 
 inverse array and original array.  then L-LCS=min. no of element need to insert in the original array
  to make it palindrom.  */


// with the problem statement and approach 


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
//#define s second
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


string str,str1;
ll n;

ll dp[1010][1010];

ll rec(ll i,ll j){ // give lcs from [i........n-1] of str nd [j......n-1] of str1
	
	//pruning
	
	// basecase
	if(i>=n||j>=n)return 0;
	
	
	// cache check
	
	if(dp[i][j]!=-1)return dp[i][j];
	
	// compute 
	ll ans=0;
	
	
	
	if(str[i]==str1[j]){
		
		ans=max(ans,1+rec(i+1,j+1));
	}else{
		ans=max(ans,rec(i,j+1));
	
	ans=max(ans,rec(i+1,j));}
	
	// save and return 
	
	return dp[i][j]=ans;
	
	
}



void solve(){
	 //s = "GeeksforGeeks";
cin>>str;
n=str.size();
str1 = string(str.rbegin(), str.rend());

memset(dp,-1,sizeof(dp));
ll lcs=rec(0,0);

ll ans=n-lcs;

cout<<ans<<nl;
	
	
	
	
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	 int _t; cin>>_t;while(_t--)
		solve();
	
	
	//cerr<<"Time elapsed: "<< 1.0*clock()/ CLOCKS_PER_SEC << "s.\n\n";
	
	
	
	
}