/*Recurring Fractions

Time-Limit: 1 sec Score: 75.00/100
Difficulty : **
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

Given two integers representing the numerator and denominator of a fraction, print the fraction in string format.
If the fractional part is repeating, enclose the repeating part in parentheses.
If multiple answers are possible, print the one which has the smallest length.


Input Format

The first line contains T (1 ≤ T ≤ 100000), the number of test cases.
Each of the next T lines contains two space-separated integers representing numerator and denominator respectively (0 ≤ |numerator| ≤ 100 and 1 ≤ |denominator| ≤ 100).
It is guaranteed that the denominator is always a non-zero integer.


Output Format

For each test case, print the fraction in string format.


Sample Input 1

4

1 2

2 1

2 3

-3 7


Sample Output 1

0.5

2

0.(6)

-0.(428571)


Note

Explanation 1:
1 / 2 = 0.5

Explanation 2:
2 / 1 = 2

Explanation 3:
2 / 3 = 0.(6). Note that 0.(66) is also the correct representation in decimal format, but it has a greater length than 0.(6).*/


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
    
ll num,den;
cin>>num>>den;


string ans;
if(num==0) {
    
    ans="0";
     cout<<ans<<nl;
    return;
    
}

if(num<0^den<0){
    
    ans+="-";
    
}

ll n=abs(num);
ll d=abs(den);

ans+=to_string(n/d);
n%=d;
if(n==0){
    cout<<ans<<nl;
    return;
    
}

ans+=".";

map<ll,ll>seen;
while(n!=0){
    if(seen.find(n)!=seen.end()){
        ans.insert(seen[n],"(");
        
        ans+=")";
        
        break;
        
    }
    
    
    
   seen[n]=ans.size(); 
    n*=10;
    ans+=to_string(n/d);
    n%=d;
    
    
    
}
cout<<ans<<nl;
    
	
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	int _t; cin>>_t;while(_t--)
		solve();
	
	
	//cerr<<"Time elapsed: "<< 1.0*clock()/ CLOCKS_PER_SEC << "s.\n\n";
	
	
	
	
}