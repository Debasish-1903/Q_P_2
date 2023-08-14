/*Max Value in the Rectangle

Time-Limit: 4 sec Score: 1.00/100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

Given a 2d-array of dimension N*M and Q queries. In each query five integers x1, y1, x2, y2, C is given, you have to increase the value of each cell in the submatrix with (x1,y1) be the leftmost corner and (x2,y2) be the rightmost corner by C. Initially the value of all the cell of the 2d-array is 0.

After all the query is performed, print the maximum value present in the 2d-array and the number of the cell with the maximum value.


Input Format

The first line contains three space-separated integers N, M, Q where 1<=N, M<=10^3, 1<=Q<=10^6.

The next Q lines contains five space separated integers x1, y1, x2, y2, C where 1<=x1<=x2<=N, 1<=y1<=y2<=M, -10^9<=C<=10^9.


Output Format

After all the query is performed, print 2 space-separated integers representing the maximum value present in the 2d-array and the number of the cell with the maximum value.


Sample Input 1

5 5 5
1 1 2 2 -8
1 2 3 4 9
2 3 3 3 -2
4 4 4 4 -4
2 3 2 4 0

Sample Output 1

9 5*/

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


 ll a[N][N];
 ll prefix[N][N];
void solve(){

ll n,m,q;
cin>>n>>m>>q;

while(q--){
    
   ll x1,y1,x2,y2,c;
   cin>>x1>>y1>>x2>>y2>>c;
   
   a[x1][y1]+=c;
   a[x1][y2+1]-=c;
   a[x2+1][y1]-=c;
   a[x2+1][y2+1]+=c;
    
}


ll max=a[1][1];
ll cnt=0;
for(ll i=1;i<=n;i++){
    
    for(ll j=1;j<=m;j++){
        
        prefix[i][j]=a[i][j]+prefix[i-1][j]+prefix[i][j-1]-prefix[i-1][j-1];
        
         if(prefix[i][j]==max){
            
            cnt++;
        }
        
        if(prefix[i][j]>max){
            
            max=prefix[i][j];
            cnt=1;
        }
        
       
        
        
        
        
    }
}


cout<<max<<" "<<cnt;


    
	
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
//	int _t; cin>>_t;while(_t--)
		solve();
	
	
	//cerr<<"Time elapsed: "<< 1.0*clock()/ CLOCKS_PER_SEC << "s.\n\n";
	
	
	
	
}