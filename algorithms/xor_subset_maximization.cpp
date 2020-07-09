#include<bits/stdc++.h>
#define show(x) cout<<#x" = "<<x<<endl;
#define show2(x,y) cout<<#x" = "<<x<<" "<<#y<<" = "<<y<<endl;
#define all(x) x.begin(),x.end()
#define INF 0x3f3f3f3f
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> iipair;
typedef pair<unsigned,unsigned> uupair;
typedef vector<int> vec;
typedef vector<unsigned> uvec;
typedef vector<ll> llvec;

ll powerof2(ll n)
{
    n|=(n>>1);
    n|=(n>>2);
    n|=(n>>4);
    n|=(n>>8);
    n|=(n>>16);
    n|=(n>>32);
    return (n+1)>>1;
}

ll xorSubsetMax(llvec a,unsigned BIT_LIMIT=64)
{

    for(unsigned i=BIT_LIMIT;i!=static_cast<unsigned>(-1);--i)
    {
        if()
    }
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
}