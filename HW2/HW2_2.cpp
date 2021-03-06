#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <cstring>
#include <vector>
#include <ctime>
#include <algorithm>
#include <sstream>
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

class sentence_location
{
    public:
        vector<unsigned int>::iterator frequency_array;
        unsigned int location;
         sentence_location()
         :frequency_array(nullptr),location(0)
         {

         }
};
vector<unsigned int> find_candidate(vector<string>,Node** );

vector<string> constuct_string_vec(string query)
{
    istringstream buffer1(query);
    vector<string> query_vector;
    string buffer2;
    while(getline(buffer1,buffer2,' '))
    {
        query_vector.push_back(buffer2);
    }
    return query_vector;
}

int num_of_word(vector<string>& sentence)
{
    int counter=0;
    for(vector<string>::iterator it_i=sentence.begin();it_i!=sentence.end();it_i++)
    {
        if(it_i->compare("*")!=0)
        {
            counter++;
        }
    }
    return counter;
}
vector<string> replace_star(vector<string> sentence,int word,int num_of_)
{
    sentence.erase(sentence.begin()+word);
    for(int i=0;i<num_of_;i++)
    {
        vector<string>::iterator it_i = sentence.begin()+word;
        sentence.insert(it_i,"_");
    }
    return sentence;
}

void expand_star(vector<string> sentence,vector<sentence_location>& candidate,vector< vector<unsigned int> >::iterator& it_frequency_array,Node** roots)
{
    bool is_clear=1;
    int num=num_of_word(sentence);
    for(vector<string>::iterator it_i=sentence.begin();it_i!=sentence.end();it_i++)
    {
        if((*it_i)=="*")
        {
            is_clear=0;
            for(int i=0;i<(5-num+1);i++)
            {
                expand_star(replace_star(sentence,it_i-sentence.begin(),i),candidate,it_frequency_array, roots);
            }
            break;
        }
    }
    if(is_clear==1)
    {
        sentence_location buffer;
        vector<unsigned int> positions=find_candidate(sentence,roots);
        for(vector<unsigned int>::iterator it_i=positions.begin();it_i!=positions.end();it_i++)
        {
            buffer.location=*it_i;
            buffer.frequency_array=(it_frequency_array+sentence.size()-2)->begin();
            candidate.push_back(buffer);
        }
    }
}


bool check_repeat(vector<string>& checklist,string buffer3)
{
    bool is_repeat=1;
     for(vector<string>::iterator it_i=checklist.begin();it_i!=checklist.end();it_i++)
     {
         if(it_i->compare(buffer3)==0)
         {
             is_repeat=0;
         }
     }
     return is_repeat;
}

void expand_or(vector<string>& sentence,vector<sentence_location>& candidate,vector< vector<unsigned int> >::iterator& it_frequency_array,Node** roots)
{
    bool is_clear=1;
    bool is_or_found=0;
    string buffer2;
    string buffer3;
    for(vector<string>::iterator it_i=sentence.begin();it_i!=sentence.end();it_i++)
    {
        for(string::iterator it_str=it_i->begin();it_str!=it_i->end();it_str++)
        {
            if(*it_str=='/')
            {
                is_clear=0;
                is_or_found=1;
                istringstream buffer1(*it_i);
                vector<string> cheklist;
                while(getline(buffer1,buffer2,'/'))
                {
                    if(check_repeat(cheklist,buffer2))
                    {
                        cheklist.push_back(buffer2);
                        buffer3=*it_i;
                        *it_i=buffer2;
                        expand_or(sentence,candidate,it_frequency_array,roots);
                        *it_i=buffer3;
                    }
                }
                break;
            }
        }
        if(is_or_found==1)
            break;
    }
    if(is_clear==1)
    {
        expand_star(sentence,candidate, it_frequency_array, roots);
    }
}

