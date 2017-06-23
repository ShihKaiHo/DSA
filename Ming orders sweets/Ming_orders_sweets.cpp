#include <cstdio>
#include <iostream>
#include <unordered_map>
#define MAX(x,y)	((x)>(y)?(x):(y))
#define MIN(x,y)	((x)<(y)?(x):(y))
using namespace std;

unordered_map<int,int> hash_table;

int hash_fun(int n, int money)
{
    return (n<<16) + money;
}
int satisfaction(int** sweet,int n, int money)
{
    if(hash_table.find(hash_fun(n,money)) != hash_table.end())
    {
        return hash_table[hash_fun(n,money)];
    }
    else if(n == 0)
    {
        int max_quanity = money / sweet[0][1];
        max_quanity = MIN(max_quanity, sweet[0][0]);
        hash_table[hash_fun(n,money)] = max_quanity*sweet[0][2];
        return max_quanity*sweet[0][2];
    }
    else
    {
        int max_quanity = money / sweet[n][1];
        max_quanity = MIN(max_quanity, sweet[n][0]);
        int max_satisfaction = -1;
        int temp;
        for(int i = 0; i<=max_quanity; i++)
        {
            temp = satisfaction(sweet,n-1,money-i*sweet[n][1]) + i*sweet[n][2];
            if(temp > max_satisfaction)
            {
                max_satisfaction = temp;
            }
        }
        hash_table[hash_fun(n,money)] = max_satisfaction;
        return max_satisfaction;
    }
}
int main()
{
    int n;
    int money;
    scanf("%d", &n);
    scanf("%d", &money);

    int** sweet = new int* [n];
    for(int i=0; i<n; i++)
    {
        sweet[i] = new int [3];
    }


    for(int i=0;i<n;i++)
    {
        scanf("%d %d %d",&sweet[i][0], &sweet[i][1], &sweet[i][2]);
    }
    printf("%d", satisfaction(sweet, n-1, money));


    for(int i=0; i<n; i++)
    {
        delete [] sweet[i];
    }
    delete sweet;

    return 0;
}
