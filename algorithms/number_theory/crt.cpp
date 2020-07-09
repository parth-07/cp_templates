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

ll crt(const llvec &a,const llvec &cp)
{
    assert(a.size() == cp.size() && "Different size of a and cp vectors , unable to determine equations");
    llvec y(a.size()),yinv(a.size());
    ll cpPro =1;
    for(unsigned i=0;i<cp.size();++i) cpPro*=cp[i];
    ll x=0;
    for(unsigned i=0;i<cp.size();++i)
    {
        y[i]=cpPro/cp[i];
        yinv[i]=getModInverse(y[i],cp[i]);
        x=(x+a[i]*y[i]*yinv[i])%cpPro;
    }
    return x;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    llvec a,cp;
    unsigned n;
    cin>>n;
    a.resize(n);
    cp.resize(n);
    for(unsigned i=0;i<n;++i)
    {
        cin>>a[i]>>cp[i];
    } 

    ll x=crt(a,cp);
    cout<<x<<endl;    
}