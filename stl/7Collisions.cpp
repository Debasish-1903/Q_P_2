/*Collisions

Time-Limit: 1 sec Score: 50.00/100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

There are N balls on the X-axis and M balls on the Y-axis. At the time, t=0, each ball on X-axis is thrown parallel to the Y-axis in the positive Y direction. Similarly, each ball on Y-axis is thrown parallel to the X-axis in the positive X direction. At any time, if two balls collide, they disappear. A collision can only happen between the ball thrown from X-axis and the ball thrown from Y-axis. No two balls from X-axis or Y-axis can collide. A ball can take part in at max one collision. You have to find the total number of collisions. 


Input Format

The first line of the input contains one integer T - the number of test cases. Then T test cases follow.
The first line of each test case contains two space-separated integers N and M - the number of balls on the X-axis and Y-axis respectively.
For each test case, N lines follow. The i-th of the line contains two space-separated integers Xi and Ui, the position and speed of the i-th ball respectively.
For each test case, M lines follow. The i-th of the line contains two space-separated integers Yi and Vi, the position and speed of the i-th ball respectively.


Output Format

For each test case, print the number of collisions on a separate line.


Constraints

1≤ T ≤ 100
1≤ N, M ≤ 105
1≤ Xi, Ui, Yi, Vi ≤ 109


Sample Input 1

3
1 1 
1 3 
3 1 
2 1 
1 4 
1 3 
4 1 
2 3 
1 2 
2 3 
1 6 
2 1 
6 1

Sample Output 1

1
1
2

Note

In the first test case of the example, at t=1 the balls collide. The number of collisions is 1.

In the second test case of the example, at t=1, the first ball on X-axis and the first ball on Y-axis collide and disappear. The number of collisions is 1.

In the third test case of the example, at t=⅓, the second ball on X-axis and the first ball on Y-axis collide and disappear. At t=1, the first ball on X-axis and the second ball on Y-axis collide and disappear. The number of collisions is 2.*/

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




 /*ll add(ll a,ll b){
	
	ll ans=(a+b)%mod;
	if(ans<0) ans+=mod;
	
	return ans;
}

 ll sub(ll a,ll b){
	
	ll ans=(a-b)%mod;
	if(ans<0) ans+=mod;
	
	return ans;
}

ll mul(ll a,ll b){
	
	ll ans=(a*b)%mod;
	if(ans<0) ans+=mod;
	
	return ans;
}*/


void solve(){

ll n,m;

cin>>n>>m;
 unordered_map<ll,ll>mp;
 
 while(n--){
     ll x,u;
     cin>>x>>u;
     
     ll mul=x*u;
     
     mp[mul]++;
     
 }
 

 
 ll cnt=0;
while(m--){
    
    ll y,v;
    cin>>y>>v;
    
    ll mul=y*v;
    
    if(!mp.empty()&&mp.find(mul)!=mp.end()){
       
       mp[mul]--;
        cnt++;
        
        if(mp[mul]==0)mp.erase(mul);
    }
    
    
    
}


cout<<cnt<<nl;

}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	 int _t; cin>>_t;while(_t--)
		solve();
	
	
	//cerr<<"Time elapsed: "<< 1.0*clock()/ CLOCKS_PER_SEC << "s.\n\n";
	
	
	
	
}