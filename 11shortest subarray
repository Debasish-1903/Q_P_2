


/*Shortest Subarray

Time-Limit: 1 sec Score: 1.00/100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

Given an array of N integers, find the length of the smallest sub-array that contains all the distinct elements of the array.


Input Format

The first line contains T, the number of test cases (1<=T<=10).

The first line contains an integer N, 1<=N<=10^5.

Next line contains N space-separated integers (0<=Ai<=1e5).

 


Output Format

For each test case print length of the smallest sub-array that contains all the distinct elements of array in a newline.


Sample Input 1

6
5
1 1 3 2 3
5
1 2 3 4 5
6
1 2 2 3 3 4
6
1 2 1 3 2 4
5
1 1 1 1 1
1
1

Sample Output 1

3
5
6
4
1
1
 


Note

For first test case → smallest subarray -> (1,3,2).

For second test case → smallest subarray -> (1,2,3,4,5).

For third test case → smallest subarray -> (1 2 2 3 3 4). */


/*
First, find the number of distinct elements in the entire subarray and then find the shortest subarray with that number of distinct elements.


If a subarray from L to R has K number of distinct elements, it is possible that a shorter subarray from X to R (L < X) also has K number of distinct elements.


We would be using two pointers to solve this problem. We start both the pointers from the beginning i.e. L = 0 and R = 0. We would be maintaining a frequency count array for the elements in the current subarray. To find the number of distinct elements in the current subarray, when increasing the frequency, if we get it as 1, that means a new element has been added to the current subarray,  the number of distinct elements in the subarray increases, and when decreasing the frequency, if we get it as 0, that means the element is no more present in the subarray and the number of distinct elements in the subarray decreases.

We start from the beginning of the array and keep increasing the right pointer, R till the number of distinct elements is less than or equal to K. If the subarray from L to R has a number of distinct elements = K, it is possible that a shorter subarray from X to R (L < X) also has K number of distinct elements. Find the length of this subarray, i.e. the penalty, and take the minimum of all such penalties. When the number of distinct elements becomes equal to K, we start moving the left pointer, until the number of distinct elements is less than K. We continue doing this till R < N.

Time Complexity per test case: O(N)


*/


#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    ll testcases;
    cin>>testcases;
    while(testcases--){
        ll n;
        cin>>n;
        ll arr[n];
        ll freq[100001] = {0};
        for(ll i=0;i<n;i++)cin>>arr[i],freq[arr[i]]++;
        ll distinctElement = 0;
        for(ll i=0;i<=100000;i++){
            distinctElement+=(freq[i]>0);
            freq[i] = 0;
        }
        ll ans = n;
        ll start = 0;
        ll current = 0;
        ll currSum = 0;
        while(current<n){
            freq[arr[current]]++;
            if(freq[arr[current]]==1)
                currSum++;
            while(start<=current and currSum==distinctElement){
                ans = min(ans,current-start+1);
                if(freq[arr[start]]==1)
                    currSum--;
                freq[arr[start]]--;
                start++;
            }
            current++;
        }
        cout<<ans<<"\n";
    }
}