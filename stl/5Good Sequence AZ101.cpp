/*Good Sequence AZ101

Time-Limit: 1 sec Score: 100.00/100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Description

You are given an array A of N integers. A sequence is called good if the value x occurs x times in the array. Find the minimum number of integers you need to delete from A to make it good.


Input Format

The first line of the input contains one integer T - the number of test cases. Then T test cases follow.

The first line of each test case contains one integer N - the length of the array. 

The second line of each test case contains N space-separated integers.


Output Format

For each test case, print the minimum number of integers you need to delete from A to make it good.


Constraints

1≤ T ≤ 105

1≤ N ≤ 105

1≤ Ai ≤ 109

It is guaranteed that the sum of N over all test cases does not exceed 106.


Sample Input 1

3
5
3 2 3 3 1
4
3 2 2 4
5
6 6 1 1 2

Sample Output 1

1
2
4

Note

For the first test case, remove 2

For the second test case, remove 3 and 4

For the third test case, remove 6, 6, 1 and 2 */


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


void solve(){

ll n;

cin>>n;

unordered_map<ll,ll>mp;

for(ll i=0;i<n;i++){
    
    ll x;
    cin>>x;
    
    mp[x]++;
    
    
}

ll cnt=0;

for(auto it:mp){
    
    if(it.s<it.f)cnt+=it.s;
    else if(it.s>it.f)cnt+=(it.s-it.f);
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