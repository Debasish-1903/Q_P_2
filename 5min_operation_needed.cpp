/*Minimum Operation Conversion

Time-Limit: 5 sec Score: 75.00/100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

You are given a number X, you can perform two operations:

Double: Multiply the number on the display by 2, or;
Decrement: Subtract 1 from the number on the display.
Return the minimum number of operations needed to convert number X to Y.


Input Format

The first line contains an integer T (number of test cases), 1 ≤ T ≤ 10^6.

The next T lines contain 2 space-separated integers X, Y where 1 ≤ X,Y ≤ 10^18.


Output Format

For each test case print the minimum number of operations required in a new line.


Constraints

1 ≤ T ≤ 10^6.
1 ≤ X,Y ≤ 10^18

Sample Input 1

3
10 15
21 14
10 22

Sample Output 1

4
7
7

Note

TEST CASE 1: X=10 Y=15

MOVES : 10 → 9 → 8 → 16 → 15     #Moves = 4
 

TEST CASE 2: X=21 Y =14

MOVES : 21 → 20 → 19 → 18 → 17 → 16 → 15 → 14    # moves = 7
 

TEST CASE 3: X=10 Y=22

MOVES : 10 → 9 → 8 → 7 → 6 → 12 → 11 → 22 # moves = 7*/


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
    
    ll x,y;
    cin>>x>>y;
    
    ll steps_cnt=0;
    
    // if(x>y){
        
    //  //   steps_cnt=x-y;
    //     cout<<x-y<<nl;
    //     return;
    // }
    
    while(y){
        
        
        if(y<x){
        
       steps_cnt+=x-y;
       // cout<<x-y<<nl;
       y=x;
        
    }
        
        
         if(y==x){
             
              
             // return;
             break;
         }
        
       if(y%2==0){
           steps_cnt++;
           y=y/2;
           
       } else if(y%2==1){
           steps_cnt++;
           y=y+1;
           
           
       }
       
      
        
        
    }
    
   cout<<steps_cnt<<nl;;
    
    
}
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	 int _t; cin>>_t;while(_t--)
		solve();
	
	
	//cerr<<"Time elapsed: "<< 1.0*clock()/ CLOCKS_PER_SEC << "s.\n\n";
	
	
	
	
}