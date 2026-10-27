#include "day4_lib.h"

#if 0

int main(void) {
	char ch1, ch2;
	scanf("%c%c", &ch1, &ch2);
	printf("[%c%c]\n", ch1, ch2);

	scanf(" %c", &ch1);
	printf("[%c]\n", ch1);

	return 0;
}

#endif

#if 0


int main(void) {
	char ch;
	char str[30] = { 0, };
	//gets(str); // Enter는 문자로 입력 안받음
	//scanf("%c", &ch);

	//printf("[%s][%c]\n", str, ch);
	my_gets(str, SIZE(str));
	printf("%s\n", str);

	return 0;
}

#endif

#if 0

int main(void) {
	char name[40] = "Tom & Jerry!!~";
	printf("%s\n", to_upper(name));

	return 0;
}

#endif

#if 0

// https://jungol.co.kr/problem/2788

#include <stdio.h>

void sort(int* a, size_t size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (a[i] > a[j]) {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

int main(void) {
    int n;
    scanf("%d", &n);

    int a[1000], leaf;
    for (int i = 0; i < n; i++) {
        scanf("%d", &leaf);
        a[i] = leaf;
    }

    sort(a, n);
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");

    int jump_count = 0;
    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            int gap = a[j] - a[i];
            for (int k = j + 1; k < n; k++) {
                if (a[k] >= a[j] + gap && a[k] <= a[j] + 2 * gap) 
                    jump_count++;
            }
        }
    }
    printf("%d", jump_count);

    return 0;
}

#endif

#if 0

int main(void) {
    char str[10] = "apple";
    char* dessert1 = str;

    dessert1[0] = 'k'; // 가능: dessert1 => stack 영역을 가리키는 주소값
    dessert1 = "banana";
    //dessert1[0] = 'k'; // 불가능: Runtime Error, dessert1 => 문자열을 가리키는 주소값

    const char* dessert2 = str;
    dessert2 = "banana"; // 가능: dessert2 자체 값 변경 가능
    // dessert2[0] = 'k'; // 불가능: Compile Error, *dessert2가 상수화
    
    char* const dessert3 = str;
    //dessert3 = "something"; // 불가능: Compile Error, dessert3가 상수화
    dessert3[0] = 'h'; // 가능: *dessert3 변경 가능

    char const* const dessert4 = str;
    //dessert4 = "new";
    //dessert4[0] = 'w'; // 불가능: Compile Error, pointer & value 모두 상수화

    char* temp = dessert4;
    temp[0] = 'k';
    temp = "wow";

    return 0;
}

#endif

#if 0

#define A 3.14

void constTest(void) {
    const int a = 3.14;
    int c;
    c = A + a + 5;
    printf("%d\n", c);
}

int main(void) {
    constTest();
    return 0;
}

#endif

#if 0

int main(void) {
    extern int GetNum();
    extern void Increment();

    printf("num: %d\n", GetNum());
    Increment();
    printf("num: %d\n", GetNum());
    Increment();
    printf("num: %d\n", GetNum());
    Increment();
    printf("num: %d\n", GetNum());

    return 0;
}

#endif
