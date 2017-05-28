#include "game.h"
#include <unordered_map>
double D(int, int, double);
using namespace std;
typedef unordered_map< int , unordered_map<int, unordered_map<double,double> > > three_d_map;
static three_d_map table;
int main()
{
    int p=4;
    int q=4;
    double s=0;
    PRINT(D(p,q,s))
    return 0;
}

double D(int p, int q, double s)
{
    if(s>150)
        return table[p][q][s]=0;
    if(p==0 && q==0)
        return s;
    else if(p==0)
        return (D(p,q-1,s+1)+D(p,q-1,s+2)+D(p,q-1,s+3)+D(p,q-1,s+4)+D(p,q-1,s+5)+D(p,q-1,s+6))/6.0;
    else if(q==0)
        return (D(p-1,q,s+10)+D(p-1,q,s+20)+D(p-1,q,s+30)+D(p-1,q,s+40)+D(p-1,q,s+50)+D(p-1,q,s+60))/6.0;
    return (MAX(D(p-1,q,s+10),D(p,q-1,s+1))
            +MAX(D(p-1,q,s+20),D(p,q-1,s+2))
            +MAX(D(p-1,q,s+30),D(p,q-1,s+3))
            +MAX(D(p-1,q,s+40),D(p,q-1,s+4))
            +MAX(D(p-1,q,s+50),D(p,q-1,s+5))
            +MAX(D(p-1,q,s+60),D(p,q-1,s+6)))/6.0;
}
