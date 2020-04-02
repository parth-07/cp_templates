#include <bits/stdc++.h>
#define show(x) cout << #x " = " << x << endl;
#define show2(x, y) cout << #x " = " << x << " " << #y << " = " << y << endl;
#define all(x) x.begin(), x.end()
#define INF 0x3f3f3f3f
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> iipair;
typedef pair<unsigned, unsigned> uupair;
typedef vector<int> vec;
typedef vector<unsigned> uvec;

template <class Type>
class SegTree
{
    typedef function<Type(Type,Type)> mergeFunction;
    mergeFunction merge; 
    unsigned sz;
    void build()
    {
        for (unsigned i = sz - 1; i > 0; --i)
        {
            tree[i] =merge(tree[(i << 1)],tree[(i << 1) | 1]);
            // show2(tree[i],i);
        }
    }
    vector<Type> tree;
    Type initial_res;
public:
    SegTree(const vector<Type> &a,const mergeFunction &fun,Type initial=0) : sz(a.size()) , merge(fun) , initial_res(initial)
    {
        tree.resize(2 * sz);
        for (unsigned i = 0; i < sz; ++i)
        {
            tree[sz + i] = a[i];
        }
        build();
    }
    void update(int index, Type val)
    {
        index += sz;
        tree[index] = val;
        for (unsigned i = index; i > 1; i >>= 1)
        {
            tree[(i >> 1)] = merge(tree[i],tree[(i ^ 1)]);
        }
    }
    Type query(int l, int r) const
    {
        Type res = initial_res;
        for (l += sz, r += sz; l <= r; l =((l + 1) >> 1), r = ((r - 1) >> 1))
        {
            // show2(tree[l],tree[r]);
            // show2(l,r);
            if (l & 1)
            {
                res =merge(res,tree[l]);
            }
            if (!(r & 1))
            {
                res =merge(res,tree[r]);
            }
        }
        return res;
    }
    Type& operator[](const unsigned);
    const Type& operator[](const unsigned) const;
};

template <class Type> Type& SegTree<Type>::operator[](const unsigned index) 
{
    return tree[index];
}

template<class Type> const Type& SegTree<Type>::operator[](const unsigned index) const
{
    return tree[index];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vec a = {0, 1, 2, 3, 4, 5, 6};
    auto sum = [] (int a,int b) { return a+b; };
    SegTree<vec::value_type> tree(a,sum);
    unsigned t;
    cin >> t;
    tree.update(1,10);
    while (t--)
    {
        unsigned l, r;
        cin >> l >> r;
        cout << tree.query(l, r) << endl;
    }
}