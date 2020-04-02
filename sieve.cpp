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

const ull LIMIT=1e3;
vector<bool> isPrime(LIMIT+1,1);
uvec prime;

void preComputation()
{
    isPrime[0]=isPrime[1]=0;
    for(unsigned i=4;i<=LIMIT;i+=2) isPrime[i]=0;
    for(ull i=3;i*i<=LIMIT;i+=2)
    {
        if(isPrime[i])
        {
            for(ull j=i*i;j<=LIMIT;j+=i) isPrime[j]=0;
        }
    }
    for(unsigned i=0;i<=LIMIT;++i)
    {
        if(isPrime[i]) prime.push_back(i);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    preComputation();
    for(auto item : prime)
        cout<<item<<"\n";

}