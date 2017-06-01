//http://tioj.infor.org/problems/1003
#include <iostream>

unsigned long long cup_pizza(int n)
{
    if(n==1)
    {
        return 2;
    }
    else
    {
        return  cup_pizza(n-1)+n;
    }
}


int main()
{
    int n;
    std::cin>>n;
    std::cout<<cup_pizza(n);
    return 0;
}
