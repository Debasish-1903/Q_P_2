//Kth Permutation - easy version

/*
Time-Limit: 1 sec Score: 100.00/100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

For the given n, consider the array A = {1, 2, …, n}. There exist n! unique permutations of the array. When we list all these n! permutations in lexicographically order, your task is to find kth permutation in that list.


Input Format

The first line contains two space-separated integers n and k.


Output Format

Print n space-separated integers, denoting the kth permutation.


Constraints

1 ≤ n ≤ 9
1 ≤ k ≤ n!


Sample Input 1

3 4

Sample Output 1

2 3 1

Sample Input 2

4 9

Sample Output 2

2 3 1 4

Note

Explanation 1: All 9 permutations in lexicographic order are

1 2 3
1 3 2
2 1 3
2 3 1
3 1 2
3 2 1
The 4th one is {2, 3, 1}. */

#include <bits/stdc++.h>
using namespace std;
#define IOS                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

void func(int k, vector<int> &arr)
{
    int n = (int)arr.size();
    k--;
    vector<int> ans;
    int fact = 1;
    for (int i = 1; i < n; i++)
    {
        fact = i * fact;
    }
    while (1)
    {
        ans.push_back(arr[k / fact]);
        arr.erase(arr.begin() + k / fact);
        if ((int)arr.size() == 0)
            break;
        k %= fact;
        fact /= (int)arr.size();
    }
    for (auto i : ans)
    {
        cout << i << " ";
    }
    cout << "\n";
}

void solve()
{
    int n, k;
    cin >> n >> k;
    if (n <= 13)
    {
        vector<int> arr;
        for (int i = 1; i <= n; i++)
        {
            arr.push_back(i);
        }
        func(k, arr);
    }
    else
    {
        vector<int> arr;
        for (int i = 1; i < n - 12; i++)
        {
            cout << i << " ";
        }
        for (int i = n - 12; i <= n; i++)
        {
            arr.push_back(i);
        }
        func(k, arr);
    }
}

signed main()
{
    IOS;
    solve();
    return 0;
}


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

ll n,k;
vector<ll>arr(100100);
void solve(){

cin>>n>>k;

arr.resize(n);


for(ll i=0;i<n;i++){
    
    arr[i]=i+1;
    
}

while(k>1){
    
    next_permutation(arr.begin(),arr.end());
    k--;
}

for(auto it:arr){
    
    cout<<it<<" ";
}

cout<<nl;
	
	
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	

		solve();
	
	
	//cerr<<"Time elapsed: "<< 1.0*clock()/ CLOCKS_PER_SEC << "s.\n\n";
	

	
	
	
}