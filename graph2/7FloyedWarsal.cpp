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

ll dist[404][404];

void solve(){
	
	ll n,m;
	cin>>n>>m;
	
	for(ll i=0;i<n;i++){
		
		for(ll j=0;j<n;j++){
			
			if(i!=j)dist[i][j]=1e18;
		}
	}
	
	
	for(ll i=0;i<m;i++){
		
		ll a,b,c;
		
		cin>>a>>b>>c;
		
		dist[a][b]=min(dist[a][b],c);
		
	}
	
	
	
	for(ll k=0;k<n;k++){
		
		for(ll i=0;i<n;i++){
			
			
			for(ll j=0;j<n;j++){
				
				dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
			}
		}
		
		
		
	}
	
	
	for(ll i=0;i<n;i++){
		for(ll j=0;j<n;j++){
			
			cout<<dist[i][j]<<" ";
			
		}
		cout<<nl;
		
	}
	
	
	
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	// int _t; cin>>_t;while(_t--)
		solve();
	
	
	//cerr<<"Time elapsed: "<< 1.0*clock()/ CLOCKS_PER_SEC << "s.\n\n";
	
	
	
	
}
*/



//applications of floyedwarsal


//find out the path which gives the shortest dist

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
ll dist[404][404];
ll par[404][404];



void solve(){
	
	ll n,m;
	cin>>n>>m;
	
	for(ll i=0;i<n;i++){
		
		for(ll j=0;j<n;j++){
			
			if(i!=j)dist[i][j]=1e18;
		}
	}
	
	
	for(ll i=0;i<m;i++){
		
		ll a,b,c;
		
		cin>>a>>b>>c;
		
		dist[a][b]=min(dist[a][b],c);
		
	}
	
	
	
	for(ll i=0;i<n;i++){
		
		for(ll j=0;j<n;j++){
			
			par[i][j]=i;
		}
	}
	
	
	for(ll k=0;k<n;k++){
		
		for(ll i=0;i<n;i++){
			
			
			for(ll j=0;j<n;j++){
				
				if(dist[i][j]>dist[i][k]+dist[k][j]){
				dist[i][j]=dist[i][k]+dist[k][j];
				
				par[i][j]=par[k][j];
			}
			}
		}
		
		
		
	}
	
	
	for(ll i=0;i<n;i++){
		for(ll j=0;j<n;j++){
			
			cout<<dist[i][j]<<" ";
			
			if(dist[i][j] != 1e18) {
				cout << "Path: ";
				vector<ll> path;
				for(ll v = j; v != i; v = par[i][v]) {
					path.push_back(v);
				}
				path.push_back(i);
				reverse(path.begin(), path.end());
				for(auto v : path) {
					cout << v << " ";
				}
			}
			cout << nl;
		}
		cout << nl;
	}
}


signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	// int _t; cin>>_t;while(_t--)
		solve();
	
	
	//cerr<<"Time elapsed: "<< 1.0*clock()/ CLOCKS_PER_SEC << "s.\n\n";
	
	
	
	
}*/




// 

//but can you tell me how this code will print the path
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

ll dist[404][404];
ll par[404][404];

 //i-->x-->-->-->y-->-->parent[x][y]-->j

void printpath(ll i,ll j){
	
	if(i!=j){
		printpath(i,par[i][j]);
	}
	
	cout<<j<<" ";
	
}

void solve(){
	
	ll n,m;
	cin>>n>>m;
	
	for(ll i=0;i<n;i++){
		
		for(ll j=0;j<n;j++){
			
			if(i!=j)dist[i][j]=1e18;
		}
	}
	
	
	for(ll i=0;i<m;i++){
		
		ll a,b,c;
		
		cin>>a>>b>>c;
		
		dist[a][b]=min(dist[a][b],c);
		
	}
	
	
	
	for(ll i=0;i<n;i++){
		
		for(ll j=0;j<n;j++){
			
			par[i][j]=i;
		}
	}
	
	
	for(ll k=0;k<n;k++){
		
		for(ll i=0;i<n;i++){
			
			
			for(ll j=0;j<n;j++){
				
				if(dist[i][j]>dist[i][k]+dist[k][j]){
				dist[i][j]=dist[i][k]+dist[k][j];
				
				par[i][j]=par[k][j];
			}
			}
		}
		
		
		
	}
	
	
	for(ll i=0;i<n;i++){
    for(ll j=0;j<n;j++){
        
        cout<<dist[i][j]<<" ";
        
        if(dist[i][j] != 1e18) {
            cout << "Path: ";
            printpath(i, j);
        }
        cout << " ";
    }
   
}

	
	
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	// int _t; cin>>_t;while(_t--)
		solve();
	
	}
	//cerr<<"Time elapsed: "<< 1.0*clock()/ CLOCKS_PER_SEC << "s.\n\n";
	
	
	
	 