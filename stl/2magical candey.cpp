
/*
The Magical Candy Bag AZ101

Time-Limit: 1 sec Score: 0/100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Description

You have N magical candy bag. The i-th bag contains Ai candies. In each minute you can eat all the candies, Ai of one bag, after that, the candies become [Ai / 2] where [x] is the greatest integer less than x. You have K minutes, find the maximum number of candies you can eat.


Input Format

The first line of the input contains one integer T - the number of test cases. Then T test cases follow.

The first line of each test case contains two space-separated integers N, K - the number of bags and the number of minutes.

The second line of each test case contains N space-separated integers.


Output Format

For each test case, print the maximum number of candies you can eat.


Constraints

1≤ T ≤ 105

1≤ N ≤ 105

0≤ K ≤ 105

1≤ Ai ≤ 109

It is guaranteed that the sum of K over all test cases does not exceed 106.


Sample Input 1

3
4 2
4 3 5 1
1 2
4
6 3
3 2 2 5 1 2

Sample Output 1

9
6
10

Note

For the first test case, first take 5 candies then the bag becomes: [4, 3, 2, 1], and then take 4 candies to get a total 5+4 = 9 candies.

For the second test case, first take 4 candies, then bag becomes: [2] and then take 2 candies to get a total 4+2 = 6 candies.

For the third test case, first take 5 candies, then bag becomes: [3, 2, 2, 2, 1, 2] and then take 3 candies, then bag becomes: [1, 2, 2, 2, 1, 2], then take 2 candies to get a total 5+3+2 = 10 candies.*/

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


void solve(){
	
ll n,k;
cin>>n>>k;

priority_queue<int>pq;

for(ll i=0;i<n;i++){
    
    ll x;
    cin>>x;
    pq.push(x);
}

ll ans=0;
while(k--){
    
    ll temp=pq.top();
   ans+=pq.top();
   pq.pop();
   pq.push(temp/2);
    
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