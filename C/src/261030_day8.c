#include "day3_lib.h"
#include "day7_lib.h"

#include <stdlib.h>
//
void free_mem(void** p) {
	if (p == NULL) return;
	free(*p);
	*p = NULL;
}

void free_mem2(void*** cp, int n) {
	if (cp == NULL) return;

	for (int i = 0; i < n; i++)
		free_mem(*cp + i);

	free_mem(cp);
}

char** get_data(int n) {
	char str[21];

	char** str_arr = (char**)calloc(n, sizeof(char*));
	if (str_arr == NULL) return 12;

	for (int i = 0; i < n; i++) {
		scanf("%s", str);
		//str_arr[i] = str; // str 값이 세개가 모두 동일, str이 포인터 상수이기 때문. (str 내용만 바뀜, str_arr[i]는 포인터이므로 모두 str을 가리킴)
		str_arr[i] = (char*)malloc(strlen(str) + 1); // (char*)calloc(sizeof(str), sizeof(char));

		if (str_arr[i] == NULL) {
			free_mem2(&str_arr, i - 1);

			return 12;
		}

		strcpy(str_arr[i], str);
	}

	return str_arr;
}

struct student {
	int num;
	double grade;
	char name[20];
	char* phone;
};

typedef struct student student_t;


#if 0

int main(void) {
	int n = 3;
	int* p = (int*)malloc(sizeof(int) * n);

	int count = 0;
	int num;

	if (p == NULL) {
		printf("Out of memeory\n");
		exit(1);
	}

	for (;scanf("%d", &num) && num > 0;count++) {
		if (count == n) {
			n += 3;
			int* ptemp = (int*)realloc(p, sizeof(int) * n);
			if (ptemp == NULL) {
				printf("Out of memory\n");
				free(p);
				exit(1);
			}

			if (p != ptemp) p = ptemp;
		}

		p[count] = num;
	}

	print_data(p, count);

	free(p);

	return 0;
}

#endif


#if 0

/*
* 복습:
* 
* char *str;
* char input[21];
* scanf("%s", input);
* 
* str = input; << 가능?
*/

typedef char c21[21];

int main(void) {
	int n = 3;
	// char *str_arr[3] >> char* 3개짜리 배열로 받는건? 확인 필요
	c21 *str_arr = (c21*)calloc(n, sizeof(c21)); // sizeof(*parr), sizeof(char[21])

	freopen("data.txt", "r", stdin);
	scanf("%d", &n);

	for (int i = 0; i < 3; i++) {
		scanf("%s", str_arr[i]);
	}

	printf("%d\n", n);
	for (int i = 0; i < 3; i++)
		printf("%s\n", str_arr[i]);

	return 0;
}

#endif


// str_arr[0] ~ str_arr[n-1] 메모리 각각 동적할당
#if 0

typedef char c21[21];

int main(void) {
	int n;

	freopen("data.txt", "r", stdin);
	scanf("%d", &n);

	char** str_arr = get_data(n);

	printf("%d\n", n);
	print_strdata(str_arr, n);

	free_mem2(&str_arr, n);

	//for (int i = 0; i < n; i++)
	//	printf("%p ", str_arr[i]);
	//printf("%p\n", str_arr);

	return 0;
}

#endif

/*
* 메모리를 따로 할당 받으면 메모리 누수 방지 처리 여러번 필요할 수 있음
* 할당 받은 메모리의 첫 (sizeof(char*) * 요소 개수) 바이트 메모리에 각 요소의 주소 계산해서 적어놓고
* 그 뒤에 차례대로 요소 대입
* 전체 사이즈대로 realloc -> 필요한 만큼만 남기기
* 포인터는 전체 메모리 영역 하나만
* => TODO: 구현 해보기
*/

#if 0

int main(void) {
	int n;
	char** str_arr = NULL;

	freopen("data.txt", "r", stdin);
	scanf("%d", &n);

	char** parr = NULL;
	parr = (char**)malloc(1000);
	
	if (parr == NULL) return 12;

	parr[0] = parr + n;
	printf("%p %p\n", parr, parr[0]);
	
	for (int i = 0; i < n; i++) {

	}

	return 0;
}

