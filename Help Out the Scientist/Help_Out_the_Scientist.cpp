#include <cstdio>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;
struct tree
{
    int ID;
    vector<tree*> child;
};
vector<int> preorder;
unordered_map<int,int> num_child;
queue<tree*> BFS;


void construct_tree(tree* parent,int& counter,int& counter2)
{
    parent->ID=preorder[counter];
    int temp=num_child[counter];
    for(int i=0;i<temp;i++)
    {
        counter++;
        tree* child=new tree;
        parent->child.push_back(child);
        construct_tree(child,counter,counter2);
    }
    if(counter2==preorder.size()-1)
        printf("%d",parent->ID);
    else
    {
        printf("%d ",parent->ID);
        counter2++;
    }
}

void print_layer_order(int& counter,int& _size )
{
    while(!BFS.empty())
    {
        tree* temp=BFS.front();
        BFS.pop();
        if(counter==_size-1)
            printf("%d",temp->ID);
        else
        {
            printf("%d ",temp->ID);
            counter++;
        }
        for(auto it=temp->child.begin();it!=temp->child.end();it++)
        {
            BFS.push(*it);
        }
    }
}

int main()
{
    int N, T,temp;
    scanf("%d %d",&N,&T);
    for(int i=0;i<N;i++)
    {
        tree temp_tree;
        tree Node;
        for(int j=0;j<T;j++)
        {
            scanf("%d",&temp);
            preorder.push_back(temp);
        }
        for(int j=0;j<T;j++)
        {
            scanf("%d",&temp);
            num_child[j]=temp;
        }
        int counter=0;
        int counter2=0;
        construct_tree(&Node,counter,counter2);
        printf("\n");
        BFS.push(&Node);
        counter=0;
        int _size=preorder.size();
        print_layer_order(counter,_size );
        printf("\n");
        preorder.clear();
        num_child.clear();
    }
    return 0;
}
