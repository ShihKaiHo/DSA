#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void print_stack(vector<int> code)
{
    for(auto it=code.begin();it!=code.end();it++)
        cout<<*it<<' ';
    cout<<endl;
    return;
}

int main()
{
    int n;
    cin>>n;
    int buffer;
    bool is_CODE;
    vector<int> code;
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
        while(buffer!=(-1))
        {
            print_stack(code);
            if(buffer>code.back())
                code.push_back(buffer);
            else if(buffer==code.back())
            {
                cin>>buffer;
                continue;
            }
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
    }


    return 0;
}
