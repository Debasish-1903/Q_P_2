/*#include<bits/stdc++.h>
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
vector<vector<ll>>grid;

vector<ll>dist;


void bellmanFord(ll src){
	
	dist[src]=0;
	
	for(ll i=0;i<n-1;i++){
		
		
		
		for(auto it:grid){
			
			auto u=it[0];
			auto v=it[1];
			auto w=it[2];
			if(dist[u]!=1e18&&dist[u]+w<dist[v]){
				dist[v]=dist[u]+w;
			}
			
		}
		
		
	}
	
	
		for(auto it:grid){
			
			auto u=it[0];
			auto v=it[1];
			auto w=it[2];
			if(dist[u]!=1e18&&dist[u]+w<dist[v]){
			  
			  cout<<-1<<nl;
			  return;
			}
			
		}	
	

	
}

void solve(){
	
	cin>>n>>m;
	
	grid.resize(n+1);
	dist.assign(n+1,1e18);
	
	for(ll i=0;i<m;i++){
		
		ll a,b,w;
		
		cin>>a>>b>>w;
		grid[i].push_back(a);
		grid[i].push_back(b);
		grid[i].push_back(w);
		
	}
	
	
	// for(auto it:grid){
		
	// 	cout<<it[0]<<it[1]<<it[2]<<nl;
	// }
	
	
	 
	 bellmanFord(1);
	 for(auto it:dist){
	 	
	 	cout<<it<<" "<<nl;
	 }
	
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	// int _t; cin>>_t;while(_t--)
		solve();
	
	
	//cerr<<"Time elapsed: "<< 1.0*clock()/ CLOCKS_PER_SEC << "s.\n\n";
	
	// worse complexity as compared to dijkstra O(V*E)==for worst case O(V^3);
	
	
} */


#include<bits/stdc++.h>
using namespace std;

struct Edge {
    int src, dest, weight;
};

vector<int> BellmanFord(int V, int src, vector<Edge>&edges) {
    vector<int> dist(V,1e18);
    dist[src] = 0;

    for(int i = 0; i < V - 1; i++) {
        for(auto& edge : edges) {
            if(dist[edge.src] != 1e18 && dist[edge.src] + edge.weight < dist[edge.dest]) {
                dist[edge.dest] = dist[edge.src] + edge.weight;
            }
        }
    }

    for(auto& edge : edges) {
        if(dist[edge.src] != 1e18&& dist[edge.src] + edge.weight < dist[edge.dest]) {
            cout << "Graph contains negative weight cycle" << endl;
            return {};
        }
    }

    return dist;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int V, E;
    cin >> V >> E;

    vector<Edge> edges(E);

    for(int i = 0; i < E; i++) {
        cin >> edges[i].src >> edges[i].dest >> edges[i].weight;
    }

    vector<int> dist = BellmanFord(V, 1, edges);

    if(!dist.empty()) {
        for(auto& d : dist) {
            cout << d << " ";
        }
        cout << endl;
    }

    return 0;
}
