#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int buffer;
    vector<int> container;
    vector<int> process;
    bool is_code=0;

    for(int i=0;i<n;i++)
    {

        cin>>buffer;
        while(buffer!=(-1))
        {
            container.push_back(buffer);
            cin>>buffer;
        }

        while(!container.empty())
        {
            buffer=container.back();
            container.pop_back();
            if(process.empty())
            {
                process.push_back(buffer);
            }
            else if(buffer>process.back())
            {
                process.push_back(buffer);
            }
            else if(buffer<process.back())
            {
                process.pop_back();
                if(process.empty())
                {
                    process.push_back(buffer);
                }
                else if(buffer<process.back())
                {
                    is_code=1;
                    break;
                }
                else
                {
                    process.push_back(buffer);
                }
            }
        }
        if(is_code==1)
            cout<<"1\n";
        else
            cout<<"0\n";
        is_code=0;
        container.clear();
        process.clear();
    }
    return 0;

}
