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



void solve(){
	
	
	string str;
	
	cin>>str;
	
	ll dp[100100];
	ll sum[100100];
	
	dp[0]=1;
	sum[0]=1;
	
	ll last[26];
	
	memset(last,0,sizeof(last));
	
	ll n=str.size();
	for(int i=1;i<=n;i++){
		
		dp[i]=sum[i-1];
		
		if(last[str[i-1]-'A']>0){
			
			dp[i]=(dp[i]-sum[last[str[i-1]-'A']-1]+mod)%mod;
		}
		
		
		
		last[str[i-1]-'A']=i;
		sum[i]=(dp[i]%mod+sum[i-1]%mod)%mod;
		
	}
	
	cout<<sum[n]<<nl;
	
	
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	int _t; cin>>_t;while(_t--)
		solve();
	
	
	//cerr<<"Time elapsed: "<< 1.0*clock()/ CLOCKS_PER_SEC << "s.\n\n";
	
	
	
	
}