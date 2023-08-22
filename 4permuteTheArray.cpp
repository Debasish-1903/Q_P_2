/*There are two arrays of size n, A [a1, a2 … an] and B [b1, b2 … bn]. You can permute the elements in both the arrays any way you want.

Your goal is to minimize the sum of the absolute differences between corresponding elements of the arrays i.e. sum of |ai-bi| for i from 1 to n.

Find this minimum sum.


Input Format

First line of input contains T, number of test cases.

First line of each test case contains n, size of the arrays.

Second line contains n integers a1, a2 … an .

Third line contians n integers b1, b2 … bn .

 

 


Output Format

For each test case print a single integer in a new line: Minimum sum of the absolute differences between corresponding elements of the arrays.


Constraints

T ≤ 10

1 ≤ n ≤ 105

0 ≤ |ai|,|bi| ≤ 106


Sample Input 1

1

3

1 2 1

2 1 1


Sample Output 1

0


Note

Arrange elements in B as [1, 2, 1].

Sum = |1-1| + |2-2| + |1-1| = 0*/


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
vector<ll>brr;
void solve(){
    
    ll n;
    cin>>n;
    arr.resize(n);
    brr.resize(n);
    
  for(ll i=0;i<n;i++){
      
      ll x;
      cin>>x;
      arr[i]=x;
      
  }
  
   for(ll i=0;i<n;i++){
      
      ll y;
      cin>>y;
      brr[i]=y;
      
  }
  
  
  
  sort(arr.begin(),arr.end());
  sort(brr.begin(),brr.end()); 
  
  ll ans=0;
  
  for(ll i=0;i<n;i++){
      
      ans+=abs(arr[i]-brr[i]);
      
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