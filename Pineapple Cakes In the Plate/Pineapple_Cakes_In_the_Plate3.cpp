#include <cstdio>
#include <iostream>
#define MIN(x,y)	((x)<(y)?(x):(y))
#define MAX(x,y)	((x)>(y)?(x):(y))

using namespace std;

int matrixA[1000][1000];

bool is_full(int& x,int& y,int& n)
{
    for(int i=y;i<y+n;i++)
    {
        for(int j=x;j<x+n;j++)
            if(matrixA[y][x]==0)
                return 0;
    }
    return 1;
}

int main()
{
    int n;
    scanf("%d",&n);
    int dimension;
    int counter=0;
    char temp[1000];

    for(int i=0;i<n;i++)
    {
        scanf("%d",&dimension);
        for(int j=0;j<dimension;j++)
        {
            scanf("%s",temp);
            for(int k=0;k<dimension;k++)
            {
                matrixA[j][k]=temp[k]-48;
            }
        }
        for(int i=0;i<dimension;i++)
        {
            for(int j=0;j<dimension;j++)
            {
                int buff=MAX(i,j);
                for(int k=1;k<dimension-buff+1;k++)
                {
                    if(is_full(j,i,k))
                        counter++;
                    else
                        break;
                }

            }
        }
        printf("%d\n",counter);
        counter=0;
    }
    return 0;
}
