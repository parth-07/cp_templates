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

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t,n;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>n;
        if(n&1)
        {
            n-=3;
            s+="7";
        }
        while(n)
        {
            n-=2;
            s+="1";
        }
        cout<<s<<"\n";
    }
}