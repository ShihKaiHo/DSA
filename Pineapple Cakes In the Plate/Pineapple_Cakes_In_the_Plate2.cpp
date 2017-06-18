#include <cstdio>
#include <iostream>

using namespace std;

int matrixA[1000][1000];
int matrixB[1000][1000];

int min(int a, int b, int c)
{
  int m = a;
  if (m > b)
    m = b;
  if (m > c)
    m = c;
  return m;
}

int main()
{
    int n;
    scanf("%d",&n);
    int dimension;
    int buffer=0;
    char temp[1000];

    for(int i=0;i<n;i++)
    {
        scanf("%d",&dimension);
        for(int j=0;j<dimension;j++)
        {
            scanf("%s",temp);
            for(int k=0;k<dimension;k++)
            {
                matrixA[j][k]=(temp[k]-48);
            }
        }
        for(int i = 0; i < dimension; i++)
            matrixB[i][0] = matrixA[i][0];
        for(int i = 0; i < dimension; i++)
            matrixB[0][i] = matrixA[0][i];
        for(int i = 1; i < dimension; i++)
        {
            for(int j = 1; j < dimension; j++)
            {
              if(matrixA[i][j] == 1)
                matrixB[i][j] = min(matrixB[i][j-1], matrixB[i-1][j], matrixB[i-1][j-1]) + 1;
              else
                matrixB[i][j] = 0;
            }
        }
        for(int i=0;i<dimension;i++)
        {
            for(int j=0;j<dimension;j++)
            {
                //printf("%d",matrixB[i][j]);
                buffer+=matrixB[i][j];
            }
            //printf("\n");

        }

        printf("%d\n",buffer);
        buffer=0;
    }
    return 0;
}
