//http://tioj.infor.org/problems/1008
#include <cstdio>
#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

int GCD(int a, int b)
{
    while(a)
    {
        if( a < b ) swap(a, b);
        a %= b;
    }
    return b;
}

struct cup_state
{
    vector<int> water_state;
    int step;
    cup_state()
    :step(0)
    {
    }
};

int state_hash_fun(cup_state& state)
{
    long long int n=0;
    for(auto it=state.water_state.begin();it!=state.water_state.end();it++)
    {
        n+=(*it);
        n=n<<6;
    }
    n=n>>6;
    return n;
}

bool check_is_hash(cup_state& state, unordered_map<int,bool>& check_map )
{
    long long int n=0;
    for(auto it=state.water_state.begin();it!=state.water_state.end();it++)
    {
        n+=(*it);
        n=n<<6;
    }
    n=n>>6;
    return check_map.find(n)!=check_map.end();
}

void print_state(cup_state state)
{
    printf("(");
    for(auto it=state.water_state.begin();it!=state.water_state.end()-1;it++)
    {
        printf("%d,",*it);
    }
    printf("%d) ",state.water_state.back());
    return;
}

int main()
{
    int n;
    scanf("%d",&n);
    //n=3;
    int gcd, mx = 0;
    int* max_capacity =new int[n];

    for(int i=0;i<n;i++)
    {
        scanf("%d",max_capacity+i);
        /*
        if(!i) gcd = max_capacity[i];
        else gcd = GCD(gcd, max_capacity[i]);
        mx = max(mx, max_capacity[i]);
        */
    }
    /*
    max_capacity[0]=3;
    max_capacity[1]=5;
    max_capacity[2]=11;
    */
    int* initial_state=new int[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",initial_state+i);
    }


    printf("cup capacity:\n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",max_capacity[i]);
    }
    printf("\n");
    int target;
    //scanf("%d",&target);
    target=7;
    /*
    if( target > mx || target % gcd != 0 )
    {
        puts("-1");
        return 0;
    }
    */
    cup_state state;
    for(int i=0;i<n;i++)
    {
        state.water_state.push_back(initial_state[i]);
    }

    queue<cup_state> state_tree;
    unordered_map<int,bool> check_map;
    state_tree.push(state);
    check_map[state_hash_fun(state)]=true;
    bool stop=false;
    int current_step=0;
    printf("step 0 :\n");

    while(!state_tree.empty() && !stop)
    {
        state=state_tree.front();
        if(state.step>current_step)
        {
            current_step++;
            printf("\nstep %d :\n",current_step);
        }
        print_state(state);
        //queue pop
        state_tree.pop();

        /*
        //check answer
        for(auto it=state.water_state.begin();it!=state.water_state.end();it++)
        {
            if(*it==target)
            {
                stop=true;
                break;
            }
        }
        if(stop)
            break;
        */
        //queue in
        //empty
        for(auto it=state.water_state.begin();it!=state.water_state.end();it++)
        {
            if (*it==0)
                continue;
            int temp=*it;
            *it=0;
            //check is hash
            if(!check_is_hash(state,check_map))
            {
                state.step++;
                state_tree.push(state);
                check_map[state_hash_fun(state)]=true;
                state.step--;
            }
            *it=temp;
        }
        //full
        for(auto it=state.water_state.begin();it!=state.water_state.end();it++)
        {
            int full=max_capacity[it-state.water_state.begin()];
            if(*it==full)
                continue;
            int temp=*it;
            *it=full;
            //check is hash
            if(!check_is_hash(state,check_map))
            {
                state.step++;
                state_tree.push(state);
                check_map[state_hash_fun(state)]=true;
                state.step--;
            }
            *it=temp;
        }
        for(auto it1=state.water_state.begin();it1!=state.water_state.end();it1++)
        {
            if(*it1==0)
                continue;
            for(auto it2=state.water_state.begin();it2!=state.water_state.end();it2++)
            {
                int full=max_capacity[it2-state.water_state.begin()];
                if(*it2==full)
                    continue;
                int temp1,temp2;
                if(it1!=it2)
                {
                    temp1=*it1;
                    temp2=*it2;
                    int rest=full - *it2;
                    if(rest>=*it1)
                    {

                        *it1=0;
                        *it2+=temp1;
                        //check is hash
                        if(!check_is_hash(state,check_map))
                        {
                            state.step++;
                            state_tree.push(state);
                            check_map[state_hash_fun(state)]=true;
                            state.step--;
                        }
                        *it1=temp1;
                        *it2=temp2;
                    }
                    else
                    {
                        *it2=full;
                        *it1-=rest;
                        //check is hash
                        if(!check_is_hash(state,check_map))
                        {
                            state.step++;
                            state_tree.push(state);
                            check_map[state_hash_fun(state)]=true;
                            state.step--;
                        }
                        *it1=temp1;
                        *it2=temp2;
                    }
                }
            }
        }
    }
    delete [] initial_state;
    delete [] max_capacity;
    return 0;
}
