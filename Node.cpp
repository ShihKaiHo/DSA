#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <cstring>
#include <vector>
#include <ctime>
#include <map>
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')
using namespace std;
//unsigned int* adress;
int longest=0;

struct adress
{
    unsigned int* frequency_pt;
    int position;
    adress()
    :position(0),frequency_pt(nullptr)
    {

    }
};
struct Node
{
    Node* children[26];
    vector<adress> adress_of_word;
    bool is_end;
    Node():is_end(0),children{nullptr}
    {
    }
};

Node* get_new_node()
{
    Node* newnode=new Node;
    return newnode;
}

void insert_node(Node* root, char* words,unsigned int* index,int position)
{
    Node* parent=root;
    for(int i=0;i<strlen(words);i++)
    {
        //if (index-abc<50)
        //cout<<words[i]<<' ';
        if(!parent->children[CHAR_TO_INDEX(words[i])])
            parent->children[CHAR_TO_INDEX(words[i])]=get_new_node();
        parent=parent->children[CHAR_TO_INDEX(words[i])];
    }
    parent->is_end=1;
    adress buffer;
    buffer.frequency_pt=index;
    buffer.position=position;
    parent->adress_of_word.push_back(buffer);
}

vector<adress> get_freqency(Node* root, char* query)
{
    Node* parent=root;
    vector<adress> no_this_word;
    int length=strlen(query);
    for(int i=0;i<length;i++)
    {
        if(!parent->children[CHAR_TO_INDEX(query[i])])
            return no_this_word;
        parent=parent->children[CHAR_TO_INDEX(query[i])];
    }
    if (parent!=nullptr&&parent->is_end==1)
        return parent->adress_of_word;
    else
        return no_this_word;
}

int main(int argc, char *argv[])
{
    clock_t t1, t2, t3;
    t1 = clock();
    //printf("%s\n","123");
    FILE* fp_2,*fp_3,*fp_4,*fp_5;
    Node *root =get_new_node();

    fp_2=fopen("2gm.small.txt","r");
    char buff_c[40];
    char buff_c2[40];
    char buff_c3[40];
    char buff_c4[40];
    unsigned int buff_d;
    unsigned int* frequency_array_2=new unsigned int[8430018];
    //abc=frequency_array;
    int i=0;
    while(fscanf(fp_2,"%s",buff_c)!=EOF)
    {
        insert_node(root,buff_c,frequency_array_2+i,1);
        fscanf(fp_2,"%s",buff_c);
        insert_node(root,buff_c,frequency_array_2+i,2);
        fscanf(fp_2,"%d",frequency_array_2+i);
        //if (frequency_array+i-abc<50)
        //cout<<*(frequency_array+i)<<endl;
        i++;
    }
    i=0;
    fclose(fp_2);
    fp_3=fopen("3gm.small.txt","r");
    unsigned int* frequency_array_3=new unsigned int[8430018];
    while(fscanf(fp_3,"%s",buff_c)!=EOF)
    {
        insert_node(root,buff_c,frequency_array_3+i,1);
        fscanf(fp_3,"%s",buff_c);
        insert_node(root,buff_c,frequency_array_3+i,2);
        fscanf(fp_3,"%s",buff_c);
        insert_node(root,buff_c,frequency_array_3+i,3);
        fscanf(fp_3,"%d",frequency_array_3+i);
        //if (frequency_array+i-abc<50)
        //cout<<*(frequency_array+i)<<endl;
        i++;
    }
    i=0;
    fclose(fp_3);
    fp_4=fopen("4gm.small.txt","r");
    unsigned int* frequency_array_4=new unsigned int[8430018];
    while(fscanf(fp_4,"%s",buff_c)!=EOF)
    {
        insert_node(root,buff_c,frequency_array_4+i,1);
        fscanf(fp_4,"%s",buff_c);
        insert_node(root,buff_c,frequency_array_4+i,2);
        fscanf(fp_4,"%s",buff_c);
        insert_node(root,buff_c,frequency_array_4+i,3);
        fscanf(fp_4,"%s",buff_c);
        insert_node(root,buff_c,frequency_array_4+i,4);
        fscanf(fp_4,"%d",frequency_array_3+i);
        //if (frequency_array+i-abc<50)
        //cout<<*(frequency_array+i)<<endl;
        i++;
    }
    fclose(fp_4);
    fp_5=fopen("5gm.small.txt","r");
    unsigned int* frequency_array_5=new unsigned int[8430018];
    while(fscanf(fp_5,"%s",buff_c)!=EOF)
    {
        insert_node(root,buff_c,frequency_array_4+i,1);
        fscanf(fp_5,"%s",buff_c);
        insert_node(root,buff_c,frequency_array_4+i,2);
        fscanf(fp_5,"%s",buff_c);
        insert_node(root,buff_c,frequency_array_4+i,3);
        fscanf(fp_5,"%s",buff_c);
        insert_node(root,buff_c,frequency_array_4+i,4);
        fscanf(fp_5,"%s",buff_c);
        insert_node(root,buff_c,frequency_array_4+i,5);
        fscanf(fp_5,"%d",frequency_array_3+i);
        //if (frequency_array+i-abc<50)
        //cout<<*(frequency_array+i)<<endl;
        i++;
    }
    i=0;
    char* test="abandoned";






    t2 = clock();
    cout<<*(get_freqency(root, test).at(0).frequency_pt)<<endl;
    cout<<(get_freqency(root, test).at(0).position)<<endl;
    cout<<*(get_freqency(root, test).at(1).frequency_pt)<<endl;
    cout<<(get_freqency(root, test).at(1).position)<<endl;
    cout<<*(get_freqency(root, test).at(2).frequency_pt)<<endl;
    cout<<(get_freqency(root, test).at(2).position)<<endl;
    t3 = clock();
    cout<<(t3-t2)/double(CLOCKS_PER_SEC);
    //cout<<longest;

    //Node root;
    //insert_word(&root,ii_dictionary.at(0).words.at(0));
    fclose(fp_2);
  return 0;
}
