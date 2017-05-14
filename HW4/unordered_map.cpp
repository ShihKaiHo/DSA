#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

int main()
{
    unordered_map<int,string> test;
    test.emplace(1,"a");
    test.emplace(2,"b");
    test.emplace(3,"c");
    test.emplace(4,"d");
    test.emplace(5,"e");
    test.emplace(6,"f");
    test.emplace(7,"g");
    auto i=test.begin();
    auto j=test.begin();
    j++;
    auto temp=i;
    i=j;
    j=temp;

    for(auto it=test.begin();it!=test.end();it++)
    {
        cout<<it->first<<" "<<it->second<<endl;
    }



    return 0;
}
