#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <cstring>
#include <vector>
#include <ctime>
#include <sstream>
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')
using namespace std;

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

int main(int argc, char *argv[])
{
    vector<string> sentence;
    sentence.push_back("*");
    sentence.push_back("second");
    sentence.push_back("*");
    sentence.push_back("fourth");
    sentence.push_back("*");
    expand_star(sentence);
  return 0;

}
