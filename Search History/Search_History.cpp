#include <cstdio>
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')
#include <cstring> //strlen
#include <string>
#include <vector>
#include <iostream>
using namespace std;
vector<string> ans;
struct Node
{
    Node* children[26];
    bool is_end;
    Node():is_end(0),children{nullptr}
    {}
};
void find_sol(Node* root, char* query)
{
    Node* parent=root;
    int length=strlen(query);
    for(int i=0;i<length;i++)
    {
        if(!parent->children[CHAR_TO_INDEX(query[i])])
            return;
        parent=parent->children[CHAR_TO_INDEX(query[i])];
    }
    if (parent!=nullptr)
    {

    }
}

Node* get_new_node()
{
    Node* newnode=new Node;
    return newnode;
}

void insert_node(Node* root, char* words)
{
    Node* parent=root;
    int length=strlen(words);
    for(unsigned int i=0;i<length;i++)
    {
        if(!parent->children[CHAR_TO_INDEX(words[i])])
            parent->children[CHAR_TO_INDEX(words[i])]=get_new_node();
        parent=parent->children[CHAR_TO_INDEX(words[i])];
    }
    parent->is_end=1;
    return;
}

int main()
{
    int n,m;
    char buff[100];
    Node* root=get_new_node();
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%s",buff);
        insert_node(root,buff);
    }
    scanf("%d",&m);
    for(int i=0;i<m;i++)
    {
        scanf("%s",buff);
        find_sol(root, buff);
        ans.clear();
    }
    cout<<root->children[CHAR_TO_INDEX('g')];
    return 0;
}
