#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> child;
vector<int> parent;
vector<int> answer;
unordered_map< int , vector<int> > tree;

void DFS(int del)
{
    answer.push_back(del);
    for(auto it=tree[del].begin();it!=tree[del].end();it++)
        DFS(*it);
}

int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    int buffer;
    vector<int> temp;

    for(int i=0;i<n;i++)
    {
        cin>>buffer;
        child.push_back(buffer);
    }
    for(int i=0;i<n;i++)
    {
        cin>>buffer;
        parent.push_back(buffer);
    }
    for(int i=0;i<n;i++)
        tree[parent[i]].push_back(child[i]);

    int del;
    cin>>del;
    DFS(del);
    sort(answer.begin(),answer.end());
    for(auto it=answer.begin();it!=answer.end();it++)
    {
        if(it!=answer.end()-1)
            cout<<*it<<' ';
        else
            cout<<*it;
    }
    return 0;
}
