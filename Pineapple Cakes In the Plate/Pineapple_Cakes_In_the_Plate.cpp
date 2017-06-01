#include <cstdio>
#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<unsigned long long,int> is_calcualted;

unsigned long long hash_table(unsigned long long left,unsigned long long right,unsigned long long up, unsigned long long down)
{
    return (left<<30)+(right<<20)+(up<<10)+(down);
}

int check_full(bool** matrix,int& left,int& right,int& up, int& down)
{
    for(int i=up;i<down;i++)
    {
        for(int j=left;j<right;j++)
        {
            if(matrix[i][j]==0)
                return 0;
        }

    }
    return 1;
}

int full_matrix(int n)
{
    return n*(n+1)*(2*n+1)/6;
}

int D(bool** matrix,int left,int right,int up, int down)
{
    unsigned long long key=hash_table(left,right,up,down);
    if(is_calcualted.find(key)!=is_calcualted.end())
        return 0;
    is_calcualted[hash_table(left,right,up,down)]=true;
    if((right-left)==1)
    {
        if(matrix[left][up]==1)
            return 1;
        else
            return 0;
    }
    if(check_full(matrix,left,right,up,down))
        return full_matrix(right-left);
    else
        return D(matrix,left,right-1,up,down-1)+D(matrix,left+1,right,up,down-1)+D(matrix,left+1,right,up+1,down)+D(matrix,left,right-1,up+1,down);
}
int main()
{
    int n;
    scanf("%d",&n);
    int dimension;
    char temp[1000];

    bool** matrix=new bool*[1000];
    for(int i=0;i<1000;i++)
    {
        matrix[i]=new bool[1000];
    }

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
        printf("%d\n",D(matrix,0,dimension,0,dimension));
        is_calcualted.clear();
    }
    return 0;
}
