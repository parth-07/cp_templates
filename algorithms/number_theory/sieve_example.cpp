#include<bits/stdc++.h>
using namespace std;
auto t1=chrono::high_resolution_clock::now();

#define show(x) clog<<#x" = "<<x<<endl;
#define show2(x,y) clog<<#x" = "<<x<<" "<<#y<<" = "<<y<<endl;
#define all(x) x.begin(),x.end()
#define INF 0x3f3f3f3f

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> iipair;
typedef pair<unsigned,unsigned> uupair;
typedef vector<int> vec;
typedef vector<unsigned> uvec;
#include "sieve.h"

constexpr ull SIEVE_LIMIT=1e6;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    PrimeNumbers<ll> pn(SIEVE_LIMIT);
    for(unsigned i=0;i<100;++i)
        cout<<pn.prime[i]<<" ";
    auto t2=chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(t2-t1).count();
    clog<<"Time Taken = "<<duration*1.0/1000<<" seconds"<<endl;
}