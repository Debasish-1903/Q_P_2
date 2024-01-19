

//diff utility 

/*x=aatu
  y=atua 
  
  diff utility = a-atu+a or -aatu+a or -a-a-t-t+a+t+u+a
  
  if we take the 0(no sign )and + sign then we get the y string and if we take 0 and - sign then we get the x string*/


// calculate the minimum length of diff utility ()




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


int n,m;
string x,y;

int dp[101][101];

 // get the minimal length of difference utility 
int rec(int l1, int l2){   // giving the optimal utility length up x[l1]....n and y[l2]......m level assuming (x[l1]and x[l2](up to the level)is precomputed)
    	
    	// pruning 
	
	// base case
	
	if(l1==n&&l2==m)return 0;
	
	
	
	// cache check
	
	if(dp[l1][l2]!=-1)return dp[l1][l2];
	
	// compute
	 int ans=1e9;
	 
	 if(l1<n){
	 	
	 	ans=min(ans,rec(l1+1,l2)+1/*-x[l1]*/);
	 }
	  if(l2<m){
	 	
	 		ans=min(ans,rec(l1,l2+1)+1/*+y[l2]*/);
	 	
	 }
	  if(l1<n&&l2<m&&(x[l1]==y[l2])){
	 	
	 	
	 		
	 		ans=min(ans,rec(l1+1,l2+1)+1);
	 	
	 }


	
	return dp[l1][l2]=ans;
	
	// save and return 
	
	
}




void solve(){
	
	cin>>x>>y;
	
	
	n=x.length();
	m=y.length();
	
	memset(dp,-1,sizeof(dp));
	cout<<rec(0,0)<<nl;
	
	
	
	
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	// int _t; cin>>_t;while(_t--)
		solve();
	
	
	//cerr<<"Time elapsed: "<< 1.0*clock()/ CLOCKS_PER_SEC << "s.\n\n";
	
	
	
	
}




///***it is the template of printing the solution ingeneral in any problem in dp******///
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


int n,m;
string x,y;

int dp[101][101];
int back[101][101];

 // get the minimal length of difference utility 
int rec(int l1, int l2){   // giving the optimal utility length up x[l1]....n and y[l2]......m level assuming (x[l1]and x[l2](up to the level)is precomputed)
    	
    	// pruning 
	
	// base case
	
	if(l1==n&&l2==m)return 0;
	
	
	
	// cache check
	
	if(dp[l1][l2]!=-1)return dp[l1][l2];
	
	// compute
	 int ans=1e9;
	 
	 if(l1<n){
	 	
	 	
	 	if(rec(l1+1,l2)+1<ans){
	 	    
	 	 ans=rec(l1+1,l2)+1/*-x[l1]*/;
	 	    back[l1][l2]=0;  // in this case it is the best optimal
	 	}
	 	    
	 	}
	 	
	 	
	 
	  if(l2<m){
	 	
	 	if(rec(l1,l2+1)+1<ans){
	 	    
	 	 ans=rec(l1,l2+1)+1/*-x[l1]*/;
	 	    back[l1][l2]=1;  // in this case it is the best optimal
	 	}
	 	    
	 	
	 }
	  if(l1<n&&l2<m&&(x[l1]==y[l2])){
	 	
	 	
	 		
	 	if(rec(l1+1,l2+1)+1<ans){
	 	    
	 	 ans=rec(l1+1,l2+1)+1/*-x[l1]*/;
	 	    back[l1][l2]=2;  // in this case it is the best optimal
	 	}
	 	    
	 	
	 }


	
	return dp[l1][l2]=ans;
	
	// save and return 
	
	
}



void generate(int l1,int l2){
    
    int ch=back[l1][l2];
    
    
    if(l1==n&&l2==m)return ;
    
    if(ch==0){
        
        
        cout<<"-"<<x[l1]<<" ";
        generate(l1+1,l2);
        
    }
    
     if(ch==1){
        
        
        cout<<"+"<<y[l2]<<" ";
         generate(l1,l2+1);
    }
     if(ch==2){
        
        
        cout<<x[l1]<<" ";
          generate(l1+1,l2+1);
    }
    
    
    
}



void solve(){
	
	cin>>x>>y;
	
	
	n=x.length();
	m=y.length();
	
	memset(dp,-1,sizeof(dp));
	cout<<rec(0,0)<<nl;
	
	generate(0,0);
	
	
	
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	// int _t; cin>>_t;while(_t--)
		solve();
	
	
	//cerr<<"Time elapsed: "<< 1.0*clock()/ CLOCKS_PER_SEC << "s.\n\n";
	
	
	
	
}