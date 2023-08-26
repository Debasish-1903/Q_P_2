/*Selling cookies

Time-Limit: 1 sec Score: 1.00/100
Difficulty : ***
 Memory: 256 MB Accepted Submissions: 100
Description

A shop makes n types of cookies. Number of cookies of type i is Ci

The shop only sells cookies as a pair. Moreover the two cookies in a pair must be of different types.

Your job is to sell as many pairs as possible and find the minimum number of cookies that remain at the end.

 

 


Input Format

First line of input contains T, number of test cases.

First line of each test case contains n.

The next line contains n integers, Ci for i from 1 to n.

 


Output Format

For each test case output one integer: Remaining cookies.


Constraints

T ≤ 10

1 ≤ n ≤ 105

1 ≤ Ci ≤ 109


Sample Input 1

1
3
2 1 3

Sample Output 1

0

Sample Input 2

1
3
3 4 5

Sample Output 2

0

Note

Explanation 1:
We can make the following 3 pairs of cookie types : (1,3), (1,3), (2,3) resulting in 0 remaining cookies.

Explanation 2:
Let types of cookies be 1, 2, 3 with count 3, 4, 5 respectively. Pairs: (1, 3), (1, 2), (1, 3), (2, 3), (2, 3), (2, 3).
0 cookies left behind.*/

/*The highest cookie stack is removed first. Is it always possible to remove all the cookies from the highest cookie stack? No. It is possible only when the number of cookies in the highest stack is less than or equal to the sum of all other cookies present. Once the highest stack is reduced to zero, the remaining cookies can be paired in between themselves such that there will be either 0 or 1 cookie left.

But if the number of cookies in the highest stack is more than all other cookies present, then all the other cookies will pair with cookies from the highest stack. Now remaining cookies in the highest stack cannot be paired anymore, so its answer will be the remaining number of cookies in the highest stack.

EXAMPLE RUN : 

1

2 4 6 9

The highest number of cookies is 9 and the sum of all other cookies = 2+4+6=12

So the highest stack can be reduced to zero. So from these 12 cookies, 9 will pair with 9 cookies of the highest stack. The remaining 3 cookies can be of any combination of cookies of the 3 smaller stacks. They will pair with themselves optimally to leave only 1 cookie unpaired. So the answer is 1.


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
//#define s second
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


vector<ll>arr;
void solve(){
    ll n;
    cin>>n;
    arr.resize(n);
    
    ll ans=0;
    for(ll i=0;i<n;i++){
        
        ll x;
        cin>>x;
        arr[i]=x;
        ans+=arr[i];
    }
    
   
   sort(arr.begin(),arr.end());
   
   ans-=arr[n-1];
   
   
   if(arr[n-1]>=ans){
       ans=arr[n-1]-ans;
       
   }else{
       
       
       ans=(ans-arr[n-1])%2;
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
