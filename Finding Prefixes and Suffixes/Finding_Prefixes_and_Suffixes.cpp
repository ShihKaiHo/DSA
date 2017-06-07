#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')
#include <algorithm>
using namespace std;
vector<string> ans;
int valve;
string temp;

char index_to_char(int& index)
{
    return static_cast<char>(index+97);
}

struct Node
{
    Node* children[26];
    int counter;
    bool is_end;
    Node():is_end(0),children{nullptr},counter(0){}
};

Node* get_new_node()
{
    Node* newnode=new Node;
    return newnode;
}

void insert_node_pre(Node* root, char* words )
{
    Node* parent=root;
    int length=strlen(words);
    for(int i=0;i<length;i++)
    {
        if(!parent->children[CHAR_TO_INDEX(words[i])])
            parent->children[CHAR_TO_INDEX(words[i])]=get_new_node();
        parent=parent->children[CHAR_TO_INDEX(words[i])];
        parent->counter++;
    }
    parent->is_end=1;
}

void find_prefix(Node* parent)
{
    if((parent->counter)>=valve)
    {
        int is_prefix=1;
        for(int i=0;i<26;i++)
        {
            if(parent->children[i]!=nullptr)
            {
                if(parent->children[i]->counter>=valve)
                {
                    is_prefix=0;
                    break;
                }
            }
        }
        if(is_prefix)
        {
            ans.push_back(temp);
            return;
        }
    }
    for(int i=0;i<26;i++)
    {
        if(parent->children[i]!=nullptr)
        {
            temp+=index_to_char(i);
            find_prefix(parent->children[i]);
            temp.pop_back();
        }
    }
    if(parent->is_end)
        return;
}

void insert_node_suf(Node* root, string words )
{
    Node* parent=root;
    int length=words.length();
    for(int i=length-1;i>=0;i--)
    {
        if(!parent->children[CHAR_TO_INDEX(words[i])])
            parent->children[CHAR_TO_INDEX(words[i])]=get_new_node();
        parent=parent->children[CHAR_TO_INDEX(words[i])];
        parent->counter++;
    }
    parent->is_end=1;
}

void build_suf(Node* parent,Node* root_suf)
{
    for(int i=0;i<26;i++)
    {
        if(parent->children[i]!=nullptr)
        {
            parent->counter--;
            temp+=index_to_char(i);
            build_suf(parent->children[i],root_suf);
            if(parent->children[i]->counter==0)
            {
                delete parent->children[i];
            }
            temp.pop_back();
        }
    }
    if(parent->is_end)
    {
        insert_node_suf( root_suf, temp );
        return;
    }
}

void find_suffix(Node* parent)
{
    if((parent->counter)>=valve)
    {
        int is_suffix=1;
        for(int i=0;i<26;i++)
        {
            if(parent->children[i]!=nullptr)
            {
                if(parent->children[i]->counter>=valve)
                {
                    is_suffix=0;
                    break;
                }
            }
        }
        if(is_suffix)
        {
            string buffer;
            for(int i=0;i<temp.length();i++)
            {
                buffer.push_back(temp[temp.length()-1-i]);
            }
            //cout<<temp<<endl;
            ans.push_back(buffer);
            return;
        }
    }

    for(int i=0;i<26;i++)
    {
        if(parent->children[i]!=nullptr)
        {
            temp+=index_to_char(i);
            find_suffix(parent->children[i]);
            temp.pop_back();
        }
    }

    if(parent->is_end)
        return;
}

int main()
{
    int n_words;
    Node* root_pre=get_new_node();
    Node* root_suf=get_new_node();
    scanf("%d",&n_words);
    scanf("%d",&valve);

    char buffer[45];
    for(int i=0;i<n_words;i++)
    {
        scanf("%s",buffer);
        insert_node_pre(root_pre,buffer);
    }
    find_prefix(root_pre);

    printf("prefix:\n");
    for(auto it=ans.begin();it!=ans.end();it++)
    {
        printf("%s\n",it->c_str());
    }
    ans.clear();

    build_suf(root_pre,root_suf);
    find_suffix(root_suf);
    sort(ans.begin(), ans.end());
    printf("suffix:\n");
    for(auto it=ans.begin();it!=ans.end();it++)
    {
        printf("%s\n",it->c_str());
    }
    return 0;
}
