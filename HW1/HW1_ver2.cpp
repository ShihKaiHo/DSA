#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <ctime>
using namespace std;
int* max_member(int*,int*);
//make new array
int main(){
clock_t start, stop;
//start = clock();
int n,m;
cin>>n>>m;
int p;
p=(int)floor(log2(double(n)))+1; //columns of lookup table
int** input = new int*[p];
for(int i = 0; i < p; i++)
{
    input[i] = new int[n];
}

int** query = new int*[m];
for(int i = 0; i < m; i++)
{
     query[i] = new int[2];
}
//input data
for(int i=0; i<n;i++)
{
    cin>>input[0][i];
}
for(int i=0;i<m;i++)
{
    cin>>query[i][0]>>query[i][1];
}
//calculate lookup data
for(int j=1;j<p;j++)
{
        for(int i=0;i<n;i++)
        {
            if(i<n-pow(2,j)+1)
            {
                input[j][i]=max(input[j-1][i],input[j-1][i+(int)pow(2,j-1)]);
            }
            else
                break;
        }
}
//output query answer
for(int i=0;i<m;i++)
{
    int len=query[i][1]-query[i][0]+1;
    if(len==0)
    {
        cout<<input[query[i][0]-1];
    }
    else
        cout<<max(input[(int)log2(len)][query[i][0]-1],input[(int)log2(len)][query[i][1]-1-(int) pow(2,(int)log2(len))+1])<<'\n';
}


for(int i = 0; i < m; i++)
{
    delete [] query[i];
}
delete [] query;

for(int i = 0; i < p; i++)
{
    delete [] input[i];
}
delete [] input;

//stop = clock();
//cout << double(stop - start) ;
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

