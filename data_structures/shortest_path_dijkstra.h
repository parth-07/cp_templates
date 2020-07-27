#ifndef SHORTEST_PATH_DIJKSTRA_H
#define SHORTEST_PATH_DIJKSTRA_H
#include "graph_dfs_bfs.h"

template<class size_type,class EdgeValueT>
struct dijkstra_node 
{
    size_type parent;
    EdgeValueT dist;
    dijkstra_node(size_type __parent,EdgeValueT __dist) : parent(__parent) , dist(__dist) { };
};

template<typename T,typename EdgeValueT>
using dijkstra_vec = vector<dijkstra_node<T,EdgeValueT> >;



template<class T,class EdgeValueT>
auto dijkstra(const Graph<T,EdgeValueT> graph,typename Graph<T,EdgeValueT>::size_type source = Graph<T,EdgeValueT>::npos)
{
    using std::set;
    using std::pair;
    using ll = long long int;
    using ds_graph = Graph<T,EdgeValueT>;
    using ds_dnode = dijkstra_node<typename ds_graph::size_type,typename ds_graph::edge_value_type>;
    using size_type = typename ds_graph::size_type;
    using edge_value_type = typename ds_graph::edge_value_type;
    using ds_pair = pair<edge_value_type,size_type>;
    using ds_set = set<ds_pair>;


    if(source == ds_graph::npos)
        source = graph.root;

    dijkstra_vec<size_type,edge_value_type> nodes_res(graph.graph_order,ds_dnode(ds_graph::npos,ds_graph::nweight));

    nodes_res[source].parent = source;
    nodes_res[source].dist = 0;

    ds_set queue;
    for(unsigned i=0;i<graph.graph_order;++i)
    {
        queue.insert({nodes_res[i].dist,i});
    }

    while(! queue.empty())
    {
        typename ds_set::iterator iter = queue.begin();
        unsigned u_i = iter->second;
        ds_dnode &u = nodes_res[u_i];
        queue.erase(iter);
        if(u.dist == ds_graph::nweight)
            break;
        for(auto edge : graph[u_i].edges)
        {
            edge_value_type temp_dist = u.dist + edge.second;
            if(temp_dist < nodes_res[edge.first].dist)
            {
                size_type v_i = edge.first;
                ds_dnode &v = nodes_res[v_i];
                queue.erase({v.dist,v_i});
                v.dist = temp_dist;
                v.parent = u_i;
                queue.insert({v.dist,v_i});
            }
        }
    }
    return nodes_res;
}


template<class S,class T>
auto get_shortest_path_dijkstra(S u_i,const T &nodes_res)
{
    vector<decltype(u_i)> path;
    while(nodes_res[u_i].parent != u_i)
    {
        path.push_back(u_i);
        u_i = nodes_res[u_i].parent;
    }
    return path;
}
#endif
//To see basic example of it's implementation , see shortest_path_dijkstra_example.cpp in the same directory