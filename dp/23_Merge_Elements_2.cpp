/*Merge Elements 2

Time-Limit: 2 sec Score: 1.00/100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

You are given N elements, in an array A. You are also given 3 constants X, Y, and Z. You can take any 2 consecutive elements a and b and merge them. On merging you get a single element with value (aX+bY+Z)%50 and this process costs you a*b. After merging you will place this element in place of those 2 elements.
 

If the sequence is [A1, A2, A3, A4] and you merge A2 and A3, you incur a cost of A2*A3 and the array becomes [A1, (A2*X+A3*Y+Z)%50, A4].
 

Find the Minimum cost to merge all the elements into a single element.


Input Format

The first line contains 4 integers, N, X, Y, Z. 1 <= N <= 50, 0<= X,Y,Z < 50.

The Second line contains N space-separated integers, the Ai for the Array.  0 <= Ai < 50


Output Format

Output a single integer, the Minimum cost to Merge all the elements.


Sample Input 1

3 1 2 3
1 2 4
 


Sample Output 1

21  */

/*aproach*/

/*
The answer is going to change as the elements are capped by Modulo. How do you design an efficient DP that takes care of all possible ordering? Think Backwards from 1 element.


What if we keep DP(l,r,x) as the cost to merge the segment into one element with value x, would that help? 

// complete apprach//

So we can design a DP with the states
DP(l,r,x) = minimum cost to merge the segment into one element of value x. if x is not possible, then this store +INF cost.


Now range (l,r) will form one element from 2 elements in the final step.
So let's say the (l, mid) and (mid+1,r) range equivalents merge and produce the final element.


So DP(l,r,(AX+BY+C)%50) = min(DP(l,mid,A) + DP(mid+1,r,B) + AB ) for all mid,A,B in range [l,r).

Now if for every l,r,z we iterate on all mid and A, B … it turns out to be O(N^6) solution.

This can be optimized to O(N^5) using the following logic.

We can calculate the DP(l,r,z) for all values of z altogether. So keep a done for (l,r) pair.

For a certain range (L,R) → We iterate on mid, and them lets say the left side has value A and the right side as B. So this particular portion updates at (AX+BY+C)%50 and value is (DP(l,mid,A) + DP(mid+1,r,B) + AB 

So we are sort of keeping DP(L,R) only and this basically returns an array for all values of merging what is the optimal value.

This makes the code given below O(N^5).





*/

#include<bits/stdc++.h>
using namespace std;

int n,x,y,z;
int arr[51];
bool done[51][51];
int memo[51][51][51];

int dp(int l,int r,int xx){
    if(l==r){
        if(arr[l]==xx)return 0;
        else return 1e9;
    }
    if(done[l][r]){
        return memo[l][r][xx];
    }

    for(int i=0;i<50;i++)memo[l][r][i]=1e9;    

    for(int mid=l;mid<r;mid++){
        for(int fs=0;fs<50;fs++){
            for(int ls=0;ls<50;ls++){
                memo[l][r][(fs*x+ls*y+z)%50] = min(memo[l][r][(fs*x+ls*y+z)%50], dp(l,mid,fs)+ dp(mid+1,r,ls) + fs*ls);
            }
        }
    }
    done[l][r]=1;
    return memo[l][r][xx];
}

void solve(){
    memset(memo,-1,sizeof(memo));
    cin>>n>>x>>y>>z;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int ans = 1e9;
    for(int i=0;i<50;i++){
        ans=min(ans,dp(0,n-1,i));
    }
    cout<<ans<<endl;
}   

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //int _t;cin>>_t;while(_t--)
    solve();
}