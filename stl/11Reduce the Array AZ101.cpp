/*Reduce the Array AZ101

Time-Limit: 1 sec Score: 0/100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Description

You are given an array of N integers. In one operation, remove any two elements in the array and add their sum to the array. The cost of this operation will be the sum of the two elements. Print the minimum cost till the size of the array does not become 1.


Input Format

The first line of the input contains one integer T - the number of test cases. Then T test cases follow.

The first line of each test case contains one integer N - the length of the array. 

The second line of each test case contains N space-separated integers.


Output Format

For each test case, print the minimum cost till the size of the array does not become 1.


Constraints

1≤ T ≤ 106

1≤ N ≤ 106

1≤ Ai ≤ 109

It is guaranteed that the sum of N over all test cases does not exceed 106.


Sample Input 1

3
4
3 1 4 2
3
1 1 1
4
2 3 1 3

Sample Output 1

19
5
18

Note

For the first test case, take 5 and 6 to get sum (5+6) = 11

For the second test case, take 1 and 1, array becomes [2, 1] and then take 2 and 1 to get sum (1+1) + (2+1) = 5

For the third test case, take 1 and 2, array becomes [3, 3, 3] and then take 3 and 3, array becomes [6, 3] and then take 6 and 3 to get sum (1+2) + (3+3) + (6+3) = 18*/


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
	
	priority_queue<ll,vector<ll>,greater<ll>>pq;
	
	while(n--){
	    
	    ll x;
	    cin>>x;
	    pq.push(x);
	    
	    
	}
	ll ans=0;
	
	while(pq.size()!=1){
	    ll top1=pq.top();
	    pq.pop();
	    ll top2=pq.top();
	    pq.pop();
	    
	    ans+=top1+top2;
	    
	    pq.push(top1+top2);
	    
	    
	}
	
	
	cout<<ans<<nl;
	
	
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	 int _t; cin>>_t;while(_t--)
		solve();
	
	
	//cerr<<"Time elapsed: "<< 1.0*clock()/ CLOCKS_PER_SEC << "s.\n\n";
	
	
	
	
}
