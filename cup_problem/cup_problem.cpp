#include <cstdio>
#include <iostream>
using namespace std;

class cup
{
    public:
    int stored_water;
    int max_capacity;
    cup(int n=0)
    :stored_water(0), max_capacity(n)
    {
    }
    void fill();
    void empty();
    void pour(cup&);
};

void cup::fill()
{
    stored_water=max_capacity;
}

void cup::empty()
{
    stored_water=0;
}

void cup::pour(cup& cup_2)
{
    int n=cup_2.max_capacity-cup_2.stored_water;
    if(this->stored_water<n)
    {
        cup_2.stored_water+=this->stored_water;
        this->empty();
    }
    if(this->stored_water>=n)
    {
        this->stored_water-=n;
        cup_2.fill();
    }

}



int main()
{
    cup first(3);
    cup second(5);
    second.fill();
    second.pour(first);
    first.empty();
    second.pour(first);
    second.fill();
    second.pour(first);
    first.pour(second);
    second.empty();
    second.pour(first);
    second.fill();
    second.pour(first);
    first.empty();
    second.pour(first);
    printf("first: %d/%d\n",first.stored_water,first.max_capacity);
    printf("second: %d/%d",second.stored_water,second.max_capacity);
    return 0;
}
