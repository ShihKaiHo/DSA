#include <vector>
#include <iostream>
using namespace std;
int main()
{
    double s=126;
    int table[25]={0};
    int temp;
    for(int l=1;l<=6;l++)
    {
        for(int k=1;k<=6;k++)
        {
            temp=k+l;
            table[temp]++;
        }
    }
    for(int i=0;i<=24;i++)
    {
        cout<<table[i]<<',';
    }

    return 0;

}
