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

//Still in testing phase , beware while using 

template<typename T>
class Mo_query
{
public:
    int index, l, r;
    ll ord;
    int blk;
    T ans;
    ll hilbertOrder(int, int, int, int);
    static int hilbertK;     //should be such that , 2^k >= n (range of l,r , number of elements ...) , k=21 , will work for till n<=2097152
    Mo_query(int idx, int ll, int rr) : index(idx), l(ll), r(rr)
    {
        ord=hilbertOrder(l,r,hilbertK,0);
    }
    Mo_query() { }
    bool operator<(const Mo_query &) const;
};
template<typename T>
int Mo_query<T>::hilbertK=21;

template<typename T>
bool Mo_query<T>::operator<(const Mo_query &rhs) const
{
    /* if(blk == rhs.blk)
        return r<rhs.r;
    else return blk<rhs.blk; */     //ordinary sorting
    /* if(blk == rhs.blk)
    {
        if(blk&1)
            r<rhs.r;
        else r>rhs.r;
    }    //Odd even sorting , basically sorting r in ascending order for odd blocks and in descending order for even blocks
    return blk<rhs.blk; */
    return ord<rhs.ord;     //using hilbert space order
}

template<typename T>
ll Mo_query<T>::hilbertOrder(int x, int y, int pow, int rotate)
{
    if (pow == 0)
    {
        return 0;
    }
    int hpow = 1 << (pow - 1);
    int seg = (x < hpow) ? (
                               (y < hpow) ? 0 : 3)
                         : (
                               (y < hpow) ? 1 : 2);
    seg = (seg + rotate) & 3;
    const int rotateDelta[4] = {3, 0, 0, 1};
    int nx = x & (x ^ hpow), ny = y & (y ^ hpow);
    int nrot = (rotate + rotateDelta[seg]) & 3;
    ll subSquareSize = ll(1) << (2 * pow - 2);
    ll ans = seg * subSquareSize;
    ll add = hilbertOrder(nx, ny, pow - 1, nrot);
    ans += (seg == 1 || seg == 2) ? add : (subSquareSize - add - 1);
    return ans;
}

template<typename T>
class Mo_ds
{
public:
    Mo_ds() { }
    void add(int);
    void remove(int);
    T getResult();
};

template<typename T>
void Mo_ds<T>::add(int idx)
{

}
template<typename T>
void Mo_ds<T>::remove(int idx)
{
    
}
template<typename T>
T Mo_ds<T>::getResult()
{

}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<Mo_query<int>> queries;  //replace with the desired type of result of the query
    //input queries
    sort(all(queries));
    int l=0,r=-1;
    Mo_ds<int> mo;  //replace int with the desired type
    for(auto &query : queries)
    {
        while(l < query.l)
        {
            mo.remove(l++);
        }
        while(l>query.l)
        {
            mo.add(--l);
        }
        while(r<query.r)
        {
            mo.add(++r);
        }
        while(r>query.r)
        {
            mo.remove(r--);
        }
        query.ans=mo.getResult();
    }
}