

//NO OF FLIPS//


//no of flips needed to make the no of subarrays with 1's should be <=k;

//lets's the array is given : 11010011110 &k=2



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


ll n,k;

vector<ll>arr;
vector<ll>pre_sum;


ll num_zero(ll l, ll r){
	
	ll cnt=(r-l+1)-(pre_sum[r]-(l>0?pre_sum[l-1]:0));
	
}

int check(ll st,ll x){

return num_zero(st,x)<=k;
}


void solve(){
	
	cin>>n>>k;
	arr.resize(n);
	pre_sum.resize(n);
	
	
	for(ll i=0;i<n;i++){
		
		cin>>arr[i];
		
		pre_sum[i]=arr[i];
		if(i)pre_sum[i]+=pre_sum[i-1];
		
	}
	
	
		
	ll total=0;
	
	
	
	
	for(ll st=0;st<n;st++){
		ll lo=st;
	    ll hi=n-1;
	    ll ans=st-1;

		
		
		while(lo<=hi){
			ll mid=lo+(hi-lo)/2;
			
			if(check(st,mid)){
				
				
				ans=mid;
				lo=mid+1;
			}else{
				
				hi=mid-1;
			}
			
			
		}
		
		total+=(ans-st+1);
		
		
		
	}
	
		
	cout<<total<<nl;
	
	
	
	
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	// int _t; cin>>_t;while(_t--)
		solve();
	
	
	//cerr<<"Time elapsed: "<< 1.0*clock()/ CLOCKS_PER_SEC << "s.\n\n";
	
	
	
	
}