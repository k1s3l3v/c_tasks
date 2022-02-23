#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void distance();
void gcd();
void reverse();
void isprime();
void least();
long int factorial(long int);
int count_spaces(char* argv);

int main() {
	distance();
	gcd();
	reverse();
	isprime();
	least();
	factorial(5);
	count_spaces("h e l l o  !");
	return 0;
}

void distance() {
	int x1, y1, x2, y2;
	puts("Input coordinates of first point:");
	scanf("%d%d", &x1, &y1);
	puts("Input coordinates of second point:");
	scanf("%d%d", &x2, &y2);
	printf("%f\n", sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2)));
	return;
}

void gcd() {
	int a, b;
	int div = 1;
	puts("Input two numbers to check nod:");
	scanf("%d%d", &a, &b);
	for (int i = 1; i <= min(a, b); i++) if ((a % i == 0) && (b % i == 0) && (i > div)) div = i;
	printf("%d\n", div);
	return;
}

void reverse() {
	int num, i = 0;
	int num_[10];
	puts("Input number to reverse:");
	scanf("%d", &num);
	while (num != 0) {
		num_[i] = num % 10;
		num /= 10;
		i++;
	}
	for (int j = 0; j < i; j++) printf("%d", num_[j]);
	return;
}

void isprime() {
	int num, div = 1;
	puts("\nInput number to check prime is it or not:");
	scanf("%d", &num);
	for (int i = 1; i < num; i++) if (num % i == 0) div = i;
	if (div == 1) puts("prime"); else puts("not prime");
	return;
}

void least() {
	float a, b, c;
	puts("Input 3 numbers to find min of them:");
	scanf("%f %f %f", &a, &b, &c);
	printf("%f\n", min(min(a, b), min(b, c)));
	return;
}

long int factorial(long int n)
{
	long int z;
	if (n == 0 || n == 1) return 1;
	z = n * factorial(n - 1);
	printf("%li\n", z);
	return z;
}

int count_spaces(char* argv) {
	int count = 0;
	while (argv[0] != '\0') {
		if (argv[0] == ' ') count++;
		argv++;
	}
	printf("\n%d", count);
	return count;
}
