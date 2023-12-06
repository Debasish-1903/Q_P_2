#include<bits/stdc++.h>    // using form 2
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


int n;
int arr[1001];
int dp[1001];

int rec(int level){  // best lis() ending at level from [1--------level]
	
	// pruning
	if(level<0) return 0;
	//base case 
	//cached check
	
	
	if(dp[level]!=-1)return dp[level];
	
	//transisition
	
	int ans=1;
	for(int prev_taken=0;prev_taken<level;prev_taken++){
		
		if(arr[prev_taken]<arr[level]){
			
			ans=max(ans,1+rec(prev_taken));
		}
		
		
	}
	//save and return 
	
	//return ans;
	return dp[level]=ans;
	
	
	
	
}


void solve(){
	
	
	cin>>n;
	for(int i=0;i<n;i++){
		
		cin>>arr[i];
		
	}
	
	memset(dp,-1,sizeof(dp));
	
	int best=1;
	for(int i=0;i<n;i++){
		
		best=max(best,rec(i));
		
	}
	
	cout<<best<<nl;
	
	
	
	
	
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	// int _t; cin>>_t;while(_t--)
		solve();
	
	
	//cerr<<"Time elapsed: "<< 1.0*clock()/ CLOCKS_PER_SEC << "s.\n\n";
	
	
	
	
}