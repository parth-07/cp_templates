#include<bits/stdc++.h>
#define show(x) cout<<#x" = "<<x<<endl;
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

const unsigned LIMIT=1e4;
const unsigned M = 1e9+7;

llvec facp(LIMIT+1);    //facp = factorial mod p

ll modInverse(ll a,ll m)    //this functions assumes m to be prime and a and m to be coprime
{
    ll p=m-2,res=1;

    while(p>0)
    {
        if(p&1) res=(res*a)%m;
        a=(a*a)%m;
        p>>=1;
    }
    return res%m;
}

void preComputeFactorial()
{
    facp[0]=facp[1]=1;
    for(ll i=2;i<=LIMIT;++i) facp[i]=(i*facp[i-1])%M;
}

ll ncr(ll n ,ll r)
{
    return ((facp[n]*modInverse(facp[r],M))%M*modInverse(facp[n-r],M))%M;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    preComputeFactorial();
    unsigned n,r;
    cin>>n>>r;
    cout<<ncr(n,r);
}