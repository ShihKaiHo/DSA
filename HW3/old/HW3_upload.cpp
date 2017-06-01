<<<<<<< HEAD
#include <iostream>
#include <cstdio>
#include <vector>
#define log2(a) (__builtin_ctzll(a))
using namespace std;
unsigned long long nextMap(unsigned long long Map, int action);

unsigned long long Map_element(unsigned long long& ,int ,int );
void print_map_formal(unsigned long long& );
bool is_win(unsigned long long& );
bool is_dead(unsigned long long& );
void set_Map(unsigned long long& );
bool check_movablilty(unsigned long long& ,int );
bool find_sol(unsigned long long,vector<int>&);
int main()
{
    unsigned long long Map=0;
    int n;
    if(scanf("%d",&n)){};
    for(int i=0;i<n;i++)
    {
        set_Map(Map);
        vector<int> sol;
        if(!find_sol(Map,sol))
        {
            printf("Action:\n-1\n");
            printf("Final:\n");
            for(int i:{0,1,2,3})
            {
                for(int j:{0,1,2,3})
                {
                    printf("-1 ");
                }
                printf("\n");
            }
        }
    }
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
        return false;

    for(int _move:{0,1,2,3})
    {
        if(check_movablilty(Map,_move))
        {
            sol.push_back(_move);
            if(find_sol(nextMap(Map,_move),sol))
                return true;
            sol.pop_back();
        }
    }
    return false;
}

unsigned long long Map_element(unsigned long long& Map,int m,int n)
{
    return (Map>>((m<<4)+(n<<2))) & 15;
}

void print_map_formal(unsigned long long& Map)
{
    int counter=0;
    for(int i:{0,1,2,3})
    {
        for(int j:{0,1,2,3})
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
    for(int i:{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15})
    {
        if(((Map>>(i<<2)) & 15)==11)
            return true;
    }
    return false;
}

bool is_dead(unsigned long long& Map)
{
    for(int i:{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15})
    {
        if(((Map>>(i<<2)) & 15)==0)
            return false;
    }
    unsigned long long compare=0;
    compare=Map ^ (Map<<4);
    for(int i:{0,1,2,4,5,6,8,9,10,12,13,14})
    {
        if(((compare>>(i<<2)) & 15 )==0)
        {
            return false;
        }
    }
    compare=Map ^ (Map<<16);
    for(int i:{0,1,2,3,4,5,6,7,8,9,10,11})
    {
        if(((compare>>(i<<2)) & 15 ) == 0)
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
    for(int i:{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15})
    {
        if(scanf("%llu",buffer+i)){};
    }
    for(int i:{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15})
    {
        if(buffer[i]!=0)
        {
            Map |=static_cast<unsigned long long>log2(buffer[i])<<(i<<2);
        }
    }
}

bool check_movablilty(unsigned long long& Map,int _move)
{
    switch(_move)
    {
        case 0:
            {
                for(int i:{0,1,2,4,5,6,8,9,10,12,13,14})
                {
                    if(Map_element(Map,i>>2,i&3)!=0)
                    {
                        if(Map_element(Map,i>>2,(i&3)+1)==0)
                            return true;
                        if((Map_element(Map,i>>2,i&3)==Map_element(Map,i>>2,(i&3)+1)))
                            return true;
                    }
                }
                return false;
            }
        case 1:
            {
                for(int i:{0,1,2,3,4,5,6,7,8,9,10,11})
                {
                    if(Map_element(Map,i>>2,i&3)!=0)
                    {
                        if(Map_element(Map,(i>>2)+1,i&3)==0)
                            return true;
                        if((Map_element(Map,i>>2,i&3)==Map_element(Map,(i>>2)+1,i&3)))
                            return true;
                    }
                }
                return false;
            }

        case 2:
            {
                for(int i:{1,2,3,5,6,7,9,10,11,13,14,15})
                {
                    if(Map_element(Map,i>>2,i&3)!=0)
                    {
                        if(Map_element(Map,i>>2,(i&3)-1)==0)
                            return true;
                        if((Map_element(Map,i>>2,i&3)==Map_element(Map,i>>2,(i&3)-1)))
                            return true;
                    }
                }
                return false;
            }
        case 3:
            {
                for(int i:{4,5,6,7,8,9,10,11,12,13,14,15})
                {
                    if(Map_element(Map,i>>2,i&3)!=0)
                    {
                        if(Map_element(Map,(i>>2)-1,i&3)==0)
                            return true;
                        if((Map_element(Map,i>>2,i&3)==Map_element(Map,(i>>2)-1,i&3)))
                            return true;
                    }
                }
                return false;
            }
    }
    return false;
}
=======
#include <iostream>
#include <cstdio>
#include <vector>
#define log2(a) (__builtin_ctzll(a))
using namespace std;
unsigned long long nextMap(unsigned long long Map, int action);

unsigned long long Map_element(unsigned long long& ,int ,int );
void print_map_formal(unsigned long long& );
bool is_win(unsigned long long& );
bool is_dead(unsigned long long& );
void set_Map(unsigned long long& );
bool check_movablilty(unsigned long long& ,int );
bool find_sol(unsigned long long,vector<int>&);
int main()
{
    unsigned long long Map=0;
    int n;
    if(scanf("%d",&n)){};
    for(int i=0;i<n;i++)
    {
        set_Map(Map);
        vector<int> sol;
        if(!find_sol(Map,sol))
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
        }
    }
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
        return false;

    for(int _move: {0,1,2,3})
    {
        if(check_movablilty(Map,_move))
        {
            sol.push_back(_move);
            if(find_sol(nextMap(Map,_move),sol))
                return true;
            sol.pop_back();
        }
    }
    return false;
}

unsigned long long Map_element(unsigned long long& Map,int m,int n)
{
    return (Map>>((m<<4)+(n<<2))) & 15;
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
        if(((Map>>(i<<2)) & 15)==11)
            return true;
    }
    return false;
}

