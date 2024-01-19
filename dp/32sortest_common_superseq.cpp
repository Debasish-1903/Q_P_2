/*Shortest Common Supersequence

Time-Limit: 2 sec Score: 100.00/100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

Given two strings 
str1 and str2
, return the shortest string that has both str1
 and str2
 as subsequences. If there are multiple valid strings, return any of them.

A string 
s is a subsequence of string t
 if deleting some number of characters from t
 (possibly 0) results in the string s
.


Input Format

Given function string ShortestCommonSupersequence( string &str1, string &str2) with string 
str1
and 
str2
 as input.


Output Format

Complete the given function string ShortestCommonSupersequence( string &str1, string &str2) and return the shortest common supersequence of the 
2
 input strings. If there are multiple valid strings, return any of them.


Constraints

1≤T≤100

1≤|str1|≤1000

1≤|str2|≤1000

Sample Input 1

4
algozenith a
zzzzz zzzz
abc caba
abc xyz

Sample Output 1

algozenith
zzzzz
cabac
xyzabc*/



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
 
 
 
 // iterative coding 


#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long int

ll n, m;
ll dp[1010][1010];
string str1, str2;

string ShortestCommonSupersequence(string &s1, string &s2) {
    n = s1.size();
    m = s2.size();
    str1 = s1;
    str2 = s2;

    // Initialize DP table
    for(ll i = 0; i<=n; i++) {
        for(ll j=0; j<=m; j++) {
            if(i == 0) dp[i][j] = j;
            else if(j == 0) dp[i][j] = i;
            else if(str1[i-1] == str2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
            else dp[i][j] = 1 + min(dp[i-1][j], dp[i][j-1]);
        }
    }

    // Construct the shortest common supersequence
    string ans;
    ll i = n, j = m;
    while(i > 0 && j > 0) {
        if(str1[i-1] == str2[j-1]) {
            ans += str1[i-1];
            i--;
            j--;
        } else if(dp[i-1][j] > dp[i][j-1]) {
            ans += str2[j-1];
            j--;
        } else {
            ans += str1[i-1];
            i--;
        }
    }

    while(i > 0) {
        ans += str1[i-1];
        i--;
    }

    while(j > 0) {
        ans += str2[j-1];
        j--;
    }

   reverse(ans.begin(), ans.end());
    
    for(auto it:ans){
        
        cout<<it;
    }
    return ans;
}





void checker() {
    string x, y;
    cin >> x >> y;
    auto s = ShortestCommonSupersequence(x, y);
    cout << s.size() << endl;
    bool f = 1;
    int i = 0, j = 0;
    while (i < x.size() && j < s.size()) {
        if (x[i] == s[j])i++, j++;
        else j++;
    }
    if (i != x.size())f = 0;
    i = 0, j = 0;
    while (i < y.size() && j < s.size()) {
        if (y[i] == s[j])i++, j++;
        else j++;
    }
    if (i != y.size())f = 0;
    cout << f << endl;
}
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);

#ifdef Mastermind_
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#endif
    int t = 1;
    // int i = 1;
    cin >> t;
    while (t--) {
        // cout << "Case #" << i << ": ";
        checker();
        // i++;
    }
    return 0;
}



