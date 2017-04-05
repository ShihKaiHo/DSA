#include <iostream>
#include <bitset>
#include <iomanip>
#define print(a) cout<<a<<'\n';
using namespace std;
unsigned long long nextMap(unsigned long long Map, int action);

enum map_action {a, w, d, s};


void print_map(unsigned long long& Map)
{
    int counter=60;
    for(int i=0;i<4;i++)
    {
        cout<<setw(4);
        for(int j=0;j<4;j++)
        {
            if((Map>>counter & 15)!=0)
                cout<<(1<<(Map>>counter & 15))<<setw(5);
            else
                cout<<"_"<<setw(5);
            counter-=4;
        }
        cout<<'\n';
    }
    cout<<'\n';
}


int main()
{
    unsigned long long Map=1;
    print_map(Map);
    map_action action;
    char input;
    while(cin>>input)
    {
        switch(input)
        {
            case 'a':
                Map=nextMap(Map, 0);
                print_map(Map);
                break;
            case 'w':
                Map=nextMap(Map, 1);
                print_map(Map);
                break;
            case 'd':
                Map=nextMap(Map, 2);
                print_map(Map);
                break;
            case 's':
                Map=nextMap(Map, 3);
                print_map(Map);
                break;
        }

    }

    return 0;
}
