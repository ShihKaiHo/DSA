#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <cstring>
#include <vector>
#include <ctime>
#include <map>
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')
#define print(a) cout<<a<<endl;
using namespace std;



struct adress
{
    unsigned int frequency_pos;
    int position;
    adress()
    :position(0),frequency_pos(0)
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

void insert_node(Node* root, char* words,unsigned int index,int position)
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
    buffer.frequency_pos=index;
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
    //printf("%s\n","123");
    FILE* fp_2,*fp_3,*fp_4,*fp_5;

    char buff_c[100];
    unsigned int buffer_d;
    unsigned int i=0;



    t1 = clock();
    vector<unsigned int> frequency_array_2;
    Node *root2 =get_new_node();
    //fp_2=fopen("2gm.small.txt","r");
    fp_2=fopen("/tmp2/dsa2017_hw02/2gm.small.txt","r");
    while(fscanf(fp_2,"%s",buff_c)!=EOF)
    {
        insert_node(root2,buff_c,i,0);
        fscanf(fp_2,"%s",buff_c);
        insert_node(root2,buff_c,i,1);
        fscanf(fp_2,"%u",&buffer_d);
        frequency_array_2.push_back(buffer_d);
        i++;
    }
    t2=clock();
    print((t2-t1)/double(CLOCKS_PER_SEC))
    print(i)
    i=0;
    fclose(fp_2);
    print("node2 has construced")


    fp_3=fopen("3gm.small.txt","r");
    //fp_3=fopen("/tmp2/dsa2017_hw02/3gm.small.txt","r");
    Node *root3 =get_new_node();
    vector<unsigned int> frequency_array_3;
    while(fscanf(fp_3,"%s",buff_c)!=EOF)
    {
        insert_node(root3,buff_c,i,0);
        fscanf(fp_3,"%s",buff_c);
        insert_node(root3,buff_c,i,1);
        fscanf(fp_3,"%s",buff_c);
        insert_node(root3,buff_c,i,2);
        fscanf(fp_3,"%u",&buffer_d);
        frequency_array_3.push_back(buffer_d);
        i++;
    }
    t1=clock();
    print((t1-t2)/double(CLOCKS_PER_SEC))
    print(i)
    i=0;
    print("node3 has construced")
    fclose(fp_3);


    Node *root4 =get_new_node();
    fp_4=fopen("4gm.small.txt","r");
    //fp_4=fopen("/tmp2/dsa2017_hw02/4gm.small.txt","r");
    vector<unsigned int> frequency_array_4;
    while(fscanf(fp_4,"%s",buff_c)!=EOF)
    {
        insert_node(root4,buff_c,i,0);
        fscanf(fp_4,"%s",buff_c);
        insert_node(root4,buff_c,i,1);
        fscanf(fp_4,"%s",buff_c);
        insert_node(root4,buff_c,i,2);
        fscanf(fp_4,"%s",buff_c);
        insert_node(root4,buff_c,i,3);
        fscanf(fp_4,"%u",&buffer_d);
        frequency_array_4.push_back(buffer_d);
        i++;
    }
    t2=clock();
    print((t2-t1)/double(CLOCKS_PER_SEC))
    print(i)
    i=0;
    print("node4 has construced")
    fclose(fp_4);

    t2=clock();


    Node *root5 =get_new_node();
    fp_5=fopen("5gm.small.txt","r");
    //fp_5=fopen("/tmp2/dsa2017_hw02/5gm.small.txt","r");
    vector<unsigned int> frequency_array_5;
    while(fscanf(fp_5,"%s",buff_c)!=EOF)
    {
        insert_node(root5,buff_c,i,0);
        fscanf(fp_5,"%s",buff_c);
        insert_node(root5,buff_c,i,1);
        fscanf(fp_5,"%s",buff_c);
        insert_node(root5,buff_c,i,2);
        fscanf(fp_5,"%s",buff_c);
        insert_node(root5,buff_c,i,3);
        fscanf(fp_5,"%s",buff_c);
        insert_node(root5,buff_c,i,4);
        fscanf(fp_5,"%u",&buffer_d);
        frequency_array_5.push_back(buffer_d);
        i++;
    }
    t1=clock();
    print((t1-t2)/double(CLOCKS_PER_SEC))
    print(i)
    print("node5 has construced")
    i=0;
    fclose(fp_5);



    char test[]="abandoned";
    t2 = clock();
    //cout<<frequency_array_2.at(get_freqency(root2, test).at(0).frequency_pos)<<endl;
    //cout<<(get_freqency(root2, test).at(0).position)<<endl;
    //cout<<frequency_array_3.at(get_freqency(root3, test).at(0).frequency_pos)<<endl;
    //cout<<(get_freqency(root3, test).at(0).position)<<endl;
    //cout<<frequency_array_4.at(get_freqency(root4, test).at(0).frequency_pos)<<endl;
    //cout<<(get_freqency(root4, test).at(0).position)<<endl;
    //cout<<frequency_array_5.at(get_freqency(root5, test).at(0).frequency_pos)<<endl;
    //cout<<(get_freqency(root5, test).at(0).position)<<endl;
    //cout<<*(get_freqency(root3, test).at(1).frequency_pt)<<endl;
    //cout<<(get_freqency(root3, test).at(1).position)<<endl;
    //cout<<*(get_freqency(root4, test).at(2).frequency_pt)<<endl;
    //cout<<(get_freqency(root4, test).at(2).position)<<endl;
    t3 = clock();
    cout<<(t3-t2)/double(CLOCKS_PER_SEC);
    //cout<<longest;

    //Node root;
    //insert_word(&root,ii_dictionary.at(0).words.at(0));

  return 0;
}
