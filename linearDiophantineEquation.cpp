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

bool findSolution(int a,int b,int c,int &x,int &y,int &g)
{
    g=gcd(a,b,x,y);
    if(c%g) return 0;
    x*=c/g;
    y*=c/g;
    if(a<0) x=-x;
    if(b<0) y=-y;
    return 1;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a,b,c,x,y,g;
    cin>>a>>b>>c;
    if(findSolution(a,b,c,x,y,g))
        cout<<a<<"*"<<x<<" + "<<b<<"*"<<y<<" = "<<c;
    else cout<<"No solution found";

}