#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "day3_lib.h"

#define SIZE(x) (sizeof(x) / sizeof((x)[0]))

#if 0

void func(char (*p)[10]) {
	printf("%d\n", sizeof(p));
	printf("%d\n", sizeof(p[0]));
	printf("%d\n", sizeof(*p));
	printf("%d\n", sizeof(**p));

	printf("\n");
}

void func2(char (*p)[5][10]) {
	printf("%d\n", sizeof(p));
	printf("%d\n", sizeof(p[0]));
	printf("%d\n", sizeof(*p));
	printf("%d\n", sizeof(**p));

	printf("\n");
}

/*
* void func3(char* p[5][10]) -> 배열은 함수 파라미터가 될 수 없음: 포인터임
* char* p[5][10] == char* (*p)[10]
* sizeof(p) = 4
* sizeof(*p) = 40
*/

void func4(char** p) {
	printf("%d\n", sizeof(p));
	printf("%d\n", sizeof(p[0]));
	printf("%d\n", sizeof(*p));
	printf("%d\n", sizeof(**p));

	printf("\n");
}

char (*func5(void))[10] {
	static char str[5][10] = { "apple", "banana", "orange"};
	return str; // char (*)[10]
}

int main(void) {
	char str[5][10];
	char* sarr[5] = { "apple", "banana", "kiwi" };


	printf("%d %d %d\n", sizeof(str[0]), sizeof(*str), sizeof(*(str + 2)));

	func(str);
	func2(&str);

	func4(sarr);

	char (*p)[10] = func5();

	return 0;
}

#endif


#if 0

//int (*func(int* arr))[5] {
//	return arr;
//}

int* func(int* arr) {
	return arr;
}

int main(void) {
	int arr[5] = { 1,2,3,4,5 };
	int* pa = 0;
	pa = func(arr);

	printf("%p %p\n", arr, pa);

	return 0;
}

#endif

#if 0

/*
* int (*p)[5]
* *p: int [5]
* **p: int
*/

/*
* int arr[5];
* arr: int * (배열의 이름은 배열과 포인터라는 양면성을 갖지만 다른 타입과 결합하여 쓰이지 않으면 포인터라고 표현)
* *arr: int
*/

/*
* p[0][1] = *(*p + 1), (*p)[1], *(p[0] + 1)
* p[1][2] = *(*(p + 1) + 2), (*(p + 1))[2], *(p[1] + 2)
* p[3][0] = **(p + 3), (*(p + 3))[0], *p[3]
*/

void func1(int (*p)[5]) {
	// 포인터, 포인터가 가리키는 요소 - 5개짜리 정수 배열, 정수 배열의 첫번째 요소 - 정수
	printf("%d %d %d\n", sizeof(p), sizeof(*p), sizeof(**p));  

	int n = sizeof(*p) / sizeof(**p); // SIZE(*p);
	for (int i = 0; i < n;i++) {
		*(*p + i) += 5;
	}
}

int main(void) {
	int arr[5] = { 1,2,3,4,5 };
	printf("%p %p %p\n", &arr, arr, &arr[0]);

	func1(&arr);
	print_data(arr, SIZE(arr));
	func1(&arr);
	print_data(arr, SIZE(arr));

	return 0;
}

#endif


#if 0

void func1(int (*p)[4], int r) {
	int c = SIZE(*p);
	int n = r * c;

	int* p2 = (int*)p; // = *p, p[0]

	// 연속 메모리인 점 활용 - 1차원과 고차원 배열의 물리적인 저장 구조는 같지만 고차원일수록 더 큰 단위의 포인터들을 가짐	
	for (int i = 0; i < n; i++)
		printf("%d ", *(*p + i)); 
		// printf("%d ", p[i / c][i % c]);

	printf("\n");
}

void func2(int (*p)[4], int r) {
	int c = SIZE(*p);
	int n = r * c;

	int (*p2)[6] = (int(*)[6])p; // int *p2[6] -> 행 몇개?

	int (*p3)[2][3] = (int (*)[2][3])p;
}

void func3(int (*p)[3][4]) {
	int r = SIZE(*p);
	int c = SIZE(**p);

	printf("r: %d, c: %d\n", r, c);
}

void func4(int (*p)[2][3][4]) {
	int k = SIZE(*p);
	int r = SIZE(**p);
	int c = SIZE(***p);

	printf("k: %d, r: %d, c: %d\n", k, r, c);
}

int main(void) {
	int arr[3][4] = { 1,2,3,4,5,6,7,8,9,10,11,12 };
	int b[2][3][4] = { 0 };

	func1(arr, SIZE(arr));
	func2(arr, SIZE(arr));
	//func2((int*)arr, sizeof(arr));

	/*
	* 지정초기화
	* int a[100] = { 1, 2, 3, [72] = 5, 6, [99] = 9 };
	* // a[0]=1, a[1]=2, a[2]=3, a[72]=5, a[73]=6, a[99]=9, 나머지는 0
	* 
	* int arr[3][4] = {
    *   [0][2] = 10,
    *   [2][1] = 20
    * };
	*/

	func3(&arr);
	func4(&b);

	return 0;
}

#endif

