#include "day4_lib.h"

void my_gets(char* str, int size) {
	int i;
	for (i = 0; i < size - 1; i++) {
		char ch = (char)getchar(); // getchar()는 ASCII 값을 int형으로 반환
		if (ch == '\n') break;

		str[i] = ch;
	}
	str[i] = 0; // 초기화가 안됐을 때도 동작하도록
}

char* to_upper(char* str) {
	int i = 0;
	while (str[i] != '\0') {
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] = str[i] - 32;
		i++;
	}
	return str;
}

/*
// 포인터 활용
char* to_upper(char* str) {
	while (*str != '\0') {
		if (*str >= 'a' && *str <= 'z') *str -= 32;
		str++;
	}
	return str;
}
*/

char* my_strcpy(char* to, const char* from) {
	char* save = to;
	for (;*to = *from;to++, from++);
	return save;
}

extern int num;

void Increment() {
	num++;
}

int GetNum() {
	return num;
}

