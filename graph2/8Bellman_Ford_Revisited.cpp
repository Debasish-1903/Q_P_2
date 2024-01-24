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


ll n,m;
vector<vector<ll>>grid;
vector<ll>dist;

void bellmanFord(ll src){
	
	dist[src]=0;
	
	bool neg_cyle=0;
	
	
	for(ll i=0;i<n-1;i++){
		
		
		for(auto it:grid){
			
			auto u=it[0];
			auto v=it[1];
			auto weight=it[2];
			
			
			if(dist[u]!=1e18&&dist[v]>dist[u]+weight){
				
				dist[v]=dist[u]+weight;
			}
			
		}
		
		
		
	}
	
	
	for(auto it:grid){
			
			auto u=it[0];
			auto v=it[1];
			auto weight=it[2];
			
			
			if(dist[u]!=1e18&&dist[v]>dist[u]+weight){
				
				neg_cyle=true;
				//break;
				
				cout<<-1<<nl;
				return;
				
			}
			
		}
	
	
	if(neg_cyle){
		
		cout<<-1<<nl;
	}
	else if(neg_cyle==0) cout<<-dist[n]<<nl;
	
	
	
}



void solve(){
	
	cin>>n>>m;
	
	grid.resize(m);
	dist.assign(n+1,1e18);
	for(ll i=0;i<m;i++){
		
		ll a,b,w;
		cin>>a>>b>>w;
		grid[i].push_back(a);
		grid[i].push_back(b);
		grid[i].push_back(-w);
		
		
	}
	
	bellmanFord(1);
	
	
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	// int _t; cin>>_t;while(_t--)
		solve();
	
	
	//cerr<<"Time elapsed: "<< 1.0*clock()/ CLOCKS_PER_SEC << "s.\n\n";
	
	
	
	
}*/


// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long int
// #define ld long double
// #define ull unsigned long long int
// #define mod 1000000007
// #define inf 1e9
// #define mt make_tuple
// #define pb push_back
// #define eb emplace_back
// #define pob pop_back
// #define f first
// #define s second
// #define nl "\n"
// #define pi pair<int,int>
// //#define v vector<long long int>
// #define vp vector<pair<int,int>>
// #define vvl vector<vector<long long int>>
// #define rep(n) for(int i=0 ; i<n ; i++)
// #define rei(i) for(int i=n ; i>0 ; i--)
// #define prio priority_queue
// #define np next_permutation
// #define N 200100

// #define yes "YES"
// #define no "NO"


// ll n,m;
// vector<vector<ll>>grid;
// vector<ll>dist;

// void bellmanFord(ll src){
	
// 	dist[src]=0;
	
// 	bool neg_cyle=0;
	
	
// 	for(ll i=0;i<n-1;i++){
		
		
// 		for(auto it:grid){
			
// 			auto u=it[0];
// 			auto v=it[1];
// 			auto weight=it[2];
			
			
// 			if(dist[u]!=1e18&&dist[v]>dist[u]+weight){
				
// 				dist[v]=dist[u]+weight;
// 			}
			
// 		}
		
		
		
// 	}
	
	
// 	for(auto it:grid){
			
// 			auto u=it[0];
// 			auto v=it[1];
// 			auto weight=it[2];
			
			
// 			if(dist[u]!=1e18&&dist[v]>dist[u]+weight){
				
// 				neg_cyle=true;
				
// 				cout<<-1<<nl;
// 				return;
// 			}
			
// 		}
	
	
// // //	if(neg_cyle){
		
// // 		cout<<-1<<nl;
// // 	}
// // 	else
// 	 cout<<-dist[n]<<nl;
	
	
	
// }



// void solve(){
	
// 	cin>>n>>m;
	
// 	grid.resize(m); // Change this line
// 	dist.assign(n+1,1e18);
// 	for(ll i=0;i<m;i++){
		
// 		ll a,b,w;
// 		cin>>a>>b>>w;
// 		grid[i].push_back(a);
// 		grid[i].push_back(b);
// 		grid[i].push_back(-w);
		
		
// 	}
	
