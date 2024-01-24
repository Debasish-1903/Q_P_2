/*Edge Reverse

Time-Limit: 1 sec Score: 50.00/100
Difficulty : ** (min)
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

Given a directed graph with 
N vertices and  M edges.

What is the minimum number of edges needed to reverse in order to have at least
 one path from vertex 
1 to vertex 
N
, where the vertices are numbered from 
1 to N
 ?


Input Format

The first line contains 
T
 - the number of test cases.

The first line of each test case contains two space-separated integers N and M
, denoting the number of vertices and the number of edges in the graph respectively.
The ith
 line of the next M lines of each test case contains two space-separated integers Xi and Yi
, denoting that the ith
 edge connects vertices from  Xi
 to Yi.


Output Format

For each test case, In a single line, print the minimum number of edges we need to revert. 
If there is no way of having at least one path from 
1 to N, print -1.


Constraints
1<T<10;
1<N,M<10^5
1<xi,yi<N;


There can be multiple edges connecting the same pair of vertices,
 There can be self-loops too i.e. Xi= Yi

Sample Input 1

1
7 7
1 2 
3 2
3 4
7 4
6 2
5 6
7 5

Sample Output 1

2

Note

We can consider two paths from 1 to 7:

7
In the first one we need to revert edges 

. In the second one - 

. So the answer is 


.*/





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
# define ii pair<ll,ll>

vector<vector<ii>>grid;
ll dist[1001001];

ll n,m;


void bfs01(ll src){
	
	
	deque<ll>dq;

	for(ll i=1;i<=n;i++){
		dist[i]=1e18;
	}
	
	
	dist[src]=0;
	
	dq.push_back(src);
	
	
	while(!dq.empty()){
		
		 auto node=dq.front();
		 
		 dq.pop_front();
		 
		 
		 for(auto  neigh:grid[node]){
		 	 auto v=neigh.f;
		 	 
		 	 auto w=neigh.s;
		 	 
		 	 
		 	 if(dist[v]>dist[node]+w){
		 	 	
		 	 	dist[v]=dist[node]+w;
		 	 	
		 	 	
		 	 	if(w==0){
		 	 		
		 	 		dq.push_front(v);
		 	 	}else{
		 	 		
		 	 		dq.push_back(v);
		 	 	}
		 	 }
		 	
		 	
		 }
		
		
	}
	
}


void solve(){
	
	
	cin>>n>>m;
	
	 grid.resize(n+1);
	 grid.clear();
	
	
	
	for(ll i=0;i<m;i++){
		
		
		ll a,b;
		cin>>a>>b;
		
		grid[a].push_back({b,0});
		grid[b].push_back({a,1});
		
	}
	
	
	 bfs01(1);
	 
	 if(dist[n]==1e18){
	 	cout<<-1<<nl;
	 }else{
	 	
	 	cout<<dist[n]<<nl;
	 }
	
	
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	int _t; cin>>_t;while(_t--)
		{    
			solve();
		}
		
	
	
	
	//cerr<<"Time elapsed: "<< 1.0*clock()/ CLOCKS_PER_SEC << "s.\n\n";
	
	
	
	
}