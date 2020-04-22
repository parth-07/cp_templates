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

template <typename T>
class DisjointSetForest
{
private :
    struct Element
    {
        T value;
        int par,rank;
        Element(const T& val,int p) : value(val) , par(p) , rank(0) { }
    };
public:
    // vector<Element> dsforest; //disjoint set forest , vector implementation should be used , when it is known before hand that nodes will be from number 1 to n
    map<int,Element> dsforest; //map implementation for random node indices
    DisjointSetForest(unsigned);

    void makeSet(int,const T& = T{});
    int findSet(int );
    void joinSets(int,int);
    void link(int,int);
    void display();
};

template<typename T>
void DisjointSetForest<T>::makeSet(int u,const T& val)
{
    dsforest.insert(make_pair(u,Element(val,u)));
}

template<typename T>
int DisjointSetForest<T>::findSet(int u)
{
    if(!dsforest.count(u))
    {
        return -1;
    }
    Element &a = dsforest[u];
    if(u != a.par)
    {
        a.par = findSet(a.par);
    }
    return a.par;
}

template<typename T>
void DisjointSetForest<T>::joinSets(int u,int v)
{
    link(findSet(u),findSet(v));
}

template<typename T>
void DisjointSetForest<T>::link(int u,int v)
{
    Element &a=dsforest[u];
    Element &b=dsforest[v];
    if(a.rank > b.rank)
    {
        b.par=a;
    }
    else
    {
        a.par=b;
        if(b.rank == a.rank)
            ++b.rank;
    }
    
}

template <typename T>
DisjointSetForest<T>::DisjointSetForest(unsigned n)
{
    for(unsigned i=0;i<n;++i)
        makeSet(i);
}

template <typename T>
void DisjointSetForest<T>::display()
{
    for (auto x : dsforest)
    {
        Element &a=x.second;
        cout<<x.first<<endl;
        cout <<"Value : "<< a.value << endl;
        cout << "Parent : " << a.par << endl;
        cout << "Rank : " << a.rank << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    unsigned n;
    cin >> n;
    DisjointSetForest<int> a(n);
    a.display();
}