vector<string> erase_q(vector<string> sentence,int word)
{
    (sentence.begin()+word)->erase(0,1);
    return sentence;
}
vector<string> erase_word(vector<string> sentence,int word)
{
    sentence.erase(sentence.begin()+word);
    return sentence;
}
void expand_q(vector<string> sentence,vector<sentence_location>& candidate,vector< vector<unsigned int> >::iterator& it_frequency_array,Node** roots)
{
    bool is_clear=1;
    for(vector<string>::iterator it_i=sentence.begin();it_i!=sentence.end();it_i++)
    {
        if(((*it_i).at(0)=='?'))
        {
            is_clear=0;
            expand_q(erase_q(sentence,it_i-sentence.begin()),candidate,it_frequency_array,roots);
            expand_q(erase_word(sentence,it_i-sentence.begin()),candidate,it_frequency_array,roots);
            break;
        }
    }
    if(is_clear==1)
    {
        expand_or(sentence,candidate,it_frequency_array,roots);
    }
}


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

vector<unsigned int> find_candidate(vector<string> sentence,Node** roots)
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


bool sentence_location_compare(const sentence_location& first, const sentence_location& second)
{
    if(*(first.frequency_array+first.location)>*(first.frequency_array+first.location))
        return true;
    else
        return false;
}

int sentence_location_case(vector<unsigned int>::iterator frequency_array_in_sentence_location,vector< vector<unsigned int> >& frequency_array)
{
    if(frequency_array_in_sentence_location==frequency_array[0].begin())
        return 0;
    else if(frequency_array_in_sentence_location==frequency_array[1].begin())
        return 1;
    else if(frequency_array_in_sentence_location==frequency_array[2].begin())
        return 2;
    else
        return 3;
}




