#include <stdlib.h>
#include <stdio.h>

char *int_to_hex_str(unsigned int n)
{
    char *str = malloc(9 * sizeof(char));
    int num_digits = 0;
    int hex_digit;

    if (n == 0)
    {
        str[0] = '0';
        str[1] = '\0';
        return str;
    }

    for (int i=7; i>=0; --i)
    {
        hex_digit = (0xf<<(4*i) & n) >> (4*i);
        if (hex_digit || num_digits)
        {
            if (hex_digit < 10)
                str[num_digits] = hex_digit + '0';
            else
                str[num_digits] = (hex_digit-10) + 'a';
 
            num_digits++;
        }
    }

    str[num_digits] = '\0';

    return str;
}

void test(unsigned int n)
{
    printf("test 1 -- u:%u x:0x%x: s:%s\n", n, n, int_to_hex_str(n));
}

int main(int argc, char *argv[])
{
    test(4345);
    test(4);
    test(0);
    test(234876655);
    test(0xffffffff);
    test(98745937);
    test(123456789);
    test(987654321);
 
    return 0; 
}
