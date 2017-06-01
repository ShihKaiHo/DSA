#include <cstdio>

unsigned long long factorial(unsigned long long n)
{
    if(n==1)
        return 0;
    if(n==2)
        return 1;
    return (n-1)*(factorial(n-1)+factorial(n-2));
}
int main()
{
    unsigned long long n;
    scanf("%llu",&n);
    do
    {
        printf("%llu\n",factorial(n));
        scanf("%llu",&n);
    }
    while(n!=0);
    return 0;
}
