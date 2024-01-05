/*Scrambled String

Time-Limit: 1 sec Score: 0.00/100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

We can scramble a string 
s to get a string t
 using the following algorithm:

If the length of the string is 
1
, stop.

If the length of the string is 
>
1
, do the following:
2.1 Split the string into two non-empty substrings at a random index, i.e., if the string is 
s
, divide it to 
x
 and 
y
 where 
s
=
x
+
y
.
2.2 Randomly decide to swap the two substrings or to keep them in the same order. i.e., after this step, 
s
 may become 
s
=
x
+
y
 or 
s
=
y
+
x
.

Apply step 
1
 recursively on each of the two substrings 
x
 and 
y
.


Input Format

The first-line contains 
T
 - the number of test cases.
Each test case contains two strings 
s
1
 and 
s
2
 of the same length.


Output Format

For each test case, output "Yes" if 
s
2
 is a scrambled string of 
s
1
, otherwise, output "No", in a newline.


Constraints

1
≤
T
≤
100

s
1.
l
e
n
g
t
h
==
s
2.
l
e
n
g
t
h

1
<=
s
1.
l
e
n
g
t
h
<=
40

s
1
 and 
s
2
 consist of lower-case English letters.


Sample Input 1

3
abcde caebd
a a
great rgeat

Sample Output 1

No
Yes
Yes

Note

For test case 
3
,
One possible scenario applied on s1 is:

"great" --> "gr/eat" // divide at random index.
"gr/eat" --> "gr/eat" // random decision is not to swap the two substrings and keep them in order.
"gr/eat" --> "g/r / e/at" // apply the same algorithm recursively on both substrings. divide at ranom index each of them.
"g/r / e/at" --> "r/g / e/at" // random decision was to swap the first substring and to keep the second substring in the same order.
"r/g / e/at" --> "r/g / e/ a/t" // again apply the algorithm recursively, divide "at" to "a/t".
"r/g / e/ a/t" --> "r/g / e/ a/t" // random decision is to keep both substrings in the same order.
The algorithm stops now and the result string is "rgeat" which is 
s
2
.
As there is one possible scenario that led s1 to be scrambled to 
s
2
, we ouput "Yes".   */



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


string s1,s2;


 /*ll add(ll a,ll b){
	
	ll ans=(a+b)%mod;
	if(ans<0) ans+=mod;
	
	return ans;
}

 ll sub(ll a,ll b){
	
	ll ans=(a-b)%mod;
	if(ans<0) ans+=mod;
	
	return ans;
}

ll mul(ll a,ll b){
	
	ll ans=(a*b)%mod;
	if(ans<0) ans+=mod;
	
	return ans;
}*/



ll rec(ll l,ll r){
	
	
	//pruning
	
	
	// base case
	
	
	if(s1.length()==1){
		
		
	}
	
	
	
	// cache check 
	
	
	//  compute 
	
	
	
	// save and return 
	
	
	
	
	
	
	
	
	
	
	
	
	
}




void solve(){
	
	cin>>s1>>s2;
	
	
	
	
	
	
	
	
	
	
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	// int _t; cin>>_t;while(_t--)
		solve();
	
	
	//cerr<<"Time elapsed: "<< 1.0*clock()/ CLOCKS_PER_SEC << "s.\n\n";
	
	
	
	
}





