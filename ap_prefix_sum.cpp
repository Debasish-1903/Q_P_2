/*AP Addition

Time-Limit: 4 sec Score: 100.00/100
Difficulty :*** 
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

Given an array of N integers and Q queries. Initially, all the elements of the array have value 0.

In each query 4 integers A, D, L, R is given, which means perform AP addition

Arr[L]+=A

Arr[L+1]+=A+D

Arr[L+2]+=A+2D

Arr[L+3]+=A+3D

.

.

.

.

Arr[R]+=A+(R-L)*D.

After performing all the operations. Print the final array % 10^9+7.


Input Format

The first line contains two space-separated integers N, Q where 1<=N<=10^6, 1<=Q<=10^6.

Next Q lines contain four space-separated integers A, D, L, R where 0<=A,D<=10^4, 1<=L<=R<=N.


Output Format

Print the N space-separated integer representing the final array %10^9+7.


Sample Input 1

5 5
1 3 1 5
2 4 2 2
5 6 3 5
6 9 5 5
1 4 2 4

Sample Output 1

1 7 17 30 36 */

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
#define N 1000010

#define yes "YES"
#define no "NO"

//const mod=1e9+7;

ll arr[N];
ll brr[N];
// ll rect[N];
// ll rect1[N];


ll add(ll a,ll b){
    
    ll ans=(a+b)%mod;
    if(ans<0) ans+=mod;
    
    return ans;
}

 ll sub(ll a,ll b){
    
    ll ans=(a-b)%mod;
    if(ans<0) ans+=mod;
    
    return ans;
}

void solve(){

ll n,q;
cin>>n>>q;


while(q--){
  ll a,d,l,r;
  
  cin>>a>>d>>l>>r;
  
  arr[l]+=(a-(d*l));
  
  arr[r+1]-=(a-(d*l));
  
  brr[l]+=d;
  brr[r+1]-=d;
  
    
    
    
}

for(ll i=1;i<=n+1;i++){
    
    arr[i]+=arr[i-1]%mod;
  // rect[i]=arr[i]+rect[i-1];
    brr[i]+=brr[i-1]%mod;
    //rect1[i]=brr[i]+rect1[i-1];
    
}

// for(ll i=1;i<=n+1;i++){
    
//   cout<<rect[i]<<" " ;
   
// }
// cout<<nl;

//  for(ll i=1;i<=n+1;i++){
    
//   cout<<rect1[i]<<" " ;
   
// }  
// cout<<nl;


for(ll i=1;i<=n;i++){
    
    ll ans=arr[i]+i*brr[i];
    ans=(ans%mod+mod)%mod;
    cout<<ans<<" ";
}

cout<<nl;
	
}




signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
//	int _t; cin>>_t;while(_t--)
		solve();
	
	
	//cerr<<"Time elapsed: "<< 1.0*clock()/ CLOCKS_PER_SEC << "s.\n\n";
	
	
	
	
}