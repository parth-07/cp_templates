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

const unsigned LIMIT=1e3;

uvec sp(LIMIT+1,0);

void preComputation()
{
    sp[1]=1;
    for(unsigned i=4;i<=LIMIT;i+=2)
    {
        sp[i]=2;
    }
    for(ull i=3;i*i<=LIMIT;i+=2)
    {
        if(!sp[i])
        {
            for(ull j=i*i;j<=LIMIT;j+=i)
            {
                if(!sp[j])
                {
                    sp[j]=i;
                }
            } 
        }
    }
    for(unsigned i=1;i<=LIMIT;++i)
    {
        if(!sp[i])
        {
            sp[i]=i;
        }
    }

}

uvec getPFactors(unsigned n)
{
    uvec pf;
    while(n!=1)
    {
        pf.push_back(sp[n]);
        n/=sp[n];
    }
    return pf;
}

uvec getPrimeFactors(unsigned n)
{
    uvec factors;
    // show(n);
    for(unsigned i=2;i*i<=n;++i)
    {
        while(n%i == 0)
        {
            // show(i);
            factors.push_back(i);
            n/=i;
        }
    }
    if(n > 1) factors.push_back(n);
    return factors;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    preComputation();
    unsigned n;
    cin>>n;
    uvec a=getPrimeFactors(n);
    /* show(n);
    show(a.size()); */
    while(n != 1)
    {
        cout<<sp[n]<<" ";
        n/=sp[n];
    }
    cout<<endl;
    for(auto x : a) cout<<x<<" ";
    cout<<endl;
}