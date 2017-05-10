#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <cstring>
#include <vector>
#include <ctime>
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')
#define print(a) cout<<a<<endl;
#include <algorithm>
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
    for(unsigned int i=0;i<strlen(words);i++)
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

vector<adress> get_freqency(Node* root, string& query)
{
    Node* parent=root;
    vector<adress> no_this_word;
    unsigned int length=query.length();
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

vector<unsigned int> find_union(vector<unsigned int> pos1,vector<unsigned int> pos2)
{
    vector<unsigned int> buffer;
    vector<unsigned int>::iterator it_i_2=pos2.begin();
    vector<unsigned int>::iterator end_of_it_i_2=pos2.end();
    for(vector<unsigned int>::iterator it_i=pos1.begin();it_i!=pos1.end()&&it_i_2!=end_of_it_i_2;it_i++)
    {
            if(*it_i==*it_i_2)
            {
                buffer.push_back(*it_i);
                it_i_2++;
            }
            else if(*it_i_2<*it_i)
            {
                it_i_2++;
                it_i--;
            }
    }
    return buffer;
}

vector<unsigned int> find_possible_sentence(vector< vector<unsigned int> >& combine_adress)
{
    vector< vector<unsigned int> >::iterator it_i=combine_adress.begin();
    vector<unsigned int> buffer(*it_i);
    if(combine_adress.size()>1)
    {
        for(it_i=combine_adress.begin()+1;it_i!=combine_adress.end();it_i++)
        {
            buffer=find_union(*it_i,buffer);
        }
    }
    return buffer;
}



vector<unsigned int> find_top_five(vector<string> sentence,Node** roots)
{
    int length=sentence.size();
    int positon_of_word=0;
    vector<adress> buffer;
    vector<unsigned int> word_adress;
    vector< vector<unsigned int> > combine_adress;
    for(vector<string>::iterator it_i=sentence.begin();it_i!=sentence.end();it_i++)
    {
        if(it_i->compare("_")!=0)
        {
            switch(length)
            {
                case 2:
                    {
                        buffer = get_freqency(roots[0],*it_i);
                        for(vector<adress>::iterator it_i_2=buffer.begin();it_i_2!=buffer.end();it_i_2++)
                        {
                            if(it_i_2->position==positon_of_word)
                            {
                                word_adress.push_back(it_i_2->frequency_pos);
                            }
                        }
                        combine_adress.push_back(word_adress);
                        word_adress.clear();
                        break;
                    }
                case 3:
                    {
                        buffer = get_freqency(roots[1],*it_i);
                        for(vector<adress>::iterator it_i_2=buffer.begin();it_i_2!=buffer.end();it_i_2++)
                        {
                            if(it_i_2->position==positon_of_word)
                            {
                                word_adress.push_back(it_i_2->frequency_pos);
                            }
                        }
                        combine_adress.push_back(word_adress);
                        word_adress.clear();
                        break;
                    }
                case 4:
                    {
                        buffer = get_freqency(roots[2], *it_i);
                        for(vector<adress>::iterator it_i_2=buffer.begin();it_i_2!=buffer.end();it_i_2++)
                        {
                            if(it_i_2->position==positon_of_word)
                            {
                                word_adress.push_back(it_i_2->frequency_pos);
                            }
                        }
                        combine_adress.push_back(word_adress);
                        word_adress.clear();
                        break;
                    }
                case 5:
                    {
                        buffer = get_freqency(roots[3],*it_i);
                        for(vector<adress>::iterator it_i_2=buffer.begin();it_i_2!=buffer.end();it_i_2++)
                        {
                            if(it_i_2->position==positon_of_word)
                            {
                                word_adress.push_back(it_i_2->frequency_pos);
                            }
                        }
                        combine_adress.push_back(word_adress);
                        word_adress.clear();
                        break;
                    }

            }

        }
        positon_of_word++;
    }
    return find_possible_sentence(combine_adress);
}

int main ()
{
    FILE* fp_2,*fp_3,*fp_4,*fp_5;

    char buff_1[100];
    char buff_2[100];
    char buff_3[100];
    char buff_4[100];
    char buff_5[100];
    unsigned int buffer_d;
    unsigned int i=0;
    Node** roots=new Node*[4];
    for(int i=0;i<4;i++)
    {
        roots[i]=get_new_node();
    }
    vector< vector<unsigned int> >frequency_array(4);
    vector< vector<unsigned int> >sentence_pos(4);
    vector< vector<unsigned int> >::iterator it_frequency_array=frequency_array.begin();

    fp_2=fopen("2gm.small.txt","r");
    //fp_5=fopen("/tmp2/dsa2017_hw02/5gm.small.txt","r");
    frequency_array[0].reserve(8430018);
    sentence_pos[0].reserve(8430018);
    sentence_pos[0][0]=ftell(fp_2);
    while(fscanf(fp_2,"%s",buff_1)!=EOF)
    {
        insert_node(roots[0],buff_1,i,0);
        fscanf(fp_2,"%s",buff_2);
        insert_node(roots[0],buff_2,i,1);
        fscanf(fp_2,"%u",&buffer_d);
        frequency_array[0][i]=buffer_d;
        if(buffer_d>692874801)
        {
            printf("%s %s\t%u %u\n",buff_1,buff_2,buffer_d,i);
        }
        i++;
        sentence_pos[0][i]=ftell(fp_2)+1;
    }
    print("node2 has been constructed")
    fclose(fp_2);
  return 0;
}
