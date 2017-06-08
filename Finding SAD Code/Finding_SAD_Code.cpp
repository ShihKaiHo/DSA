#include <iostream>
#include <stack>
using namespace std;

stack<int> code;

int main()
{
    int n;
    cin>>n;
    int buffer;
    bool is_CODE=0;

    for(int i=0;i<n;i++)
    {
        cin>>buffer;
        while(buffer!=-1)
        {
            code.push(buffer);
            cin>>buffer;
        }
    }
    while(!code.empty())
    {
        cout<<code.top()<<' ';
        code.pop();
    }


}
