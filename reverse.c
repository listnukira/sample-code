#include <stdio.h>

void reverse(char* str)
{
	// version 1
	/*
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
	*/

	// version 2
	///*
	char* end = str;
	char tmp;
	if (str) {
		while (*end) { // 找出字串尾端
			++end;
		}
		--end; // 往回一個字元，因為最後為 null
		
		// 前後互相交換
		while (str < end) {
			tmp = *str;
			*str++ = *end;
			*end-- = tmp;
		}

	}
	//*/
}

int main()
{
	char str[] = "abcdefghijklmn";

	printf("Before reverse: %s\n", str);

	reverse(str);

	printf("After reverse: %s\n", str);

	return 0;
}
