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

const unsigned EULER_TOTIENT_LIMIT=1e4;

template<typename T>    //euler totient in O(sqrt(n))
T getPhi(T n)
{
    T res=n;
    for(T i=2;i<=n*n;++i)
    {
        if(n%i == 0)
        {
            while(n%i == 0)
                n/=i;
            res-=res/i;
        }
    }
    if(n>1)
        res-=res/n;
    return res;
}

vec phi;

void eulerTotientPreComputation()   //precomputation of O(nlog(logn)) , to get euler totient of any number from 1 to n , in O(1)
{
    phi.resize(EULER_TOTIENT_LIMIT+1);
    phi[0]=0;
    phi[1]=1;
    for(unsigned i=2;i<=EULER_TOTIENT_LIMIT;++i)
        phi[i]=i;
    for(unsigned i=2;i<=EULER_TOTIENT_LIMIT;++i)
    {
        if(phi[i] == i)
        {
            for(unsigned j=i;j<=EULER_TOTIENT_LIMIT;j+=i)
                phi[j]-=phi[j]/i;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    eulerTotientPreComputation();
    unsigned t;
    cin>>t;
    while(t--)
    {
        unsigned n;
        cin>>n;
        show(getPhi(n));
        show(phi[n]);

    }
    
}