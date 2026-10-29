#include "day7_lib.h"
#include "day3_lib.h"

#include <stdlib.h>

typedef struct _function_t {
	int (*fp)(int, int);
	char* name;
	int res;
} _function_t;

#if 0

int main(void) {
	int (*f[])(int, int) = {sum, sub, mul, divi, mod};

	// define -> 컴파일 타임에 알 수 있는 값 => 상수, 배열 크기로 선언에 사용 가능 / int size는 이미 변수이므로 불가능
	int size = SIZE(f);
	int *res = (int*)malloc(sizeof(int) * size);
	int total = 0;
	int a = 25, b = 6;

	for (int i = 0; i < size; i++) {
		res[i] = f[i](a, b);
		total += res[i];

		printf("res[%d]: %d\n", i, res[i]);
	}

	printf("total: %d\n", total);

	free(res);

	return 0;
}

#endif



#if 0

int main(void) {
	// define -> 컴파일 타임에 알 수 있는 값 => 상수, 배열 크기로 선언에 사용 가능
	_function_t func_arr[] = { { sum, "sum" },{ sub, "sub" },{ mul, "mul" },{ divi, "divi" },{ mod, "mod" } };
	_function_t* p = func_arr;

	// int size에 대입하는 순간 변수화
	int size = SIZE(func_arr);
	int total = 0;
	int a = 25, b = 6;

	//for (int i = 0; i < size; i++) {
	//	func_arr[i].res = func_arr[i].fp(a, b);
	//	total += func_arr[i].res;

	//	printf("%s(%d, %d) = %d\n", func_arr[i].name, a, b, func_arr[i].res);
	//}

	for (int i = 0; i < size; i++) {
		p->res = p->fp(a, b);
		total += p->res;

		printf("%s(%d, %d) = %d\n", p->name, a, b, p->res);
		++p;
	}

	printf("total = %d\n", total);

	return 0;
}


#endif

#if 0

typedef struct _score_t {
	int kor;
	int eng;
	int mat;
} score_t;

void print_score(score_t* arr, int n) {
	for (int i = 0; i < n; i++)
		printf("kor: %d, eng: %d, math: %d\n", arr[i]); // 구조체는 멤버 값 그대로 복사해서 전달 (배열도 그대로 복사)
		//printf("kor: %d, eng: %d, math: %d\n", arr[i].kor, arr[i].eng, arr[i].mat);
	printf("\n");
}

int compScore(void* a, void* b) {
	score_t* score_a = (score_t*)a;
	score_t* score_b = (score_t*)b;

	// ((score_t*)a)->mat (O)
	// (score_t*)a->mat (X): 후치 우선
	if (score_a->mat > score_b->mat) return 1;
	if (score_a->mat < score_b->mat) return -1;
	return 0;
}

int main(void) {
	int array[] = { 8,5,2,12,7,9,4,6,10,3 };
	double darray[] = { 3.14,3.139,4.65,5,2532.4634, -1.387, 2.24852, 17.29857 };
	char* sarray[] = { "kiwi", "melon", "banana", "orange", "strawberry" };
	int arr[][3] = { { 1,3,5 },{ 3,1,2 },{ 2,4,1 } };
	score_t students[] = { { 80, 90, 85 },{ 100, 80, 70 },{ 82, 60, 95 },{ 59, 98, 42 },{ 83, 95, 88 } };

	int size = SIZE(array);

	print_data(array, size);
	sort_array(array, size, comp_asc);
	print_data(array, size);
	sort_array(array, size, comp_desc);
	print_data(array, size);

	qsort(array, SIZE(array), sizeof(array[0]), compInt);
	print_data(array, size);


	print_doubledata(darray, SIZE(darray));
	qsort(darray, SIZE(darray), sizeof(darray[0]), compDouble);
	print_doubledata(darray, SIZE(darray));

	print_strdata(sarray, SIZE(sarray));
	qsort(sarray, SIZE(sarray), sizeof(sarray[0]), compStr);
	print_strdata(sarray, SIZE(sarray));

	// 1번 인덱스 요소 기준으로 오름차순 정렬
	print_2Darr(arr, SIZE(arr), SIZE(arr[0]));
	qsort(arr, SIZE(arr), sizeof(arr[0]), comp2D);
	print_2Darr(arr, SIZE(arr), SIZE(arr[0]));

	// 수학 점수 기준으로 오름차순 정렬
	print_score(students, SIZE(students));
	qsort(students, SIZE(students), sizeof(students[0]), compScore);
	print_score(students, SIZE(students));

	return 0;
}

#endif

#if 0

// 배열 포인터 리턴형
int (*get_array())[4] {
	static int arr[3][4] = { 0 };
	return arr;
}

// 함수 리턴형
int (*get_function(int idx)) (int, int) {
	static int (*fp[])(int, int) = { sum, sub, mul, divi };
	return fp[idx];
}

int main(void) {
	int (*fp)(int, int) = get_function(1);
	int (*ap)[4] = get_array();

	printf("%d - %d = %d\n", 20, 10, fp(20, 10));

	return 0;
}

#endif


#if 0

typedef int (*FP1) (int, int);
typedef FP1(*FP2) (int, int);

int main(void) {
	int (*(*p(int, int (*)(int, int)))(int, int))(int, int);
	FP2 q(int, FP1);
}

#endif


#if 0

typedef int (*FP) (int, int);

int main(void) {
	void* vp;
	int a = 10;
	double b = 3.14;
	
	vp = &a;
	printf("%d\n", *(int*)vp);

	vp = &b;
	printf("%.2lf\n", *(double*)vp);

	vp = sum;
	printf("%d\n", ((FP)vp)(10, 20));

	return 0;
}

#endif


#if 1

int main(void) {
	int* arr = (int*)malloc(sizeof(int) * 10);
	if (arr != 0)
		return 12;
	print_data(arr, SIZE(arr)); // 불가

	return 0;
}

#endif


/*
* 선택 과제:
* 화면에 선택지 출력 (1. sum, 2. sub, 3. ... 0. exit)
* 선택지 숫자를 입력 받아 실행 반복
*/
#if 0

int main(void) {
	_function_t func_p[] = { { sum, "sum" },{ sub, "sub" },{ mul, "mul" },{ divi, "div" },{ mod, "mod" } };


	return 0;
}

#endif


