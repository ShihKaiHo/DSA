#include <cstdio>
#include <iostream>
#include <stack>
#include <vector>
#include <queue>
using namespace std;
int N;
vector< vector<int> > ans;

struct object
{
    vector<int> answer;
    queue<int> initial;
    stack<int> mid_stack;
    object()
    {
        for(int i=1;i<=N;i++)
        {
            initial.push(i);
        }
    }
};

void go_through(object push_pop_seq)
{
    if(push_pop_seq.initial.size()==0 && push_pop_seq.mid_stack.size()==0)
    {
        ans.push_back(push_pop_seq.answer);
        return;
    }
    else if(push_pop_seq.initial.size()==0 )
    {
        push_pop_seq.answer.push_back(push_pop_seq.mid_stack.top());
        push_pop_seq.mid_stack.pop();
        go_through(push_pop_seq);
        return;
    }
    else if(push_pop_seq.mid_stack.size()==0)
    {
        push_pop_seq.mid_stack.push(push_pop_seq.initial.front());
        push_pop_seq.initial.pop();
        go_through(push_pop_seq);
        return;
    }
    else
    {
        int temp=push_pop_seq.mid_stack.top();
        push_pop_seq.answer.push_back(temp);
        push_pop_seq.mid_stack.pop();
        go_through(push_pop_seq);
        push_pop_seq.mid_stack.push(temp);
        push_pop_seq.answer.pop_back();

        push_pop_seq.mid_stack.push(push_pop_seq.initial.front());
        push_pop_seq.initial.pop();
        go_through(push_pop_seq);
        return;
    }
}

int main()
{
    scanf("%d",&N);
    object initial_state;
    go_through(initial_state);
    for(auto it=ans.rbegin();it!=ans.rend();it++)
    {
        for(auto it2=it->begin();it2!=it->end();it2++)
        {
            printf("%d ",*it2);
        }
        printf("\n");
    }
    return 0;
}
