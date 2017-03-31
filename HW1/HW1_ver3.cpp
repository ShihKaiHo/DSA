#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
using namespace std;

int construct_tree(int*,int,int,int);

struct query
{
    int L;
    int R;
};
int print_max(int*,query,int=0,int=0,int=0);
int main(){
int n,m;
cin>>n>>m;
int* tree=new int[(2<<(31-__builtin_clz(n)))-1];
query* q=new query[m];
//input data
int low=0;
int high=n-1;
int pos=0;
tree[pos]=construct_tree(tree,low,high,pos);
for(int i=0;i<m;i++)
{
    cin>>q[i].L>>q[i].R;
}
for(int i=0;i<m;i++)
{
    q[i].L--;
    q[i].R--;
    cout<<print_max(tree,q[i],pos,low,high)<<'\n';
}






delete [] q;
delete [] tree;

return 0;
}
////////////////////////////////////////////////////////////////////////////////
int construct_tree(int* tree,int low,int high,int pos)
{
    if(low==high)
    {
        cin>>tree[pos];
        return tree[pos];
    }

    int mid = (low+high)/2;
    tree[pos]=max(construct_tree(tree,mid+1,high,2*pos+2), construct_tree(tree,low,mid,2*pos+1));
    return tree[pos];
}

int print_max(int* tree, query q,int pos,int low,int high)
{
    if (q.L<=low&&high<=q.R)
        return tree[pos];
    if (high<q.L||low>q.R)
        return -1;
    int mid=(low+high)/2;
    return max(print_max(tree,q,2*pos+1,low,mid),print_max(tree,q,2*pos+2,mid+1,high));
}
