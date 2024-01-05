#include<bits/stdc++.h>
using namespace std;
//#define mod 1000000007
#define int long long 
#define ll long long
//#define ll int64_t
#define endl "\n"
#define inf 1e9
#define N 1000100


void solve(){
    ll num; cin>>num;
    bitset<64> bset(num);
    cout<<bset<<endl;
    if(num<0LL) num*=-1LL;
    int lsb,msb;
    if(num==0LL) cout<<"-1\n-1\n0\n-1\n";
    else {
        //msb
        for(int i=63;i>=0;i--) {
            if(bset[i]) {
                msb=i;
                break;
            }
        }
        cout<<msb<<"\n";
        //lsb
        for(int i=0;i<64;i++) {
            if(bset[i]) {
                lsb=i;
                break;
            }
        }
        cout<<lsb<<"\n";
        //4th query
        if(msb!=lsb || lsb==0) cout<<"0\n";
        else cout<<"1\n";
        
        //5th query
        cout<<(1LL<<lsb)<<"\n";
    }
        
        //6th query
        if(num<=1LL || bset[63]) cout<<"2\n";
        else if(msb!=lsb) cout<<(1LL<<(msb+1))<<"\n";
        else cout<<(1LL<<msb)<<"\n";
}
  
signed main() {

          ios_base::sync_with_stdio(0);

          cin.tie(0);cout.tie(0);
           int __t;cin>>__t;
           while(__t--)
            solve();
}