#include <cstdio>
#include <iostream>
#include <unordered_map>
using namespace std;
bool matrix[1000][1000];

unordered_map<int,bool> is_calcualted;

int hash_table(int& x,int& y,int& dimension)
{
    return (x<<20)+(y<<10)+(dimension);
}

int check_full(int& x,int& y,int& dimension)
{
    int a=y+dimension;
    int b=x+dimension;
    for(int i=y;i<a;i++)
    {
        for(int j=x;j<b;j++)
            if(matrix[i][j]==0)
                return 0;
    }
    return 1;
}


int D(int x,int y,int dimension)
{
    if(is_calcualted.find(hash_table(x,y,dimension))!=is_calcualted.end())
        return 0;
    is_calcualted[hash_table(x,y,dimension)]=true;
    if(dimension==1)
    {
        if(matrix[y][x]==1)
            return 1;
        else
            return 0;
    }

    return check_full(x,y,dimension)+D(x,y,dimension-1)+D(x,y+1,dimension-1)+D(x+1,y,dimension-1)+D(x+1,y+1,dimension-1);
}
int main()
{
    int n;
    scanf("%d",&n);
    int dimension;
    char temp[1000];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&dimension);
        for(int j=0;j<dimension;j++)
        {
            scanf("%s",temp);
            for(int k=0;k<dimension;k++)
            {
                matrix[j][k]=temp[k]-48;
            }
        }
        printf("%d\n",D(0,0,dimension));
        is_calcualted.clear();
    }
    return 0;
}
