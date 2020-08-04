#include<bits/stdc++.h>
#include "disjoint_set_union.h"

using namespace std;

#define show(x) cout<<#x" = "<<x<<endl;

int main()
{
	DisjointSets<int> dsu;
	dsu.make_set(1);
	dsu.make_set(2);
	dsu.make_set(3);
	dsu.make_set(4);
	dsu.make_set(7);
	dsu.make_set(9);

	dsu.join(1,2);
	dsu.join(3,4);
	dsu.join(7,9);
	dsu.join(7,4);

	show(dsu.in_same_set(1,2));
	show(dsu.in_same_set(1,3));
	show(dsu.in_same_set(4,7));
}