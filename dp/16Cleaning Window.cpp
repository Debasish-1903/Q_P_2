/*Cleaning Window

Time-Limit: 2 sec Score: 0.00/100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Description

There is a building with N (numbered 1 through N from top to bottom) floors, each with M windows. All the windows need to be cleaned. For each valid i and j, the window (i,j) must be cleaned on the A(i,j)-th turn. From window(i, j), water flows to the window(i+1,j-1), window(i+1,j), and window(i+1,j+1) if exists. When a window(i,j) is cleaned, window(i+1,j-1), window(i+1,j) and window(i+1,j+1) become dirty because of dirty water after cleaning window(i,j). Water flows further down of these dirty windows making next level windows dirty, and the same things go on recursively. 

E.g. When the window(0, 5) is getting cleaned. Then the water flows down to windows (1, 4), (1, 5) and (1, 6) making them dirty. Then the water flows from the window (1, 4) down to (2, 3), (2, 4), (2, 5), from the window (1,5) to (2, 4), (2, 5), (2, 6). And so on.

You have to determine whether each window will be clean after the cleaning process ends.


Input Format

The first line of the input contains one integer T - the number of test cases. Then T test cases follow.

The first line of each test case contains two space-separated integers N, M - the size of the building.

Each of the next N lines contains Ai,j - the time at which window (i,j) is cleaned. At a time, only one window can be cleaned.


Output Format

For each test case, print N lines, each with M integers denoting whether the (i,j)-th window will be clean or not after the cleaning process ends.


Constraints

1 ≤ T ≤ 1000

1 ≤ N, M ≤ 1000

1 ≤ Ai,j ≤ NM

Sum of NM across all test cases <= 10^7.

 


Sample Input 1

3
2 2
4 3
2 1
3 3
1 2 3
6 5 4
7 8 9
3 4
1 4 7 3
5 8 2 6
12 11 9 10

Sample Output 1

11
00
111
111
111
1111
1100
1111

Note

For the first test case, when window(1,1) and window(1,2) are cleaned, 
they make the window(2,1) and window(2,2) dirty. They were cleaned earlier, so they remain dirty.

For the second test case, all the windows remain clean because when a window 
becomes dirty, it gets cleaned afterwards. */

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
ll time_th[1010][1010];

//map<ll,pair<ll,ll>>time_th;


ll dp[1010][1010];


 bool rec(ll i,ll j){
 	
 	
 	if(i<=0||j<=0||i>n||j>m){return dp[i][j]=true;}
 	
 	//
 	if(dp[i][j]!=-1)return dp[i][j];
 	
 	bool ans=false;
 	
 	ll temp=max(max(rec(i-1,j),rec(i-1,j-1)),rec(i-1,j+1));
 	
 	if(temp<=time_th[i][j]){
 		
 		ans=true;
 	}else{
 		ans=false;
 	}
 	
 	
 	return dp[i][j]=ans;
 	
 	}
 	
 	
 	
 

void solve(){
	
	cin>>n>>m;
	
	

 memset(dp,-1,sizeof(dp));
	
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=m;j++){
		
		cin>>time_th[i][j];
		
		}
	}
	
	
	for(ll i=1;i<=n;i++){
		
		for(ll j=1;j<=m;j++){
			
			
			cout<<rec(i,j);
			
			//cout<<dp[i][j];
		}
		cout<<nl;
	}
	
	
	
	
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	int _t; cin>>_t;while(_t--)
		solve();
	
	
	//cerr<<"Time elapsed: "<< 1.0*clock()/ CLOCKS_PER_SEC << "s.\n\n";
	
	
	
	
}


