#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')

using namespace std;

struct Node
{
    Node* children[26];
    int counter;
    bool is_end;
    Node():is_end(0),children{nullptr},counter(0)
    {
    }
};

Node* get_new_node()
{
    Node* newnode=new Node;
    return newnode;
}

void insert_node(Node* root, char* words )
{
    Node* parent=root;
    int length=strlen(words);
    for(int i=0;i<length;i++)
    {
        if(!parent->children[CHAR_TO_INDEX(words[i])])
            parent->children[CHAR_TO_INDEX(words[i])]=get_new_node();
        parent=parent->children[CHAR_TO_INDEX(words[i])];
    }
    parent->is_end=1;
}


int main()

{
    int n_words;
    int valve;
    Node* root=get_new_node();
    scanf("%d",&n_words);
    scanf("%d",&valve);

    char buffer[100];
    for(int i=0;i<n_words;i++)
    {
        scanf("%s",buffer);

    }
    return 0;
}
