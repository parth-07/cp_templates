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

struct disjoint
{
    int s,p,rank;
    disjoint(int parent): p(parent) { }
    void link(disjoint &a)
    {
        if(rank >= a.rank)
        {
            a.p=s;
            if(rank == a.rank)
                ++rank; 
        }
        else rank=a.s;
    }
    void join(disjoint &a)
    {
        link(findSet(s),findSet(a.s));
    }
    dis
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
}