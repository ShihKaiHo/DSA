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



struct address
{

    unsigned int frequency_pos;
    int position;
    adress()
    :position(0),frequency_pos(0)
    unsigned int* frequency_pt;
    address()
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


void insert_node(Node* root, char* words,unsigned int index,int position)
{
    Node* parent=root;
    for(unsigned int i=0;i<strlen(words);i++)

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

    buffer.frequency_pos=index;

    buffer.frequency_pt=index;

    buffer.position=position;
    parent->adress_of_word.push_back(buffer);
}


vector<adress>& get_freqency(Node* root, char* query)

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
<<<<<<< HEAD
    clock_t t1, t2, t3, t4, t5;
    //printf("%s\n","123");
    FILE* fp_2,*fp_3,*fp_4,*fp_5;

    char buff_c[100];
    unsigned int buffer_d;
    unsigned int i=0;

    t4=clock();
    t1 = clock();
    vector<unsigned int> frequency_array_2(8430018);
    Node *root2 =get_new_node();
    fp_2=fopen("2gm.small.txt","r");
    //fp_2=fopen("/tmp2/dsa2017_hw02/2gm.small.txt","r");
    while(fscanf(fp_2,"%s",buff_c)!=EOF)
    {
        insert_node(root2,buff_c,i,0);
        fscanf(fp_2,"%s",buff_c);
        insert_node(root2,buff_c,i,1);
        fscanf(fp_2,"%u",&buffer_d);
        frequency_array_2.at(i)=buffer_d;

    clock_t t1, t2, t3;
    t1 = clock();
    int counter=0;
    //printf("%s\n","123");
    FILE* fp_2,*fp_3,*fp_4,*fp_5;


    fp_2=fopen("2gm.small.txt","r");
    char buff_c[100];

    unsigned int frequency_array_2[8430018];
    //abc=frequency_array;
    int i=0;

    Node *root2 =get_new_node();
    while(fscanf(fp_2,"%s",buff_c)!=EOF)
    {
        insert_node(root2,buff_c,frequency_array_2+i,0);
        fscanf(fp_2,"%s",buff_c);
        insert_node(root2,buff_c,frequency_array_2+i,1);
        fscanf(fp_2,"%d",frequency_array_2+i);

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
    vector<unsigned int> frequency_array_3(15960930);
    while(fscanf(fp_3,"%s",buff_c)!=EOF)
    {
        insert_node(root3,buff_c,i,0);
        fscanf(fp_3,"%s",buff_c);
        insert_node(root3,buff_c,i,1);
        fscanf(fp_3,"%s",buff_c);
        insert_node(root3,buff_c,i,2);
        fscanf(fp_3,"%u",&buffer_d);
        frequency_array_3.at(i)=buffer_d;

    print("node2 has construced")
    i=0;
    fclose(fp_2);

    fp_3=fopen("3gm.small.txt","r");
    Node *root3 =get_new_node();
    unsigned int frequency_array_3[15960930];
    while(fscanf(fp_3,"%s",buff_c)!=EOF)
    {
        insert_node(root3,buff_c,frequency_array_3+i,0);
        fscanf(fp_3,"%s",buff_c);
        insert_node(root3,buff_c,frequency_array_3+i,1);
        fscanf(fp_3,"%s",buff_c);
        insert_node(root3,buff_c,frequency_array_3+i,2);
        fscanf(fp_3,"%d",frequency_array_3+i);
        counter++;
        //if (frequency_array+i-abc<50)
        //cout<<*(frequency_array+i)<<endl;
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
    vector<unsigned int> frequency_array_4(11765370);
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
        frequency_array_4.at(i)=buffer_d;
        i++;
    }
    t2=clock();

    Node *root4 =get_new_node();
    fp_4=fopen("4gm.small.txt","r");

    unsigned int frequency_array_4[11765370];

    while(fscanf(fp_4,"%s",buff_c)!=EOF)
    {
        insert_node(root4,buff_c,frequency_array_4+i,0);
        fscanf(fp_4,"%s",buff_c);
        insert_node(root4,buff_c,frequency_array_4+i,1);
        fscanf(fp_4,"%s",buff_c);
        insert_node(root4,buff_c,frequency_array_4+i,2);
        fscanf(fp_4,"%s",buff_c);
        insert_node(root4,buff_c,frequency_array_4+i,3);
        fscanf(fp_4,"%d",frequency_array_4+i);
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
    vector<unsigned int> frequency_array_5(5773240);
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
        frequency_array_5.at(i)=buffer_d;

    t2=clock();
    Node *root5 =get_new_node();
    fp_5=fopen("5gm.small.txt","r");
    unsigned int frequency_array_5[5343240];
    while(fscanf(fp_5,"%s",buff_c)!=EOF)
    {
        insert_node(root5,buff_c,frequency_array_5+i,0);
        fscanf(fp_5,"%s",buff_c);
        insert_node(root5,buff_c,frequency_array_5+i,1);
        fscanf(fp_5,"%s",buff_c);
        insert_node(root5,buff_c,frequency_array_5+i,2);
        fscanf(fp_5,"%s",buff_c);
        insert_node(root5,buff_c,frequency_array_5+i,3);
        fscanf(fp_5,"%s",buff_c);
        insert_node(root5,buff_c,frequency_array_5+i,4);
        fscanf(fp_5,"%d",frequency_array_5+i);

        i++;
    }
    t1=clock();
    print((t1-t2)/double(CLOCKS_PER_SEC))
    print(i)
    print("node5 has construced")
    i=0;
    fclose(fp_5);

    t5=clock();
    print("total time is ....")
    print((t5-t4)/double(CLOCKS_PER_SEC))


    char test[]="extremely";
    t2 = clock();
    cout<<frequency_array_2.at(get_freqency(root2, test).at(0).frequency_pos)<<endl;
    cout<<(get_freqency(root2, test).at(0).position)<<endl;
    cout<<frequency_array_3.at(get_freqency(root3, test).at(0).frequency_pos)<<endl;
    cout<<(get_freqency(root3, test).at(0).position)<<endl;
    cout<<frequency_array_4.at(get_freqency(root4, test).at(0).frequency_pos)<<endl;
    cout<<(get_freqency(root4, test).at(0).position)<<endl;
    cout<<frequency_array_5.at(get_freqency(root5, test).at(0).frequency_pos)<<endl;
    cout<<(get_freqency(root5, test).at(0).position)<<endl;
=======



    //char* test="abandoned";
    //t2 = clock();
    //cout<<*(get_freqency(root2, test).at(0).frequency_pt)<<endl;
    //cout<<(get_freqency(root2, test).at(0).position)<<endl;

    //cout<<*(get_freqency(root3, test).at(1).frequency_pt)<<endl;
    //cout<<(get_freqency(root3, test).at(1).position)<<endl;
    //cout<<*(get_freqency(root4, test).at(2).frequency_pt)<<endl;
    //cout<<(get_freqency(root4, test).at(2).position)<<endl;

    t3 = clock();
    print((t3-t2)/double(CLOCKS_PER_SEC));

    //t3 = clock();
    //cout<<(t3-t2)/double(CLOCKS_PER_SEC);

    //cout<<longest;

    //Node root;
    //insert_word(&root,ii_dictionary.at(0).words.at(0));

  return 0;
}
