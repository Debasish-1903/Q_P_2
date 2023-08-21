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
	
	int n,k;
	cin>>n>>k;
	pair<int,int>arr[n];
	
	for(int i=0;i<n;i++){
		
		cin>>arr[i].f>>arr[i].s;
		//arr.f=speed;arr.s=efficiency // we need to calculate(maximize the sum of efficiencies multiplied by min speed within window of k)
		
	}
	
	sort(arr,arr+n);
	reverse(arr,arr+n);
	
	ll top_k_sum=0;
	prio<int,vector<int>,greater<int>>pq;
	ll total_score=0;
	
	for(int i=0;i<n;i++){
		
		pq.push(arr[i].s);
		top_k_sum+=arr[i].s;
		
		if(pq.size()>k){
			
			int x=pq.top();
			pq.pop();
			
			top_k_sum-=x;
			
		}
		
		if(pq.size()==k){
			
			total_score=max(total_score,arr[i].f*top_k_sum);
			
		}
		
	}
	
	cout<<total_score<<nl;
	
	
	
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	// int _t; cin>>_t;while(_t--)
		solve();
	
	
	//cerr<<"Time elapsed: "<< 1.0*clock()/ CLOCKS_PER_SEC << "s.\n\n";
	
	
	
	
}