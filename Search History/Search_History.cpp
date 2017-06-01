#include <cstdio>
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')
#include <cstring> //strlen
#include <iostream>
#include <string>
#include <vector>
using namespace std;


vector<string> ans;

char index_to_char(int index)
{
    return static_cast<char>(index+97);
}

struct Node
{
    Node* children[26];
    bool is_end;
    Node():is_end(0),children{nullptr}
    {}
};

void find_search_history(Node* parent,string& prefix)
{
    if(parent->is_end==true)
    {
        ans.push_back(prefix);
    }
    for(int i=0;i<26;i++)
    {
        char temp;
        if(parent->children[i]!=nullptr)
        {
            temp=index_to_char(i);
            prefix+=temp;
            find_search_history(parent->children[i], prefix);
            prefix.pop_back();
        }
    }
    return;
}

void find_solution(Node* root, char* query)
{
    Node* parent=root;
    int length=strlen(query);
    string prefix;
    for(int i=0;i<length;i++)
    {
        if(!parent->children[CHAR_TO_INDEX(query[i])])
            return;
        prefix+=query[i];
        parent=parent->children[CHAR_TO_INDEX(query[i])];
    }
    find_search_history(parent,prefix);
    return;
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
        find_solution(root, buff);
        if(ans.empty())
            printf("NO MATCHING!\n");
        else
        {
            for(auto it=ans.begin();it!=ans.end();it++)
            {
                printf("%s\n",it->c_str());
            }
            ans.clear();
        }

    }
    return 0;
}
