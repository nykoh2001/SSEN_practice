#include "day3_lib.h"

#if 1

struct myfunc_t {
	int (*func)(int*, int*);
	char* fname;
};

int main(void) {
	int score[5] = { 0 };
	int size = SIZE(score);

	input_data(score, size);
	print_data(score, size);

	printf("total = %d\n", sum_data(score, size));
	printf("average = %.2lf\n", avg_data(score, size));

	printf("max = %d\n", findmax_ary(score, size));
	printf("min = %d\n", findmin_ary(score, size));
	
	sort_ary(score, size);
	print_data(score, size);

	// 함수 포인터
	int (*fp)(int*, int*) = sum_data;
	printf("fp = %d\n", fp(score, size));

	// 함수 포인터 배열
	int(*fp_list[3])(int*, int*) = { sum_data, findmax_ary, findmin_ary };
	char* fname[] = { "total", "max", "min" };

	// 구조체로 맵핑
	struct myfunc_t myfunc_arr[] = {
		{ sum_data, "total" },
		{ findmax_ary, "max" },
		{ findmin_ary, "min" }
	};
	
	for (int i = 0; i < SIZE(myfunc_arr); i++) 
		printf("fp[%d] (%s): %d\n", i, myfunc_arr[i].fname, myfunc_arr[i].func(score, size));
	

	return 0;
}

#endif


#if 0

#include <string.h>

int main(void) {
	char str1[80] = "cat";
	char str2[80];

	strcpy(str1, "tiger");
	strcpy(str2, str1);

	printf("%s, %s\n", str1, str2);

	char str[80];
	scanf("%s", str); // 공백 포함 불가, I am a boy[enter] -> 'I', '\0', 줄바꿈도 문자로 인식됨
	gets(str); // " am a boy\0", Enter 대신 null

	printf("Input string: %s\n", str);

	char ch;
	scanf("%c", &ch);
	printf("%c\n", ch);

	scanf("%c", &ch);
	printf("-%c-", ch);

	return 0;
}

#endif


#if 0

int main(void) {
	char str[80] = "apple"; // read/write가 가능한 메모리 공간 확보 -> read-only 공간의 문자열을 복사
	char* p1 = str;
	char* p2 = "banana";

	// 포인터 상수: str, "apple", "banana" - 배열이름/문자열로 보이지만 내부적으로 주소값
	// 포인터 변수: p1, p2 
	// p1: 참조를 통한 char 읽고 쓰기 가능
	// p2: 참조를 통해 char 읽기만 가능
	printf("%s\n", "apple" + 2); // "apple" -> a의 주소값으로 인식 => 출력값 ple (%s -> null 나올때까지 출력)
	printf("%c\n", "banana"[3]);

	// str = "banana"; // 포인터 상수, write 불가 - str이나 p2가 가리키는 값 자체는 변경 가능
	p2[0] = 'k'; // 런타임 에러, readonly 메모리에 write

	return 0;
}

#endif

#if 0

int main() {
	int a = 10, b = 20;

	printf("a: %d, b: %d\n", a, b);
	swap(&a, &b);
	printf("a: %d, b: %d\n", a, b);
	
	return 0;
}

#endif
