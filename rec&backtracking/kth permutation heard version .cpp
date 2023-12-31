/*Kth Permutation - hard version

Time-Limit: 1 sec Score: 75.00/100
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

1 ≤ n ≤ 105
1 ≤ k ≤ min(n!, 109)


Sample Input 1

3 4

Sample Output 1

2 3 1

Sample Input 2

10 3

Sample Output 2

1 2 3 4 5 6 7 9 8 10 */


/*Observe that 13! > 109.


At max, the last 13 numbers are only important. Remaining n - 13 numbers will remain the same in the answer permutation.


Let a = {1, 2, …, n}. See 13! > 109. 

At max, the last 13 numbers are important when n > 13, because only they're permutating in the answer array, and remaining n - 13 numbers will remain same. If n ≤ 13, then the whole array can get permutated.

Now do iteratively. Find out the farthest index from the last, that has to be changed. Suppose index i needs to change, then we've to choose ceil(k / (n - i)!) th smallest number from a[i] to a[n - 1].

How the expression in bold is derived? You can observe this when you try to simulate the process on your pen and paper. Just think about it.

And go on doing the same for other indices from i + 1 to n - 1.

See editorial code for more clear understanding.  */




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