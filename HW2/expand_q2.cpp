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


