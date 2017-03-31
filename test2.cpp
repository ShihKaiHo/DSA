
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
    unsigned int frequency;
};

int main(int argc, char *argv[])
{
    vector<dictionary> ii_dictionary(10);
    ifstream ii_gm("2gm.small.supersmall.txt",ios::in);
    dictionary buffer;

    for(int i=0;ii_gm.good();i++)
    {
        ii_gm>>buffer.first;
        ii_gm>>buffer.second;
        ii_gm>>buffer.frequency;
        ii_dictionary.push_back(buffer);

        cout<<ii_dictionary.at(i).first<<endl;
    }
    cout<<"end";

    ii_gm.close();
  return 0;
}
