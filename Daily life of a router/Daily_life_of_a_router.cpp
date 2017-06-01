#include <cstdio>
#include <iostream>
#include <bitset>
#include <stdlib.h>
using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    int operation;
    char temp;
    string part_IP;
    bitset<32> IP;
    scanf("%d",&operation);
    temp=getc(stdin); //read out the space

    for(int i=3;i>=0;i--)
    {
        temp=getc(stdin);
        part_IP+=temp;
        while((temp=getc(stdin))!='.' )
        {
            if(temp=='/')
                break;
            part_IP+=temp;
        }
        IP |= bitset<32>(atoi(part_IP.c_str()))<<(i*8);
        cout<<IP<<endl;
        part_IP.clear();
    }




    return 0;
}
