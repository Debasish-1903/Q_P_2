#include <bits/stdc++.h>

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



class DisjointSet{   
	
vector<ll>rank,parent;
	
public:
	
		
	DisjointSet(ll n){// constructor
		
	rank.resize(n+1,1); // for 1 based indexing
	parent.resize(n+1);
	
	
	for(ll i=0;i<=n;i++){
		parent[i]=i;
	}
	
}

 int findUPar(ll node){
 	
 	if(node==parent[node]){
 		return node;
 	}
 	
 	return parent[node]=findUPar(parent[node]);  // caching the  recurstion of findUPar(parent of node) // path compression
 	                                                // path compression it takes o(log n)
 	                                               
 	
 }
 
void findUnionBySize(ll u,ll v){
 	
 	ll root_u=findUPar(u);
 	ll root_v=findUPar(v);
 	
 	
 	if(root_u==root_v) return ;
 	
 	if(rank[root_u]<rank[root_v]){  // rank compression  with both rank and path compression o(log*n)-->hockerman func
 		
 		parent[root_u]=root_v;
          rank[root_v]+=rank[root_u];
 		
 	}else{
 		
 		parent[root_v]=root_u;
 		rank[root_u]+=rank[root_v];
 		
 		
 		
 	}  
 	
 	
 }

 
 	
};

void solve(){
	
	ll n,m;
	cin>>n>>m;
	
	vector<pair<ll,ll>>graph[100100];
	
	vector<pair<ll,pair<ll,ll>>>edglist;
	for(ll i=1;i<=m;i++){
		
		ll a,b,c;
		cin>>a>>b>>c;
		
		edglist.push_back({c,{a,b}});
		
	}

	sort(edglist.begin(),edglist.end()); // from smaller edge weight to higher weight 
	
	DisjointSet ds(n);
	
	ll min_mst_cost=0;
	ll edge_cnt=0;
	
	for(auto it:edglist){
		
		
		auto cost=it.f;
		auto x=it.s.f;
		auto y=it.s.s;
		
		if(ds.findUPar(x)!=ds.findUPar(y)){
			edge_cnt++;
			graph[x].push_back({y,cost});
			graph[y].push_back({x,cost}); // final undirected tree
			
			min_mst_cost+=cost;
			ds.findUnionBySize(x,y);
		}
		
	}
	
	

if(edge_cnt!=n-1){
	
	cout<<"no solution";
}
  else {cout<<min_mst_cost<<nl;}
	
 		
 	} 
	
	
	


signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	// int _t; cin>>_t;while(_t--)
		solve();
	
	
	//cerr<<"Time elapsed: "<< 1.0*clock()/ CLOCKS_PER_SEC << "s.\n\n";
	
	
	
	
}