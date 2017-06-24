#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

vector<int> jump_step;
vector<int> ice;
int max_hieght;

bool can_reach(int step, bool ice_floor[])
{
    if(step > max_hieght)
        return 0;
    else if(step < 0)
        return 0;
    else if(ice_floor[step])
        return 0;
    else
        return 1;
}
void reset_table(bool table[][10002], int max_hieght, int jump_num)
{
    for(int i=0; i<=jump_num; i++)
    {
        for(int j=0; j<=max_hieght; j++)
            table[i][j] = 0;
    }
    table[0][0] = 1;
}
int main()
{
    int n;
    scanf("%d", &n);

    int jump_num;
    int ice_num;

    int temp;

    bool table[102][10002];
    bool ice_floor[10001];
    table[0][0] = 1;

    for(int i=0; i<n; i++)
    {
        scanf("%d %d %d", &jump_num, &ice_num, &max_hieght);

        for(int j=0; j<jump_num; j++)
        {
            scanf("%d", &temp);
            jump_step.push_back(temp);
        }
        for(int j=0; j<ice_num; j++)
        {
            scanf("%d", &temp);
            ice.push_back(temp);
            ice_floor[temp] = 1;
        }
        bool flag = 1;
        for(int step=0; step<jump_num; step++)
        {
            flag = 1;
            for(int hieght=0; hieght<=max_hieght; hieght++)
            {
                if(table[step][hieght])
                {
                    flag = 0;
                    if(can_reach(hieght+jump_step[step], ice_floor))
                    {
                        table[step+1][hieght+jump_step[step]] = 1;
                    }
                    if(can_reach(hieght-jump_step[step], ice_floor))
                    {
                        table[step+1][hieght-jump_step[step]] = 1;
                    }
                }
            }
            if(flag)
            {
                break;
            }
        }

        /*
        for(int j=0; j<=jump_num; j++)
        {
            for(int k=0; k<=max_hieght; k++)
                printf("%d ",table[j][k]);
            printf("\n");
        }
        */
        if(flag)
        {
            printf("-1\n");
        }
        else
        {
            bool flag2 = 1;
            for(int j=max_hieght; j >= 0; j--)
            {
                if(table[jump_num][j])
                {
                    flag2 = 0;
                    printf("%d\n",j);
                    break;
                }
            }
            if(flag2)
                printf("-1\n");
        }

        reset_table(table, max_hieght, jump_num);
        for(auto it=ice.begin(); it!=ice.end(); it++)
        {
            ice_floor[*it] = 0;
        }
        jump_step.clear();
        ice.clear();
    }
    return 0;
}
