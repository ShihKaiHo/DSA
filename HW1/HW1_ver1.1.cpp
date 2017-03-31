#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>

using namespace std;
int* max_member(int*,int*);
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

int*** lookup = new int**[n];
for(int i = 0; i < n; i++)
{
     lookup[i] = new int*[p];
}

for(int i=0;i<n;i++)
{
    for(int j=0;j<p;j++)
    {
        if(i+(int)pow(2,j)-1<n)
            lookup[i][j]=*max_member(input+i,input+i+int(pow(2,j))-1);
    }
}
for(int i=0;i<m;i++)
{
    int len=query[i][1]-query[i][0]+1;
    cout<<max(lookup[query[i][0]-1][(int)log2(len)],lookup[query[i][1]-1-(int) pow(2,(int)log2(len))+1][(int)log2(len)])<<'\n';
}

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


