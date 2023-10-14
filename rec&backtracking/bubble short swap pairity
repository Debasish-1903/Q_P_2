/*Bubble Sort Swap Parity

Time-Limit: 2 sec Score: 1.00/100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

You all know the Bubble Sort! The classical sorting algorithm.

In this problem, you have to find the parity of the number of swaps that will perform in the standard bubble sort algorithm on the given input array.

For more details about Bubble Sort refer this: https://en.wikipedia.org/wiki/Bubble_sort


Input Format

The first line of input contains one integer T (1 ≤ T ≤ 105) — the number of test cases. Then T test cases follow.
The first line of each test case contains N (2 ≤ N ≤ 105), the number of elements in an array A.
The second line contains N space-separated integers A1, A2, ..., AN, (0 ≤ Ai ≤ 109).
It is guaranteed that the sum of N does not exceed 5 x 105.


Output Format

For each test case, print the answer on a new line denoting the parity of number swaps in the Bubble Sort.


Sample Input 1

3

4

8 4 2 1

3

2 1 3

6

1 2 3 4 5 5


Sample Output 1

0

1

0


Note

Explanation 1:

First Iteration	4 2 1 8	3 swaps
Second Iteration	 2 1 4 8 	2 swaps
Third Iteration 	1 2 4 8 	1 swap
Total Swaps: 6, so the parity is 0.

 

Explanation 2:

First Iteration	1 2 3	1 swap
Total Swaps: 1, so the parity is 1.

 

Explanation 3:

The given array is already sorted, so 0 swaps and hence, 0 parity. */


#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define LD long double

const int N = 100010;

int inf = 1e9;
int mod = 1e9 + 7;

long long solve(vector<int> &A, int l, int r) {
    if(l > r) return 0;
    if(l == r) return 0;
    if(r - l == 1) {
        if(A[r] < A[l]) {
            swap(A[r], A[l]);
            return 1;
        }
        return 0;
    }

    int mid = (l + r) / 2;

    long long ans = solve(A, l, mid) + solve(A, mid + 1, r);

    int ptr = mid + 1;
    for(int i = l; i <= mid; i++) {
        while(ptr <= r && A[ptr] < A[i])
            ptr++;
        ans += 1LL * (ptr - mid - 1);
    }
    vector<int> temp;
    for(int i = l; i <= r; i++)
        temp.push_back(A[i]);
    sort(temp.begin(), temp.end());
    for(int i = l; i <= r; i++)
        A[i] = temp[i - l];
    return ans;
}

signed main()
{
    //freopen("IN", "r", stdin);
    //freopen("OUT", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int T; cin >> T;
    while(T--) {
        int n; cin >> n;
        vector<int> A(n);
        for(int i = 0; i < n; i++) cin >> A[i];
        cout << solve(A, 0, n - 1) % 2 << "\n";
    }
    return 0;
}