// 	bellmanFord(1);
	
	
// }

// signed main(){
// 	ios_base::sync_with_stdio(0);
// 	cin.tie(0);cout.tie(0);
	
// 	// int _t; cin>>_t;while(_t--)
// 		solve();
	
	
// 	//cerr<<"Time elapsed: "<< 1.0*clock()/ CLOCKS_PER_SEC << "s.\n\n";
	
	
	
	
	
// } 



// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long int
// #define ld long double
// #define ull unsigned long long int
// #define mod 1000000007
// #define inf 1e9
// #define mt make_tuple
// #define pb push_back
// #define eb emplace_back
// #define pob pop_back
// #define f first
// #define s second
// #define nl "\n"
// #define pi pair<int,int>
// //#define v vector<long long int>
// #define vp vector<pair<int,int>>
// #define vvl vector<vector<long long int>>
// #define rep(n) for(int i=0 ; i<n ; i++)
// #define rei(i) for(int i=n ; i>0 ; i--)
// #define prio priority_queue
// #define np next_permutation
// #define N 200100

// #define yes "YES"
// #define no "NO"


// ll n,m;
// vector<vector<ll>>grid;
// vector<ll>dist;

// void bellmanFord(ll src){
	
// 	dist[src]=0;
	
// 	bool neg_cyle=0;
	
	
// 	for(ll i=1;i<=m;i++){
		
		
// 		for(auto it:grid){
			
// 			auto u=it[0];
// 			auto v=it[1];
// 			auto weight=it[2];
			
			
// 			if(dist[v]>dist[u]+weight){
				
// 				dist[v]=dist[u]+weight;
// 			}
			
// 		}
		
		
		
// 	}
	
	
// 	for(auto it:grid){
			
// 			auto u=it[0];
// 			auto v=it[1];
// 			auto weight=it[2];
			
			
// 			if(dist[v]>dist[u]+weight){
				
// 				neg_cyle=true;
//                cout<<-1<<nl;
//                 return;
// 			}
			
// 		}
	
    
//     cout<<-dist[n]<<nl;
	
// 	}



// void solve(){
	
// 	cin>>n>>m;
	
// 	grid.resize(m);
// 	dist.assign(n+1,1e18);
// 	for(ll i=0;i<m;i++){
		
// 		ll a,b,w;
// 		cin>>a>>b>>w;
// 		grid[i].push_back(a);
// 		grid[i].push_back(b);
// 		grid[i].push_back(-w);
		
		
// 	}
	
// 	bellmanFord(1);
	
	
// }

// signed main(){
// 	ios_base::sync_with_stdio(0);
// 	cin.tie(0);cout.tie(0);
	
// 	// int _t; cin>>_t;while(_t--)
// 		solve();
	
	
// 	//cerr<<"Time elapsed: "<< 1.0*clock()/ CLOCKS_PER_SEC << "s.\n\n";
	
	
	
	
// }

#include <bits/stdc++.h>
using namespace std;

#define int long long

const int mod = 1e9+7;

void solve()
{
    int m,n; cin>>m>>n;
    vector<vector<int>> edges;
    
    for(int i=0;i<n;i++)
    {
        int a,b,c; cin>>a>>b>>c;
        edges.push_back({a,b,-c});
    }
    
    vector<int> dist(m+1,1e18);
    
    dist[1]=0;
    for(int i=1;i<=m;i++)
    {
        for(auto it:edges)
        {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            
            if(dist[u]+wt < dist[v]) dist[v] = dist[u]+wt;
        }
    }
    
    for(auto it:edges)
    {
        int u = it[0];
        int v = it[1];
        int wt = it[2];
            
        if(dist[u]+wt < dist[v])
        {
            cout<<-1<<endl;
            return;
        }
    }
    
    cout<<-dist[m]<<endl;
    
    
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int _t=1;

    //cin>>_t;
    
    while(_t--) solve();
    
    return 0;
}