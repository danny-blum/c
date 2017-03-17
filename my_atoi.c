#include <stdio.h>
#include <string.h>



#define MAX_LEN 200

int my_atoi(const char *str) {
    int val = 0;
    int i;
    int len = strnlen(str, MAX_LEN);
    char c;
    int place_val;
    int mult = 1;

    for (i=len-1; i>=0; i--) {
	c = str[i];
	place_val = c - '0';
	val += place_val * mult;
	mult *= 10;
    }

    return val;
}


int main(int argc, char *argv[]) {
    int testval;

    testval = my_atoi("12345");
    printf("Test 1: %d\n", testval);

    testval = my_atoi("987654");
    printf("Test 2: %d\n", testval);

    return 0;
}
