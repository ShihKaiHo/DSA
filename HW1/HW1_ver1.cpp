#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>

using namespace std;
//void straightforward(int ,int* ,int**);
int* max_member(int*,int*);
void make_lookup_table(int*,int**,int,int);
void find_max(int**,int**,int,int,int);
//////////////////////////////////////////////
int main(){
int n,m;
cin>>n>>m;
int* input = new int[n];

int** query = new int*[m];
for(int i = 0; i < m; i++)
{
     query[i] = new int[2];
}
///////////////////////////////////////////
for(int i=0; i<n;i++)
{
    cin>>input[i];
};
for(int i=0;i<m;i++)
{
    cin>>query[i][0]>>query[i][1];
}
////////////////////////////////////////////////
int p;
p=(int)floor(log2(double(n)))+1; //columns of lookup table

int** lookup = new int*[n];
for(int i = 0; i < n; i++)
{
     lookup[i] = new int[p];
}

make_lookup_table(input,lookup,n,p);
for(int i=0;i<n;i++)
{
    for(int j=0;j<p;j++)
    {
        cout<<lookup[i][j]<<' ';
    }
    cout<<'\n';
}
find_max(query,lookup,n,m,p);

delete [] input;
for(int i = 0; i < m; i++)
{
    delete [] query[i];
}
delete [] query;

for(int i = 0; i < n; i++)
{
    delete [] lookup[i];
}
delete [] lookup;


return 0;
}
////////////////////////////////////////////////////////////////////////////////////
int* max_member(int* first,int* last)
{
    if (first==last)
    {
        return last;
    }
    int* largest=first;
    while (first!=last)
    {
        first++;
        if (max(*first,*largest)==*first)
            largest=first;
        else
            continue;
    }
    return largest;
}


void make_lookup_table(int* input, int**lookup,int n,int p)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<p;j++)
        {
            if(i+(int)pow(2,j)-1<n)
                lookup[i][j]=*max_member(input+i,input+i+int(pow(2,j))-1);
           // else
               // lookup[i][j]=-1;
        }
    }
}
void find_max(int** query,int** lookup,int n ,int m,int p)
{
    for(int i=0;i<m;i++)
    {
        int len=query[i][1]-query[i][0]+1;
        cout<<max(lookup[query[i][0]-1][(int)log2(len)],lookup[query[i][1]-1-(int) pow(2,(int)log2(len))+1][(int)log2(len)])<<'\n';
    }
}

