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

void expand_q(vector<string>& sentence)
{
    string buffer;
    bool is_clear=1;
    for(vector<string>::iterator it_i=sentence.begin();it_i!=sentence.end();it_i++)
    {
        if(((*it_i).at(0)=='?'))
        {
            is_clear=0;
            (*it_i).erase(0,1);
            expand_q(sentence);
            (*it_i).insert(0,"?");
            buffer=*it_i;
            sentence.erase(it_i);
            expand_q(sentence);
            sentence.insert(it_i,buffer);
            break;
        }
    }
    if(is_clear==1)
    {
       for(vector<string>::iterator it_i=sentence.begin();it_i!=sentence.end();it_i++)
            cout<<*it_i<<' ';
        cout<<endl;
    }
}



int main(int argc, char *argv[])
{
    vector<string> sentence;
    vector<string> sentence2;
    sentence.push_back("first");
    sentence.push_back("?second");
    sentence.push_back("?third");
    sentence.push_back("?fourth");
    sentence.push_back("?fifth");
    expand_q(sentence);



  return 0;

}


