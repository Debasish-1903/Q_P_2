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




 ll n,m;
 
 
  ll dp[1010][1010];
  ll back[1010][1010];
 
 
 string str1,str2;
 
 ll rec(ll i,ll j){ 
 	
 	// pruning 
 	
 	// base case
 	
 	if(i==n&&j==m)return 0;
 	
 	//cache check
 	
 	if(dp[i][j]!=-1)return dp[i][j];
 	
 	
 	// transition 
 	
 	ll ans=1e18;
 	
 	if(i<n){
 	    
 	    
 	    if(rec(i+1,j)+1<ans){
 	        ans=rec(i+1,j)+1;
 	        
 	        back[i][j]=0;
 	        
 	    }
 	   
 	    
 	    
 	}
 	
 	
 	if(j<m){
 	    
 	   if(rec(i,j+1)+1<ans){
 	        ans=rec(i,j+1)+1;
 	        
 	        back[i][j]=1;
 	        
 	    }
 	}
 	
 	if(i<n&&j<m&&str1[i]==str2[j]){
 	    
 	    if(rec(i+1,j+1)+1<ans){
 	        ans=rec(i+1,j+1)+1;
 	        
 	        back[i][j]=2;
 	        
 	    }
 	}
 	
 	
 	// save and return 
 	
 	return dp[i][j]=ans;
 	
 }
 

// void generate(ll i,ll j){
    
//     ll ch=back[i][j];
    
    
//     	if(i==n&&j==m)return ;
    
//     if(ch==0){
        
//         cout<<str1[i];
//         generate(i+1,j);
//     }
//      if(ch==1){
        
//         cout<<str2[j];
//         generate(i,j+1);
//     }
    
//      if(ch==2){
        
//         cout<<str2[j];
//         generate(i+1,j+1);
//     }
    
    
// } 
 
 string generate(ll i,ll j){
    string result = "";
    ll ch=back[i][j];
    if(i==n&&j==m)return result;
    if(ch==0){
        result += str1[i];
        result += generate(i+1,j);
    }
    if(ch==1){
        result += str2[j];
        result += generate(i,j+1);
    }
    if(ch==2){
        result += str2[j];
        result += generate(i+1,j+1);
    }
    return result;
}

 
 

void solve(){
    
cin>>str1>>str2;



n=str1.length();
m=str2.length();


memset(dp,-1,sizeof(dp));

rec(0,0);

  cout<<generate(0,0)<<nl;;
	
	
	
}



signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	 int _t; cin>>_t;while(_t--)
		solve();
	
	
	//cerr<<"Time elapsed: "<< 1.0*clock()/ CLOCKS_PER_SEC << "s.\n\n";
	
	
	
	
}

