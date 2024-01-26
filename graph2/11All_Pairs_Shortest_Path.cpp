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
				
				temp+=dist[node[i]][node[j]]; //// get the all pair distnce for all active nodes.
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


/*The process of removing vertices from the present to the future is equivalent to adding vertices from the future to the present.
Therefore, the problem can be reframed as follows: Start from the future, progressively add vertices, and eventually reconstruct the graph as provided in the input.

Example
Lets take the Test Case 2 into consideration :
So the adjacency matrix is

0 3 1 1
6 0 400 1
2 4 0 1
1 1 1 0
The order in which vertices are removed are

4 1 2 3
We remove the vertex 1 at first and then remove the vertex 2.

Step 1 : Starting from future
So as discussed we would approach this problem from future. Initially we dont have any nodes so the total cost of shortest paths will be 0.

Step 2 : Adding node 3
We add the vertex 3 to an empty graph. The shortest path costs will still be 0 because there is no other node to traverse to. There is just a node 3 and traveling to 3 requires 0 cost.

So the shortest path adjacency matrix now stands to be

0
Step 3 : Adding node 2
After adding node 2, we now have 2 nodes 2 and 3. Using the floyd warshal algorithm continuation to find the shortest path matrix we get :

0 400
4 0
So the shortest path summation comes out to be 404.

Step 4 : Adding node 1
After adding node 1, we now have 3 vertices 1, 2 and 3. Using the floyd warshal algorithm continuation to find the shortest path matrix we get :

0 3 1
6 0 7
2 4 0
So the shortest path summation comes out to be 23.

Step 4 : Adding node 4
After adding node 4, we now have all the 4 vertices 1, 2, 3 and 4. Using the floyd warshal algorithm continuation to find the shortest path matrix we get :

0 1 1 1
1 0 2 1
1 2 0 2
1 2 2 0
So the shortest path summation comes out to be 17.

So we got our answers as 0, 404, 23, 17. Since this is the shortest path values as we keep on adding the vertices from future, we need to reverse them to get the values of removing the vertices each time and getting the shortest path sum cost.


#include<bits/stdc++.h>
#define ll long long int
#define N 510
using namespace std;

ll inf=1e16;
int main()
{
    int n;
    ll A[N][N]; // the adjecency matrix
    scanf("%d",&n); // take n.
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) scanf("%lld",&A[i][j]); // we take the graph in a 0 indexed manner.
    vector<ll> ans; // the final answer array.
    int x[N]; // the order of elements removed.
    for(int i=0;i<n;i++) scanf("%d",&x[i]),x[i]--;// take input, -- for 0 index
    for(int i=n-1;i>=0;i--) // move from backward [x[i],x[i+1]...x[n-1]] are the active edges.
    {
        for(int j=0;j<n;j++) 
            for(int k=0;k<n;k++) 
                A[j][k]=min(A[j][k],A[j][x[i]]+A[x[i]][k]); // relax the current node (Floyd washall)

        // After the ith iteration. The matrix has relaxed nodes x[i],x[i+1]...x[n-1].
        // So we these are the active nodes, and Floyd warshall ensures all those have correct shortest paths.
        ll temp=0;
        for(int j=i;j<n;j++) 
            for(int k=i;k<n;k++)
                temp+=A[x[j]][x[k]]; // get the all pair distnce for all active nodes.
        ans.push_back(temp); // add it to the ans.
    }
    for(int i=(int)ans.size()-1;i>=0;i--) printf("%lld ",ans[i]); // print in reverse order as we added instead of remove.
    return 0;
}*/