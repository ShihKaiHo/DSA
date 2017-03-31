#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fstream>
#include <cstring>
#include <vector>
#include <ctime>
#include <sstream>
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')
#define print(a) cout<<a<<endl;
using namespace std;

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

void expand_star(vector<string> sentence)
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
                expand_star(replace_star(sentence,it_i-sentence.begin(),i));
            }
            break;
        }
    }
    if(is_clear==1)
    {
        for(vector<string>::iterator it_i=sentence.begin();it_i!=sentence.end();it_i++)\
            cout<<*it_i<<' ';
        cout<<endl;
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

void expand_or(vector<string>& sentence)
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
                        expand_or(sentence);
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
        expand_star(sentence);
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
void expand_q(vector<string> sentence)
{
    bool is_clear=1;
    for(vector<string>::iterator it_i=sentence.begin();it_i!=sentence.end();it_i++)
    {
        if(((*it_i).at(0)=='?'))
        {
            is_clear=0;
            expand_q(erase_q(sentence,it_i-sentence.begin()));
            expand_q(erase_word(sentence,it_i-sentence.begin()));
            break;
        }
    }
    if(is_clear==1)
    {
        expand_or(sentence);
    }
}


int main(int argc, char *argv[])
{
    clock_t t1, t2, t3, t4, t5;
    t1=clock();
    string query;
    while(getline(cin,query))
    {
        vector<string> query_vec(constuct_string_vec(query));
        expand_q(query_vec);
    }
    t2=clock();
    print((t2-t1)/double(CLOCKS_PER_SEC));
    return 0;
}


