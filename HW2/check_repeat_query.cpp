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


bool check_repeat_query(vector<string> sentence,vector< vector<string> >& check_repeat_query_list)
{
    bool is_repeat=0;
    for(vector< vector<string> >::iterator it_i=check_repeat_query_list.begin();it_i!=check_repeat_query_list.end();it_i++)
    {
        if(it_i->size()==sentence.size())
        {
            int counter=0;
            for(vector<string>::iterator it_i_2=it_i->begin();it_i_2!=it_i->end();it_i_2++)
            {
                if(it_i_2->compare(sentence[it_i_2-it_i->begin()])==0)
                {
                    counter++;
                }
            }
            if(counter==sentence.size())
                return true;
        }
    }
    return false;
}


int main()
{
    vector<string> sentence1{"123","456","789"};
    vector<string> sentence2{"ABC","DEF","GHI"};
    vector<string> sentence3{"JKL","MNO","PQR"};
    vector<string> sentence4{"STU","VWX","YZ_"};
    vector<string> sentence5{"023","456","789"};
    vector<string> sentence6{"123","456","789","101112"};

    vector< vector<string> > check_repeat_query_list;
    check_repeat_query_list.push_back(sentence1);
    check_repeat_query_list.push_back(sentence2);
    check_repeat_query_list.push_back(sentence3);
    check_repeat_query_list.push_back(sentence4);

    cout<<check_repeat_query(sentence6,check_repeat_query_list);

    return 0;
}









