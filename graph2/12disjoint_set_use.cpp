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



class DisjointSet{   
	

	
public:
	
		vector<ll>rank,parent;
	DisjointSet(ll n){// constructor
		
	rank.resize(n+1,0); // for 1 based indexing
	parent.resize(n+1);
	
	
	for(ll i=0;i<=n;i++){
		parent[i]=i;
	}
	
}

 int findUPar(ll node){
 	
 	if(node==parent[node]){
 		return node;
 	}
 	
 	return parent[node]=findUPar(parent[node]);  // caching the  recurstion of findUPar(parent of node)
 	
 	
 	
 }
 
 
 void findUnionByRank(ll u,ll v){
 	
 	ll ultimate_parent_u=findUPar(u);
 	ll ultimate_parent_v=findUPar(v);
 	
 	
 	if(ultimate_parent_u==ultimate_parent_v) return ;
 	
 	if(rank[ultimate_parent_u]<rank[ultimate_parent_v]){
 		
 		parent[ultimate_parent_u]=ultimate_parent_v;
 		
 	}else if(rank[ultimate_parent_u]>rank[ultimate_parent_v]){
 		
 		rank[ultimate_parent_v]=ultimate_parent_u;
 		
 	}else{
 		
 		parent[ultimate_parent_v]=ultimate_parent_u;
 		rank[ultimate_parent_u]++;
 		
 		
 		
 	}  
 	
 	
 }
 
 	
};

void solve(){
	
	DisjointSet ds(7);
	
	ds.findUnionByRank(1,2);
	ds.findUnionByRank(2,3);
	ds.findUnionByRank(4,5);
	ds.findUnionByRank(6,7);
	ds.findUnionByRank(5,6);
	
	
	
	if(ds.findUPar(3)==ds.findUPar(7)){
		
		cout<<"both are in same union set"<<nl;
	}else {
		
		cout<<"not same"<<nl;
	}
	
	//ds.findUnionByRank(3,7);
	
	ds.findUnionByRank(3,7);
	
	
	
	
		for(auto it:ds.parent){
 		cout<<"par[i]"<<it<< " ";
 	}
 	
 	cout<<nl;
 	
 	for(auto it:ds.rank){
 		cout<<"rank[i]"<<it<< " ";
 	}
 	
 	cout<<nl;
 		
 	} 
	
	
	


signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	// int _t; cin>>_t;while(_t--)
		solve();
	
	
	//cerr<<"Time elapsed: "<< 1.0*clock()/ CLOCKS_PER_SEC << "s.\n\n";
	
	
	
	
}