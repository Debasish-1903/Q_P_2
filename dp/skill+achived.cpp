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

ll time[1001];
ll skill[1001];

ll n,x,k;

ll rec(ll level,ll time_taken,ll item_taken){// rec (..,..,..,) means exploring all the possiblities from [level....n-1]
	                                            // and return the count
	
	// pruning
	// basecase
	if(level==n){
		return 0;
	}
	
	
	//cache chek
	//compute/transistion
	
	ll ans=rec(level+1,time_taken,item_taken); // don't take
	
	if(time_taken+time[level]<x&&item_taken+1<k){
		
		ans=max(ans,(skill[level]+rec(level+1,time_taken+time[level],item_taken+1)));
	}
	// save and return
	
	
	
	
	
	
	
	
}


void solve(){
	cin>>n>>x>>k;
	
	for(ll i=0;i<n;i++){
		
		cin>>time[i];
		cin>>skill[i];
		
	}
	
	
	
	cout<<ll rec(0)<<nl;
	
	
	
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	// int _t; cin>>_t;while(_t--)
		solve();
	
	
	//cerr<<"Time elapsed: "<< 1.0*clock()/ CLOCKS_PER_SEC << "s.\n\n";
	
	
	
	
}