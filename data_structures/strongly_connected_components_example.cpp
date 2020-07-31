#include<bits/stdc++.h>
#include "strongly_connected_components.h"

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
    clog<<name<<" = "<<value<<" | ";
    describe(var_names,args...);
}

template <typename T, typename S, typename G, typename... R,
template <typename, typename, typename, typename...> class M>
ostream &operator<<(ostream &os, const M<T, S, G, R...> &v) {
    os << "{";
    for (auto i : v) {
        os << i << ',';
    }
    os << "\b}";
    return os;
}
template <class T, class V>
ostream &operator<<(ostream &os, const pair<T, V> &p) {
    os << p.first << ": " << p.second;
    return os;
}
template <typename S, typename T, template <typename, typename...> class V>
ostream &operator<<(ostream &os, const V<S, T> &m) {
    os << "[";
// show((func(S,T...)));
    for (auto i : m) {
        os << i << ",";
    }
    os << "\b]";
    return os;
}
ostream &operator<<(ostream &os, string s) {
    for (auto i : s) os << i;
    return os;
}

int main()
{
    int sz = 9;
    Graph<int> graph(sz);
    for(unsigned i=1;i<=sz;++i)
    {
        graph.update_value(i-1,i);
    }
    graph.add_directed_edge(0,1);
    graph.add_directed_edge(0,2);
    graph.add_directed_edge(0,3);
    graph.add_directed_edge(2,4);
    graph.add_directed_edge(2,5);
    graph.add_directed_edge(3,6);
    graph.add_directed_edge(6,7);
    graph.add_directed_edge(7,8);

    graph.add_directed_edge(1,2);
    graph.add_directed_edge(2,0);

    graph.add_directed_edge(8,3);

    auto comps = get_strongly_connected_comps(graph);
    for(auto comp : comps)
    {
        show(comp);
    }

}