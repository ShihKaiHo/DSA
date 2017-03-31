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
<<<<<<< HEAD
if(is_clear==1)\
    {\
       for(vector<string>::iterator it_i=sentence.begin();it_i!=sentence.end();it_i++)\
            cout<<*it_i<<' ';\
        cout<<endl;\
    }
#define print(a) cout<<a<<endl;
using namespace std;

void expand_or(vector<string>& sentence)
{
    bool is_clear=1;
    bool is_or_found=0;
=======
       for(vector<string>::iterator it_i=sentence.begin();it_i!=sentence.end();it_i++)\
            cout<<*it_i<<' ';\
        cout<<endl;
#define print(a) cout<<a<<endl;
using namespace std;

void expand_or(vector<string> sentence)
{
    bool is_clear=1;
    bool is_or_found=0;
    string buffer;
>>>>>>> 9a1452cb7c7de8879e107525965936fcfb77beae
    for(vector<string>::iterator it_i=sentence.begin();it_i!=sentence.end();it_i++)
    {
        for(string::iterator it_str=it_i->begin();it_str!=it_i->end();it_str++)
        {
            if(*it_str=='/')
            {
<<<<<<< HEAD
                is_or_found=1;
                string buffer;
                //cout<<it_i-sentence.begin()<<' '<<it_str-it_i->begin()<<endl;
                is_clear=0;
                buffer=it_i->substr(it_str-it_i->begin(),it_i->end()-1-it_i->begin());
                *it_i=it_i->substr(0,it_str-it_i->begin());
                expand_or(sentence);
                (*it_i)+=buffer;

                buffer=it_i->substr(0,it_str-it_i->begin()+1);
                //print(*it_i)
                *it_i=it_i->substr(it_str-it_i->begin()+1,it_i->end()-1-it_i->begin());

=======
                is_clear=0;
                is_or_found=1;
                buffer=it_i->substr(it_str-it_i->begin(),it_i->end()-1-it_i->begin());
                *it_i=it_i->substr(0,it_str-it_i->begin());
                //PRINT(sentence)
                expand_or(sentence);
                (*it_i)+=buffer;
                buffer=it_i->substr(0,it_str-it_i->begin()+1);
                //print(*it_i)
                *it_i=it_i->substr(it_str-it_i->begin()+1,it_i->end()-1-it_i->begin());
                //PRINT(sentence)
>>>>>>> 9a1452cb7c7de8879e107525965936fcfb77beae
                expand_or(sentence);
                (*it_i)=buffer+(*it_i);
                break;
            }
<<<<<<< HEAD
            if(is_or_found!=0)
                break;
        }

    }
PRINT(sentence)
=======
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
>>>>>>> 9a1452cb7c7de8879e107525965936fcfb77beae
}



int main(int argc, char *argv[])
{
    vector<string> sentence;
<<<<<<< HEAD
    string buffer;
    sentence.push_back("I/they");
    sentence.push_back("like/hate");
    sentence.push_back("to");
    sentence.push_back("eat");
    sentence.push_back("apple/peach");
    vector<string>::iterator it_i=sentence.begin()+4;
    string::iterator it_str=it_i->begin()+5;
=======
    //string buffer;
    sentence.push_back("I/They");
    sentence.push_back("like/hate");
    sentence.push_back("to");
    sentence.push_back("eat/bite");
    sentence.push_back("apple/orange/peach");
    //vector<string>::iterator it_i=sentence.begin()+4;
    //string::iterator it_str=it_i->begin()+5;
>>>>>>> 9a1452cb7c7de8879e107525965936fcfb77beae
    //buffer=it_i->substr(0,it_str-it_i->begin()+1);
    //print(*it_i)
    //*it_i=it_i->substr(it_str-it_i->begin()+1,it_i->end()-1-it_i->begin());
    //print(*it_i)
    //*it_i=buffer.append(*it_i);
    //print(*it_i)
    expand_or(sentence);





  return 0;

}


