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


int n,m;
string x,y;

int dp[101][101];

 // get the minimal length of difference utility 
int rec(int l1, int l2){   // giving the optimal utility length till the x[l1] and y[l2] level
    	
    	// pruning 
	
	// base case
	
	if(l1==n&&l2==m)return 0;
	
	
	
	// cache check
	
	if(dp[l1][l2]!=-1)return dp[l1][l2];
	
	// compute
	 int ans=1e9;
	 
	 if(l1<n){
	 	
	 	ans=min(ans,rec(l1+1,l2)+1/*-x[l1]*/);
	 }
	  if(l2<m){
	 	
	 		ans=min(ans,rec(l1,l2+1)+1/*+y[l2]*/);
	 	
	 }
	  if(l1<n&&l2<m&&(x[l1]==y[l2])){
	 	
	 	
	 		
	 		ans=min(ans,rec(l1+1,l2+1)+1);
	 	
	 }


	
	return dp[l1][l2]=ans;
	
	// save and return 
	
	
}




void solve(){
	
	cin>>x>>y;
	
	
	n=x.length();
	m=y.length();
	
	memset(dp,-1,sizeof(dp));
	cout<<rec(0,0)<<nl;
	
	
	
	
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	// int _t; cin>>_t;while(_t--)
		solve();
	
	
	//cerr<<"Time elapsed: "<< 1.0*clock()/ CLOCKS_PER_SEC << "s.\n\n";
	
	
	
	
}