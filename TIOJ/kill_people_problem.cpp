//http://tioj.infor.org/problems/1004
#include<iostream>

int survial(int n,bool start)
{
    if(n==1)
        return 1;
    if(start==0)
    {
        if(n%2==0)
            return 2*survial(n/2,0)-1;
        else
            return 2*survial((n+1)/2,1)-1;
    }
    else
    {
        if(n%2==0)
            return 2*survial(n/2,1);
        else
            return 2*survial(n/2,0);
    }


}


int main()
{
    int n;
    std::cin>>n;
    std::cout<<survial(n,0);

    return 0;
}
