#include <cstdio>
#include <iostream>
#include <vector>
#define MAX(x,y)	((x)>(y)?(x):(y))
#define MIN(x,y)	((x)<(y)?(x):(y))
using namespace std;
int* grape_box;
int** table;
int n;

int max_grape()
{
    int space;
    int ll, lr, rr, i, j;
    for (space = 0; space < n; space++)
    {
        for (i = 0, j = space; j < n; i++, j++)
        {
            ll = ((i+2) <= j) ? table[i+2][j] : 0;
            lr = ((i+1) <= (j-1)) ? table[i+1][j-1] : 0;
            rr = (i <= (j-2))? table[i][j-2]: 0;

            table[i][j] = MAX(grape_box[i] + MIN(ll, lr), grape_box[j] + MIN(lr, rr));
        }
    }
    return  table[0][n-1];
}

int main()
{
    scanf("%d", &n);
    table = new int*[n];
    for(int i=0;i<n;i++)
    {
        table[i] = new int[n];
    }
    grape_box = new int [n];





    int sum = 0;
    int temp;
    for(int i=0; i<n; i++)
    {
        scanf("%d", &temp);
        sum += temp;
        grape_box[i] = temp;
    }


    int first_max=max_grape();

    if(first_max >= sum/2)
    {
        printf("Y\n%d", 2*first_max - sum);
    }
    else
    {
        printf("N\n%d", sum - 2*first_max);
    }



    return 0;
}
