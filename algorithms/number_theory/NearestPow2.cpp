#include<bits/stdc++.h>
#define INF 0x3f3f3f3f

using std::cin;
using std::cout;
using std::endl;

typedef long long ll;

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
int main()
{
    ll n;
    cin>>n;
    cout<<"nearest power of 2 less than or equal to n = "<<powerof2(n)<<endl;
}