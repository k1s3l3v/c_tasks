#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void main() {
    int i;
    scanf("%i", &i);
    if (i % 2 == 0) printf("even");
    else printf("odd");
}
