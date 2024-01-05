

// longest common subsequence 
/*
a=AGGTAB
b=GXTXATB

lcs=GTAB == length of longest common subsequence(lcs)=4;

*/



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



string a,b;
int n,m;


int dp[1010][1010];
int rec(int i,int j){
	// length of longest common subsequence from [i.....n-1]and [j......m-1]
	
	
	//pruning 
	
	
	
	//base case 
	if(i>=n||j>=m){
		
		return 0;
	}
	
	// cache check
	
	if(dp[i][j]!=-1)return dp[i][j];
	
	// compute /transistion
	
	int ans=1;
	ans=max(ans,rec(i,j+1));
	ans=max(ans,rec(i+1,j));
	
	if(a[i]==b[j]){
		
		ans=max(ans,1+rec(i+1,j+1));
	}
	
	
	// save and return 
	
	return dp[i][j]=ans;
	
	
	
	

}

// void print_lcs() {
//     string lcs = "";
//     int i = 0, j = 0;
//     while(i < n && j < m) {
//         if(a[i] == b[j]) {
//             lcs += a[i];
//             i++;
//             j++;
//         } else if(dp[i+1][j] > dp[i][j+1]) { // think string a and b (index ) wise not dp index wise 
//             i++;
//         } else {
//             j++;
//         }
//     }
//     cout << "Longest Common Subsequence: " << lcs << "\n";
// }
 
 
 
 
 void print_lcs(){
 	
 	int i,j=0;
 	
 	string lcs="";
 	while(i<n&&j<m){
 		
 		
 		
 		if(a[i]==b[j]){
 			
 			lcs+=a[i];
 			
 			i++;
 			j++;
 		}else if(dp[i,j+1]>dp[i+1,j]){  //think string a and b (index ) wise not dp index wise 
 			j++;
 		}else {
 			i++;
 		}
 		
 		
 	
 
 
 
 }
 	
 	
 		cout<<lcs<<nl;
 	
 }
 
 
 
 void print_dp(){
 	
 	for(int i=0;i<n;i++){
 		for(int j=0;j<m;j++){
 			
 			cout<<dp[i][j]<<" ";
 			
 		}
 		
 		cout<<nl;
 	}
 	
 	
 	
 }

void solve(){
	
	cin>>n>>m;
	
	cin>>a>>b;
	
	
	memset(dp,-1,sizeof(dp));
	
	cout<<rec(0,0)<<nl;
	
	 print_lcs();
	 print_dp();
	
	
	
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	// int _t; cin>>_t;while(_t--)
		solve();
	
	
	//cerr<<"Time elapsed: "<< 1.0*clock()/ CLOCKS_PER_SEC << "s.\n\n";
	
	
	
	
}