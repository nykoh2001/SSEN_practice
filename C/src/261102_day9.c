#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

#include "day7_lib.h"

#define SIZE(x) (sizeof(x) / sizeof((x)[0]))

#if 0

int main(void) {
	int a = 0x12345678;
	char c = a;

	printf("%X %X\n", a, c);

	return 0;
}

#endif

#if 0

typedef struct _color {
	unsigned int red: 8;
	unsigned int green : 8;
	unsigned int blue: 8;
	// 나머지 8비트는 공백
} color_t;

typedef struct _color_w_padding {
	unsigned int red : 8;
	unsigned int green : 8;
	unsigned int : 0; // 나머지 16비트 공백으로 채우기
	unsigned int blue : 8;
} color_w_padding_t;

int main(void) {
	color_t color = { 0x12,0x34,0x7856 }; // 12 34 56 00, 0x7856에서 LSB~2개 비트 잘려서 들어감
	color_w_padding_t color_w_p = { 0x12,0x34,0x7856 };

	printf("%d\n", sizeof(color));
	printf("%d\n", sizeof(color_w_p));

	return 0;
}

#endif

#if 0

typedef struct _IP_Header {
	uint8_t version : 4;
	uint8_t ihl : 4;
	uint8_t tos;
	uint16_t total_length;
	
	uint16_t identification;
	uint16_t flag_x : 1;
	uint16_t flag_d : 1;
	uint16_t flag_m : 1;
	uint16_t fragment_offset : 13;

	uint8_t ttl;
	uint8_t protocol;
	uint16_t checksum;

	uint32_t source_address;
	uint32_t destinatin_address;
	uint32_t ip_option;
} IP_Header;

#endif

// 메모리 효율
#if 0

typedef struct _bit {
	// 4byte 중 9bit 사용
	unsigned int a : 3;
	unsigned int b : 3;
	unsigned int c : 3;

	unsigned int d; // 추가하면 전체 8 바이트 - TODO: 메모리 상으로 어떻게 되는지 추가 조사하기
} bit_t;


int main(void) {
	bit_t x;
	bit_t* p;
	p = &x;

	// mov, and, or 등의 연산 실행
	x.a = 1; // a가 사용하는 3개 비트를 0으로 초기화 => 1 대입 - bit field는 메모리 절약 가능, 성능 관점에서는 떨어질 가능성
	x.b = 2; // 20 = 0x14 => LSB ~ 3bit만 남아서 0b100 = 4
	x.c = 3;
	printf("%d %d %d\n", x.a, x.b, x.c);
	printf("%d %d %d\n", p->a, p->b, p->c);
	
	printf("%X\n", x); // 11010001 ???????0 == 0xCCCCCCD1 (CCC... : 초기화된 적 없으므로 쓰레기값)
	printf("%X\n", *(char*)&x); // signed char -> signed int로 승격: 1로 left padding => 0xFFFFFFD1
	printf("%X\n", *(unsigned char*)&x); // unsigned char -> signed int로 승격: 0로 left padding => 0xD1

	return 0;
}

#endif

// 성능 효율
#if 0

typedef struct _bit {
	unsigned int a;
	unsigned int b;
	unsigned int c;
	unsigned int d; 
} bit_t;

int main(void) {
	bit_t x;

	x.a = 1;  // 1개 mov
	x.b = 2; 
	x.c = 3;

	printf("%d %d %d\n", x.a, x.b, x.c);

	return 0;
}

#endif



#if 0

typedef struct _bit {
	uint32_t a : 3;
	uint32_t b : 3;
	uint32_t c : 3;
} bit_t;

union bit_union {
	int a : 3;
	int b : 3;
	int c : 3;
};

int main(void) {
	bit_t X = { 1,2,3 };

	X = (bit_t){ 4,5,6 }; // C++에서는 지원 안됨 - 안쓰는게 낫다

	printf("%d %d %d\n", X.a, X.b, X.c);

	union bit_union Y = { 10 };
	printf("%d %d %d\n", Y.a, Y.b, Y.c); // 이렇게는 안씀 -  bit field 구조체를 한번에 정의하고 싶을 때 유니언 사용

	return 0;
}

#endif

#if 0

/*
* Union을 쓰는 이유:
* 같은 값에 대해 다른 단위를 갖는 멤버들을 한번의 대입으로 같이 변경
* 값을 한번에 입력받고 비트단위로 관리할때 + 그 값을 실시간으로 제어하려 할때
* 네트워크 프로토콜 헤더 필드처럼 비트 단위로 나누어진 메모리 공간에 특정 값을 효율적으로 설정
* 하나의 메모리 공간을 여러 멤버가 공유하여 동일한 데이터를 서로 다른 자료형이나 형태로 접근할 때 사용
* 레지스터 제어:
*	e.g.)
*	union register {
*		uint8_t all;
*		struct bits {
*			uint8_t mode: 3;
*			...
*		}
*	}
* 모터 제어:
* 
typedef struct _motor
{
    uint32_t pos : 8;
    uint32_t vel : 6;
    uint32_t acc : 6;
    uint32_t kp : 6;
    uint32_t kd : 6;
}motor_t;

typedef union _motor_control
{
    motor_t motor_param; // 전체를 나타내는 것을 먼저
    uint32_t command;
}motor_control_t;
*/

