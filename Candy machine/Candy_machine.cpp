#include <cstdio>
#include <vector>
#include <queue>
#include <iostream>
#define MAX(x,y)	((candy_machine[(x)])>=(candy_machine[(y)])?(x):(y))
#define MIN(x,y)	((x)<=(y)?(x):(y))
using namespace std;
priority_queue<int, vector<int>, greater<int> > vacancy;

void insert_candy(int* candy_machine, int& candy)
{
    if(vacancy.size() == 1)
    {
        candy_machine[vacancy.top()] = candy;
        vacancy.push(vacancy.top()+1);
        vacancy.pop();
    }
    else
    {
        candy_machine[vacancy.top()] = candy;
        vacancy.pop();
    }
}

void pop_candy(int* candy_machine)
{
    if(vacancy.top() == 1)
    {
        printf("0\n");
    }
    else
    {
        printf("%d\n", candy_machine[1]);
        int pos = 1;
        int max_parent;
        while(candy_machine[2*pos] != 0 || candy_machine[2*pos+1] != 0)
        {
            max_parent = MAX(2*pos, 2*pos+1);
            candy_machine[pos] = candy_machine[max_parent];
            pos = max_parent;
        }
        candy_machine[pos] = 0;
        vacancy.push(pos);
    }
}
int main()
{
    int candy_machine[196605];
    int operation;
    int candy;

    vacancy.push(1);

    while(scanf("%d", &operation) != EOF)
    {
        switch(operation)
        {
            case 1:
                {
                    scanf("%d", &candy);
                    insert_candy(candy_machine,candy);
                    /*
                    for(int i=1; i<20; i++)
                    {
                        cout<<candy_machine[i]<<" ";
                    }
                    cout<<endl;
                    cout<<"vacancy top: "<<vacancy.top()<<endl;
                    */
                    break;

                }
            case 2:
                {
                    pop_candy(candy_machine);
                    /*
                    for(int i=1; i<20; i++)
                    {
                        cout<<candy_machine[i]<<" ";
                    }
                    cout<<endl;
                    cout<<"vacancy top: "<<vacancy.top()<<endl;
                    */
                    break;
                }
        }
    }

   return 0;
}
