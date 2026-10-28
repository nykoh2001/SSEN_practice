#include "day6_lib.h"

#if 0

int main(void) {
	int a[3][4] = { 0 };
	printf("%d\n", sizeof(a[-1])); // 범위 밖의 배열 이름도 배열 취급

	return 0;
}

#endif

#if 0

int main(void) {
	int a[3][4] = { 100, 324,4264,235,6246,7234,212,35,442,644,7,82 };
	print_2D(&a);

	return 0;
}

#endif

#if 0

int main(void) {
	int a = 10, b = 5;
	int* ap = &a, *bp = &b;
	int** app = &ap, **bpp = &bp;

	printf("%d %d %p %p %p %p\n", a, b, ap, bp, app, bpp);

	exchange0(&a, &b);
	printf("%d %d %p %p %p %p\n", a, b, ap, bp, app, bpp);

	exchange1(&ap, &bp);
	printf("%d %d %p %p %p %p\n", a, b, ap, bp, app, bpp);

	exchange2(&app, &bpp);
	printf("%d %d %p %p %p %p\n", a, b, ap, bp, app, bpp);

	exchange3(&ap, &bp);
	printf("%d %d %p %p %p %p\n", a, b, ap, bp, app, bpp);

	exchange4(&app, &bpp);
	printf("%d %d %p %p %p %p\n", a, b, ap, bp, app, bpp);

	exchange5(&app, &bpp);
	printf("%d %d %p %p %p %p\n", a, b, ap, bp, app, bpp);

	return 0;
}

#endif

#if 0

int add(int a, int b) {
	return a + b;
}

void func1(int (*p)(int, int)) {
	printf("%d\n", p(10, 20));
}

void func2(int (**p)(int, int)) {
	printf("%d\n", (*p)(10, 20)); // 주의: 포인터 우선처리
}

int main(void) {
	int (*f)(int, int) = add;
	int a = 10, b = 20;
	int (*fp[5])(int, int) = { add }; // 함수 포인터 배열

	printf("%d + %d = %d\n", a, b, f(a, b));
	//printf("%d\n", **add(a, b)); // add는 후치 연산을 먼저
	
	/*
	* 함수 이름의 주소와 참조 값이 같은 이유:
	* 컴파일 -> 함수 코드가 기계어로 번역되어 text segment에 저장됨
	* 함수 이름은 사용될 때에 함수 코드가 시작되는 메모리 주소를 나타내는 포인터로 전환됨
	* 
	* 함수 이름의 자동 변환:
	* 함수 이름을 그대로 쓰면 -> 함수가 시작하는 주소를 가리키는 포인터
	* 함수의 주소 -> 함수가 시작하는 주소
	* 
	* 무한 루프 규칙(Function Designator):
	* 함수 이름을 역참조 -> 함수 원본으로 가라는 뜻
	* C 표쥰에서 함수는 식 자체로 사용될 수 없음
	* 컴파일러가 역참조를 함수가 시작하는 주소를 가리키는 포인터로 복구
	*/
	printf("%p %p %p %p\n", add, *add, **add, &add);

	func1(f);
	func2(fp);

	return 0;
}

#endif


#if 0

void func(char** p, size_t size) {
	for (int i = 0; i < size; i++)
		printf("%s ", p[i]);
}

int main(void) {
	char* parray[5] = { "hello", "world", "apple", "banana", "what else" };
	func(parray, SIZE(parray));

	return 0;
}

#endif


#if 1

void func(int** parray, int size) {
	for (int arr_idx = 0; arr_idx < size; arr_idx++) {
		int* current_array = parray[arr_idx];
		int current_size = *current_array;

		for (int num_idx = 1; num_idx <= current_size; num_idx++)
			printf("%d ", current_array[num_idx]);
		
		printf("\n");
	}
}

int main(void) {
	int a[] = {3, 1, 2, 3};
	int b[] = { 5,10,20,30,40,50 };
	int c[] = { 4,5,6,7,8 };

	int* array[] = { a, b, c };
	func(array, SIZE(array));

	return 0;
}

#endif



