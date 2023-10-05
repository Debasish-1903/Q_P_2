
Product of the Last K numbers

Time-Limit: 2 sec Score: 1.00/100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

Design the algorithm which supports the following operations.

add(int x): Add x to the back of the current list of numbers.
getProduct(int k): Print the product of the last k numbers % 1000000007 in the current list. It's guaranteed that the list will contain at least k elements.
Initially, the list is empty.

Complete the code.


Input Format

The first line contains Q - the number of queries.
Each query is one of the types of queries explained in the problem statement.


Constraints

1 ≤ Q ≤ 105
0 ≤ x ≤ 109


Sample Input 1

10
add 3
add 0
add 2
add 5
add 4
getProduct 2
getProduct 3
getProduct 4
add 8
getProduct 2

Sample Output 1

20
40
0
32




#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007

class ProductOfKNumbers {
public:
    vector<ll> prod;
    int zeroCount;

    ProductOfKNumbers() {
        prod.push_back(1);
        zeroCount = 0;
    }

    void add(int num) {
        if(num == 0) {
            prod.clear();
            prod.push_back(1);
            zeroCount++;
        } else {
            prod.push_back((prod.back()%mod * (num%mod)) % mod);
        }
    }

    ll getProduct(int k) {
        if(prod.size()-1<k) {
            return 0;
        } else {
            ll result = prod.back();
            ll inverse = power(prod[prod.size() - k - 1], mod - 2);
            return (result * inverse) % mod;
        }
    }

    ll power(ll a, ll b) {
        ll result = 1;
        while(b > 0) {
            if(b & 1) {
                result = (result * a) % mod;
            }
            a = (a * a) % mod;
            b >>= 1;
        }
        return result;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int Q;
    cin >> Q;

    ProductOfKNumbers productOfKNumbers;

    while(Q--) {
        string op;
        cin >> op;

        if(op == "add") {
            int num;
            cin >> num;
            productOfKNumbers.add(num);
        } else {
            int k;
            cin >> k;
            cout << productOfKNumbers.getProduct(k) << "\n";
        }
    }

    return 0;
}
