/*Word Break

Time-Limit: 2 sec Score: 0.00/100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

Given a string 
s
 and a dictionary of strings 
w
o
r
d
s
, output "Yes" if 
s
 can be segmented into a space-separated sequence of one or more dictionary 
w
o
r
d
s
, else output "No".

Note that the same word in the dictionary may be reused multiple times in the segmentation.


Input Format

First-line contains 
T
 - the number of test cases.
The first line of each test case contains 
n
 - the size of the dictionary 
w
o
r
d
s
.
The second line of each test case contains string 
s
.
The next 
n
 lines of each test case contain 
n
 words of the dictionary 
w
o
r
d
s
.


Output Format

For each test case, output "Yes" if 
s
 can be segmented into a space-separated sequence of one or more dictionary 
w
o
r
d
s
, else output "No".


Constraints

1
≤
T
≤
1000

1
≤
n
≤
1000

1
≤
|
s
|
≤
300

1
≤
w
o
r
d
s
[
i
]
.
l
e
n
g
t
h
(
)
≤
20

Sum of 
|
s
|
 over all test cases is 
≤
 
3
×
10
4
.


Sample Input 1

3
6
ilikealgozenith
algozenith
love
like
i
you
algo
2
applepenapple
apple
pen
3
mississippi
miss
ippi
sis

Sample Output 1

Yes
Yes
No

Note

for test 1, ilikealgozenith -> i + like + algozenith .



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


ll n;
string s;
map<string,ll>dict;

ll dp[310];



bool rec(ll level,string x){
	
	// pruning 
	
	// basecase
	
	if(level==x.size())return 1;
	
	
	// cache check 
	
	if(dp[level]!=-1)return dp[level];
	
	// compute 
	
	bool ans=false;
	
	for(ll end=level;end<s.size();end++){
		
		string sub=x.substr(level,end-level+1);
		
		if(dict.find(sub)!=dict.end()){
			
			ans|=rec(end+1, x);
		}
		
	}
	
	// save and return 
	
	return dp[level]=ans;
	
	
	}



void solve(){
	
	cin>>n;
	cin>>s;
	
	dict.clear();
	for(ll i=0;i<n;i++){
		
		string word;
		cin>>word;
		dict[word]++;
		
		
	}
	
	memset(dp,-1,sizeof(dp));
	if(rec(0,s))cout<<"YES"<<nl;
	else cout<<"NO"<<nl;

	
	
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	 int _t; cin>>_t;while(_t--)
		solve();
	
	
	//cerr<<"Time elapsed: "<< 1.0*clock()/ CLOCKS_PER_SEC << "s.\n\n";
	
	
	
	
}