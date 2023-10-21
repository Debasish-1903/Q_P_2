
/*Description

You have given an array A of N elements. An Inversion Count of the array is defined as the number of pairs (i, j) such that Ai > Aj and i < j.
Find the Inversion Count in A.


Input Format

The first line of input contains one integer T (1 ≤ T ≤ 105) — the number of test cases. Then T test cases follow.
The first line of each test case contains N (2 ≤ N ≤ 105), the number of elements in an array A.
The second line contains N space-separated integers A1, A2, …, AN, (0 ≤ Ai ≤ 109)
It is guaranteed that the sum of N over all test cases does not exceed 5 x 105.


Output Format

For each test case, print the answer on a new line denoting the Inversion Count.


Sample Input 1

3

4

8 4 2 1

3

3 1 2

6

1 2 3 4 5 5


Sample Output 1

6

2

0


Note

Explanation 1:
Inversion Pairs are (8, 4), (8, 2), (8, 1), (4, 2), (4, 1), (2, 1).

Explanation 2:
Inversion Pairs are (3, 1), (3, 2).

Explanation 3:
There are no Inversion Pairs. And hence, 0 Inversion Count.*/





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

        cout << solve(A, 0, n - 1) << "\n";

    }

    return 0;

}