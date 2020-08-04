#ifndef EULER_WALK_H
#define EULER_WALK_H

#include "tree.h"

using std::vector;


template <class TreeT>
class EulerWalk
{
public:
	using size_type = typename TreeT::size_type;
	struct Node
	{
		size_type t_in, t_out;
		Node(size_type __t_in = TreeT::npos,size_type __t_out = TreeT::npos) : t_in(__t_in), t_out(__t_out) {}
		Node(const Node &) = default;
	};
	vector<size_type> walk;
	vector<Node> nodes;
	EulerWalk(TreeT& __tree);

private:
	void euler_tour(size_type bud, size_type parent);
	TreeT& tree;
};

template<class TreeT>
EulerWalk<TreeT>::EulerWalk(TreeT& __tree) : nodes(vector<Node>(__tree.nodes.size())) , tree(__tree)
{
	tree.reset_colors();
	euler_tour(tree.root,TreeT::npos);
}

template<class TreeT>
void EulerWalk<TreeT>::euler_tour(size_type bud,size_type parent)
{
	Node& u = nodes[bud];
	u.t_in = walk.size();
	walk.push_back(bud);
	for(auto edge : tree[bud].edges)
	{
		size_type v_i = edge.first;
		if(v_i == parent)
			continue;
		euler_tour(v_i,bud);
	}
	u.t_out=walk.size();
	walk.push_back(bud);
}
#endif
//To see example of it's implementation , see euler_walk_example.cpp file in the same directory