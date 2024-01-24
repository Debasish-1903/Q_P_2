/*One Piece

Time-Limit: 1 sec Score: 1.00/100
Difficulty : **
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

Monkey D. Luffy, on his journey of becoming the "King of Pirates" and to conquer the "One Piece", wants to travel across the Grand Line.
Grand Line is a mysterious sea, and is in the shape of a 
N
∗
M
 grid 
S
 with each cell denoting the wind direction. The sign of 
s[i][j];
 can be:

1
 which means wind in the cell flows to the right. (i.e from 
s[i][j]-->s[i][j+1]
2 which means wind in the cell flows to the left. (i.e from 
S[i][j]-->s[i][j-1];

3
 which means wind in the cell flows downwards. (i.e from 
s[i][j]-->s[i+1][j]
4
 which means wind in the cell flows upwards. (i.e from 
S[i][j]-->s[i-1][j]

Notice that there could be some signs on the cells of the grid 
S
 that point outside the Grand Line sea grid.

Luffy's ship "Merry" can only sail along the wind direction and can't go outside the Grand Line sea grid 
S
 at any point.
Luffy can also modify the wind's direction on a cell with 
cost=1
. ( can modify the sign on a cell one time only )
Find the minimum cost to make Luffy's Voyage from the top left corner of the Grand line i.e 
S[1][1]
 to its bottom right corner i.e 
S[N][M]
 possible.


Input Format

Input is given from Standard Input in the following format:

s1,1 .....
..........
..........
........sn,m

Output Format

Print the answer.


Constraints

2
≤
N
,
M
≤
1000

N
 and 
M
 are integers.
1 ≤ 
S
i
,
j
 ≤ 4.


Sample Input 1

4 4
1 1 1 1
2 2 2 2
1 1 1 1
2 2 2 2 

Sample Output 1

3

Sample Input 2

3 3
1 1 3
3 2 2
1 1 4

Sample Output 2

0

Note
For Sample 1, You will start at point 
(0,0).The path to 
(3,3)is as follows. (0,0)--> (0,1)-->(0,2)--> (0,3)
 change the arrow to down with 
cost=1--> (1,3)--> (1,2)--> (1,1)--> (1,0)
 change the arrow to down with 
cost=1--> (2,0)
--> (2,1)--> (2,2)--> (2,3)change the arrow to down with 
cost=1--> (3,3)

The total cost = 3.
 
 
 */


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
#define mp make_pair
#define ii pair<ll,ll>

ll n,m;


vector<vector<ll>>grid;

ll dx[4]={0,0,1,-1};
ll dy[4]={1,-1,0,0};


void bfs01(ll src_x,ll src_y){
	
	
	vector<vector<ll>>dist(n,vector<ll>(m,1e9));
	deque<ii>dq;
	
	dist[src_x][src_y]=0;
	
	dq.push_back(mp(src_x,src_y));
	
	
	while(!dq.empty()){
		
		auto it =dq.front();
		
		auto x=it.f;
		auto y=it.s;
		
		dq.pop_front();
		
		for(ll k=0;k<4;k++){
			
			auto xx=x+dx[k];
			auto yy=y+dy[k];
			
			
			ll w=(k+1==grid[x][y])? 0:1;
			
			if(xx>=0&&yy>=0&&xx<n&&yy<m&&dist[xx][yy]>dist[x][y]+w){
				
				dist[xx][yy]=dist[x][y]+w;
				
				if(w==1){
					
					dq.push_back(mp(xx,yy));
				}else if(w==0){
					
					dq.push_front(mp(xx,yy));
				}
				
				
			}
			
			
			
		}
		
		
		
		
		
	}
	
	cout<<dist[n-1][m-1]<<nl;
	
	
	
}




void solve(){
	
	cin>>n>>m;
	
	grid.assign(n,vector<ll>(m,0));
	
	
	for(ll i=0;i<n;i++){
		for(ll j=0;j<m;j++){
			
			cin>>grid[i][j];
		}
	}
		
	bfs01(0,0);
	
	
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	// int _t; cin>>_t;while(_t--)
		solve();
	
	
	//cerr<<"Time elapsed: "<< 1.0*clock()/ CLOCKS_PER_SEC << "s.\n\n";
	
	
	
	
}