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
const unsigned M = 29;

llvec inv;


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
ll gcd(ll a,ll b,ll &x,ll &y)
{
    if(!a)
    {
        x=0;
        y=1;
        return b;
    }
    ll x1,y1,g;
    g=gcd(b%a,a,x1,y1);
    y=x1;
    x=y1-(b/a)*x1;
    return g;
}

ll getModInverse(ll a,ll m)
{
    ll x,y;
    if(gcd(a,m,x,y) == 1)
    {
        return (x%m+m)%m;
    }
    else return 0;
}

ll InverseAll(ll n , ll m)
{
    inv.resize(min(n,m));
    inv[1]=1;
    for(ll i=2;i<min(n,m);++i)
    {
        inv[i] = ((-(m/i)*inv[m%i])%m + m)%m; 
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    unsigned a,m;
    m=M;
    InverseAll(m,m);
    cin>>a;
    cout<<"Mod inverse of a wrt m = "<<modInverse(a,m)<<" "<<inv[a];    
    cout<<"Mod inverse of a wrt m = "<<getModInverse(a,m);
}