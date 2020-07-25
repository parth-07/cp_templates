#include<bits/stdc++.h>
#include "sparse_table.h"

using namespace std;


int main()
{
    vector<int> a ={1,2,3,4,5,6,7,8,9,10};
    SparseTable<int> sparse(a,[](int a,int b){return a+b;},0);
    cout<<sparse.query(2,5)<<endl;
    cout<<sparse.query(3,5)<<endl;
    SparseTable<int> sparse_rmq(a,[](int a,int b){return min(a,b);},numeric_limits<int>::max(),1);
    // sparse_rmq.display_static_variables();
    cout<<sparse_rmq.query(2,5)<<endl;
    cout<<sparse_rmq.query(3,5)<<endl;
}