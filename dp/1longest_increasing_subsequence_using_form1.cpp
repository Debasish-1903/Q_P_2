#include<bits/stdc++.h> // using form 1;   xxxxxxxx WRONG XXXXXXX NEED TO CHECK LETTER
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

int arr[1010];
ll dp[1010][100100];
bool done[1010][100100];


int rec(int level,int last_taken){ // longest subsequence upto level from [level,------n-1]; // take or don't take 
	
	
	// pruning 
	
	
	if(level>n)return 0;
	
	// base case
	// if(level==n){
	// 	return 1;
	// }
	
	// cache check
	if(done[level][last_taken]!=0)return dp[level][last_taken];
	// compute 
	
	//int ans=rec(level+1,last_taken); // dont take
	
int ans,ans1=1;
ans=rec(level+1,last_taken);
 
	if(arr[level]>arr[last_taken]){
		
		ans1=1+rec(level+1,level); // take 
	}
	  
	 ans=max(ans,ans1);
	
	// save and return
	return dp[level][last_taken]=ans;
	
	

}
 


void solve(){
	
	cin>>n;
	for(int i=0;i<n;i++){
		
		cin>>arr[i];
		
	}
	
	memset(done,0,sizeof(done));
	
	int best=1;
	for(int i=0;i<n;i++){
		
		best=max(best,rec(i,i));
	}
	
	cout<<best<<nl;
	
	
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	 int _t; cin>>_t;while(_t--)
		solve();
	
	
	//cerr<<"Time elapsed: "<< 1.0*clock()/ CLOCKS_PER_SEC << "s.\n\n";
	
	
	
	
}