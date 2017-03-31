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
int counter=0;
vector<string> sentencecut(vector<string> sentence,int word,int character_i,int length)
{
    sentence.at(word)=sentence.at(word).substr(character_i,length);
    return sentence;
}

void expand_or(vector<string> sentence)
{
    bool is_clear=1;
    bool is_or_found=0;
    for(vector<string>::iterator it_i=sentence.begin();it_i!=sentence.end();it_i++)
    {
        for(string::iterator it_str=it_i->begin();it_str!=it_i->end();it_str++)
        {
            if(*it_str=='/')
            {
                is_clear=0;
                is_or_found=1;
                expand_or(sentencecut(sentence, it_i-sentence.begin(),0,it_str-it_i->begin()));
                expand_or(sentencecut(sentence, it_i-sentence.begin(),it_str-it_i->begin()+1,it_i->end()-1-it_i->begin()));
                break;
            }
        }
        if(is_or_found==1)
            break;
    }
    if(is_clear==1)
    {
        for(vector<string>::iterator it_i=sentence.begin();it_i!=sentence.end();it_i++)\
            cout<<*it_i<<' ';\
        cout<<endl;
        counter++;
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
    vector<string> sentence;
    vector<string> sentence2;
    sentence.push_back("I/He/They/She");
    sentence.push_back("have/has");
    sentence.push_back("an/an");
    sentence.push_back("pan/apple");
    sentence.push_back("?pineapple/applepan");
    expand_q(sentence);
    cout<<counter;
    return 0;

}


