#include <iostream>
#include <vector>
using namespace std;

vector< vector<int> > ans;
vector<int> temp;
int tree[(1<<21)+1];
int N;
int target;
long long int buffer;

void DFS(int parent)
{
    /*
    for(auto it=temp.begin();it!=temp.end();it++)
    {
        cout<<*it<<' ';
    }
    cout<<endl;
    */
    if(buffer==target)
        ans.push_back(temp);
    if(2*parent<(1<<(N+1)))
    {
        temp.push_back(tree[2*parent]);
        buffer+=tree[2*parent];
        DFS(2*parent);
        buffer-=tree[2*parent];
        temp.pop_back();


        temp.push_back(tree[2*parent+1]);
        buffer+=tree[2*parent+1];
        DFS(2*parent+1);
        buffer-=tree[2*parent+1];
        temp.pop_back();

        return;
    }
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin>>N;
    for(int i=1;i<(1<<(N+1));i++)
    {
        cin>>tree[i];
    }
    cin>>target;

    buffer=tree[1];
    temp.push_back(tree[1]);
    DFS(1);

    for(auto it=ans.begin();it!=ans.end();it++)
    {
        for(auto it2=it->begin();it2!=it->end();it2++)
        {
            if(it2!=it->end()-1)
                cout<<*it2<<' ';
            else
                cout<<*it2;
        }
        cout<<'\n';
    }
    return 0;

}
