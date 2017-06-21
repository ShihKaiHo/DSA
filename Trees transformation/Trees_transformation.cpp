#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>
using namespace std;
vector<int> tree;
int H;
void print_preorder(int n)
{
    printf("%d ",tree[n]);
    if( n > ((1<<H-1)-1) )
    {
        return;
    }
    else if(tree[2*n] == -1 && tree[2*n+1]== -1 )
    {
        return;
    }
    else if(tree[2*n+1]== -1)
    {
        print_preorder(2*n);
        return;
    }
    else if(tree[2*n]== -1)
    {
        print_preorder(2*n+1);
        return;
    }
    else
    {
        print_preorder(2*n);
        print_preorder(2*n+1);
        return;
    }
    return;
}

void print_inorder(int n)
{
    if( n > ((1<<H-1)-1) )
    {
        printf(" %d",tree[n]);
        return;
    }
    if(tree[2*n] == -1 && tree[2*n+1]== -1 )
    {
        printf(" %d",tree[n]);
        return;
    }
    else if(tree[2*n+1] == -1)
    {
        print_inorder(2*n);
        printf(" %d",tree[n]);
        return;
    }
    else if(tree[2*n] == -1)
    {
        printf(" %d",tree[n]);
        print_inorder(2*n+1);
        return;
    }
    else
    {
        print_inorder(2*n);
        printf(" %d",tree[n]);
        print_inorder(2*n+1);
        return;
    }
    return;
}

void print_level_order()
{
    queue<int> level_order;
    level_order.push(1);
    int pos=1;
    while(!level_order.empty())
    {
        pos=level_order.front();
        level_order.pop();
        while(tree[pos] != -1)
        {
            printf("%d ",tree[pos]);
            if(pos > ((1<<H-1)-1) )
                break;
            else
            {
                if(tree[2*pos] != -1)
                    level_order.push(2*pos);
                pos=2*pos+1;
            }
        }
    }

    return;
}



int main()
{
    int buffer;
    scanf("%d",&H);
    while(H!=0)
    {
        tree.push_back(0);
        for(int i=0; i < ((1<<H) -1) ;i++)
        {
            scanf("%d",&buffer);
            tree.push_back(buffer);
        }
        buffer=1;
        printf("preorder: ");
        print_preorder(buffer);
        printf("\npostorder:");
        buffer=1;
        print_inorder(buffer);
        printf("\nlevel order: ");
        print_level_order();
        printf("\n");
        tree.clear();
        scanf("%d",&H);
        if(H!=0)
            printf("\n");
    }


    return 0;
}
