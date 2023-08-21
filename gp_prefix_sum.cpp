/*GP Addition

Time-Limit: 4 sec Score: 1.00/100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

Given an array of N integers and Q queries and an integer K. Initially, all the elements of the array have value 0.

In each query 3 integers A, L, R is given, which means perform GP addition

Arr[L]+=A

Arr[L+1]+=AK

Arr[L+2]+=AKK

Arr[L+3]+=AKKK

.

.

.

.

Arr[R]+=A*(K^(R-L))

 

After performing all the operations. Print the final array % 10^9+7.


Input Format

The first line contains three space-separated integers N, Q, K where 1<=N<=10^6, 1<=Q<=10^6, 1<=K<=10^9.

Next Q lines contain three space-separated integers A, L, R where 0<=A<=10^4, 1<=L<=R<=N.


Output Format

Print the N space-separated integer representing the final array %10^9+7.


Sample Input 1

5 5 2
3 1 5
4 2 2
6 3 5
9 5 5
4 2 4

Sample Output 1

3 14 26 52 81 */


#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define LD long double

const int N = 100010;

int inf = 1e9;
int mod = 1e9 + 7;

inline void add(int &a, int b) {
  a += b;
  if (a >= mod) a -= mod;
}

inline void sub(int &a, int b) {
  a -= b;
  if (a < 0) a += mod;
}

inline int mul(int a, int b) {
  return (int) ((long long) a * b % mod);
}

inline int power(int a, long long b) {
  int res = 1;
  while (b > 0) {
    if (b & 1) {
      res = mul(res, a);
    }
    a = mul(a, a);
    b >>= 1;
  }
  return res;
}

inline int inv(int a) {
  a %= mod;
  if (a < 0) a += mod;
  int b = mod, u = 0, v = 1;
  while (a) {
    int t = b / a;
    b -= t * a; swap(a, b);
    u -= t * v; swap(u, v);
  }
  assert(b == 1);
  if (u < 0) u += mod;
  return u;
}


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, q, k;
    cin >> n >> q >> k;
    int A[n + 2];
    memset(A, 0, sizeof(A));

    while(q--) {
        int a, l, r;
        cin >> a >> l >> r;
        add(A[l], mul(a, inv(power(k, l))));
        sub(A[r + 1], mul(a, inv(power(k, l))));
    }

    for(int i = 1; i <= n; i++) {
        add(A[i], A[i - 1]);
        cout << mul(A[i], power(k, i)) << " ";
    }
    cout << "\n";

    return 0;
}

// my solution why wrong??


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

ll mul(ll a,ll b){
	
	ll ans=(a*b)%mod;
	if(ans<0) ans+=mod;
	
	return ans;
}

ll power(ll a,ll b){
    
    if (b == 0)
        return 1;
    
    ll ans=1;
   while(b){
       
       if(b%2){
           
           ans*=a%mod;
           
       }
       
       a*=a%mod;
       
       b/=2;
       
       
   } 
    
    
    ans=(ans%mod+mod)%mod;
    return ans;
}

void solve(){

ll n,q,k;
cin>>n>>q>>k;
vector<ll>arr(n+2,0);
//vector<ll>brr(n+2,0);


while(q--){
    
  ll a,l,r;
  
  cin>>a>>l>>r;
 
    arr[l]+=a%mod;
    
    arr[r+1]-=a*power(k,(r-l+1))%mod;
     arr[r+1] = (arr[r+1] % mod + mod) % mod; 
}


for(ll i=1;i<=n+1;i++){
    
    arr[i]+=(arr[i-1]*k)%mod;
    
     arr[i] = (arr[i] % mod + mod) % mod; 
    
}
for(ll i=1;i<=n;i++){
    
    
    ll ans=arr[i]%mod;
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




// accepted submission correct one 

#include<bits/stdc++.h>
using namespace std;
const int M=1e9+7;
long long expo(long long a,long long b){
    long long ans=1;
    while (b){
        if(b%2){ans=(ans*a)%M;}
        a=(a*a)%M;
        b=b/2;
    } return ans;
}

signed main(){
    int n,q; long long K; cin>>n>>q>>K;
    long long a[n]={0}; long long k[n+1];
    long long p[n+1]={0};
    for (int i=0;i<n+1;i++){k[i]=expo(K,i);}
    while(q--){
        long long A,l,r; cin>>A>>l>>r;
        p[l-1]=(p[l-1]+A+M)%M;
        p[r]=((p[r]-(A*k[r-l+1]))+M)%M;   
    }
    for(int i=1;i<n+1;i++){
        p[i]=(p[i]+((p[i-1]*K)+M)%M);
        while(p[i]<0){p[i]=(p[i]+M)%M;}
        p[i]=p[i]%M;
    }
    // for(int i=0;i<n+1;i++){
    //     cout<<p[i]<<" ";
    // }
    cout<<'\n';
    //  for(int i=0;i<n;i++){
    //     cout<<o[i]<<" ";
    // }
    // cout<<'\n';
    for(int i=0;i<n;i++){
        a[i]=p[i];
        while(a[i]<0){a[i]=(a[i]+M)%M;}
        a[i]=a[i]%M;
        cout<<a[i]<<" ";
    }

}