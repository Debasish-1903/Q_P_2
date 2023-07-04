/*Maximum Area AZ101

Time-Limit: 3 sec Score: 1.00/100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Description

You have a rectangular sheet of paper with dimensions H x W. You make N horizontal and verticals cuts in the sheet. Find the area of the maximum fragment after each cut.

It is guaranteed that there won't be any two identical cuts. Also, The cut that you make in the previous queries persists on the paper for the next queries. 


Input Format

The first line of the input contains one integer T - the number of test cases. Then T test cases follow.

The first line of each test case contains three space-separated integers H W N - the dimensions of the sheet and the number of cuts.

Each of the next N lines is of the form H Y or V X. For H Y, you make a horizontal cut at distance Y from the lower edge of the sheet and for V X, you make a vertical cut at a distance X from the left edges of the sheet.


Output Format

For each test case, print the area of the maximum fragment after each cut.


Constraints

1≤ T ≤ 105

1≤ N ≤ 105

2≤ W, H ≤ 109

1≤ Y ≤ H - 1

1≤ X ≤ W - 1

It is guaranteed that the sum of N over all test cases does not exceed 106.


Sample Input 1

2
5 3 3
H 1
V 1
V 2
3 5 4
H 2
V 2
H 1
V 1

Sample Output 1

12
8
4
10
6
3
3 */


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


 
void solve(){
	
ll h,w,n;
cin>>h>>w>>n;

set<ll,greater<ll>>hori_cut;
set<ll,greater<ll>>verti_cut;
multiset<ll,greater<ll>>h_seg,w_seg;

hori_cut.insert(0);
hori_cut.insert(h);
verti_cut.insert(0);
verti_cut.insert(w);
h_seg.insert(h);
w_seg.insert(w);

while(n--){
 char c;
 ll x;
 cin>>c>>x;
 
 if(c=='H'){
     hori_cut.insert(x);
     auto it =hori_cut.lower_bound(x);
    
     auto left=it;
     auto right=it;
     left--;
     right++;
     h_seg.erase(h_seg.find(*left-*right));
     h_seg.insert(*left-x);
     h_seg.insert(x-*right);
     
     
 }else{
     
     verti_cut.insert(x);
     auto it=verti_cut.lower_bound(x);
     auto left=it;
     auto right=it;
     left--;
     right++;
     
     w_seg.erase(w_seg.find(*left-*right));
     w_seg.insert(*left-x);
     w_seg.insert(x-*right);
     
 }
    
    auto ans=(*h_seg.begin())*(*w_seg.begin());
    
    cout<<ans<<nl;
    
    
    
}
	
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	 int _t; cin>>_t;while(_t--)
		solve();
	
	
	//cerr<<"Time elapsed: "<< 1.0*clock()/ CLOCKS_PER_SEC << "s.\n\n";
	
	
	
	
}
