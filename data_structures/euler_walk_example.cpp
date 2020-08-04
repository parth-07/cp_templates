#include<bits/stdc++.h>
#include "euler_walk.h"

using namespace std;

int main()
{
	Tree<int> tree(9);
	tree.add_undirected_edge(0,1);
	tree.add_undirected_edge(0,2);
	tree.add_undirected_edge(1,3);
	tree.add_undirected_edge(1,4);
	tree.add_undirected_edge(1,5);
	tree.add_undirected_edge(2,6);
	tree.add_undirected_edge(2,7);
	tree.add_undirected_edge(6,8);

	EulerWalk<decltype(tree)> euler(tree);
	for(auto item : euler.walk)
		cout<<item<<" ";
	cout<<endl;
	cout<<euler.nodes[0].t_in<<" "<<euler.nodes[0].t_out<<endl;
	cout<<euler.nodes[3].t_in<<" "<<euler.nodes[3].t_out<<endl;
	cout<<euler.nodes[1].t_in<<" "<<euler.nodes[1].t_out<<endl;

}