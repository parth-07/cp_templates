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
typedef map<int, int> iimap;
typedef set<int> iset;

//Important trees algorithms
//Still in testing phase , beware while using them

template <typename T>
class SparseTable //O(1) range query sparse table , would work only on idempotent functions like min() or max()
{
public:
    typedef vector<T> stvec;
    typedef vector<stvec> stgrid;
    typedef function<T(T, T)> stfun;
    unsigned SBE_p2 = 24; //Should be enough , p2 = power of 2
    stvec lg, p2;
    stvec a;
    stgrid st;
    unsigned sz, k;
    stfun f;
    SparseTable() {}
    SparseTable(const stvec &source) : a(source)
    {
        preCompute();
    }

    void preCompute();
    void preComputelg();
    T query(int, int);
};

template <typename T>
T SparseTable<T>::query(int l, int r)
{
    // show2(l,r);
    ll j = lg[r - l + 1];
    // show(j);
    if (a[st[l][j]] < a[st[r - p2[j] + 1][j]])
        return st[l][j];
    else
        return st[r - p2[j] + 1][j];
    // return f(st[l][j], st[r - (1 << j) + 1][j]);
}

template <typename T>
void SparseTable<T>::preCompute()
{
    sz = a.size();
    preComputelg();
    k = floor(log2(sz));

    st.resize(sz + 1, stvec(k + 1));

    for (unsigned i = 0; i < sz; ++i)
        st[i][0] = i;

    for (unsigned j = 1; j <= k; ++j)
    {
        for (unsigned i = 0; i + p2[j] - 1 < sz; ++i)
        {
            if (a[st[i][j - 1]] < a[st[i + p2[j - 1]][j - 1]])
                st[i][j] = st[i][j - 1];
            else
            {
                st[i][j] = st[i + p2[j - 1]][j - 1];
            }
            // show2(i,j);
            // show(st[i][j]);
        }
    }
}

template <typename T>
void SparseTable<T>::preComputelg()
{
    lg.resize(sz + 1);
    lg[1] = 0;
    for (int i = 2; i <= sz; ++i)
        lg[i] = lg[i / 2] + 1;
    p2.resize(SBE_p2 + 1);
    p2[0] = 1;
    for (int i = 1; i <= SBE_p2; ++i)
        p2[i] = (p2[i - 1] << 1);
}

template <typename T> //type of weight isnt as in template parameter now;
class Tree
{
private:
    class Node
    {
    public:
        T value;
        iimap edges;
        int parent, depth;
        Node() {}
    };

public:
    enum Color
    {
        WHITE,
        GREY,
        BLACK
    };

    vector<Node> tree;
    vector<unsigned> euler_walk, euler_lca_walk;
    vector<unsigned> euler_start, euler_finish, euler_lca_start, euler_lca_depth;

    int root;
    SparseTable<unsigned> sparse_lca;
    bool basicStatus = 0;
    Tree(unsigned n, int r = 0);

    void addUndirectedEdge(int u, int v, int weight = 1);
    void addDirectedEdge(int u, int v, int weight); //edge from u to v

    void dfsDisplay(int bud = -1, int par = -1);
    void calBasicProperties(int bud = -1, int par = -1);
    void basicPropertiesDfs(int bud = -1, int par = -1); //properties like depth, parent
    void bfsDisplay(int bud = -1);

    void buildEulerWalkPathQueries(int bud = -1, int par = -1);
    void eulerWalk(int bud = -1, int par = -1);

    void prepareLCA();
    void buildEulerWalkLCA(int bud = -1, int par = -1);
    unsigned lca(int, int);

    unsigned size();

    Node &operator[](const unsigned index)
    {
        return tree[index];
    }
    const Node &operator[](const unsigned index) const
    {
        return tree[index];
    }
};

template <typename T>
void Tree<T>::calBasicProperties(int bud, int par)
{
    basicStatus = 1;
    basicPropertiesDfs(bud, par);
}

template <typename T>
unsigned Tree<T>::size()
{
    return tree.size();
}

template <typename T>
Tree<T>::Tree(unsigned n, int r) : root(r)
{
    tree.resize(n);
}

template <typename T>
void Tree<T>::addUndirectedEdge(int u, int v, int weight)
{
    tree[u].edges[v] = weight;
    tree[v].edges[u] = weight;
}

