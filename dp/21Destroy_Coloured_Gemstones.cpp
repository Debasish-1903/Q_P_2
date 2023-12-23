/*Destroy Coloured Gemstones

Time-Limit: 4 sec Score: 0.00/100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Description

You are given an array of colored gemstones. In one second, you can remove exactly one continuous substring of colored gemstones that is a palindrome. You have to find the minimum number of seconds needed to destroy all the gemstones.


Input Format

The first line of the input contains one integer T - the number of test cases. Then T test cases follow.

The first line of each test case contains one integer N - the length of the array. 

The second line of each test case contains N space-separated integers.


Output Format

For each test case, print the minimum number of seconds needed to destroy all the gemstones.


Constraints

1≤ T ≤ 200

1≤ N ≤ 100

1≤ Ai ≤ N


Sample Input 1

3
4
1 3 3 1
3
2 4 3
11
1 3 2 3 2 4 3 3 4 3 1

Sample Output 1

1
3
2

Note

For the first test case, the given array is a palindrome. You can remove it in one go.

For the second test case, you will have to destroy one gemstone at a time.

For the third test case, first destroy 2 3 2 and then 1 3 4 3 3 4 3 1 as follows: 1 3 [2 3 2] 4 3 3 4 3 1  */


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

vector<ll>arr;
ll dp[110][110];
ll dp_[110];


ll palindrom(ll l,ll r){
	
	
	if(l>=r)return 1;
	
	if(dp[l][r]!=-1)return dp[l][r];
	
	ll ans=0;
	if(arr[l-1]==arr[r-1]){
	if(palindrom(l+1,r-1))ans=1;
	
	}
	
	return dp[l][r]=ans;
}


ll rec(ll i){
	
	//pruning 
	
	
	// base case 
	if(i==0)return -1;
	
	
	// cache and check 
	if(dp_[i]!=-1)return dp_[i];
	
	
	// compute
	
	ll ans=1e18; 
	for(ll j=0;j>=0;j++){
		if(palindrom(j+1,i)){
			
		//	arr.erase(arr.begin()+j,arr.begin()+i+1);
			ans=min(ans,1+rec(j));
			
			
		}
		
	}
	
	
	// save and return 
	
	return dp_[i]=ans;
	
	
	
}



void solve(){
	
cin>>n;	

arr.resize(n);

arr.clear();

for(ll i=0;i<n;i++){
	
	cin>>arr[i];
	
}


memset(dp,-1,sizeof(dp));
memset(dp_,-1,sizeof(dp_));
cout<<rec(n)<<nl;


	
	
	
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	int _t; cin>>_t;while(_t--)
		solve();
	
	
	//cerr<<"Time elapsed: "<< 1.0*clock()/ CLOCKS_PER_SEC << "s.\n\n";
	
	
	
	
}