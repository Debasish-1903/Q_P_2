/*All Pairs Shortest Path
1 min. readView original
Problem Code     *****()std

Accesscode : 14384

Description

We have given an adjacency representation of a directed weighted graph and 
an array of vertices. At each iteration, a vertex is removed from the graph. 
Vertices are removed in the order given in the array. When the vertex is 
removed, all the edges that go in and out are also removed. 

Print the sum of all pairs shortest path just before each iteration.

Input Format

The first line contains integer n (1≤n≤500) — 
the number of vertices in the graph.
Next n lines contain n integers each — the graph adjacency matrix: 
the j-th number in the i-th line aij (1≤aij≤105,aii=0) represents 
the weight of the edge that goes from vertex i to vertex j.
The next line contains n distinct integers: x1,x2,...,xn (1≤xi≤n) — 
the order of vertices removed from the graph.

Output Format

Print N space-separated numbers, where ith number represents the
 sum of all pairs shortest path just before ith removal.
 
 Constraints

1 ≤ N ≤ 500


Sample Input 1

2
0 5
4 0
1 2

Sample Output 1

9 0

Sample Input 2

4
0 3 1 1
6 0 400 1
2 4 0 1
1 1 1 0
4 1 2 3

Sample Output 2

17 23 404 0 */


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


ll n;

void solve(){
	cin>>n;
	
	ll dist[n][n];
	vector<ll>ans;
	
	for(ll i=0;i<n;i++){
		
		for(ll j=0;j<n;j++){ 
			cin>>dist[i][j];   // take the input array 
		}
	}
	
	ll node[n];
	for(ll i=0;i<n;i++){
		
		cin>>node[i];
		node[i]--;  // o based indexing 
	}
	
	
	for(ll k=n-1;k>=0;k--){   // relaxing the graph dist when a new node comes and start it from last (coming from future to present )
		
		for(ll i=0;i<n;i++){
			
			for(ll j=0;j<n;j++){
				
				dist[i][j]=min(dist[i][j],dist[i][node[k]]+dist[node[k]][j]); 
			}
		}
		
		
		ll temp=0;
		for(ll i=k;i<n;i++){
			for(ll j=k;j<n;j++){
				
				temp+=dist[node[i]][node[j]];
			}
		}
		
		
		
		
		ans.push_back(temp);
	
	}
	
	
	
	for(ll i=n-1;i>=0;i--){
		cout<<ans[i]<<" ";
		
	}
	
	
	
	
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	// int _t; cin>>_t;while(_t--)
		solve();
	
	
	//cerr<<"Time elapsed: "<< 1.0*clock()/ CLOCKS_PER_SEC << "s.\n\n";
	
	
	
	
}
