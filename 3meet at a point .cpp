/*Meet at a Point

Time-Limit: 2 sec Score: 100.00/100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

There are 
n
 friends in a 2D plane who want to meet at some common point. Each of their position is given to you as 
x
 & 
y
 coordinates.

The distance a person covers to go from position 
(
x
1
,
y
1
)
 to 
(
x
2
,
y
2
)
 is the Manhattan distance, i.e., 
|
x
1
−
x
2
|
+
|
y
1
−
y
2
|
.

They choose the meeting point such that the sum of distances covered by each of them to reach it is minimum. Find this minimum sum of distances.


Input Format

The first line of input contains 
T
, the number of test cases.
The first line of each test case contains 
n
.
Each of the next 
n
 lines contains two integers 
(
x
,
y
)
.


Output Format

For each test case output one integer: The minimum sum of distances covered by them.


Constraints

1
≤
T
≤
10

1
≤
n
≤
10
5

0
≤
x
,
y
≤
10
6

Sample Input 1

1
3
0 4
4 0
2 2

Sample Output 1

8

Note

Point 
(
2
,
2
)
 is the optimal meeting point in this case.*/


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
	vector<ll>xrr;
	vector<ll>yrr;

void solve(){
	
	
	ll n;
	cin>>n;
	
	xrr.resize(n);
   yrr.resize(n);

	
for(ll i=0;i<n;i++){
    
  ll x,y;
  cin>>x>>y;
  
  xrr[i]=x;
    yrr[i]=y;
}

sort(xrr.begin(),xrr.end());
sort(yrr.begin(),yrr.end());




ll midian_x=xrr[n/2];
ll midian_y=yrr[n/2];

//cout<<midian_x<<"  "<<midian_y<<nl;

ll dist_x=0;
ll dist_y=0;
for(ll i=0;i<n;i++){
    
    dist_x+=abs(midian_x-xrr[i]);
    
    //cout<<dist_x<<nl;
    dist_y+=abs(midian_y-yrr[i]);
    
   // cout<<dist_y<<nl;
}
	
ll ans=dist_x+dist_y;

cout<<ans<<nl;
	
	
	
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	 int _t; cin>>_t;while(_t--)
		solve();
	
	
	//cerr<<"Time elapsed: "<< 1.0*clock()/ CLOCKS_PER_SEC << "s.\n\n";
	
	
	
	
}