
/*Description

You are given a non-empty string S consisting of lower case characters. You can change at most K letters to maximise the cost. If in the final string, X immediately precedes Y, you get an increase in cost by C. You have to determine the maximum cost possible.


Input Format

The first line of the input contains one integer T - the number of test cases. Then T test cases follow.

The first line of each test case contains string S and an integer K - the number of characters you can change at most.

The second line of each test case contains M - the number of cost values.

The following M lines contain two space-separated integers along with a character X Y C - you get an increase in cost by C if X immediately precedes Y.


Output Format

For each test case, print a single integer denoting the maximum cost possible on a separate line.


Constraints

1 ≤ T ≤ 100

1 ≤ |S| ≤ 100 where |S| denotes the length of the string S

0 ≤ K ≤ 100

0 ≤ M ≤ 676

‘a’ ≤ X, Y ≤ ‘z’

-1000  ≤ C ≤ 1000

It is guaranteed that no pair X Y is mentioned twice in the input data.


Sample Input 1

3
akcbd 2
3
a d 55
b z 100
b c 50
srtlmx 2
2
e a -167
c v -932
abcd 2
4
x y 10
y z 100
a x -150
z d -150

Sample Output 1

155
0
100

Note

For the first test case, change string to adcbz, cost becomes 100+55 = 155

For the second test case, changing any character will result in negative cost, we don’t change the original string/we can change the string so that e,a and c,v are not adjacent.

For the third test case, change string to yzcd, cost becomes 100.*/



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

string str;
ll k;
ll n, m;

ll cost[28][28];
 ll dp[110][26][110];
  ll visited[110][26][110];
 
 
 // form 1:
 
 ll rec(ll level,ll prev_char,ll left){    // mamximum cost using left no of char changes from level to n-1 
     
     
     if(left<0)return -1e18;
     
     
     if(level==n) return 0;
     
     
     
     // cache check 
     
     if(visited[level][prev_char][left]!=-1){
         
         
         return dp[level][prev_char][left];
     }
     
     
     // transition 
     
     ll ans=-1e18;
     for(ll i=0;i<26;i++){   // it is just checking the 26 possible character for the current postion i=character 
         
         
         if(str[level]-'a'==i){
             
             ans=max(ans,rec(level+1,i,left)+cost[prev_char][i]);
             
         }else{
             
              ans=max(ans,rec(level+1,i,left-1)+cost[prev_char][i]);
             
         }
         
         
         
         
     }
     
     
     // save and return 
     
     
     visited[level][prev_char][left]=1;
     
     return dp[level][prev_char][left]=ans;
     
     
 }
 
 
 
 
void solve(){
    
    cin>>str>>k;
    
    n=str.length();
    
    cin>>m;
    
    
    memset(cost,0,sizeof(cost));
     memset(visited,-1,sizeof(visited));
      
      
      for(ll i=0;i<102;i++){
          
          
          for(ll j=0;j<26;j++){
              
              for(ll l=0;l<=102;l++){
                    dp[i][j][l]=-1e18;
                  
              }
          }
      }
    
    for(ll i=0;i<m;i++){
        
        char c1,c2;
        ll c;
        
        
        cin>>c1>>c2>>c;
        
        cost[c1-'a'][c2-'a']=c;
        
    }
    
    
    ll maxi=-1e18;
    ll x;
    
    for(ll i=0;i<26;i++){
        
        
        
       if(str[0]-'a'==i){
             
            x= rec(1,i,k);
             
         }else{
             
              x=rec(1,i,k-1);
             
         }
         
         
         if(x>maxi){
             maxi=x;
         }
    
    }
    
    
    cout<<maxi<<nl;
    
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	 int _t; cin>>_t;while(_t--)
		solve();
	
	
	//cerr<<"Time elapsed: "<< 1.0*clock()/ CLOCKS_PER_SEC << "s.\n\n";
	
	
	
	
}


