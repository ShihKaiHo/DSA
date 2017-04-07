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

unsigned long long Map_element(unsigned long long& Map,int& m,int& n)
{
    return (Map>>(4*m+n)) & 15;
}


void print_map_formal(unsigned long long& Map)
{
    int counter=0;
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            if((Map>>counter & 15)!=0)
                printf("%u ",(1<<(Map>>counter & 15)));
            else
                printf("%u ",0);
            counter+=4;
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

bool is_dead(unsigned long long& Map)
{
    for(int i=0;i<16;i++)
    {
        if(((Map>>i*4) & 15)==0)
            return false;
    }
    unsigned long long compare=0;
    compare=Map ^ (Map<<4);
    for(int i=0;i<15;i++)
    {
        if(i%4!=3)
        {
            if((compare>>(60-(i>>2)) & 15 )==0)
            {
                return false;
            }
        }
    }
    compare=Map ^ (Map<<16);
    for(int i=0;i<12;i++)
    {
        /*
        cout<<"i is ...";
        print(i)
        print("diff bit is ...")
        print((compare>>(60-(i>>2))&15))
        */
        if((compare>>(60-(i>>2)) & 15 ) == 0)
        {
            return false;
        }
    }
    return true;
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
            Map |=(unsigned long long)log2(buffer[i])<<(i<<2);
        }
    }
}

bool check_movablilty(unsigned long long& Map,int _move)
{
    switch(_move)
    {
        case 0:
            {
                for(unsigned long long i=0;i<16;i++)
                {
                    if(i%4!=3)
                    {
                        if(Map_element(Map,i/4,i%4)!=0)
                        {
                            if((Map_element(Map,i/4,i%4)==Map_element(Map,i/4,i%4+1))||Map_element(Map,i/4,i%4+1)==0)
                                return true;
                        }
                    }

                }
                return false;
            }

        case 1:
            {
                for(unsigned long long i=0;i<12;i++)
                {
                    if(Map_element(Map,i/4,i%4)!=0)
                    {
                        if((Map_element(Map,i/4,i%4)==Map_element(Map,i/4+1,i%4))||Map_element(Map,i/4+1,i%4)==0)
                            return true;
                    }
                }
                return false;
            }

        case 2:
            {
                for(unsigned long long i=1;i<16;i++)
                {
                    if(i%4!=0)
                    {
                        if(Map_element(Map,i/4,i%4)!=0)
                        {
                            if((Map_element(Map,i/4,i%4)==Map_element(Map,i/4,i%4-1))||Map_element(Map,i/4,i%4-1)==0)
                                return true;
                        }
                    }
                }
                return false;
            }
        case 3:
            {
                for(unsigned long long i=4;i<16;i++)
                {
                    if(Map_element(Map,i/4,i%4)!=0)
                    {
                        if((Map_element(Map,i/4,i%4)==Map_element(Map,i/4-1,i%4))||Map_element(Map,i/4-1,i%4)==0)
                            return true;
                    }
                }
                return false;
            }
    }
    return false;
}

int main()
{
    unsigned long long Map=0;
    int n;
    scanf("%d",&n);
    set_Map(Map)
    print_map_formal(Map);
    return 0;
}





void print_map(unsigned long long& Map)
{
    int counter=0;
    for(int i=0;i<4;i++)
    {
        cout<<setw(4);
        for(int j=0;j<4;j++)
        {
            if((Map>>counter & 15)!=0)
                cout<<(1<<(Map>>counter & 15))<<setw(5);
            else
                cout<<"_"<<setw(5);
            counter+=4;
        }
        cout<<'\n';
    }
    cout<<'\n';
}

void manual_test(unsigned long long& Map)
{
    char input;
    while(cin>>input)
    {
        switch(input)
        {
            case 'd':
                Map=nextMap(Map, 0);
                print_map(Map);
                break;
            case 's':
                Map=nextMap(Map, 1);
                print_map(Map);
                break;
            case 'a':
                Map=nextMap(Map, 2);
                print_map(Map);
                break;
            case 'w':
                Map=nextMap(Map, 3);
                print_map(Map);
                break;
        }
        if (input=='e')
            break;
        cout<<"check d...";
        print(check_movablilty(Map,0))
        cout<<"check s...";
        print(check_movablilty(Map,1))
        cout<<"check a...";
        print(check_movablilty(Map,2))
        cout<<"check w...";
        print(check_movablilty(Map,3))
    }
}
