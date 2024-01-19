#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define ull unsigned long long int
#define mod 1000000007
//#define inf 1e9
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


#define ii pair<ll,ll>
#define mp make_pair

ll n,m;
vector<ll>grid[100100];

ll dist[100100];

// level==dist==distance from the src node

ll inf=1e9;
void bfs(ll src){
	
	 queue<ii>q;
	
	  for(ll i=1;i<=n;i++) {
	  	
	  	dist[i]=inf;
	  	
	}
	
	dist[src]=0;
	
	
	q.push({src,dist[src]});
	
	
	
	while(!q.empty()){
		
		 auto it=q.front();
		 
		    ll node=it.f;
		    
		    ll dis=it.s;
		 q.pop();
		 
		 
		 for(auto neigh:grid[node]){
		 	   
		 	   
		 	    if(dist[neigh]>dis+1){
		 	    	
		 	    	dist[neigh]=dis+1;
		 	    	q.push({neigh,dist[neigh]});
		 	    }
		 	 
		 	
		 	
		 }
		
		
		
		
	}
	
	for(int i=1;i<=n;i++){
	cout<<"i:"<<i<<" dist:"<<dist[i]<<nl;}  // print the distance from each node 
}

void solve(){
	
	cin>>n>>m;
	
	for(ll i=0;i<m;i++){
		
		ll a,b;
		
		cin>>a>>b;
		
		grid[a].push_back(b);
		
		
	}
	
	
	bfs(1);
	
	
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	// int _t; cin>>_t;while(_t--)
		solve();
	
	
	//cerr<<"Time elapsed: "<< 1.0*clock()/ CLOCKS_PER_SEC << "s.\n\n";
	
	
	
	
}