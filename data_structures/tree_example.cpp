#include<bits/stdc++.h>
#include "tree.h"

using namespace std;

int main()
{
    Tree<int> tree(9);
    tree.add_undirected_edge(0,1);
    tree.add_undirected_edge(0,2);
    tree.add_undirected_edge(0,3);
    tree.add_undirected_edge(2,4);
    tree.add_undirected_edge(2,5);
    tree.add_undirected_edge(3,6);
    tree.add_undirected_edge(6,7);
    tree.add_undirected_edge(7,8);

    tree.dfs();
    cout<<endl;
    tree.bfs();
    cout<<endl;
}