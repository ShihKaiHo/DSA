#include <iostream>
#include <bitset>
#include <iomanip>
#include <cstdio>
#define log2(a) (__builtin_ctzll(a))
#define print(a) cout<<a<<'\n';
using namespace std;
unsigned long long nextMap(unsigned long long Map, int action);

enum map_action {a, w, d, s};

void print_map(unsigned long long& );
void manual_test(unsigned long long& Map);

void print_map_formal(unsigned long long& Map)
{
    int counter=60;
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            if((Map>>counter & 15)!=0)
                printf("%u ",(1<<(Map>>counter & 15)));
            else
                printf("%u ",0);
            counter-=4;
        }
        printf("\n");
    }
}

bool is_win(unsigned long long& Map)
{
    for(int i=0;i<16;i++)
    {
        if(((Map>>i*4) & 15)==11)
            return true;
    }
    return false;
}

void set_Map(unsigned long long& Map)
{
    Map=0;
    unsigned long long buffer[16];
    for(unsigned long long i=0;i<16;i++)
    {
        if(scanf("%llu",buffer+i)){};
    }
    for(unsigned long long i=0;i<16;i++)
    {
        if(buffer[i]!=0)
        {
            Map |=log2(buffer[i])>>(60-(i<<2));
        }
    }
}

int main()
{
    int a;
    cin>>a;
    print(a)
    return 0;

}


