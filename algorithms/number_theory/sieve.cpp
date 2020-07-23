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

auto t1=chrono::high_resolution_clock::now();

const ull SIEVE_LIMIT=1e6;
vector<bool> isPrime(SIEVE_LIMIT+1,1);
uvec prime;

void preComputation()
{
    isPrime[0]=isPrime[1]=0;
    for(unsigned i=4;i<=SIEVE_LIMIT;i+=2) isPrime[i]=0;
    for(ull i=3;i*i<=SIEVE_LIMIT;i+=2)
    {
        if(isPrime[i])
        {
            for(ull j=i*i;j<=SIEVE_LIMIT;j+=i) isPrime[j]=0;
        }
    }
    for(unsigned i=0;i<=SIEVE_LIMIT;++i)
    {
        if(isPrime[i]) prime.push_back(i);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    preComputation();
    for(unsigned i=0;i<100;++i)
        cout<<prime[i]<<" ";
    cout<<"\n";
    cout<<prime.size();
    auto t2=chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(t2-t1).count();
    clog<<"Time Taken = "<<duration*1.0/1000<<" seconds"<<endl;
}