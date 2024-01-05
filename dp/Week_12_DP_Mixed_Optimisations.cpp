/*there are 2 piles present , A and B stones are present respectively
In one turn one player can do two things--
1. take any no of stones from one pile 

2. take equal no of stones from both the piles


who can't move  he will be lost  */




// recursive way
int rec(ll x,ll y){
	
	
	//pruning 
	
	
	// basecase
	if(x==0&&y==0)return 0;
	
	
	
	// caching 
	
	if(dp[x][y]!=-1)return dp[x][y];
	
	
	//compute 
	int ans=0;  // by default it is a loosing state if in transition any loosing state appear then this 
	// state become wining state
	
	for(ll z=0;z<x;z++){
		
		if(rec(z,y)==0){
			
			ans=1;
			break;
		}
	}
	
	for(ll z=0;z<y;z++){
		
		if(rec(x,z)==0){
			
			ans=1;
			break;
		}
	}
	
	
	for(ll z=1;z<=min(x,y);z++){   // focus on it ...start at 1 and goes up to min(x,y)
		       // means remove 1 stone and check up to how much we can go
		if(rec(x-z,y-z)==0){
			
			ans=1;
			break;
		}
	}
	
	
	// save and return 
	
	return dp[x][y]=ans;
	
	
}


// void solve(){
	
// 	ll a,b;
	
// 	cin>>a>>b;
	
// 	memset(dp,-1,sizeof(dp));
	
	
// 	cout<<rec(a,b);
	
	
	
	
	
// }





// iterative way

void solve(){
	
	ll a,b;
	
	cin>>a>>b;
	
	
	for(int x=0;x<=a;x++){
		
	  for(int y=0;y<=b;y++){
	  	
	  	// base case
	  	
	  	if(x==0&&y==0)dp[x][y]=0;
	  	
	  	
	  	int ans=0;  // by default it is a loosing state if in transition any loosing state appear then this 
	// state become wining state
	
	for(ll z=0;z<x;z++){
		
		if(dp[z][y]==0){
			
			ans=1;
			break;
		}
	}
	
	for(ll z=0;z<y;z++){
		
		if(dp[x][z]==0){
			
			ans=1;
			break;
		}
	}
	
	
	for(ll z=1;z<=min(x,y);z++){   // focus on it ...start at 1 and goes up to min(x,y)
		       // means remove 1 stone and check up to how much we can go
		if(dp[x-z][y-z]==0){
			
			ans=1;
			break;
		}
	}
	
	
	// save and return 
	
        dp[x][y]=ans;
	
	  	
	  	
	  }
	}
	
	
	cout<<dp[a][b];
	
	
	
	
	
}


signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	// int _t; cin>>_t;while(_t--)
		solve();
	
	
	//cerr<<"Time elapsed: "<< 1.0*clock()/ CLOCKS_PER_SEC << "s.\n\n";
	
	
	
	
}








//denomination //

// we were given some integers, in a denomination , we need to make a target number=s using these 
//numbers using each no.s any no of time;



//sequence of solving dp problem


/* step1: which form? form1 or 2 or 3 or 4 ?
step2: state formation ==defination  of dp  rec(level,x){  // can we make x ? // count the total no of possible way to make // find the min}
step3: transition  --> or/and  || summ +  || min/max

step4: time complexity: O(no of states(1+transistion per state))==O(#s(1+#T)) ==O(E+V) of dag(directed acyclick graph)


*/
// recursive way

int n;
int den[1005];

bool dp[1005][1005];
bool done[1005][1005]; // visited array

bool rec(int level,int x){
	
	
	//pruning 
	
	 if(x<0)return false;
	//base case
	if(level==n){
		
		if(x==0)return true;
		else return false;
	}
	
	
	// cache check
	
	if(done[level][x])return dp[level][x];
	
	
	// recursive case
	bool ans=rec(level,x-den[level])||rec(level+1,x);
	
	// save and return
	
	
	dp[level][x]=ans;
	done[level][x]=true;
	
	return ans;
	
	
}

void solve(){
	
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>den[i];
	}
	
	int target_sum;
	cin>>target_sum;
	
	for(int i=0;i<n;i++){
		
		for(int j=0;j<=target_sum;j++){
			
			done[i][j]=false;
		}
	}
	
	
	
	cout<<rec(0,target_sum)<<nl;
	//herer rec(level,x)//
	
	
	
	
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	// int _t; cin>>_t;while(_t--)
		solve();
	
	
	//cerr<<"Time elapsed: "<< 1.0*clock()/ CLOCKS_PER_SEC << "s.\n\n";
	
	
	
	
}

// iterative way

int denom[1001];

void solve(){
	
	int n,m;
	cin>>n>>m;
	
	for(int i=0;i<n;i++){
		
		cin>>denom[i];
		
	}
	
	
	
	int dp[n+1][m+1]; // because for iterator dp we need to store the base case also in dp array(unlike recursive )
	for(int l=n;l>0;l--){
		
		for(int s=0;s<=m;s++){
			
			//base case
			if(l==n){
				
				
				if(s==0) dp[l][s]=1;
				
					else dp[l][s]=0;
			}
			
			
			// other general case
			
			dp[l][s]=0;
			
			if(dp[l+1][s]){
				
				dp[l][s]=1;
			}
			
			
			if(s>=denom[l]&&dp[l][s-denom[l]]){
				
				dp[l][s]=1;
			}
			
			
			
		}
		
	}
	
	cout<<dp[0][m]<<nl;
	
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	// int _t; cin>>_t;while(_t--)
		solve();
	
	
	//cerr<<"Time elapsed: "<< 1.0*clock()/ CLOCKS_PER_SEC << "s.\n\n";
	
	
	
	
}

