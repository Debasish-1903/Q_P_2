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


int n;

 vector<int>denom;
 bool cachedDp[1005][1005]; // question is boolean type so we keep dp as boolean 
 
 bool visited[1005][1005]; // already done 
 
 
 bool rec(int level,int x){
 	
 	// pruning
 	
 	if(x<0)return false;
 	
 	// basecase
 if(level==n){
 	
if(x==0)return true;
else return false; }
	
 	// cache check
 	
 	if(visited[level][x])return cachedDp[level][x];
 	
 	//recursive case // same as transisition

bool ans=rec(level+1,x)||rec(level,x-denom[level]);
 	
 	
 	//ans and return
 	visited[level][x]=true; // visited is marked true
 	cachedDp[level][x]=ans;
 	
 	return ans;
 	
 	
 	
 	
 	
 }
 

void solve(){
	
	
	cin>>n;
	denom.resize(n);
	
	for(int i=0;i<n;i++){
		
		cin>>denom[i];
		
	}
	
	
	int target;
	cin>>target;
	
	
	// for multiple testcase we need to make visited(done) array false 
	
	for(int i=0;i<n;i++){
		
		for(int j=0;j<=target;j++){
			
			visited[i][j]=false;
		}
	}
  	
	cout<<rec(0,target)<<nl;
	
	
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	// int _t; cin>>_t;while(_t--)
		solve();
	
	
	//cerr<<"Time elapsed: "<< 1.0*clock()/ CLOCKS_PER_SEC << "s.\n\n";
	
	
	
	
}