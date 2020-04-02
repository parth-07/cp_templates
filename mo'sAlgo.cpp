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

int BLOCK_SZ;

struct Query
{
    int l,r;

    bool operator<(Query rhs) const
    {
        return iipair(l/BLOCK_SZ,r) < iipair(rhs.l/BLOCK_SZ,rhs.r);
    }
};

void add(int idx);
void remove(int idx);
int getResult();

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<Query> queries;
    vector<int> result;
    int l=0,r=-1;

    for(auto item : queries)
    {
        while(l<item.l)
        {
            remove(l);
            l++;
        }
        while(l>item.l)
        {
            --l;
            add(l);
        }
        while(r<item.r)
        {
            ++r;
            add(r);
        }
        while(r>item.r)
        {
            remove(r);
            --r;
        }
        result.push_back(getResult());
    }
    
}