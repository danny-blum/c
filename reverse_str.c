#include <string.h>
#include <stdio.h>
#include <stdlib.h>



void *reverse_string(char *str, int len) {
    int low;
    int high;

    char c;

    for(low=0,high=len-1; low<high; low++,high--) {
	c = str[low];
	str[low] = str[high];
	str[high] = c;
    }
}




int main(int argc, char *argv[]) {

    char *s1 = "This is the first test.";
    char *s2 = "This is the second test.";

    char *str1 = malloc(strlen(s1)+1);
    char *str2 = malloc(strlen(s2)+1);
    strcpy(str1, s1);
    strcpy(str2, s2);

    reverse_string(str1, strlen(str1));
    reverse_string(str2, strlen(str2));

    printf("str1: %s\n", str1);
    printf("str2: %s\n", str2);
}
