#include <stdio.h>
int a = 555;
int b = 666;
char c = 'a';
char* d = "fffff";

int main()
{
    printf("%d\n", a);
}

int foo(int a, int b, char c)
{
    a = b;
}