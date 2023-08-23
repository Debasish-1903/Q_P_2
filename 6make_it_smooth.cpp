/*Make it smooth

Time-Limit: 1 sec Score: 50.00/100
Difficulty : *
 Memory: 256 MB Accepted Submissions: 100
Description

You are given an array A of size N. In one operation you can select any non-decreasing subarray and increment all the elements in the subarray by one. Your goal is to make the whole array non-decreasing in minimum operations.

 


Input Format

First line of input contains T, number of test cases.

First line of each test case contains n.

Next line contains n integers of array A.

 


Output Format

For each test case print a single integer in a new line: Minimum number of operations.


Constraints

T ≤ 10

1 ≤ n ≤ 105

0 ≤ Ai ≤ 109


Sample Input 1

2

4

5 3 2 5

3

1 1 1


Sample Output 1

3

0*/




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


vector<ll>arr;
void solve(){
    
  ll n;
  cin>>n;
  
  arr.resize(n);
  for(ll i=0;i<n;i++){
      
      ll x;
      cin>>x;
      
      arr[i]=x;
      
  }
  ll ans=0;
  for(ll i=1;i<n;i++){
      
      
      if(arr[i]<arr[i-1]){
          
          ans+=(arr[i-1]-arr[i]);
          
      }
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