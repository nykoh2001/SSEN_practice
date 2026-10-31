#include "day7_lib.h"

int sum(int a, int b) {
	return a + b;
}

int sub(int a, int b) {
	return a - b;
}

int mul(int a, int b) {
	return a * b;
}

int divi(int a, int b) {
	return a / b;
}

int mod(int a, int b) {
	return a % b;
}

int comp_asc(int a, int b) {
	return a > b;
}

int comp_desc(int a, int b) {
	return a < b;
}

// 교환 필요 시 1, 아닐 시 0
void sort_array(int* arr, int size, int(*comp)(int, int)) {
	for (int i = 0; i < size - 1; i++) {
		for (int j = i + 1; j < size; j++) {
			if (comp(arr[i], arr[j])) {
				swap(&arr[i], &arr[j]);
			}
		}
	}
}

/*
* a > b: 양수
* a == b: 0
* a < b: 음수
*
* 1) early return / 삼항 연산자 -> 연산 개수 최소화 가능
* 2) (a > b) - (b - a) -> 항상 >,-,< 3개 연산
* 
* 실제로는 컴파일러가 성능이 비슷하거나 같은 수준으로 최적화
* 따라서 가독서이 좋은 1)을 권장
*/
int compInt(const void* a, const void* b) {
	// void*는 형변환을 해줘야 사용 가능
	int ai = *(int*)a;
	int bi = *(int*)b;
	return (ai > bi) - (ai < bi);
}

int compDouble(const void* a, const void* b) {
	double ad = *(double*)a;
	double bd = *(double*)b;
	return (ad > bd) - (ad < bd);
}

void print_doubledata(double* arr, int size) {
	for (int i = 0; i < size; i++)
		printf("%.2lf ", arr[i]);
	printf("\n");
}

void print_strdata(char** str, int size) {
	for (int i = 0; i < size; i++) {
		printf("%s", str[i]);
		printf(" ");
	}
	printf("\n");
}

int compStr(void* str1, void* str2) {
	return strcmp(*(char**)str1, *(char**)str2);
}

void print_2Darr(int (*arr)[3], int r, int c) {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++)
			printf("%d ", arr[i][j]);
		printf("\n");
	}
	printf("\n");
}

int comp2D(const void* a, const void* b) {
	// int**로 형변환하면 왜 안되나? : arr + i 꼴이 인자로 들어옴, 컴파일러는 참조 시에 주소가 가리키는 값으로 가서 바로 읽어옴
	// 배열 포인터는 포인터가 가리키는 요소가 일반 요소보다 한차원 윗레벨에 있다는 것이 명시됨 -> 컴파일러가 알아차림
	int* arr1 = *(int(*)[3])a;
	int* arr2 = *(int(*)[3])b;
	
	/*
	* int* arr1 = a;
	* int* arr2 = b; 
	* 동작. 하지만 웬만해서는 void 앞에 캐스팅 붙여주자
	*/

	if (*(arr1 + 1) > *(arr2 + 1)) return 1;
	if (*(arr1 + 1) == *(arr2 + 1)) return 0;
	return -1;
}
