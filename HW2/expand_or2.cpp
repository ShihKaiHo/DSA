#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <cstring>
#include <vector>
#include <ctime>
#include <sstream>
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')
#define PRINT(sentence)     \
       for(vector<string>::iterator it_i=sentence.begin();it_i!=sentence.end();it_i++)\
            cout<<*it_i<<' ';\
        cout<<endl;
#define print(a) cout<<a<<endl;
using namespace std;
vector<string> sentencecut(vector<string> sentence,int word,int character_i,int length)
{
    sentence.at(word)=sentence.at(word).substr(character_i,length);
    return sentence;
}

void expand_or(vector<string> sentence)
{
    bool is_clear=1;
    bool is_or_found=0;
    string buffer;
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
    }
}
int main(int argc, char *argv[])
{
    vector<string> sentence;
    //string buffer;
    sentence.push_back("I/He/She/They");
    sentence.push_back("have/has");
    sentence.push_back("a/an");
    sentence.push_back("pan/apple");
    //vector<string>::iterator it_i=sentence.begin()+4;
    //string::iterator it_str=it_i->begin()+5;
    //buffer=it_i->substr(0,it_str-it_i->begin()+1);
    //print(*it_i)
    //*it_i=it_i->substr(it_str-it_i->begin()+1,it_i->end()-1-it_i->begin());
    //print(*it_i)
    //*it_i=buffer.append(*it_i);
    //print(*it_i)
    //cout<<sentence.at(it_i-sentence.begin()).substr(0,it_str-it_i->begin());
    expand_or(sentence);





  return 0;

}


