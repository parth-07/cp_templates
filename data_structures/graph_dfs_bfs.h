#ifndef GRAPH_DFS_BFS_H
#define GRAPH_DFS_BFS_H

#include <bits/stdc++.h>

using std::map;
using std::numeric_limits;
using std::queue;
using std::stack;
using std::vector;
using std::clog;

template <class T, class EdgeValueT = int>
class Graph
{
public:
    using size_type = size_t;
    using value_type = T;
    using edge_value_type = EdgeValueT;

private:
    using node_edges_type = map<size_type, EdgeValueT>;
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
        node_edges_type edges;
        Color color;
        int distance;
        size_type parent;
        size_type time_discovered, time_finished;
        Node(T = 0);
        Node(const Node &) = default;
    };
    vector<Node> nodes;

public:
    using const_iterator = typename vector<Node>::const_iterator;
    using const_reverse_iterator = typename vector<Node>::const_reverse_iterator;
    using iterator = typename vector<Node>::iterator;
    using reverse_iterator = typename vector<Node>::reverse_iterator;

    constexpr static size_type npos = numeric_limits<size_type>::max();

    const Node &operator[](const size_type index) const;
    const Node &operator[](const size_type index);

    size_type root;
    size_type graph_order;

    Graph(size_type __graph_order = 0,size_type __root = 0);
    Graph(const Graph &) = default;

    void build(size_type __n , size_type __root = 0);
    void update_value(size_type index, value_type val);
    void add_directed_edge(size_type u_i, size_type v_i, EdgeValueT = 1);
    void add_undirected_edge(size_type u_i, size_type v_i, EdgeValueT = 1);
    void bfs(size_type = npos);
    void dfs(size_type = npos);

    iterator begin();
    iterator end();
    iterator begin() const;
    iterator end() const;
    const_iterator cbegin() const;
    const_iterator cend() const;
    const_reverse_iterator rbegin() const;
    const reverse_iterator rend() const;
};

template <class T, class EdgeValueT>
constexpr typename Graph<T, EdgeValueT>::size_type Graph<T, EdgeValueT>::npos;

template <class T, class EdgeValue>
Graph<T, EdgeValue>::Node::Node(T __value) : value(__value) {}

template <class T, class EdgeValueT>
inline Graph<T, EdgeValueT>::Graph(size_type __graph_order,size_type __root) : graph_order(__graph_order) , root(__root)
{
    if (__graph_order)
        build(__graph_order,__root);
}

template <class T, class EdgeValueT>
inline void Graph<T, EdgeValueT>::build(size_type __graph_order,size_type __root)
{
    nodes.clear();
    nodes.resize(__graph_order);
    graph_order = __graph_order;
    root = __root;
}

template <class T, class EdgeValueT>
inline void Graph<T, EdgeValueT>::update_value(size_type index, value_type __value)
{
    nodes[index].value = __value;
}

template <class T, class EdgeValueT>
inline void Graph<T, EdgeValueT>::add_directed_edge(size_type u_i, size_type v_i, EdgeValueT weight)
{
    nodes[u_i].edges[v_i] = weight;
}

template <class T, class EdgeValueT>
inline void Graph<T, EdgeValueT>::add_undirected_edge(size_type u_i, size_type v_i, EdgeValueT weight)
{
    nodes[u_i].edges[v_i] = weight;
    nodes[v_i].edges[u_i] = weight;
}

template <class T, class EdgeValueT>
void Graph<T, EdgeValueT>::bfs(size_type source)
{
    if (source == npos)
        source = root;
    for (size_type i = 0; i < graph_order; ++i)
    {
        nodes[i].distance = -1;
        nodes[i].parent = npos;
        nodes[i].color = WHITE;
    }
    nodes[source].color = GREY;
    nodes[source].distance = 0;
    nodes[source].parent = source;
    queue<size_type> node_queue;
    node_queue.push(source);
    while (!node_queue.empty())
    {
        size_type u_i = node_queue.front();
        Node &u = nodes[u_i];
        for (auto edge : nodes[u_i].edges)
        {
            size_type v_i = edge.first;
            Node &v = nodes[v_i];
            if (v.color == WHITE)
            {
                v.color = GREY;
                v.parent = u_i;
                v.distance = u.distance + 1;
                node_queue.push(v_i);
            }
        }
        u.color = BLACK;
        clog << u_i << " ";
        node_queue.pop();
    }
}

template <class T, class EdgeValueT>
void Graph<T, EdgeValueT>::dfs(size_type source)
{
    if (source == npos)
        source = root;
    for (auto &u : nodes)
    {
        u.color = WHITE;
        u.parent = npos;
    }
    size_type time = 0;
    stack<size_type> node_stack;
    nodes[source].parent = source;
    nodes[source].color = GREY;
    node_stack.push(source);
    while (!node_stack.empty())
    {
        size_type u_i = node_stack.top();
        Node &u = nodes[u_i];
        node_stack.pop();
        clog<<u_i<<" ";
        for (auto edge : u.edges)
        {
            size_type v_i = edge.first;
            Node &v = nodes[v_i];
            if (v.color == WHITE)
            {
                v.parent = u_i;
                v.color = GREY;
                node_stack.push(v_i);
            }
        }
        u.color = BLACK;
    }
}

template <class T, class EdgeValueT>
inline const typename Graph<T, EdgeValueT>::Node &Graph<T, EdgeValueT>::operator[](const size_type index)
{
    return nodes[index];
}

template <class T, class EdgeValueT>
inline const typename Graph<T, EdgeValueT>::Node &Graph<T, EdgeValueT>::operator[](const size_type index) const
{
    return nodes[index];
}

template <class T, class EdgeValueT>
inline typename Graph<T, EdgeValueT>::const_iterator Graph<T, EdgeValueT>::cbegin() const
{
    return nodes.cbegin();
}

template <class T, class EdgeValueT>
inline typename Graph<T, EdgeValueT>::const_iterator Graph<T, EdgeValueT>::cend() const
{
    return nodes.cend();
}

template <class T, class EdgeValueT>
inline typename Graph<T, EdgeValueT>::iterator Graph<T, EdgeValueT>::begin()
{
    return nodes.begin();
}

template <class T, class EdgeValueT>
inline typename Graph<T, EdgeValueT>::iterator Graph<T, EdgeValueT>::end()
{
    return nodes.end();
}

#endif

//To see basic implementation of this class , see graph_dfs_bfs_example.cpp file in the same directory