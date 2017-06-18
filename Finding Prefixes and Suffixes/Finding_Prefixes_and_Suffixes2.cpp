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
string temp2;
string temp3;
char index_to_char(int& index)
{
    return static_cast<char>(index+97);
}


struct Node
{
    Node* children[26];
    int counter;
    bool is_end;
    Node():is_end_pre(0),is_end_suf(0),children{nullptr},counter_pre(0),counter_suf(0){}
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
        parent->counter_pre++;
    }
    parent->is_end_pre=1;
    parent=root;
    for(int i=length-1;i>=0;i--)
    {
        if(!parent->children[CHAR_TO_INDEX(words[i])])
            parent->children[CHAR_TO_INDEX(words[i])]=get_new_node();
        parent=parent->children[CHAR_TO_INDEX(words[i])];
        parent->counter_suf++;
    }
    parent->is_end_suf=1;

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
        //insert_node_suf(root_suf,buffer);
    }
    delete root_pre;

    return 0;
}
