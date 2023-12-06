#include <bits/stdc++.h>
using namespace std;

#define ll int64_t

int dp[105][100100];

int  rec(int level,vector<int>&arr,int left){
    
      int n=arr.size();
    
    //pruning
    
    
    if(left<0)return 0;
    
    //base case
    
    if(level==n){
        
        if(left==0)return 1;
        else return 0;
    }
    
    //cache check
    
    if(dp[level][left]!=-1)return dp[level][left];
       
    // compute /transition
    
     int ans=rec(level+1,arr,left)||rec(level+1,arr,left-arr[level]);

    
    // save and return
     dp[level][left]=ans;
    
    return ans;
}


vector<int>printf(int level,vector<int>&arr,int left){
    
    vector<int>final_arr;
    
    int x=arr.size();
    //base case
    if(level==x){
        
        return final_arr;
        
    }
    
    if(rec(level+1,arr,left)){
        printf(level+1,arr,left);
    }else if(rec(level+1,arr,left-arr[level])){
        
        final_arr.push_back(level);
        printf(level+1,arr,left-arr[level]);
    }
    
}



vector<vector<int>> subset_queries(vector<int> &arr, vector<int> &queries) {
    // Write code here.
    
       memset(dp,-1,sizeof(dp));
       
       vector<vector<int>>v;
       
       
    for(int i=0;i<queries.size();i++){
         if(rec(0,arr,queries[i])){
           
            v.push_back(printf(0,arr,queries[i]));
            
             }else{
               
                v.push_back({-1});
             }

    }
    
    
    
    
    return v;
}

void solve() {
    int N, Q;
    cin >> N >> Q;
    vector<int> arr(N);
    for (int i = 0; i < N; i++)cin >> arr[i];
    vector<int> queries(Q);
    for (int i = 0; i < Q; i++)cin >> queries[i];
    auto ans = subset_queries(arr, queries);

    // checker.
    if (ans.size() != Q) {
        cout << 101 << endl;
        return;
    }
    for (int i = 0; i < Q; i++) {
        auto x = ans[i];
        if (x.size() == 0) {
            cout << 101 << endl;
            continue;
        }
        if (x.size() == 1 && x[0] == -1) {
            cout << -1 << endl;
            continue;
        }
        ll sum = 0, p = -10;
        for (auto y : x) {
            if (y < 0 || y >= N || p >= y ) { // valid 0-indexed.
                sum = -1111;
                break;
            }
            p = y;
            sum += arr[y];
        }
        if (sum == queries[i]) {
            cout << 1 << endl;
        }
        else cout << 101 << endl;
    }
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
    // cin >> t;
    while (t--) {
        // cout << "Case #" << i << ": ";
        solve();
        // i++;
    }
    return 0;
}