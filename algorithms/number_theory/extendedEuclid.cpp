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

int gcd(int a,int b,int &x,int &y)
{
    if(!a)
    {
        x=0;
        y=1;
        return b;
    }
    int x1,y1,g;
    g=gcd(b%a,a,x1,y1);
    y=x1;
    x=y1-(b/a)*x1;
    return g;
}



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a,b,g,x,y;
    cin>>a>>b;
    g=gcd(a,b,x,y);
    cout<<a<<"("<<x<<")"<<" + "<<b<<"("<<y<<")"<<" = "<<g;
}