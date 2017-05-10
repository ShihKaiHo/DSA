#include <iostream>
#include <stdlib.h>
#include <stdio.h>
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



int main(int argc, char *argv[])
{
    string query("?members * be appointed/to/without by");
    getline(cin,query);
    vector<string> query_vec(constuct_string_vec(query));
    for(vector<string>::iterator it_i=query_vec.begin();it_i!=query_vec.end();it_i++)
    {
        print(*it_i);
    }
    return 0;
}