template <typename T>
void Tree<T>::addDirectedEdge(int u, int v, int weight)
{
    tree[u].edge[v] = weight;
}

template <typename T>
void Tree<T>::basicPropertiesDfs(int bud, int par)
{
    if (bud == -1)
    {
        bud = par = root;
    }
    Node &a = tree[bud];
    a.parent = par;
    if (bud == par)
    {
        a.depth = 0;
    }
    else
    {
        a.depth = tree[a.parent].depth + 1;
    }
    for (auto x : a.edges)
    {
        if (x.first == par)
            continue;
        basicPropertiesDfs(x.first, bud);
    }
}
template <typename T>
void Tree<T>::dfsDisplay(int bud, int par)
{
    if (bud == -1)
    {
        bud = par = root;
    }
    cout << bud << " ";
    for (auto x : tree[bud].edges)
    {
        if (x.first == par)
            continue;
        dfsDisplay(x.first, bud);
    }
}

template <typename T>
void Tree<T>::bfsDisplay(int bud)
{
    if (bud == -1)
    {
        bud = root;
    }
    queue<int> q;
    vector<Color> status(tree.size(), WHITE);

    q.push(bud);
    while (!q.empty())
    {
        status[q.front()] = BLACK;
        cout << q.front() << " ";
        for (auto x : tree[q.front()].edges)
        {
            if (status[x.first] == WHITE)
                q.push(x.first);
        }
        q.pop();
    }
}

template <typename T>
void Tree<T>::buildEulerWalkPathQueries(int bud, int par)
{
    euler_walk.clear();
    euler_start.resize(tree.size());
    euler_finish.resize(tree.size());
    eulerWalk(bud, par);
}

template <typename T>
void Tree<T>::eulerWalk(int bud, int par)
{
    if (bud == -1)
    {
        bud = par = root;
    }
    euler_start[bud] = euler_walk.size();
    euler_walk.push_back(bud);
    for (auto x : tree[bud].edges)
    {
        if (x.first == par)
            continue;
        eulerWalk(x.first, bud);
    }
    euler_finish[bud] = euler_walk.size();
    euler_walk.push_back(bud);
}

template <typename T>
void Tree<T>::prepareLCA()
{
    if (!basicStatus)
        calBasicProperties();
    euler_lca_start.resize(tree.size());
    euler_lca_walk.clear();
    euler_lca_depth.clear();
    buildEulerWalkLCA();
    for (auto x : euler_lca_walk)
        euler_lca_depth.push_back(tree[x].depth);
    sparse_lca = SparseTable<unsigned>(euler_lca_depth);
}

template <typename T>
void Tree<T>::buildEulerWalkLCA(int bud, int par)
{
    if (bud == -1)
        bud = par = root;
    euler_lca_start[bud] = euler_lca_walk.size();
    euler_lca_walk.push_back(bud);
    for (auto x : tree[bud].edges)
    {
        if (x.first == par)
            continue;
        buildEulerWalkLCA(x.first, bud);
        euler_lca_walk.push_back(bud);
    }
}

template <typename T>
unsigned Tree<T>::lca(int u, int v)
{
    u = euler_lca_start[u];
    v = euler_lca_start[v];
    if (u > v)
        swap(u, v);
    // show2(u,v);
    return euler_lca_walk[sparse_lca.query(u, v)];
}

int main()
{
    unsigned n = 10;
    Tree<int> tree(n);
    for (unsigned i = 0; i < n; ++i)
    {
        tree[i].value = i + 1;
    }
    unsigned u, v;
    for (unsigned i = 0; i < n - 1; ++i)
    {
        cin >> u >> v;
        --u;
        --v;
        tree.addUndirectedEdge(u, v);
    }
    // tree.dfsDisplay();
    // cout<<endl;
    // tree.bfsDisplay();
    tree.basicPropertiesDfs();
    tree.prepareLCA();

    for (unsigned i = 0; i < tree.size(); ++i)
    {
        show(i);
        cout << "value : " << tree[i].value << endl;
        cout << "depth : " << tree[i].depth << endl;
        cout << "parent : " << tree[i].parent + 1 << endl;
    }

    unsigned q;
    cin >> q;
    while (q--)
    {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        cout << tree.lca(u, v) + 1 << endl;
    }
}