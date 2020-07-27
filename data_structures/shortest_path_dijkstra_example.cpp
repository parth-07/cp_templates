#include<bits/stdc++.h>
#include "shortest_path_dijkstra.h"

using namespace std;


#define show(args...) describe(#args,args)
template<typename T>
void describe(string var_name,T value)
{
    clog<<var_name<<" = "<<value<<"\n";
}

template<typename T,typename... Args>
void describe(string var_names,T value,Args... args)
{
    string::size_type pos = var_names.find(',');
    string name = var_names.substr(0,pos);
    var_names = var_names.substr(pos+1);
    clog<<name<<" = "<<value<<" ";
    describe(var_names,args...);
}

int main()
{
    int n = 9;
    Graph<int,int> graph(n);
    graph.add_undirected_edge(0,1);
    graph.add_undirected_edge(0,2);
    graph.add_undirected_edge(0,3);
    graph.add_undirected_edge(1,4);
    graph.add_undirected_edge(1,5);
    graph.add_undirected_edge(1,6);
    graph.add_undirected_edge(2,7);
    graph.add_undirected_edge(2,8);

    auto nodes_res = dijkstra(graph);

    for(unsigned i=0;i<n;++i)
    {
        show(i,nodes_res[i].parent);
        show(i,nodes_res[i].dist);
    }

    get_shortest_path_dijkstra(7, nodes_res);

}