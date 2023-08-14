/*Triangle Sum Query

Time-Limit: 4 sec Score: 1.00/100
Difficulty : ****
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

Given a 2d-array of dimension N*M and Q queries. In each query three integers x1, y1, L are given, you have to find the sum of the triangle ( check the image ) %10^9+7.

Assume that the value of cell outside the grid has value 0.



Input Format

The first line contains three space-separated integers N, M, Q where 1<=N, M<=10^3, 1<=Q<=10^6.

Next N lines contains M space-separated integers (-1e9<=Aij<=1e9).

Next Q lines contains three space separated integers x1, y1, L where 1<=x1<=N, 1<=y1<=M, 1<=L<=1000.


Output Format

For each query print the sum of the triangle.


Sample Input 1

5 5 5
-1 2 3 -4 2
0 0 0 0 4
1 2 4 3 5
-1 -5 -2 3 4
0 -3 -5 3 -6
1 1 2
1 2 3
2 3 3
4 4 4
2 3 2

Sample Output 1

1000000006
2
5
10
5*/
//for visualization //
//https://lh5.googleusercontent.com/ytCYRQPvCdVeJJOQ07S47tiA1hxnWyXUHLzyb7z8or3xuUJc8X8Jz-NzcImez2nkk4H0dKQaSWtAoBb4Kicj4YLVAm-w6TQWRx8-tSt0zQmxGKzmjcKWTeNIsnRIPAWddoFq4u6J

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
#define N 1010

#define yes "YES"
#define no "NO"

//const mod=1e9+7;

ll arr[N][N];
ll rect[N][N];
ll tri[N][N];


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

ll n,m,q;
cin>>n>>m>>q;


for(ll i=1;i<=n;i++){
    
    for(ll j=1;j<=m;j++){
        
        cin>>arr[i][j];
      
        
    }
}

for(ll i=1;i<=n;i++){
    
    for(ll j=1;j<=m;j++){
        
        rect[i][j]=(arr[i][j]+rect[i][j-1]+rect[i-1][j]-rect[i-1][j-1])%mod;
        
    tri[i][j]=(rect[i][j]-rect[i][j-1]+tri[i-1][j-1])%mod;    
      
        
    }
}


while(q--){
    
   ll x1,y1,l;
   cin>>x1>>y1>>l;
   
   ll i=max(1ll*0,x1-l);
   ll j=max(1ll*0,y1-l);
   
   ll ans=tri[x1][y1]-tri[i][j]-(rect[i][y1]-rect[i][j]); // here (rect[x-l][y1]-rect[x1-l][y1-l])is the rectangle section which should be removed pls visualize it//
 
   ans=(ans%mod+mod)%mod;
   
   cout<<ans<<nl;
  
}





    
	
}




signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
//	int _t; cin>>_t;while(_t--)
		solve();
	
	
	//cerr<<"Time elapsed: "<< 1.0*clock()/ CLOCKS_PER_SEC << "s.\n\n";
	
	
	
	
}
