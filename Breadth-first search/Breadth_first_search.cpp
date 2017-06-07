#include <cstdio>
#include <iostream>
#include <queue>
#include <unordered_map>
#define CHAR_TO_INT(x) (static_cast<int>(x)-static_cast<int>('a'))
#define abbre(m,n) \
    if((init.x+(m))<9 && 0<=(init.x+(m)) && (init.y+(n))<9 && 0<=(init.y+(n)) && _map[init.x+(m)][(init.y+(n))]==0 )\
    {\
        if((init.x+(m))==fin.x && (init.y+(n))==fin.y)\
        {\
            buff.x=init.x+(m);\
            buff.y=init.y+(n);\
            buff.moves=init.moves+1;\
            _map[init.x+(m)][(init.y+(n))]=1;\
            BFS.push(buff);\
            return;\
        }\
        else if(_map[init.x+(m)][init.y+(n)]!=(-1))\
        {\
            buff.x=init.x+(m);\
            buff.y=init.y+(n);\
            buff.moves=init.moves+1;\
            _map[init.x+(m)][(init.y+(n))]=1;\
            BFS.push(buff);\
        }\
    }\



using namespace std;
void print_map();
int _map[9][9];

struct coordinate
{
    int x;
    int y;
    int moves;
    coordinate()
    :moves(0){}
};

queue<coordinate> BFS;

void can_go(coordinate init,coordinate& fin)
{
    coordinate buff;
    abbre(1,2)
    abbre(2,1)
    abbre(2,-1)
    abbre(1,-2)
    abbre(-1,-2)
    abbre(-2,-1)
    abbre(-2,1)
    abbre(-1,2)
    //print_map();
    //printf("\n");
    return;
}

void print_map()
{
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
            printf("%d\t",_map[i][j]);
        printf("\n");
    }
}
int main()
{
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
            _map[i][j]=0;
    }
    coordinate init;
    coordinate fin;

    int n_holes;
    char buff1[10];
    char buff2[10];
    scanf("%d",&n_holes);
    for(int i=0;i<n_holes;i++)
    {
        scanf("%s",buff1);
        _map[CHAR_TO_INT(buff1[0])][static_cast<int>(buff1[1])-49]=(-1);
    }
    int query;
    scanf("%d",&query);
    for(int i=0;i<query;i++)
    {
        scanf("%s",buff1);
        //printf("%s\n",buff1);
        init.x=CHAR_TO_INT(buff1[0]);
        init.y=static_cast<int>(buff1[1])-49;
        scanf("%s",buff2);
        //printf("%s\n",buff2);
        fin.x=CHAR_TO_INT(buff2[0]);
        fin.y=static_cast<int>(buff2[1])-49;
        BFS.push(init);
        _map[init.x][init.y]=1;
        _map[fin.x][fin.y]=0;
        coordinate temp;

        while(!BFS.empty())
        {
            //print_map();
            temp=BFS.front();
            //cout<<temp.x+1<<' '<<temp.y+1<<' '<<temp.moves<<endl;
            BFS.pop();
            if(temp.x==fin.x && temp.y==fin.y)
                break;
            can_go(temp,fin);
        }
        printf("Going from %s to %s needs %d moves.\n",buff1,buff2,temp.moves);


        while(!BFS.empty())
        {
            BFS.pop();
        }
        for(int j=0;j<9;j++)
        {
            for(int k=0;k<9;k++)
            {
                if(_map[j][k]!=(-1))
                    _map[j][k]=0;
            }
        }
    }

}
