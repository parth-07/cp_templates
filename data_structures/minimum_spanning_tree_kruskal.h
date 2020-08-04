#ifndef MINIMUM_SPANNING_TREE_KRUSKAL_H
#define MINIMUM_SPANNING_TREE_KRUSKAL_H
#include <bits/stdc++.h>
#include "disjoint_set_union.h"
#include "graph_dfs_bfs.h"

using std::pair;
using std::set;

template <typename GraphT>
GraphT mst_kruskal(const GraphT &graph)
{
	using size_type = typename GraphT::size_type;
	using edges_type = set<pair<typename GraphT::edge_value_type, pair<size_type, size_type> > >;
	edges_type all_edges;
	DisjointSets<size_type> dsu;

	for (unsigned i = 0; i < graph.nodes.size(); ++i)
	{
		dsu.make_set(i);
		for (auto edge : graph[i])
		{
			all_edges.insert(edge.second, {i, edge.first});
		}
	}

	GraphT mst(graph.nodes.size());

	for (auto edge : all_edges)
	{
		size_type u_i = edge.second.first;
		size_type v_i = edge.second.second;
		if(!dsu.in_same_set(u_i,v_i))
		{
			mst.add_undirected_edge(u_i,v_i,edge.first);
			dsu.join(u_i,v_i);
		}
	}
	return mst;
}

#endif
//To see example of it's implementation , see minimum_spanning_tree_kruskal_example.cpp file in the same directory