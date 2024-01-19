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

  // it is used for weighted graph (any weight) without the cylcle sum=-ve 
/*ex: 
      node node weigth
      2 3 3
      3 4 10
      4 5 -6
      5 3 -3     for this case dijkstra is valid as loop (10-6-3=1>0) 
      
      
      
      but for this case dijkstra will be not valid
       
       2 3 3
      3 4 8
      4 5 -6
      5 3 -3     for this case dijkstra is valid as loop (8-6-3=-11<0) 
      

*/

#define ii pair<ll,ll>
#define mp make_pair

ll n,m;




vector<ii>g[100100];

int visited[100100];
ll dist[100100];



void dijkstra(ll src){
	
	for(ll i=1;i<=n;i++){
		
		dist[i]=1e18;
		visited[i]=0;
		
	}
	
	dist[src]=0;
	
	 priority_queue<ii,vector<ii>,greater<ii>>pq;
	 pq.push(mp(dist[src],src));
	
	while(!pq.empty()){

          auto it=pq.top();
          ll dis=it.f;
          ll node=it.s;
           
           pq.pop();
           
           
           if(visited[node]){
           	continue;
           }
           
           visited[node]=1;
           
           
           for(auto neigh:g[node]){
           	
           	auto weight=neigh.s;
           	auto v=neigh.f;
           	
           	if(dis+weight<dist[v]){
           		
           		dist[v]=dis+weight;
           		
           		pq.push(mp(dist[v],v));
           	}
           	
           	
           	
           }


     		
		
		
		
	}
	
	
	for(ll i=1;i<=n;i++){
		
		
		cout<<"i"<<i<<" "<<"dist:"<<dist[i]<<nl;
	}
	
	
	
}


void solve(){
	
	
	cin>>n>>m;
	
	for(ll i=0;i<m;i++){
		
		ll a,b,w;
		
		cin>>a>>b>>w;
		
		// undirected graph
		
		g[a].push_back({b,w});
		g[b].push_back({a,w});
		
		 
		 dijkstra(1);
		
	}
	
	
	
	
	
	
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	// int _t; cin>>_t;while(_t--)
		solve();
	
	
	//cerr<<"Time elapsed: "<< 1.0*clock()/ CLOCKS_PER_SEC << "s.\n\n";
	
	
	
	
}