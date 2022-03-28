#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <malloc.h>

void reverse(char *dest) {
	int len, i;
	char* start, * end, temp;

	len = strlen(dest);
	start = dest;
	end = dest;

	for (i = 0; i < len - 1; i++) end++;

	for (i = 0; i < len / 2; i++) {
		temp = *end;
		*end = *start;
		*start = temp;

		start++;
		end--;
	}
}

int main() {
	char str[256], str_[256], cur_str[256], ch;
	int* gisto;
	int i = 0, spaces = 0, tabs = 0, enters = 0, j = 0, len_str = 0, n, flag = 0, spaces_ = 0;

	while ((ch = getchar()) != EOF) {
		str[i] = ch;
		str_[i] = ch;
		if (ch == ' ') spaces++;
		if (ch == '\n') enters++;
		if (ch == '\t' || str[i] == '\v') tabs++;
		if ((ch == '\t' || ch == ' ')) str_[i] = '\n';
		i++;
	}
	str[i] = '\0';
	str_[i] = '\0';
	for (i = 0; i < strlen(str_) - 1; i++) {
		if (str_[i] == '\n' && str_[i + 1] == '\n') while (str_[i + 1] == '\n') {
			for (j = i + 1; j < strlen(str_); j++) str_[j] = str_[j + 1];	
		}
		while (str_[i] == '~' || str_[i] == '|' || str_[i] == '_' || str_[i] == '-' || str_[i] == '+' || str_[i] == '#' || str_[i] == '(' || str_[i] == '*' || str_[i] == ')' || str_[i] == '&' || str_[i] == '/' || str_[i] == '.' || str_[i] == ',' || str_[i] == '?' || str_[i] == ':' || str_[i] == ';' || str_[i] == '!' || str_[i] == '"' || str_[i] == "'" || str_[i] == '@' || str_[i] == '%' || str_[i] == '`' || str_[i] == '{' || str_[i] == '}' || str_[i] == '[' || str_[i] == ']' || str_[i] == '=' || str_[i] == '<') {
			for (j = i; j < strlen(str_); j++) str_[j] = str_[j + 1];
		}
	}
	for (i = 0; i < strlen(str_); i++) if (str_[i] == '\n') spaces_++;
	printf("\nthere are %d spaces, %d enters and %d tabs\n", spaces, enters, tabs);
	j = 0;
	n = spaces_;
	gisto = (int*)malloc(n * sizeof(int));
	for (i = 0; i < n; i++) gisto[i] = 0;
	for (i = 0; i < strlen(str_); i++) {
		if (str_[i] == '\0') break;
		if (str_[i] == '\n') j++;
		else gisto[j]++;
	}
	puts(str_);

	puts("\nGISTO:\n.");
	for (i = 0; i < n; i++) {
		for (j = 0; j < gisto[i]; j++) printf("-");
		printf("\n");
		puts(".");
	}
	puts("\n");

	puts("LENGTH MORE THAN 80:");
	for (i = 0; i < strlen(str); i++) {
		if (str[i] != '\n') {
			cur_str[len_str] = str[i];
			cur_str[len_str + 1] = '\0';
			len_str++;
		}
		else {
			if (len_str > 80) puts(cur_str);
			len_str = 0;
		}
	}
	puts("\n");

	puts("REVERSE:");
	for (i = 0; i < strlen(str); i++) {
		if (str[i] != '\n') {
			cur_str[len_str] = str[i];
			cur_str[len_str + 1] = '\0';
			len_str++;
		}
		else {
			reverse(cur_str);
			puts(cur_str);
			len_str = 0;
		}
	}

	free(gisto);
	return 0;
}
