#include<bits/stdc++.h>
#include "euler_totient_function.h"

using namespace std;

typedef long long ll;

constexpr unsigned EULER_TOTIENT_LIMIT = 1e3;

int main()
{
    EulerTotients<ll> phi(EULER_TOTIENT_LIMIT);
    for(unsigned i=0;i<=15;++i)
    {
        cout<<"phi["<<i<<"] = "<<phi[i]<<" ";
        cout<<get_phi(i)<<endl;
    }
}

