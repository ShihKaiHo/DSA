#include <iostream>
#include <bitset>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <stack>
#define log2(a) (__builtin_ctzll(a))
#include <ctime>
#define print(a) cout<<a<<'\n';
using namespace std;
unsigned long long nextMap(unsigned long long Map, int action);

enum map_action {a, w, d, s};

void print_map(unsigned long long& );
void manual_test(unsigned long long& );
unsigned long long Map_element(unsigned long long& ,int ,int );
void print_map_formal(unsigned long long& );
bool is_win(unsigned long long& );
bool is_dead(unsigned long long& );
void set_Map(unsigned long long& );
bool check_movablilty(unsigned long long& ,int );
bool find_sol(unsigned long long,vector<int>&);
int main()
{
    clock_t t1, t2;
    t2=clock();
    unsigned long long Map=0;
    int n;
    if(scanf("%d",&n)){};
    for(int i=0;i<n;i++)
    {
        set_Map(Map);
        vector<int> sol;
        find_sol(Map,sol);
    }
    t1=clock();
    print("total time is ....")
    print((t1-t2)/double(CLOCKS_PER_SEC))
    return 0;
}

bool find_sol(unsigned long long Map,vector<int>& sol)
{
    if(is_win(Map))
    {
        printf("Action:\n");
        for (vector<int>::iterator it = sol.begin() ; it != sol.end(); ++it)
            printf("%d ",*it);
        printf("\n");
        printf("Final:\n");
        print_map_formal(Map);
        return true;
    }
    if(is_dead(Map))
    {
        if(!sol.empty())
        {
            sol.pop_back();
            return false;
        }
        else
        {
            printf("Action:\n-1\n");
            printf("Final:\n");
            for(int i=0;i<4;i++)
            {
                for(int j=0;j<4;j++)
                {
                    printf("-1 ");
                }
                printf("\n");
            }
            return false;
        }
    }

    for(int _move=0;_move<4;_move++)
    {
        if(check_movablilty(Map,_move))
        {
            sol.push_back(_move);
            if(find_sol(nextMap(Map,_move),sol))
                return true;
        }
    }
    return false;
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

unsigned long long Map_element(unsigned long long& Map,int m,int n)
{
    return (Map>>(16*m+4*n)) & 15;
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
