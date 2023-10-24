
/*Target Subsets

Time-Limit: 3 sec Score: 1.00/100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

You have given an array of length N, and a number X. Find the number of subsets with the sum of elements less than equal to X.

Note:

The sum of elements in an empty subset is 0.
The set may contain duplicates elements.

Input Format

The first line of input contains T - the number of test cases.
The first line of each test case contains two space-separated numbers N and X.
The second line of each test case contains N space-separated integers A1, A2, ..., AN.  


Output Format

Print the number of subsets with a sum less than equal to X in a new line for each test case.


Constraints

1 ≤ T ≤ 5
1 ≤ N ≤ 35
0 ≤ Ai ≤ 104
0 ≤ X ≤ 106


Sample Input 1

2
2 1
1 2
3 8
2 2 6

Sample Output 1

2
7

Note

Explanation 1:
The subsets are {}, {1}, {2}, {1, 2}. The number of subsets with sum ≤ 1 is 2.

Explanation 2:
The subsets are {}, {2}, {2}, {6}, {2, 2}, {2, 6}, {2, 6}, {2, 2, 6} The number of subsets with sum ≤ 8 is 7.  */





#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll n,x;
vector<ll> arr;

vector<ll> generate(vector<ll>&vec){
    ll size = vec.size();
    vector<ll> res;

    for(int mask=0;mask < (1<<size);mask++){
        ll sum = 0;
        for(int i=0;i<size;i++){
            if((mask >> i) & 1){
                sum += vec[i];
            }
        }
        res.push_back(sum);
    }

    sort(res.begin(),res.end());
    return res;
}

void solve(){
    cin>>n>>x;

    arr.resize(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    vector<ll> subsets[2];

    for(int i=0;i<n;i++){
        subsets[i%2].push_back(arr[i]);
    }

    auto subset_1 = generate(subsets[0]);
    auto subset_2 = generate(subsets[1]);

    ll cnt = 0;

    for(auto it : subset_1){
        cnt += upper_bound(subset_2.begin(),subset_2.end(),x-it) - subset_2.begin();
    }

    cout<<cnt<<"\n";
    subsets[0].clear();
    subsets[1].clear();
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("Input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    #endif
    ll t;
    cin>>t;
    // memset(dp,-1,sizeof(dp));
    while(t--){
        solve();
    }
    return 0;
}