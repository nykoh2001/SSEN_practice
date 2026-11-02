#define _CRT_SECURE_NO_WARNINGS
#define STR_MAX_LEN 21

#include <stdio.h>
#include <stdlib.h>

#if 0
int main(void) {
	int n;

	freopen("data.txt", "r", stdin);
	scanf("%d", &n);

	char str[STR_MAX_LEN];
	const size_t max_byte = sizeof(str) * n + sizeof(char*) * n;

	char** str_arr = (char**)malloc(max_byte);
	char* curr_pointer = (char*)str_arr + sizeof(char*) * n;

	if (str_arr == NULL) return 12;

	for (int i = 0; i < n; ++i) {
		scanf("%20s", str);
		str_arr[i] = curr_pointer;

		int length = strlen(str) + 1;
		strcpy(curr_pointer, str);
		curr_pointer += length;
	}

	printf("Before realloc: %p, (size: %d)\n", str_arr, max_byte);
	for (int i = 0; i < n; ++i)
		printf("%p: %s\n", str_arr[i], str_arr[i]);

	size_t used_size = curr_pointer - (char*)str_arr;
	char** temp = (char**)realloc(str_arr, used_size);
	if (temp == NULL) {
		free(str_arr);
		return 12;
	}
	/*
	* 중요: 재할당 후 주소가 바뀌었을 경우 기존의 문자열들을 가리키는 포인터 값 변경
	*/
	if (temp != str_arr) {
		size_t offset = (char*)temp - (char*)str_arr;
		for (int i = 0; i < n; i++)
			temp[i] += offset;
	}

	str_arr = temp;
	printf("After realloc: %p, (size: %d)\n", str_arr, used_size);

	char** str_ptr = str_arr;
	for (int i = 0; i < n; ++i) {
		printf("%p: %s\n", str_ptr[i], str_ptr[i]);
	}

	free(str_arr);

	return 0;
}
#endif
