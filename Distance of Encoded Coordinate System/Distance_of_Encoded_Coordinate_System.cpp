#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    int distence;
    string P;
    for(int i=0;i<n;i++)
    {
        cin>>distence;
        cin>>P;
        bool can_reach=1;
        for(int j=0;j<distence;j++)
        {
            if(!next_permutation(P.begin(),P.end()))
            {
                can_reach=0;
                break;
            }
        }
        if(can_reach)
            cout<<P<<"\n";
        else
            cout<<"NOPE!!\n";
    }
    return 0;
}
