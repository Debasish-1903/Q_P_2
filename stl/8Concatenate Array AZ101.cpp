/*Concatenate Array AZ101

Time-Limit: 1 sec Score: 50.00/100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Description

You are given an array A of N integers. Find the length of the largest increasing subsequence if the array A is concatenated to itself N times. A sequence A is a subsequence of an array B if A can be obtained from B by deletion of several (possibly, zero or all) elements. The longest increasing subsequence should be strictly increasing.


Input Format

The first line of the input contains one integer T - the number of test cases. Then T test cases follow.

The first line of each test case contains one integer N - the length of the array. 

The second line of each test case contains N space-separated integers.


Output Format

For each test case, print the length of the largest increasing subsequence if the array A is concatenated to itself N times. 


Constraints

1≤ T ≤ 2*105

1≤ N ≤ 106

1≤ Ai ≤ 109

It is guaranteed that the sum of N over all test cases does not exceed 106.


Sample Input 1

3
3
2 1 3
5
3 1 1 1 4
4
3 2 1 4

Sample Output 1

3
3
4

Note

For the first test case, 2 1 3 2 1 3 2 1 3

For the second test case, 3 1 1 1 4 3 1 1 1 4 3 1 1 1 4 3 1 1 1 4 3 1 1 1 4

For the third test case, 3 2 1 4 3 2 1 4 3 2 1 4 3 2 1 4*/



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

ll n;
cin>>n;

set<ll>st;
while(n--){
    
    ll x;
    cin>>x;
    st.insert(x);
    
}

cout<<st.size()<<nl;


}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	 int _t; cin>>_t;while(_t--)
		solve();
	
	
	//cerr<<"Time elapsed: "<< 1.0*clock()/ CLOCKS_PER_SEC << "s.\n\n";
	
	
	
	
}