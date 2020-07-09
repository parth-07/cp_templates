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

ll binExpo(ll a,ll b)
{
    ll res=1;
    while(b > 0)
    {
        if(b&1)
        {
            res*=a;
        }
        a*=a;
        b>>=1;
    }
    return res;
}


ll binExpo(ll a,ll b,ll m)
{
    ll res=1;
    while(b > 0)
    {
        if(b&1)
        {
            res=(res*a)%m;
        }
        a=(a*a)%m;
        b>>=1;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    unsigned a,b;
    cin>>a>>b;
    cout<<binExpo(a,b);
    
}