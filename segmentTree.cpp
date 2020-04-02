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
typedef vector<ll> llvec;

unsigned leftChild(unsigned i)
{
    return (i<<1)+1;
}

unsigned rightChild(unsigned i)
{
    return (i+1)<<1;
}

void build(unsigned node,unsigned start,unsigned end,llvec &seg,llvec &a)
{
    if(start == end)
    {
        seg[node] = a[start];
        return;
    }
    unsigned mid = start + (end-start)/2;
    build(leftChild(node),start,mid,seg,a);
    build(rightChild(node),mid+1, end,seg,a);
    seg[node]=seg[leftChild(node)] + seg[rightChild(node)];
}

void update(unsigned node,unsigned start,unsigned end,unsigned index,ll val,llvec &seg,llvec &a)
{   
    if(start > index || end < index) return ;
    if(start == end)
    {
        seg[node]=val;
        a[start]=val;
        return;
    }
    unsigned mid = start + (end-start)/2;
    update(leftChild(node),start,mid,index,val,seg,a);
    update(rightChild(node),mid+1,end,index,val,seg,a);
    seg[node]=seg[leftChild(node)] + seg[rightChild(node)];

}

ll query(unsigned node,unsigned start,unsigned end ,unsigned l,unsigned r,llvec &seg,llvec &a)
{
    if(l<=start && r>=end) return seg[node];
    else if(start > r || end < l) return 0;
    unsigned mid = start + (end-start)/2;
    ll suml,sumr;
    suml = query(leftChild(node),start,mid,l,r,seg,a);
    sumr = query(rightChild(node),mid+1,end,l,r,seg,a);
    return suml+sumr;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    

}