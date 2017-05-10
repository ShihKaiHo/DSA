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
        for(vector<string>::iterator it_i=sentence.begin();it_i!=sentence.end();it_i++)\
            cout<<*it_i<<' ';\
        cout<<endl;
    }
}



int main(int argc, char *argv[])
{
    vector<string> sentence;
    //string buffer;
    sentence.push_back("I/They/I");
    sentence.push_back("like");
    sentence.push_back("to");
    sentence.push_back("eat");
    sentence.push_back("apple/orange/peach");
    //vector<string>::iterator it_i=sentence.begin()+4;
    //string::iterator it_str=it_i->begin()+5;
    //buffer=it_i->substr(0,it_str-it_i->begin()+1);
    //print(*it_i)
    //*it_i=it_i->substr(it_str-it_i->begin()+1,it_i->end()-1-it_i->begin());
    //print(*it_i)
    //*it_i=buffer.append(*it_i);
    //print(*it_i)
    expand_or(sentence);





  return 0;

}


