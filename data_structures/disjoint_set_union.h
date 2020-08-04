#ifndef DISJOINT_SET_UNION_H
#define DISJOING_SET_UNION_H
#include <bits/stdc++.h>

using std::map;

template <class T>
class DisjointSets
{
private:
    struct Node
    {
        T parent;
        unsigned rank;
        Node() = default;
        Node(T __parent) : parent(__parent) , rank(0) { }
    };
    using ds_map = map<T,Node> ;
    ds_map nodes;
    void link(const T &k1,const T &k2);
public :
    DisjointSets() = default;
    void make_set(const T &key) ;
    void join(const T &k1,const T &k2);
    T find_set(const T &key);
    bool in_same_set(const T &k1,const T &k2);
};

template<class T>
void DisjointSets<T>::make_set(const T &key)
{
    nodes.insert({key,Node(key)});
}

template<class T>
T DisjointSets<T>::find_set(const T &key)
{
    if(nodes[key].parent != key)
        nodes[key].parent = find_set(nodes[key].parent);
    return nodes[key].parent;
}

template<class T>
void DisjointSets<T>::link(const T &k1,const T &k2)
{
    Node &u = nodes[k1];
    Node &v = nodes[k2];
    if(u.rank > v.rank)
        v.parent = k1;
    else
    {
        u.parent = k2;
        if(u.rank == v.rank)
            v.rank+=1;
    }
    
}

template<class T>
void DisjointSets<T>::join(const T &k1,const T &k2)
{
    link(find_set(k1),find_set(k2));
}

template<class T>
bool DisjointSets<T>::in_same_set(const T &k1,const T &k2)
{
    return find_set(k1)==find_set(k2);
}

#endif
//To see example of it's implementation , see disjoing_set_union_example.cpp in the same directory