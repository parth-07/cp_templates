#ifndef TREE_H
#define TREE_H
#include<bits/stdc++.h>

using std::map;
using std::numeric_limits;
using std::queue;
using std::vector;
using std::cout;

template <class T, class EdgeValueT = int>
class Tree
{
public:
    using size_type = size_t;
    using value_type = T;
    using edge_value_type = T;
    using node_edges = map<size_type, edge_value_type>;

    constexpr static size_type npos = numeric_limits<size_type>::max();
    constexpr static edge_value_type nweight = numeric_limits<edge_value_type>::max() / 4;

private:
    enum Color
    {
        WHITE = 0,
        GREY,
        BLACK
    };
    class Node
    {
    public:
        T value;
        node_edges edges;
        size_type parent, depth;
        Color color = WHITE;
        Node(T __value = 0) : value(__value) {}
        Node(const Node &) = default;
    };

public:
    vector<Node> nodes;
    const size_type root;
    Tree(size_type sz = 0, size_type __root = 0);
    Tree(const Tree&) = default;
    void add_directed_edge(const size_type u_i, const size_type v_i, edge_value_type weight = 1);
    void add_undirected_edge(const size_type u_i, const size_type v_i, edge_value_type weight = 1);
    void dfs(size_type bud = npos, size_type parent = npos);
    void bfs(size_type bud = npos);
    Node& operator[](const size_type);
    const Node& operator[](const size_type) const;
    void reset_colors();
};

template <class T, class EdgeValueT>
constexpr typename Tree<T, EdgeValueT>::size_type Tree<T, EdgeValueT>::npos;

template <class T, class EdgeValueT>
constexpr typename Tree<T, EdgeValueT>::edge_value_type Tree<T, EdgeValueT>::nweight;

template <class T, class EdgeValueT>
Tree<T, EdgeValueT>::Tree(size_type sz, size_type __root) : nodes(vector<Node>(sz)), root(__root) {}

template <class T, class EdgeValueT>
void Tree<T, EdgeValueT>::add_directed_edge(const size_type u_i, const size_type v_i, edge_value_type weight)
{
    nodes[u_i].edges[v_i] = weight;
}

template <class T, class EdgeValueT>
void Tree<T, EdgeValueT>::add_undirected_edge(const size_type u_i, const size_type v_i, edge_value_type weight)
{
    nodes[u_i].edges[v_i] = weight;
    nodes[v_i].edges[u_i] = weight;
}
template<class T,class EdgeValueT>
void Tree<T,EdgeValueT>::dfs(size_type bud, size_type parent)
{
    if (bud == npos)
        bud = root;
    Node &u = nodes[bud];
    cout << bud << " ";
    for (auto item : u.edges)
    {
        size_type v_i = item.first;
        if (v_i == parent)
            continue;
        dfs(v_i, bud);
    }
}

template<class T,class EdgeValueT>
void Tree<T,EdgeValueT>::bfs(size_type bud)
{
    if (bud == npos)
        bud = root;
    for (auto &node : nodes)
        node.color = WHITE;

    queue<size_type> node_queue;
    nodes[bud].color = GREY;
    node_queue.push(bud);
    while (!node_queue.empty())
    {
        size_type u_i = node_queue.front();
        node_queue.pop();
        Node &u = nodes[u_i];
        cout << u_i << " ";
        for (auto edge : u.edges)
        {
            size_type v_i = edge.first;
            Node &v = nodes[v_i];
            if (v.color == WHITE)
            {
                v.color = GREY;
                node_queue.push(v_i);
            }
        }
        u.color = BLACK;
    }
}

template<class T,class EdgeValueT>
inline typename Tree<T,EdgeValueT>::Node& Tree<T,EdgeValueT>::operator[](const size_type index)
{
    return nodes[index];
}

template<class T,class EdgeValueT>
inline const typename Tree<T,EdgeValueT>::Node& Tree<T,EdgeValueT>::operator[](const size_type index) const
{
    return nodes[index];
}

template<class T,class EdgeValueT>
inline void Tree<T,EdgeValueT>::reset_colors()
{
    for(auto &node : nodes)
        node.color = WHITE;
}

#endif
//To see basic example of it's implementation , see tree_example.cpp file in the same directory