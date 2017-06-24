#include <cstdio>
#include <iostream>
#include <stack>

using namespace std;

struct land
{
    int height;
    int width;
    land()
    :width(1), height(0){}
};

int main()
{
    int input;
    stack<land> land_array;
    int trapped_water = 0;

    land temp;
    scanf("%d", &input);
    temp.height = input;
    land_array.push(temp);

    while(scanf("%d", &input) != EOF)
    {
        if(input == 0)
        {
            while(!land_array.empty())
            {
                land_array.pop();
            }
            if(scanf("%d", &input) != EOF)
            {
                temp.height = input;
                land_array.push(temp);
                continue;
            }
            else
            {
                break;
            }
        }
        else if(input < land_array.top().height)
        {
            temp.height = input;
            temp.width = 1;
            land_array.push(temp);
        }
        else
        {
            int counter=1;
            while(land_array.size() > 1 && land_array.top().height <= input)
            {
                trapped_water += (input - land_array.top().height)*land_array.top().width;
                counter += land_array.top().width;
                land_array.pop();
            }
            if(input < land_array.top().height)
            {
                temp.height = input;
                temp.width = counter;
                land_array.push(temp);
            }
            else if(land_array.size() == 1 && input >= land_array.top().height)
            {
                trapped_water -= (counter - 1)*(input - land_array.top().height);
                land_array.pop();
                temp.height = input;
                temp.width = counter;
                land_array.push(temp);
            }
        }
    }
    printf("%d",trapped_water);

    return 0;
}
