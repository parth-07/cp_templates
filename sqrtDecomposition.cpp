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

unsigned BLK_SZ;

uvec b,a;
int k;

void build()
{
    BLK_SZ=ceil(sqrt(a.size()));
    b.resize(BLK_SZ,0);
    for(unsigned i=0;i<a.size();++i)
    {
        b[i/BLK_SZ]+=(a[i]%k == 0);
    }
}

void update(unsigned l,unsigned r,int y)
{
    for(unsigned i=l;i<=r;++i)
    {
        b[i/BLK_SZ]-=(a[i]%k == 0);
        a[i]+=y;
        b[i/BLK_SZ]+=(a[i]%k == 0);
    }
}

unsigned query(int l,int r)
{
    unsigned res=0;
    while(l%BLK_SZ!=0 && l<=r)
    {
        if(a[l]%k == 0) ++res;
        ++l;
    }
    while((r+1)%BLK_SZ != 0 && r>=l)
    {
        if(a[r]%k == 0 ) ++res;
        --r;
    }
    for(int i=l/BLK_SZ;i<(r+1)/BLK_SZ;++i) res+=b[i];
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    unsigned n,q;
    cin>>n>>q>>k;
    a.resize(n);
    for(unsigned i=0;i<n;cin>>a[i++]);
    build();
    unsigned type,l,r,y;
    while(q--)
    {
        cin>>type;
        switch(type)
        {
            case 1:
                cin>>l>>r;
                cout<<query(l,r)<<"\n";
                break;
            case 2:
                cin>>l>>r>>y;
                update(l,r,y);
                break;
        }
    }

}