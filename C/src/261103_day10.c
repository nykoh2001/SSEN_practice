#define _CRT_SECURE_NO_WARNINGS
#define SIZE(x) sizeof((x)) / sizeof((x)[0])

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>


#if 0

typedef int (*fp)(int, int);

int func(int a, int b) {
	return a + b;
}

int main(void) {
	int temp = func;
	int result = ((fp)temp)(10, 20);
	printf("%d\n", result);

	return 0;
}

#endif


#if 0

#define ABS(x) ((x) >= 0 ? (x) : -1 * (x))
#define MIN(x, y) ((x) > (y) ? (y) : (x))
#define MAX(x, y) ((x) < (y) ? (y) : (x))
#define SWAP(x, y) { (x) = (x) ^ (y); (y) = (x) ^ (y); (x) = (x) ^ (y); }

int main(void) {
	int a = 10, b = 20;

	printf("ABS = %d\n", ABS(-1 * a));
	printf("MIN = %d\n", MIN(a, b));
	printf("MAX = %d\n", MAX(a, b));

	SWAP(a, b);
	printf("a = %d, b = %d\n", a, b);

	return 0;
}

#endif

#if 0

#define SOUND_DEVICE_TYPE 1

int main(void) {
	#if !SOUND_DEVICE_TYPE
	printf("No sound device.\n");
	#else

	// 컴파일 되는 경우 전처리 하면서 이미 에러 발생, 실행 불가
	#error CODE 10 : Unknown Device!

	#endif

	printf("Sound mode = %d\n", SOUND_DEVICE_TYPE);
}

#endif

#if 0

// __LINE__, __FILE__을 통해 디버깅 용이할 듯
#define Assert(x) { \
    if((x) >=4) printf("Range error : %s, %d\n", __FILE__, __LINE__);\
}

int main(void) {
	int a[4] = { 10,20,30,40 };
	int i;

	for (i = 0; i <= 4; ++i) {

// line 번호를 100으로 변경
#line 100

		Assert(i);
		printf("a[%d] = %d\n", i, a[i]);
	}
}

#endif

#if 0

#define string(x) printf(#x" is %d\n", x)       //문자열화 연산자
#define charr(x) printf("%c is %c\n", #@x, x)   //문자화 연산자, #@: 외따옴표

//#define concat(x,i) printf(#x###i" is %d\n", x##i)  //결합 연산자, #x###i => #x ## #i
#define concat(x,i) printf(#x#i" is %d\n", x##i)  //결합 연산자, #x###i => #x ## #i => #x#i

int main(void)
{
	int s = 10, c = 97, ca = 7, cb = 9;

	string(s); // printf("s"" is %d\n", s); => printf("s is %d\n", s);
	charr(c); // printf("%c is %c\n", 'c', c);
	concat(c, a); // printf("%s is %d\n", "a", ca);
	concat(c, b); // printf("%s is %d\n", "b", cb);
	
	return 0;
}

#endif

#if 1

//#define NDEBUG // 디버그 안함 - assert 동작 안함
#include <assert.h>

int main() {
	int x;
	printf("\nEnter an integer value: ");
	(void)scanf("%d", &x);
	assert(x >= 0); // Assertion failed, file/line 정보 같이 출력
	printf("You entered %d.", x);

	return(0);
}

#endif