typedef struct rgb_t {
	uint32_t blue : 8;
	uint32_t green : 8;
	uint32_t red : 8;
} RGB_t;

// 멤버들이 사실상 같은 대상을 나타낼 때 union 사용?
typedef union pixelcolor {
	uint32_t color; // 순서 바꾸면 왜 안되는가: 초기화 식은 첫번째 멤버를 기준으로 수행 -> 초기화 값이 uint32이기 때문
	RGB_t rgb;
} pixel_t;

int main(void) {
	printf("%d %d\n", sizeof(RGB_t), sizeof(pixel_t));

	pixel_t X = { 0x123456 };
	printf("%X %X %X\n", X.rgb.red, X.rgb.green, X.rgb.blue);
	printf("%X\n", X.color);

	X.color = 0x7722DD;
	printf("%X %X %X\n", X.rgb.red, X.rgb.green, X.rgb.blue);

	return 0;
}

#endif

#if 0

// 순서대로 1, 2, 3
enum {KOR = 1, ENG, MAT};

int main(void) {
	int scores[4] = { 0, 90, 80, 85 };
	printf("%d\n", scores[KOR]);
	printf("%d\n", scores[KOR] + scores[MAT]);

	return 0;
}

#endif


#if 0

typedef struct _function_t {
	int (*fp)(int, int);
	char* name;
	char operator;
} function_t;

enum {EXIT, SUM, SUB, MUL, DIVI, MOD};

int get_command_no(function_t* func_arr, size_t size) {
	int cmd_no;

	printf("=========================================================\n");
	printf("| ");

	for (int i = 1; i < size; i++)
		printf("%d. %s | ", i, func_arr[i].name);
	
	printf("0. EXIT |\n");
	printf("=========================================================\n");

	scanf("%d", &cmd_no);

	if (cmd_no < 0 || cmd_no >= size)
		return 0;
	return cmd_no;
}

int main(void) {
	int a = 25, b = 6;
	function_t func_arr[] = {
		{ 0 },
		{ sum, "SUM", '+'},
		{ sub, "SUB", '-'},
		{ mul, "MUL", '*'},
		{ divi, "DIVI", '/'},
		{ mod, "MOD", '%'}
	};
	int cmd_no = 0;

#if 0
	// 연산을 반복하다가 cmd_no가 0이면 중단
	printf("do-while\n");
	while (cmd_no = get_command_no(func_arr, SIZE(func_arr))) {
		function_t* curr_func = &func_arr[cmd_no];
		printf("%s: %d %c %d = %d\n", curr_func->name, a, curr_func->operator, b, curr_func->fp(a, b));
	}

#elif 0
	// switch-case, enum으로 작성
	printf("Enum, Switch-case\n");
	function_t func;
	while (cmd_no = get_command_no(func_arr, SIZE(func_arr))) {
		switch (cmd_no) {
		case SUM:
		case SUB:
		case MUL:
		case DIVI:
		case MOD:
			func = func_arr[cmd_no];
			printf("%s: %d %c %d = %d\n", func.name, a, func.operator, b, func.fp(a, b));
			break;
		//default: // 코드 동작 상 모든 case를 다 거치고 오게 됨
			break;
		}
	}

#elif 1

	// 이 코드 동작 한번 보기
	function_t* fp;
	while (cmd_no = get_command_no(func_arr, SIZE(func_arr))) {
		/* cmd_no 유효하지 않으면 여기서 검사하거나 get_command_no에 넣는 식으로 */
		//if (cmd_no >= SIZE(func_arr) || cmd_no < 0) {
		//	printf("Invalid input\n");
		//	continue;
		//}

		switch (cmd_no) {
		case SUM:
		case SUB:
		case MUL:
		case DIVI:
		case MOD: 
			fp = func_arr + cmd_no;
		default:
			continue; // 필수: 없으면 컴파일 에러 (정의되지 않은 fp 사용 가능성)
		}

		printf("***********************\n");
		printf("[%s]: %d %c %d = %d\n", fp->name, a, fp->operator, b, fp->fp(a, b));
		printf("***********************\n");
	}

#endif
	
	return 0;
}

#endif

#if 1

typedef char (*C_10_P)[10];
typedef int (*FUNC)(C_10_P, int);

int printAry(C_10_P ary, int size) {
	int i;
	for (i = 0; i < size; i++) {
		printf("%s ", ary[i]);
	}
	printf("\n");
}

int main(void) {
	char fruit[][10] = { "apple", "melon", "cherry" };
	FUNC fn;
	fn = printAry;
	fn(fruit, sizeof(fruit) / sizeof(fruit[0]));
	
	return 0;
}

#endif
