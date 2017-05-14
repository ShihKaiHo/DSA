#include <stdio.h>
#include <iostream>
using namespace std;
int main ()
{
  char c;
  puts ("Enter text. Include a dot ('.') in a sentence to exit:");
  do {
    scanf("%c",&c);
    cout<<c<<endl;
  } while (c != '.');
  return 0;
}
