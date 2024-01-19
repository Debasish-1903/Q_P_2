/*Mountain Arrays

Time-Limit: 5 sec Score: 1.00/100
Difficulty : ****(minimal)
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

Vivek wrote down a sequence containing distinct positive integers. Shubham wanted to reorder the elements to get a "mountain sequence". A sequence a0, a1, ..., an-1 is called a mountain sequence if there exists an index j, where 0 < j < n-1, such that the sequence a0, a1, ..., aj is strictly increasing, and the sequence aj, aj+1, ..., an-1 is strictly decreasing. A sequence is strictly increasing if each element is strictly greater than the element before it, and a sequence is strictly decreasing if each element is strictly less than the element before it.

Shubham also wanted the resulting sequence to satisfy one additional rule. The absolute difference between each pair of adjacent elements must be less than or equal to K.

Find the number of valid sequence modulo 10^9+7.


Input Format

The first line contains an integer T - number of test cases. ( 1 ≤ T ≤ 50).

The first line of each test case contains two space-separated integers N, K, (1≤ N ≤ 1000, 1 ≤ K ≤ 1000000000).

The second line contains N- space-separated distinct integers (1 ≤ Ai ≤ 1000000000).


Output Format

For each test case print the number of valid sequence mod 10^9+7 in a newline.


Sample Input 1

2
4 6
10 4 1 5
9 44
96 29 21 90 46 77 31 63 79

Sample Output 1

4 
126  */


#include <bits/stdc++.h> 
using namespace std;
#define int long long

int mod = 1e9+7;
int n, k;
int a[1001];
int dp[1001][1001];
int rec(int l, int r, int index){
    
    //cout<<"l:"<<l<<" r:"<<r<<" indx:"<<index<<endl;
    if(index==n){
        if(l==0 or r==0) return 0;
        return 1LL;
    }
    if(~dp[l][r]) return dp[l][r];
    int ans = 0;
    if(a[index]+k>=a[l]) ans = rec(index, r, index+1);
   // cout<<endl<<"left:"<<l<<" r:"<<r<<" indx:"<<index<<endl;
    
    if(a[index]+k>=a[r]) (ans += rec(l, index, index+1))%=mod;
    return dp[l][r] = ans;
}

void solve(){
    cin>>n>>k; for(int i = 0; i < n; i++) cin>>a[i];
    sort(a, a+n); reverse(a, a+n);
    memset(dp, -1, sizeof(dp));
    cout << rec(0, 0, 1) << '\n';
}   

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //solve();
    int t; cin >> t; for(int i = 0; i < t; i++) solve();
    return 0;
}