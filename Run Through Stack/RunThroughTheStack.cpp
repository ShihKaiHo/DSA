#include <cstdio>
#include <iostream>
#include <stack>
#include <vector>
#include <queue>
using namespace std;
int N;
vector< vector<bool> > ans;

struct object
{
    vector<bool> sequence;
    int push;
    int pop;
    object()
    :push(0),pop(0){}
};

void go_through(object push_pop_seq)
{
    if(push_pop_seq.push==N && push_pop_seq.pop==N)
    {
        ans.push_back(push_pop_seq.sequence);
        return;
    }
    else if(push_pop_seq.push==N )
    {
        push_pop_seq.sequence.push_back(false);
        push_pop_seq.pop++;
        go_through(push_pop_seq);
    }
    else if((push_pop_seq.push-push_pop_seq.pop)==0)
    {
        push_pop_seq.sequence.push_back(true);
        push_pop_seq.push++;
        go_through(push_pop_seq);
    }
    else
    {
        push_pop_seq.sequence.push_back(true);
        push_pop_seq.push++;
        go_through(push_pop_seq);
        push_pop_seq.push--;
        push_pop_seq.sequence.pop_back();

        push_pop_seq.sequence.push_back(false);
        push_pop_seq.pop++;
        go_through(push_pop_seq);
    }
}

int main()
{
    //scanf("%d",&N);
    N=12;
    object temp;
    go_through(temp);
    queue<int> initial;
    queue<int> temp;
    for(int i=1;i<=N;i++)
    {
        initial.push(i);
    }
    for(auto it=ans.begin();it==ans.end();it++)
    {






    }
    return 0;
}
