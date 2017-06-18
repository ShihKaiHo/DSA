#include <iostream>
#include <string>
#include <unordered_map>
#define MAX(x,y)	((x)>(y)?(x):(y))
#define MIN(x,y)	((x)<(y)?(x):(y))

using namespace std;
string buffer;
unordered_map<int,int> is_calculate;
int hash_fun(int pos,char up_bond)
{
    return (pos<<10)+up_bond;
}
int DP(int pos, char up_bond)
{
    if(is_calculate.find(hash_fun(pos,up_bond))!=is_calculate.end())
    {
        return is_calculate[hash_fun(pos,up_bond)];
    }
    if(up_bond=='a')
    {
        is_calculate[hash_fun(pos,up_bond)]=0;
        return 0;
    }
    if(pos==0)
    {
        if(up_bond>buffer[0])
        {
            is_calculate[hash_fun(pos,up_bond)]=1;
            return 1;
        }
        else
        {
            is_calculate[hash_fun(pos,up_bond)]=0;
            return 0;
        }
    }
    else if(up_bond>buffer[pos])
    {
        int temp = MAX(DP(pos-1, up_bond),DP(pos-1, buffer[pos])+1);
        is_calculate[hash_fun(pos,up_bond)]=temp;
        return temp;
    }
    else
    {
        int temp = DP(pos-1, up_bond);
        is_calculate[hash_fun(pos,up_bond)]=temp;
        return temp;
    }

}


int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>buffer;
        int length = buffer.length();
        cout<<DP(length-1, 'z'+1)<<"\n";
        is_calculate.clear();
    }
    return 0;
}
