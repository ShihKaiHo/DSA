#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct up_down
{
    int up;
    int down;
};


int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    bool is_CODE=false;
    bool stop=false;
    int curren_min;
    vector<up_down> range;

    int buffer;
    for(int i=0;i<n;i++)
    {
        cin>>buffer;
        curren_min=buffer;
        while(buffer!=-1)
        {
            if(stop)
            {
                cin>>buffer;
                continue;
            }
            if(buffer>curren_min)
            {
                for(auto it=range.rbegin();it!=range.rend();it++)
                {
                    if( buffer < (it->up) && buffer > (it->down) )
                    {
                        is_CODE=true;
                        stop=true;
                        break;
                    }
                }
            }

            if( buffer < curren_min )
            {
                curren_min = buffer;
            }
            else if( buffer > curren_min )
            {
                if(!range.empty())
                {
                    if(curren_min == (range.back()).down)
                    {
                        (range.back()).up=buffer;
                    }
                    else
                    {
                        up_down temp;
                        temp.up=buffer;
                        temp.down=curren_min;
                        range.push_back(temp);
                    }
                }
                else
                {
                    up_down temp;
                    temp.up=buffer;
                    temp.down=curren_min;
                    range.push_back(temp);
                }

            }
            cin>>buffer;
        }
        if(is_CODE)
            cout<<"1\n";
        else
            cout<<"0\n";
        is_CODE=0;
        stop=0;
        range.clear();
    }


    return 0;
}
