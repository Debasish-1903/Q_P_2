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

string str;
ll k;
ll n, m;

ll cost[28][28];
 ll dp[110][26][110];
  ll visited[110][26][110];
 
 
 // form 1:
 
 ll rec(ll level,ll prev_char,ll left){    // mamximum cost using left no of char changes from level to n-1 
     
     
     if(left<0)return -1e18;
     
     
     if(level==n) return 0;
     
     
     
     // cache check 
     
     if(visited[level][prev_char][left]!=-1){
         
         
         return dp[level][prev_char][left];
     }
     
     
     // transition 
     
     ll ans=-1e18;
     for(ll i=0;i<26;i++){   // it is just checking the 26 possible character for the current postion i=character 
         
         
         if(str[level]-'a'==i){
             
             ans=max(ans,rec(level+1,i,left)+cost[prev_char][i]);
             
         }else{
             
              ans=max(ans,rec(level+1,i,left-1)+cost[prev_char][i]);
             
         }
         
         
         
         
     }
     
     
     // save and return 
     
     
     visited[level][prev_char][left]=1;
     
     return dp[level][prev_char][left]=ans;
     
     
 }
 
 
 
 
void solve(){
    
    cin>>str>>k;
    
    n=str.length();
    
    cin>>m;
    
    
    memset(cost,0,sizeof(cost));
     memset(visited,-1,sizeof(visited));
      
      
      for(ll i=0;i<102;i++){
          
          
          for(ll j=0;j<26;j++){
              
              for(ll l=0;l<=102;l++){
                    dp[i][j][l]=-1e18;
                  
              }
          }
      }
    
    for(ll i=0;i<m;i++){
        
        char c1,c2;
        ll c;
        
        
        cin>>c1>>c2>>c;
        
        cost[c1-'a'][c2-'a']=c;
        
    }
    
    
    ll maxi=-1e18;
    ll x;
    
    for(ll i=0;i<26;i++){
        
        
        
       if(str[0]-'a'==i){
             
            x= rec(1,i,k);
             
         }else{
             
              x=rec(1,i,k-1);
             
         }
         
         
         if(x>maxi){
             maxi=x;
         }
    
    }
    
    
    cout<<maxi<<nl;
    
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	 int _t; cin>>_t;while(_t--)
		solve();
	
	
	//cerr<<"Time elapsed: "<< 1.0*clock()/ CLOCKS_PER_SEC << "s.\n\n";
	
	
	
	
}


