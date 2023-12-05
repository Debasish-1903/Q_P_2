


// a array of numbers are given ,lets say [2,3,5,9]
//there are n items x1,x2,x3,....xn  . find if subset of the items exists that sums upto target T




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

int n;
int x[101];
int target;

bool  dp[105][105];
bool done[105][105];

bool rec(int level,int t){
	
	//pruning
	
	if(t<0)return false;
	//basecase
	
	if(level==n){
		
		
		if(target!=0&&t==0){
			
			return true;
		}else false;
	}
	
	//cache chekc
	
	if(done[level][t]==true)return dp[level][t];
	
	//compute
	
	bool ans=rec(level+1,t)||rec(level+1,t-x[level]);
	
	
	
	
	//save and return
	done[level][t]=true;
	dp[level][t]=ans;
	
	return ans;
	
	
}


void printf(int level,int t){
	
	
	cout<<"printf : "<<level<<" "<<t<<nl;
	//basecase
	if(level==n){
		
		return;
	}
	
	if(rec(level+1,t)){  //don't take
		
		printf(level+1,t);
		
	}else if(rec(level+1,t-x[level])){
		
		cout<<x[level]<<" ";
		printf(level+1,t-x[level]);
		
	}
	
	
	
	//take
	
}





void solve(){
	
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>x[i];
	}
	
	
	cin>>target;
	
	for(int i=0;i<n;i++){
		for(int j=0;j<=target;j++){
			
			done[i][j]=false;
		}
	}
	
	//cout<<rec(0,target)<<nl;
	
	if(rec(0,target)){
		
		printf(0,target);
	}else{
		cout<<"no solutin"<<nl;
	}
	
	
	
	
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	// int _t; cin>>_t;while(_t--)
		solve();
	
	
	//cerr<<"Time elapsed: "<< 1.0*clock()/ CLOCKS_PER_SEC << "s.\n\n";
	
	
	
	
}