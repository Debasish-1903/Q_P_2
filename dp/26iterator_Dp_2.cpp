//denomination  or infinite coin toss problem 






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



int denom[1001];

void solve(){
	
	int n,m;
	cin>>n>>m;
	
	for(int i=0;i<n;i++){
		
		cin>>denom[i];
		
	}
	
	
	
	int dp[n+1][m+1]; // because for iterator dp we need to store the base case also in dp array(unlike recursive )
	for(int l=n;l>0;l--){
		
		for(int s=0;s<=m;s++){
			
			//base case
			if(l==n){
				
				
				if(s==0) dp[l][s]=1;
				
					else dp[l][s]=0;
			}
			
			
			// other general case
			
			dp[l][s]=0;
			
			if(dp[l+1][s]){
				
				dp[l][s]=1;
			}
			
			
			if(s>=denom[l]&&dp[l][s-denom[l]]){
				
				dp[l][s]=1;
			}
			
			
			
		}
		
	}
	
	cout<<dp[0][m]<<nl;
	
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	// int _t; cin>>_t;while(_t--)
		solve();
	
	
	//cerr<<"Time elapsed: "<< 1.0*clock()/ CLOCKS_PER_SEC << "s.\n\n";
	
	
	
	
}