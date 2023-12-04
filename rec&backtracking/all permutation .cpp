/* All Permutations

Time-Limit: 1 sec Score: 100.00/100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Description

Given an array of numbers, that might contain duplicates, print all possible unique permutations in lexicographically increasing order.


Input Format

The first line of input contains n - the size of the array.
The second line contains n space-separated integers denoting the elements of the array - a1, a2, …, an.


Output Format

Print all permutations in lexicographically increasing order. See the sample output for more clarity.


Constraints

1 ≤ n ≤ 8
0 ≤ ai ≤ 109


Sample Input 1

3
1 1 1

Sample Output 1

1 1 1

Sample Input 2

3
1 2 1

Sample Output 2

1 1 2
1 2 1
2 1 1

Sample Input 3

3
2 1 3

Sample Output 3

1 2 3
1 3 2
2 1 3
2 3 1
3 1 2
3 2 1 */


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
// vector<ll>vec(10000);

vector<ll>current_perm;
multiset<ll>available;

bool is_valid(ll x){
    
 for(auto it :current_perm){
     
     if(x==it)return 0;
 }
    
   return 1; 
    
}


void rec(ll level){
    // base case
    
    
    if(level==n){
        
        for(auto it:current_perm){
            
            cout<<it<<" ";
        }
        cout<<nl;
        return;
    }
    
    
    //choice
    
    set<ll>st(available.begin(),available.end());
    
    for(auto num:st){
        
        current_perm.push_back(num);
        available.erase(available.find(num));
        rec(level+1);
        current_perm.pop_back();
       available.insert(num);
        
        
    }
    
    
    
}



void solve(){

cin>>n;

ll x;
for(ll i=0;i<n;i++){
    
    cin>>x;
    available.insert(x);
}



rec(0);
	
	
	
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	

		solve();
	
	
	//cerr<<"Time elapsed: "<< 1.0*clock()/ CLOCKS_PER_SEC << "s.\n\n";
	
	
	
	
}