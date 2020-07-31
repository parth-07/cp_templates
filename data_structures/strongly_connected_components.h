#ifndef STRONGLY_CONNECTED_COMPONENETS_H
#define STRONGLY_CONNECTED_COMPONENTS_H
#include <bits/stdc++.h>
#include "graph_dfs_bfs.h"

using std::set;

typedef vector<unsigned> uvec;
typedef vector<uvec> ugrid;

/* helper functions */
template<typename GraphT>
auto get_reverse_graph(const GraphT &graph);

template<typename GraphT>
void dfs_get_order_base(GraphT &graph,unsigned source,stack<typename GraphT::size_type> &order);

template<typename GraphT>
auto dfs_get_order(GraphT &graph );

template<typename GraphT>
void dfs_get_comp(GraphT &graph , unsigned source , uvec &comp );
/* helper functions end */

/* real deal - only function you need to know about */
template <typename GraphT>
ugrid get_strongly_connected_comps(GraphT &graph);


template <typename GraphT>
auto get_reverse_graph(const GraphT &graph)
{
    using size_type = typename GraphT::size_type;

    GraphT r_graph = GraphT(graph.nodes.size());
    for (size_type u_i = 0; u_i < graph.nodes.size(); ++u_i)
    {
        for (auto edge : graph[u_i].edges)
        {
            size_type v_i = edge.first;
            r_graph.add_directed_edge(v_i, u_i);
        }
    }
    return r_graph;
}

template<typename GraphT>
void dfs_get_order_base(GraphT &graph,unsigned source,stack<typename GraphT::size_type> &order)
{
    using size_type = typename GraphT::size_type;
    graph[source].color = GraphT::GREY;
    for(auto edge : graph[source].edges)
    {
        size_type v_i = edge.first;
        if(graph[v_i].color == GraphT::WHITE)
        {
            dfs_get_order_base(graph,v_i,order);
        }
    }
    graph[source].color = GraphT::BLACK;
    order.push(source);
}

template<typename GraphT>
auto dfs_get_order(GraphT &graph)
{
    using size_type = typename GraphT::size_type;
    graph.reset_color();
    stack<size_type> order;
    for(size_type i=0;i<graph.nodes.size();++i)
    {
        if(graph[i].color == GraphT::WHITE)
        {
            dfs_get_order_base(graph,i,order);
        }
    }
    return order;
}



template<typename GraphT>
void dfs_get_comp(GraphT &graph , unsigned source , uvec &comp )
{
    using size_type = typename GraphT::size_type;
    using Node = typename GraphT::Node;

    graph[source].color = GraphT::GREY;
    comp.push_back(source);

    for(auto edge : graph[source].edges)
    {
        size_type v_i = edge.first;
        Node &v = graph.nodes[v_i];
        if(v.color == GraphT::WHITE)
        {
            dfs_get_comp(graph,v_i,comp);
        }
    }
    graph[source].color = GraphT::BLACK;
}

template <typename GraphT>
ugrid get_strongly_connected_comps(GraphT &graph)
{
    using size_type = typename GraphT::size_type;

    GraphT r_graph = get_reverse_graph(graph);
    auto order = dfs_get_order(graph);
    ugrid strong_components;

    while(! order.empty())
    {
        auto u_i = order.top();
        order.pop();
        if(r_graph[u_i].color == GraphT::WHITE)
        {
            uvec comp;
            dfs_get_comp(r_graph,u_i,comp);
            strong_components.push_back(comp);
        }
    }
    return strong_components;
}

#endif
//To see example of it's implementations , see stronly_connected_components_example.cpp file in the same directory