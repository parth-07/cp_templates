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

int longestIncSubLength(const vec &a)
{
    if(a.empty())   return 0;
    vec tail(a.size(),INF);
    tail[0]=a[0];
    int length=1;
    for(unsigned i=1;i<a.size();++i)
    {
        if(a[i]<tail[0])
        {
            tail[0]=a[0];
        }
        else if(a[i] > tail[length-1])
        {
            tail[length++]=a[i];
        }
        else 
        {
            vec::iterator iter=upper_bound(all(tail),a[i]);
            *iter=a[i];
        }
    }
    return length;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vec a{ 2, 5, 3, 7, 11, 8, 10, 13, 6 };
    cout<<longestIncSubLength(a);
}