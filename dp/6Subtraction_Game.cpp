//form 5//


/*Subtraction Game

Time-Limit: 1 sec Score: 0.00/100
Difficulty : **
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

Vivek and Abhishek are playing a game of chips, taking turns alternatively. Initially, there are 
x
 chips on the table. On each turn, a player can pick up 
2
m
 chips such that 
m
≥
0
 and 
x
≥
2
m
. A player loses the game if he has no chips to pick from the table.

Given that Vivek starts the game, Predict the winner of the game.


Input Format

The first line contains 
T
 - the number of test cases.
The next 
T
 lines contain an integer 
x
, - the number of chips on the table.


Output Format

For each test case, Predict the winner of the chip game. Output "Vivek" if Vivek wins; else output "Abhishek", on a new line.


Constraints

1
≤
T
≤
10
6
.
0
≤
x
≤
2
×
10
5
.


Sample Input 1

5
0 
2
12783
1001
33

Sample Output 1

Abhishek
Vivek
Abhishek
Vivek
Abhishek*/


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

ll c;

ll done[200100];
ll dp[200100];


ll rec(ll x){ // state ==moves by the first player ... if any (x-2^m)==0 means oponen should lose then the current state will be wining state
	
	if(x<0)return 0;
	
	if(x==0)return 0;
	
	
	if(done[x])return dp[x];
	
	int ans=0;
	for(ll m=0;(1<<m)<=x;m++){
		
		
		if(rec(x-(1<<m))==0){
			
			ans=1;
			break;
		}
	}
	
	done[x]=true;
	return dp[x]=ans;
	
}

void solve(){
	
	cin>>c;
	
	// for(ll i=0;i<c;i++){
	// 	done[i]=false;
	// }
	
	if(rec(c)==1)cout<<"Vivek"<<nl;
	else{
		cout<<"Abhishek"<<nl;
	}
	
	
	
	
	
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	int _t; cin>>_t;while(_t--)
		solve();
	
	
	//cerr<<"Time elapsed: "<< 1.0*clock()/ CLOCKS_PER_SEC << "s.\n\n";
	
	
	
	
}