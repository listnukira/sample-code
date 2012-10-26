#include <stdio.h>

void reverse(char* str)
{
	//unsigned int size = sizeof(*str) / sizeof(str[0]);
	unsigned int size = 0;
	char* p = str;
	while (*(p++) != '\0')
		++size;

	int i;
	for (i = 0; i < size / 2; ++i) {
		char tmp = *(str + i);
		*(str + i) = *(str + size - i - 1);
		*(str + size - i - 1) = tmp;
	}
}

int main()
{
	char str[] = "abcdefghijklmn";

	printf("Before reverse: %s\n", str);

	reverse(str);

	printf("After reverse: %s\n", str);

	return 0;
}
