/*Jump Game

Time-Limit: 1 sec Score: 100.00/100
Difficulty : ***(std)
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

Given an array having 
n elements, the cost to move from ith
 element to its adjacent element ( if exist ) at i+1 and 
i−1 is b, and the cost to move to other same valued index is a.
Find min cost to reach every index from a given source index of the array.


Input Format

First-line contains 
n - size of the array and costs a and b
..
Second line contains n elements of the array.
The third line contains a source index src
.


Output Format

In a single line, print the min-cost to reach every index from a given source index src

.


Constraints

1≤n≤2×105

1≤a,b≤109

1≤arr[i]≤100
1≤src≤n

Sample Input 1

10 1 2                                
1 2 1 1 2 3 2 3 2 1                                  
1

Sample Output 1

0 2 1 1 3 5 3 5 3 1 

Sample Input 2

1 1 2                                
7                                  
1

Sample Output 2

0*/



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

ll n,m,a,b;


//int visited[100100];
//ll dist[100100];




void dijkstra(vector<vector<ii>>&grid,ll src){
    vector<int>visited(m+1,0);
        vector<ll>dist(m+1,1e18);
	
// 	for(ll i=1;i<=m+1;i++){
		
// 		dist[i]=1e18;
// 		visited[i]=0;
// 		//parent[i]=-1;
		
// 	}
	
	dist[src]=0;
	
	//vector<ll>parent(n+1,-1);
	
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
           
           
           for(auto neigh:grid[node]){
           	
           	auto weight=neigh.s;
           	auto v=neigh.f;
           	
           	if(dis+weight<dist[v]){
           		
           		dist[v]=dis+weight;
           	//	parent[v]=node;
           		
           		pq.push(mp(dist[v],v));
           	}
           	
           	
           	
           }

}
     		
		for(ll i=1;i<=n;i++){
			
			cout<<dist[i]<<" ";
		}
		cout<<nl;
		
		
	
}




void solve(){
	cin>>n>>b>>a;
	
	vector<ll>arr(n+1);
	 map<ll,ll>pseudo;
	 
	
	 m=n;
	
	
	
	for(ll i=1;i<=n;i++){
		cin>>arr[i];
		
		if(!pseudo[arr[i]]){
			m+=1;
			
			pseudo[arr[i]]=m;
		}
	}
		
	
vector<vector<ii>>grid(m+1);

	//creating type 1 node (adjacent); total no of nodes =2(N-1) at worst case
	
	
	for(ll i=1;i<=n;i++){
		
		
		if(i-1>=1){
			
			grid[i].push_back({i-1,a});
		}
		
		if(i+1<=n){
			grid[i].push_back({i+1,a});
		}
		
	}
	
	//type 2[same valued index edge] total no of nodes =2N at worst case
	
	for(ll i=1;i<=n;i++){
		
		grid[i].push_back({pseudo[arr[i]],0});
		grid[pseudo[arr[i]]].push_back({i,b});
		
		
	}
	
	ll src;
	cin>>src;
	
// 	for(auto it:grid){
		
// 		for(auto it1:it) {
// 			cout<<"{"<<it1.f<<" "<<it1.s<<"}"<<" ";}
// 			cout<<nl;
// 	}
	
	

	
	
	dijkstra(grid,src);
	
	
	
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
//	int _t; cin>>_t;while(_t--)
		solve();
	
	
	//cerr<<"Time elapsed: "<< 1.0*clock()/ CLOCKS_PER_SEC << "s.\n\n";
	
	
	
	
}


/*approach 
Approach: use the Super Node idea to reduce the number of edges.
For each same values nodes, generate a supernode, such that

i−−0−→SuperNodei and SuperNode i−−a−→i

for all index i having same value arr[i].
Now we have at max 2∗n nodes in the graph and 4∗n−2 edges.
Now apply Dijkstra's algorithm.
So , Time complexity of Dijktra's will be ~ 
O(nlogn)
.*/