#endif


#if 0

void print_student(student_t a) {
	printf("%d %.1lf %s\n", a.num, a.grade, a.name);

	return 0;
};

void print_studentP(student_t* a) {
	printf("%d %.1lf %s\n", a->num, a->grade, a->name);

	return 0;
}

int main(void) {
	student_t a = { 1, 4.3, "Nayeon Ko", "010-1234-5678" }; // name: 포인터 상수, phone: 포인터 변수
	student_t b = a; // copy
	b.num = 2;

	print_student(a);
	print_student(b);

	print_studentP(&b);

	return 0;
}

#endif

#if 0

void init_student(student_t* p, int n) {
	student_t* temp = NULL;
	for (int i = 0; i < n; i++) {
		temp = p + i;
		scanf("%d %lf %s", &temp->num, &temp->grade, temp->name); // p[i].name : char *, &p[i].name: char (*)[] (포인터 배열)
	}
}

void print_student(student_t* p, int n) {
	student_t* temp = NULL;
	for (int i = 0; i < n; i++) {
		temp = p + i;
		printf("%d %.1lf %s\n", temp->num, temp->grade, temp->name);
	}
}

int main(void) {
	student_t s_arr[4] = { 0 };
	freopen("student.txt", "r", stdin);

	init_student(s_arr, SIZE(s_arr));
	print_student(s_arr, SIZE(s_arr));

	return 0;
}

#endif

// 포인터 멤버 배열에 동적 메모리 할당 받기
#if 1

typedef struct _profile {
	int age;
	char name[20];
	char *color[3];
} profile;

typedef struct _student {
	int num;
	double grade;
	profile prof;
} student;

void init_student(student* p, int n) {
	student* temp = NULL;

	//for (int i = 0; i < n; i++) {
	//	temp = p + i;
	//	
	//	scanf("%d %lf %d", &temp->num, &temp->grade, &temp->prof.age);
	//	
	//	char str[20];
	//	for (int j = 0; j < 3; j++) {
	//		scanf("%s", str);
	//		temp->prof.color[j] = (char*)malloc(sizeof(char) * (strlen(str) + 1)); // 동적 메모리 할당: 공간이 정해지지 않은 포인터에 대입 불가
	//		strcpy(temp->prof.color[j], str);
	//	}

	//	scanf("%s", temp->prof.name);
	//}

	/*
	* 여기선 profile alias 못하나?
	*/
	for (int i = 0; i < n; ++i) {
		scanf("%d %lf %d", &p[i].num, &p[i].grade, &p[i].prof.age);
		char (*arr)[10] = (char(*)[10])calloc(3, sizeof(char[10]));
		p[i].prof.color[0] = arr[0];
		p[i].prof.color[1] = arr[1];
		p[i].prof.color[2] = arr[2]; // -> 각 student 당 한번씩만 메모리 해제
		scanf("%s %s %s", p[i].prof.color[0], p[i].prof.color[1], p[i].prof.color[2]);
		scanf("%s", p[i].prof.name);
	}
}

void print_student(student* p, int n) {
	student* temp = NULL;
	profile prof;

	for (int i = 0; i < n; i++) {
		temp = p + i;
		prof = temp->prof;
		printf("%d %.2lf %d %s %s %s %s\n", temp->num, temp->grade, prof.age, prof.color[0], prof.color[1], prof.color[2], prof.name);
	}
}

void free_mem3(student* p, int n) {
	profile* prof = NULL;
	if (p == NULL) return;
	for (int i = 0; i < n; i++) {
		prof = &p[i].prof;
		free(prof->color[0]); // free(p[i].prof.color): 에러. 왜 안되는지 확인
		
		// memset(prof->color[0], 0, 12);
		prof->color[0] = 0;
		prof->color[1] = 0;
		prof->color[2] = 0;
	}
}

int main(void) {
	freopen("student2.txt", "r", stdin);
	student stu[3] = { 0 };

	init_student(stu, SIZE(stu));
	print_student(stu, SIZE(stu));
	
	//  메모리 해제
	free_mem3(stu, SIZE(stu));

	return 0;
}

#endif
