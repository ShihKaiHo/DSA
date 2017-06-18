#include <iostream>
#include <stack>
#include <vector>
using namespace std;

<<<<<<< HEAD
struct up_down
{
    int up;
    int down;
};

=======
void print_stack(vector<int> code)
{
    for(auto it=code.begin();it!=code.end();it++)
        cout<<*it<<' ';
    cout<<endl;
    return;
}
>>>>>>> ed5b0744c247ea4555900c84ddb90425bba94526

int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
<<<<<<< HEAD
    bool is_CODE=false;
    bool stop=false;
    int curren_min;
    vector<up_down> range;

    int buffer;
=======
    int buffer;
    bool is_CODE;
    vector<int> code;
>>>>>>> ed5b0744c247ea4555900c84ddb90425bba94526
    for(int i=0;i<n;i++)
    {
        is_CODE=0;
        cin>>buffer;
        if(buffer==(-1))
        {
            cout<<"0\n";
            continue;
        }
        code.push_back(buffer);
        cin>>buffer;
<<<<<<< HEAD
        curren_min=buffer;
        while(buffer!=-1)
        {
            if(stop)
=======
        while(buffer!=(-1))
        {
            print_stack(code);
            if(buffer>code.back())
                code.push_back(buffer);
            else if(buffer==code.back())
>>>>>>> ed5b0744c247ea4555900c84ddb90425bba94526
            {
                cin>>buffer;
                continue;
            }
<<<<<<< HEAD
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
=======
            else
            {
                while(!code.empty())
                {
                    print_stack(code);
                    code.pop_back();
                    if(code.empty())
                        break;
                    if(buffer>code.back())
                    {
                        is_CODE=1;
                        break;
                    }
                }
                code.push_back(buffer);
            }
            cin>>buffer;
        }
        print_stack(code);
        cout<<is_CODE<<'\n';
        code.clear();
>>>>>>> ed5b0744c247ea4555900c84ddb90425bba94526
    }


    return 0;
}
