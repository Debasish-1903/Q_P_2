/* Square sum

Time-Limit: 1 sec Score: 1.00/100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Description

You are given an array A of n non-negative integers.

Define function F = Summation of |Ai-X|2 for all i from 1 to n.

Find the minimum value of the function F by choosing an appropriate integer X.

 


Input Format

First line of input contains T, number of test cases.

First line of each test case contains n .

Second line contains n integers, Ai , the array A.


Output Format

For each test case print the minimum value of F.


Constraints

T ≤ 10

1 ≤ n ≤ 105

0 ≤ Ai ≤ 106


Sample Input 1

1

3

2 2 3


Sample Output 1

1 */



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
 ll ans=0;
 for(ll i=0;i<n;i++){
     
   ll x;
   cin>>x;
   arr[i]=x;
   ans+=arr[i];
   
   
     
 }
 
 
 double mean=(ans/(double)n);
 
 ll f=floor(mean);
 ll c=ceil(mean);
 
 
 ll result1=0;
 
 ll result2=0;
 for(ll i=0;i<n;i++){
     
     result1+=((arr[i]-c)*(arr[i]-c));
     result2+=((arr[i]-f)*(arr[i]-f));
     
 }
 
 
 cout<<min(result1,result2)<<nl;
 
}



signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
    int _t; cin>>_t;while(_t--)
		solve();
	
	
	//cerr<<"Time elapsed: "<< 1.0*clock()/ CLOCKS_PER_SEC << "s.\n\n";
	
	
	
	
}