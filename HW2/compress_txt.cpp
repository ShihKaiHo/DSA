#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

struct dictionary
{
    string first;
    string second;
    //string third;
    //string fourth;
    //string fifth;
    unsigned int frequency;
    dictionary()
    {
        first="\0";
        second="\0";
        frequency=0;
    }

};

int main(int argc, char *argv[])
{
    vector<dictionary> ii_dictionary;
    ifstream ii_gm("2gm.small.txt",ios::in);
    ofstream ii_super_small("2gm.small.supersmall.txt");
    dictionary buffer;
    for(int i=0;ii_gm.good();i++)
    {
        ii_gm>>buffer.first;
        ii_gm>>buffer.second;
        ii_gm>>buffer.frequency;
        if(i%1000==0)
        {
            ii_super_small<<buffer.first<<' '<<buffer.second<<'\t'<<buffer.frequency<<' ';
            ii_dictionary.push_back(buffer);
        }
    }

    ii_gm.close();
    ii_super_small.close();
  return 0;
}

