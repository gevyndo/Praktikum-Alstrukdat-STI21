#include <stdio.h>

int gura(int x,int y)
{
    return ~(~x&~y);
}
int garut(int x, int y)
{
    return(x|y);
}
int yamada(int x)
{
    return !(!((x+(~134)^(x+(~182)))>>31));
}
int fauna(int x, int n)
{
    return x>>(n<<3)&255;
}
int main()
{
    printf("%d\n", garut(5,6));
    printf("%d\n",gura(5,6));
    printf("%d\n",yamada(182));
}

