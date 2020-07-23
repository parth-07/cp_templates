#include<bits/stdc++.h>
#include "graph_dfs_bfs.h"

using namespace std;

int main()
{
    Graph<int> graph(9);
    
    graph.add_undirected_edge(0,3);
    graph.add_undirected_edge(0,5);
    graph.add_undirected_edge(1,2);
    graph.add_undirected_edge(1,3);
    graph.add_undirected_edge(1,6);
    graph.add_undirected_edge(2,4);
    graph.add_undirected_edge(2,8);
    graph.add_undirected_edge(3,4);
    graph.add_undirected_edge(3,5);
    graph.add_undirected_edge(5,8);
    graph.add_undirected_edge(6,7);
    graph.add_undirected_edge(7,8);

    graph.bfs();
    cout<<endl;
    graph.dfs();

}