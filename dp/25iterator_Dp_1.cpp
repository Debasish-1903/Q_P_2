
/*there are 2 piles present , A and B stones are present respectively
In one turn one player can do two things--
1. take any no of stones from one pile 

2. take equal no of stones from both the piles


who can't move  he will be lost  */





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


//form 5 --game dp

ll dp[1000][1000];


int rec(ll x,ll y){
	
	
	//pruning 
	
	
	// basecase
	if(x==0&&y==0)return 0;
	
	
	
	// caching 
	
	if(dp[x][y]!=-1)return dp[x][y];
	
	
	//compute 
	int ans=0;  // by default it is a loosing state if in transition any loosing state appear then this 
	// state become wining state
	
	for(ll z=0;z<x;z++){
		
		if(rec(z,y)==0){
			
			ans=1;
			break;
		}
	}
	
	for(ll z=0;z<y;z++){
		
		if(rec(x,z)==0){
			
			ans=1;
			break;
		}
	}
	
	
	for(ll z=1;z<=min(x,y);z++){   // focus on it ...start at 1 and goes up to min(x,y)
		       // means remove 1 stone and check up to how much we can go
		if(rec(x-z,y-z)==0){
			
			ans=1;
			break;
		}
	}
	
	
	// save and return 
	
	return dp[x][y]=ans;
	
	
}


// void solve(){
	
// 	ll a,b;
	
// 	cin>>a>>b;
	
// 	memset(dp,-1,sizeof(dp));
	
	
// 	cout<<rec(a,b);
	
	
	
	
	
// }




void solve(){
	
	ll a,b;
	
	cin>>a>>b;
	
	
	for(int x=0;x<=a;x++){
		
	  for(int y=0;y<=b;y++){
	  	
	  	// base case
	  	
	  	if(x==0&&y==0)dp[x][y]=0;
	  	
	  	
	  	int ans=0;  // by default it is a loosing state if in transition any loosing state appear then this 
	// state become wining state
	
	for(ll z=0;z<x;z++){
		
		if(dp[z][y]==0){
			
			ans=1;
			break;
		}
	}
	
	for(ll z=0;z<y;z++){
		
		if(dp[x][z]==0){
			
			ans=1;
			break;
		}
	}
	
	
	for(ll z=1;z<=min(x,y);z++){   // focus on it ...start at 1 and goes up to min(x,y)
		       // means remove 1 stone and check up to how much we can go
		if(dp[x-z][y-z]==0){
			
			ans=1;
			break;
		}
	}
	
	
	// save and return 
	
        dp[x][y]=ans;
	
	  	
	  	
	  }
	}
	
	
	cout<<dp[a][b];
	
	
	
	
	
}


signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	// int _t; cin>>_t;while(_t--)
		solve();
	
	
	//cerr<<"Time elapsed: "<< 1.0*clock()/ CLOCKS_PER_SEC << "s.\n\n";
	
	
	
	
}


