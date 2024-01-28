/*Edge Removals

Time-Limit: 2 sec Score: 0.00/100
Difficulty : **
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

You have given an undirected graph G with N nodes, indexed from 1 to N and M edges, indexed from 1 to M.

There are two types of operations:
1 X: Remove the edge numbered X.
2: Print the number of connected components in the graph.


Input Format

The first line of contains three space-separated numbers N, M, Q (1 ≤ N, M, Q ≤ 100000).

The next M lines contain 2 space-separated integers u and v which depicts an edge between nodes u and v (1 ≤ u, v ≤ N). ith line denotes the ith edge.

This is followed by Q lines, each describing an operation in the following format:
1 X: Remove the edge numbered X.
2: Print the number of connected components in the graph.

There are no self-loops or multiple edges in the graph.

Note: If there are multiple queries for removal of the same edge, then the last such query should be considered. Also, the index of the edges does not change after the removal of any of the edges between the nodes.

 


Output Format

The output should consist of the answer to each of the operations of the 2nd type printed on a new line.


Sample Input 1

3 3 5
1 2
2 3
3 1
2
1 2
2
1 1
2
 


Sample Output 1

1
1
2
 


Note

Initially, the graph is connected.
Even after the removal of the 2nd edge, the graph is connected. Now if we remove the 1st edge, node 2 is now isolated. And graph now contains 2 components as {2}, {1, 3}.*/



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


class disJoint_set{
	
	
	vector<ll>rank,parent;
	
	
public:
	
	ll cnt =0;
	disJoint_set(ll n){
		
		rank.resize(n+1,0);
		parent.resize(n+1);
		
		
		for(ll i=0;i<=n;i++){
			
			parent[i]=i;
		}
		cnt=n;
		
	}
	
	
	ll parentFindU(ll node){
		
		
		if(node==parent[node]){
			
			return node;
		}
		
		return parent[node]=parentFindU(parent[node]);
	}
	
	
	void findUnionByRank(ll u,ll v){
		
		ll root_u=parentFindU(u);
		ll root_v=parentFindU(v);
		
		if(root_u==root_v)return ;
		
		if(rank[root_u]<rank[root_v]){
			
			
			parent[root_u]=root_v;
			cnt--;
			
		}else if(rank[root_u]>root_v){
			
			parent[root_v]=root_u;
			cnt--;
		}else{
			
			parent[root_v]=root_u;
			rank[root_u]++;
			cnt--;
			
		}
		
	}
	
	
	
	
	
};




void solve(){
	
	ll n,m,q;
	
	cin>>n>>m>>q;
	
	ii data[m+1];
	
	for(ll i=1;i<=m;i++){
		
		ll x,y;
		cin>>x>>y;
		
		data[i]={x,y};
	}
	
	
	
	
	
	ii queries[q];
	
	
	bool marked[m+1];
	memset(marked,false,sizeof(marked));
	
	
	for(ll i=0;i<q;i++){
		
		ll t;
		cin>>t;
		
		if(t==2){
			queries[i]={2,-1};
		}else if(t==1){  
			ll w;
			cin>>w;
			queries[i]={1,w};
			
			marked[w]=true;
		}
		 
	}
	
	
	disJoint_set ds(n);
	
	for(ll i=1;i<=m;i++){
		
		
		if(!marked[i]){
			
			auto u=data[i].f;
			auto v=data[i].s;
			
			ds.findUnionByRank(u,v);
			
		}
	}
	


vector<ll>ans;
	for(ll i=q-1;i>=0;i--){
		
		if(queries[i].f==2){
			
			ans.push_back(ds.cnt);
		}
		else if(queries[i].f==1){
			
			auto it=queries[i].s;
			
			ds.findUnionByRank(data[it].f,data[it].s);
			
			
		}
	}

	
	reverse(ans.begin(),ans.end());
	
for(auto it:ans){
	
	cout<<it<<nl;
}	
	
	
	
	
	
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	// int _t; cin>>_t;while(_t--)
		solve();
	
	
	//cerr<<"Time elapsed: "<< 1.0*clock()/ CLOCKS_PER_SEC << "s.\n\n";
	
	
	
	
}