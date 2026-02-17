#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a, b, c, f;
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);
    
    if ((a<=b && a >=c)||(a>=b && a<=c)) f=a;
    if ((b<=a && b >=c)||(b>=a && b<=c)) f=b;
    if ((c<=a && c >=b)||(c>=a && c<=b)) f=c;
    printf("%d\n", f);
    
    return 0;
}
