/*

Disjoint Union

Time-Limit: 0.2 sec Score: 100.00/100
Difficulty : *(min)
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

Write a program that manipulates a disjoint set S = S1, S2, ..., Sk.

First of all, the program should read an integer n, then make a disjoint 
set where each element consists of 0, 1, ..., n-1 respectively.

Next, the program should read an integer q and manipulate the set of q queries.
 There are two kinds of queries for different operations:

unite(x, y): unite sets that contain x and y, say Sx and Sy, into a new set.
same(x, y): determine whether x and y are in the same set.

Input Format

The first line contains two space-separated integers n and q, (1 ≤ n ≤ 104, 1 ≤ q ≤ 105).
Then, q queries are given in the form com x y, where com represents
 the type of queries. '0' denotes unite and '1' denotes same operation (x != y).


Output Format

For each same operation, print 1 if x and y are in the same set, otherwise 0, in a line.


Sample Input 1

5 12
0 1 4
0 2 3
1 1 2
1 3 4
1 1 4
1 3 2
0 1 3
1 2 4
1 3 0
0 0 4
1 0 2
1 3 0
 


Sample Output 1

0
0
1
1
1
0
1
1
 */

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
 		
 		parent[ultimate_parent_v]=ultimate_parent_u; // This line was missing in your code
 		
 	}else{
 		
 		parent[ultimate_parent_v]=ultimate_parent_u;
 		rank[ultimate_parent_u]++;
 		
 		
 		
 	}  
 	
 	
 }

 
 	
};

void solve(){
	
	
ll n,q;

cin>>n>>q;

DisjointSet ds(n);

while(q--){
    
  ll com,x,y;
  
  
  cin>>com>>x>>y;
  
  
  if(com==0){
      
      ds.findUnionByRank(x,y);
  }
  
  if(com==1){
      
      if(ds.findUPar(x)==ds.findUPar(y))cout<<1<<nl;
      else cout<<0<<nl;
      
  }
    
    
    
    
}
	
	

	
 		
 	} 
	
	
	


signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	// int _t; cin>>_t;while(_t--)
		solve();
	
	
	//cerr<<"Time elapsed: "<< 1.0*clock()/ CLOCKS_PER_SEC << "s.\n\n";
	
	
	
	
}