bool is_dead(unsigned long long& Map)
{
    for(int i=0;i<16;i++)
    {
        if(((Map>>(i<<2)) & 15)==0)
            return false;
    }
    unsigned long long compare=0;
    compare=Map ^ (Map<<4);
    for(int i=0;i<15;i++)
    {
        if(i%4!=3)
        {
            if((compare>>(60-(i<<2)) & 15 )==0)
            {
                return false;
            }
        }
    }
    compare=Map ^ (Map<<16);
    for(int i=0;i<12;i++)
    {
        if((compare>>(60-(i<<2)) & 15 ) == 0)
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
                for(int i=0;i<16;i++)
                {
                    if(i%4!=3)
                    {
                        if(Map_element(Map,i>>2,i&3)!=0)
                        {
                            if((Map_element(Map,i>>2,i&3)==Map_element(Map,i>>2,(i&3)+1))||Map_element(Map,i>>2,(i&3)+1)==0)
                                return true;
                        }
                    }

                }
                return false;
            }

        case 1:
            {
                for(int i=0;i<12;i++)
                {
                    if(Map_element(Map,i>>2,i&3)!=0)
                    {
                        if((Map_element(Map,i>>2,i&3)==Map_element(Map,(i>>2)+1,i&3))||Map_element(Map,(i>>2)+1,i&3)==0)
                            return true;
                    }
                }
                return false;
            }

        case 2:
            {
                for(int i=1;i<16;i++)
                {
                    if(i%4!=0)
                    {
                        if(Map_element(Map,i>>2,i&3)!=0)
                        {
                            if((Map_element(Map,i>>2,i&3)==Map_element(Map,i>>2,(i&3)-1))||Map_element(Map,i>>2,(i&3)-1)==0)
                                return true;
                        }
                    }
                }
                return false;
            }
        case 3:
            {
                for(int i=4;i<16;i++)
                {
                    if(Map_element(Map,i>>2,i&3)!=0)
                    {
                        if((Map_element(Map,i>>2,i&3)==Map_element(Map,(i>>2)-1,i&3))||Map_element(Map,(i>>2)-1,i&3)==0)
                            return true;
                    }
                }
                return false;
            }
    }
    return false;
}
>>>>>>> c815147133690dda30e7fb2c31f4a1e047d846b4
