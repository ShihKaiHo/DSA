#include <cstdio>
#include <iostream>
using namespace std;
int tree[2048];

void print_inorder(int n)
{
    if(tree[2*n]==(-1) && tree[2*n+1]==(-1))
    {
        printf("%d ",tree[n]);
        return;
    }
    else if(tree[2*n+1]==(-1))
    {
        print_inorder(2*n);
        printf("%d ",tree[n]);
        return;
    }
    else if(tree[2*n]==(-1))
    {
        printf("%d ",tree[n]);
        print_inorder(2*n+1);
        return;
    }
    else
    {
        print_inorder(2*n);
        printf("%d ",tree[n]);
        print_inorder(2*n+1);
        return;
    }
}

int main()
{
    int n_query;
    scanf("%d",&n_query);
    int n_num;
    int buff;
    for(int i=0;i<2048;i++)
        tree[i]=(-1);

    for(int i=0;i<n_query;i++)
    {
        scanf("%d",&n_num);
        int special=0;
        for(int j=1;j<=n_num;j++)
        {
            scanf("%d",&buff);
            tree[j]=buff;
        }
        if(tree[1]==(-1))
        {
            printf("\n");
            for(int j=1;j<=n_num;j++)
            {
                tree[j]=(-1);
            }
            continue;
        }
        print_inorder(1);
        for(int j=1;j<=n_num;j++)
        {
            tree[j]=(-1);
        }
        if(i<(n_query-1))
            printf("\n");
    }
    return 0;
}
