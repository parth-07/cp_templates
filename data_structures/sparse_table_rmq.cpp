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

//Still in testing phase

template <typename T>
class SparseTable       //O(1) range query sparse table , would work only on idempotent functions like min() or max()
{
public:
    typedef vector<T> stvec;
    typedef vector<stvec> stgrid;
    typedef function<T(T,T)> stfun;
    stvec lg;
    stvec a;
    stgrid st;
    unsigned sz, k;
    stfun f;
    SparseTable(){}
    SparseTable(const stvec &source,const stfun &fun) : a(source) , f(fun){
        preCompute();
    }
    void preCompute();
    void preComputelg();
    T rmq(int , int );
};

template<typename T>
T SparseTable<T>::rmq(int l,int r)
{
    // show2(l,r);
    ll j=lg[r-l+1];
    // show(j);
    return f(st[l][j],st[r-(1<<j)+1][j]);
}

template <typename T>
void SparseTable<T>::preCompute()
{
    sz = a.size();
    k = floor(log2(sz));

    st.resize(sz + 1, stvec(k + 1));

    for (unsigned i = 0; i < sz; ++i)
        st[i][0] = a[i];
    
    for (unsigned j = 1; j <= k; ++j)
    {
        for (unsigned i = 0; i + (1 << j) - 1 < sz; ++i)
        {
            st[i][j] = f(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
            // show2(i,j);
            // show(st[i][j]);
        }
    }
    preComputelg();
}

template<typename T>
void SparseTable<T>::preComputelg()
{
    lg.resize(sz+1);
    lg[1]=0;
    for(int i=2;i<=sz;++i)
        lg[i]=lg[i/2]+1;
    
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vec a={1,2,3,4,5,5,4,3,2,1};
    SparseTable<int> sparse(a,[](int a,int b){return min(a,b); });
    for(auto x : a)
        cout<<x<<" ";
    cout<<endl;
    unsigned q;
    int l,r;
    cin>>q;
    while(q--)
    {
        cin>>l>>r;
        --l;
        --r;
        cout<<sparse.rmq(l,r)<<endl;
    }
}