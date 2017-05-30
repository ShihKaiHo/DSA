#include "game.h"
#include <unordered_map>
using namespace std;
int trans(int p,int q,int s)
{
    return ((s<<6)+(p<<3)+q);
}

unordered_map<int,double> hash_table;
double D(int, int, double);
using namespace std;
int main()
{
    PRINT(D(3,4,10))
    PRINT(D(2,4,30))
    PRINT(D(2,3,33))
    PRINT(D(1,3,73))
    PRINT(D(0,3,123))


    return 0;
}

double D(int p, int q, double s)
{
    int temp=trans(p,q,s);
    if(s>150)
    {
        if(hash_table.find(temp)==hash_table.end())
            hash_table[temp]=0.0;
        return 0;
    }
    else if(p==0 && q==0)
    {
        if(hash_table.find(temp)==hash_table.end())
            hash_table[temp]=s;
        return s;
    }
    else if(p==0)
    {
        if(hash_table.find(temp)==hash_table.end())
        {
            hash_table[temp]=0;
            for(int i=1;i<=6;i++){hash_table[temp]+=D(p,q-1,s+i)/6.0;}
        }
        return hash_table[temp];
    }
    else if(q==0)
    {
        if(hash_table.find(temp)==hash_table.end())
        {
            hash_table[temp]=0;
            for(int i=1;i<=6;i++){hash_table[temp]+=D(p-1,q,s+i*10)/6.0;}
        }
        return hash_table[temp];
    }
    else
    {
        if(hash_table.find(temp)==hash_table.end())
        {
            hash_table[temp]=0;
            for(int i=1;i<=6;i++){hash_table[temp]+=MAX(D(p-1,q,s+i*10),D(p,q-1,s+i))/6.0;}
        }
        return hash_table[temp];
    }
}
