#include <cstdio>
#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    int m;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&m);
        stack<int> initial;
        stack<int> mid;
        stack<int> answer;
        initial.push(m+1);
        int temp;
        for(int j=1;j<=m;j++)
        {
            scanf("%d",&temp);
            answer.push(temp);
        }
        if(m==1 || m==2)
        {
            printf("Y 1\n");
            continue;
        }
        while(!answer.empty())
        {
            if(answer.top()==initial.top()-1)
            {
                initial.push(answer.top());
                answer.pop();
            }
            else if(!mid.empty() && (mid.top()==initial.top()-1))
            {
                initial.push(mid.top());
                mid.pop();
            }
            else
            {
                mid.push(answer.top());
                answer.pop();
            }
        }
        int tick=0;
        while(!mid.empty())
        {
            if(mid.top()==initial.top()-1)
            {
                initial.push(mid.top());
                mid.pop();
            }
            else
            {
                printf("Y 2\n");
                break;
            }
        }
        if(mid.empty())
        {
            printf("Y 1\n");
        }
    }


    return 0;
}
