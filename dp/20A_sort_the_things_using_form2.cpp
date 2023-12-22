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
	
	if(level==0){
		
		
		if(state==0)return 0;
		else return cost[0];
	}
	
	// cache check
	
	if(dp[level][state]!=-1)return dp[level][state];
	
	
	
	// compute 
	
	ll ans=1e18;
	
	if(state==0){
	if(str[level-1]<=str[level]){
		
		ans=min(ans,rec(level-1,0));
	}
	
	
	
	if(rev[level-1]<=str[level]){
		
		ans=min(ans,rec(level-1,1));
	}}else if(state==1){
	
	if(str[level-1]<=rev[level]){
		
		ans=min(ans,rec(level-1,0)+cost[level]);
	}
	
	if(rev[level-1]<=rev[level]){
		
		ans=min(ans,rec(level-1,1)+cost[level]);
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
	
	
	
	// for(ll i=0;i<n;i++){
		
		
	// 	cout<<rev[i]<<nl;
	// }
	
	//cout<<nl;
	
	memset(dp,-1,sizeof(dp));
	
	ll ans= rec(n-1,0);
	
	ans=min(ans,rec(n-1,1));
	
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