#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n = 200;
    int i = 0;
    int j = 0;
    char s[10];

    if (n == 0)
    {
    putchar(n);
    }
    while (n > 0)
    {
    s[i] = n % 2;
    n = n / 2;
    ++i;
    }

    for (j = i - 1; j >= 0; --j)
    {
    printf("%d", s[j]);
    }
    putchar('\n');
    return 0;
}
