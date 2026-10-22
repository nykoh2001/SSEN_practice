#if 0

#include <stdio.h>

int main(void) {
	float a = 1.2345678901234567890f;
	double b = 1.234567890123456789;

	printf("%.20f\n", a);
	printf("%.20f\n", b);

	float c = 3.999999f;

	printf("%d\n", (int)c);
	
	return 0;
}

#endif

#if 0

#include <stdio.h>

int main(void) {
	const double tax_rate = 0.12;

	double* dp = &tax_rate;
	*dp = 0.14;

	printf("%.2lf\n", tax_rate);

	return 0;
}

#endif


#if 0

#include <stdio.h>

// cp를 통해 캐릭터를 바꿀 수 없음
const char* cp = "rabbit";

// cp의 재할당/변경 불가
//char* const cp = "rabbit";

cp = "cat";
cp[0] = 'A';

printf("%s\n", cp);


#endif

#if 0

#include <stdio.h>

int mystrlen(const char *str) {
	const char* s;

	if (str == 0)
		return 0;
	for (s = str; *s; ++s);
	return s - str; // pointer 빼기 연산: 두 포인터 사이의 요소 개수
}

int main(void) {
	//char name[10] = "Rabbit";
	//int a = mystrlen(name);
	int a = mystrlen("Apple");

	printf("%d\n", a);

	return 0;
}

#endif

#if 0

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int a;
	scanf("%d", &a);
	printf("%d\n", a);

	return 0;
}

#endif

#if 0

#include <stdio.h>

int main(void) {
	int a = -1;
	unsigned int b = 1;
	if (a < b) {
		printf("a is less than b");
	}
	else {
		printf("a is not less than b");
	}
}

#endif

#if 0

#include <stdio.h>

int main(void) {
	int a = 10, b = 20;
	int res;

	res = (a > b) ? a : b;

	if (a > b) {
		res = a;
	}
	else {
		res = b;
	}

	printf("%d\n", res);

	return 0;
}

#endif


#if 0

#include <stdio.h>

unsigned int setBit(unsigned int num, unsigned int bitPosition) {
	return (1 << bitPosition) | num;
}

unsigned int clearBit(unsigned int num, unsigned int bitPosition) {
	return ~(1 << bitPosition) & num;
}

unsigned int toggleBit(unsigned int num, unsigned int bitPosition) {
	return (1 << bitPosition) ^ num;
}

int main(void) {
	unsigned int num = 0b1010;
	printf("%X\n", setBit(num, 2));
	printf("%X\n", clearBit(num, 1));
	printf("%X\n", toggleBit(num, 3));

	return 0;
}

#endif