int main(int argc, char *argv[])
{
    print("ABCD")
    clock_t t1, t2, t3, t4, t5;
    //printf("%s\n","123");
    FILE* fp_2,*fp_3,*fp_4,*fp_5;

    char buff_c[100];
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
    t4=clock();
    t1 = clock();
    frequency_array[0].reserve(8430018);
    sentence_pos[0].reserve(8430018);
    fp_2=fopen("2gm.small.txt","r");

    //fp_2=fopen("/tmp2/dsa2017_hw02/2gm.small.txt","r");
    sentence_pos[0][0]=ftell(fp_2);
    while(fscanf(fp_2,"%s",buff_c)!=EOF)
    {
        insert_node(roots[0],buff_c,i,0);
        fscanf(fp_2,"%s",buff_c);
        insert_node(roots[0],buff_c,i,1);
        fscanf(fp_2,"%u",&buffer_d);
        frequency_array[0][i]=buffer_d;
        i++;
        sentence_pos[0][i]=ftell(fp_2)+1;
    }

    t2=clock();
    print((t2-t1)/double(CLOCKS_PER_SEC))
    print(i)
    i=0;
    print("node2 has been constructed")


    fp_3=fopen("3gm.small.txt","r");
    //fp_3=fopen("/tmp2/dsa2017_hw02/3gm.small.txt","r");
    frequency_array[1].reserve(15960930);
    sentence_pos[1].reserve(15960930);
    sentence_pos[1][0]=ftell(fp_3);
    while(fscanf(fp_3,"%s",buff_c)!=EOF)
    {
        insert_node(roots[1],buff_c,i,0);
        fscanf(fp_3,"%s",buff_c);
        insert_node(roots[1],buff_c,i,1);
        fscanf(fp_3,"%s",buff_c);
        insert_node(roots[1],buff_c,i,2);
        fscanf(fp_3,"%u",&buffer_d);
        frequency_array[1][i]=buffer_d;
        i++;
        sentence_pos[1][i]=ftell(fp_3)+1;
    }
    t1=clock();
    print((t1-t2)/double(CLOCKS_PER_SEC))
    print(i)
    i=0;
    print("node3 has been constructed")


    fp_4=fopen("4gm.small.txt","r");
    //fp_4=fopen("/tmp2/dsa2017_hw02/4gm.small.txt","r");
    frequency_array[2].reserve(11765370);
    sentence_pos[2].reserve(11765370);
    sentence_pos[2][0]=ftell(fp_4);
    while(fscanf(fp_4,"%s",buff_c)!=EOF)
    {
        insert_node(roots[2],buff_c,i,0);
        fscanf(fp_4,"%s",buff_c);
        insert_node(roots[2],buff_c,i,1);
        fscanf(fp_4,"%s",buff_c);
        insert_node(roots[2],buff_c,i,2);
        fscanf(fp_4,"%s",buff_c);
        insert_node(roots[2],buff_c,i,3);
        fscanf(fp_4,"%u",&buffer_d);
        frequency_array[2][i]=buffer_d;
        i++;
        sentence_pos[2][i]=ftell(fp_4)+1;
    }
    t2=clock();
    print((t2-t1)/double(CLOCKS_PER_SEC))
    print(i)
    i=0;
    print("node4 has been constructed")


    t2=clock();


    fp_5=fopen("5gm.small.txt","r");
    //fp_5=fopen("/tmp2/dsa2017_hw02/5gm.small.txt","r");
    frequency_array[3].reserve(5773240);
    sentence_pos[3].reserve(5773240);
    sentence_pos[3][0]=ftell(fp_5);
    while(fscanf(fp_5,"%s",buff_c)!=EOF)
    {
        insert_node(roots[3],buff_c,i,0);
        fscanf(fp_5,"%s",buff_c);
        insert_node(roots[3],buff_c,i,1);
        fscanf(fp_5,"%s",buff_c);
        insert_node(roots[3],buff_c,i,2);
        fscanf(fp_5,"%s",buff_c);
        insert_node(roots[3],buff_c,i,3);
        fscanf(fp_5,"%s",buff_c);
        insert_node(roots[3],buff_c,i,4);
        fscanf(fp_5,"%u",&buffer_d);
        frequency_array[3][i]=buffer_d;
        i++;
        sentence_pos[3][i]=ftell(fp_5)+1;
    }
    t1=clock();
    print((t1-t2)/double(CLOCKS_PER_SEC))
    print(i)
    print("node5 has been constructed")
    i=0;
    t5=clock();
    print("total time is ....")
    print((t5-t4)/double(CLOCKS_PER_SEC))


    string query;
    vector<sentence_location> candidate;
    char buffer_string[200];

    while(getline(cin,query))
    {
        vector<string> query_vec(constuct_string_vec(query));
        expand_q(query_vec,candidate,it_frequency_array, roots);
        partial_sort (candidate.begin(), candidate.begin()+5, candidate.end(),sentence_location_compare);
        for(vector<sentence_location>::iterator it_i=candidate.begin();it_i!=candidate.end();it_i++)
        {
            switch(sentence_location_case(it_i->frequency_array,frequency_array))
            {
                case 0:
                    {
                        fseek(fp_2, sentence_pos[0][it_i->location], SEEK_SET);
                        fgets(buffer_string,200,fp_2);
                        printf("%s",buffer_string);
                    }

                case 1:
                    {
                        fseek(fp_3, sentence_pos[1][it_i->location], SEEK_SET);
                        fgets(buffer_string,200,fp_3);
                        printf("%s",buffer_string);
                    }
                case 2:
                    {
                        fseek(fp_4, sentence_pos[2][it_i->location], SEEK_SET);
                        fgets(buffer_string,200,fp_4);
                        printf("%s",buffer_string);
                    }
                case 3:
                    {
                        fseek(fp_5, sentence_pos[3][it_i->location], SEEK_SET);
                        fgets(buffer_string,200,fp_5);
                        printf("%s",buffer_string);
                    }
            }
        }
    }


    t3 = clock();
    print((t3-t2)/double(CLOCKS_PER_SEC));


    fclose(fp_2);
    fclose(fp_3);
    fclose(fp_4);
    fclose(fp_5);
  return 0;
}
