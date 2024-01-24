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
//#define v vector<long long int>
#define vp vector<pair<int,int>>
#define vvl vector<vector<long long int>>
#define rep(n) for(int i=0 ; i<n ; i++)
#define rei(i) for(int i=n ; i>0 ; i--)
#define prio priority_queue
#define np next_permutation
#define N 200100

#define yes "YES"
#define no "NO"


#define mp make_pair
#define ii pair<ll,ll>


ll n,m;
vector<vector<ii>>grid;

vector<ll>dist,path,min_fl,max_fl,visited; 
// store min no of flights in the min cost route till each road





void dijkstra(ll src){
	
	
	// for(ll i=1;i<=n;i++){
		
	// 	dist[i]=1e18;
	// 	visited[i]=0;
		
	// 	 max_fl[i]=0;
	// 	 min_fl[i]=0;
	// 	 path[i]=0;
	// 	 	}
	
	
	dist[src]=0;
	
	path[src]=1;
    min_fl[src]=0;
    max_fl[src]=0;
	
	priority_queue<ii,vector<ii>,greater<ii>>pq; // min heap representation
	
	pq.push(mp(dist[src],src));
	
	
	while(!pq.empty()){
		
		auto it=pq.top();
		
		auto node=it.s;
		
		auto weight=it.f;
			pq.pop();
		
		
		if(visited[node]){
			continue;
		}
			visited[node]=1;
		
		
		
	
		
		
		for(auto neigh:grid[node]){
			
			auto v=neigh.f;
			auto w=neigh.s;
			
			// if(v==n){
				
			// 	if(dist[v]==weight+w) dist_cnt.push_back(dist[v]);
			// }
			

			if(dist[v]>weight+w){
				
				
				dist[v]=weight+w;
				
				path[v]=path[node];
				min_fl[v]=min_fl[node]+1;
				max_fl[v]=max_fl[node]+1;
				
				
				
				pq.push(mp(dist[v],v));
				
			}else if(dist[v]==weight+w){
				
				
				path[v]=(path[node]+path[v])%mod;
				min_fl[v]=min(min_fl[node]+1,min_fl[v]);
				max_fl[v]=max(max_fl[node]+1,max_fl[v]);
				
			}
			
		
			
			
		}
		
		
	}
	
	
}



void solve(){
	
	cin>>n>>m;
	
	grid.resize(n+1);
	dist.assign(n+1,1e18);
	visited.assign(n+1,0);
	path.assign(n+1,0);
	max_fl.assign(n+1,0);
	min_fl.assign(n+1,0);
	
	for(ll i=0;i<m;i++){
		
		ll a,b,c;
		cin>>a>>b>>c;
		grid[a].push_back({b,c});
		
	}
	
	
	dijkstra(1);
	
	if(dist[n]==1e18){
		
		cout<<-1<<nl;
	}
	
	else cout<<dist[n]<<" "<<path[n]<<" "<<min_fl[n]<<" "<<max_fl[n];
	
	

}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	// int _t; cin>>_t;while(_t--)
		solve();
	
	
	//cerr<<"Time elapsed: "<< 1.0*clock()/ CLOCKS_PER_SEC << "s.\n\n";
	
	
	
	
}