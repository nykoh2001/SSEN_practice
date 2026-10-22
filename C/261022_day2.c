#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#if 0

unsigned int setBits(unsigned int num, unsigned int start, unsigned int count) {
	return num | ((1u << count) - 1u) << start;
}

unsigned int clearBits(unsigned int num, unsigned int start, unsigned int count) {
	return num & ~(((1u << count) - 1u) << start);
}

unsigned int toggleBits(unsigned int num, unsigned int start, unsigned int count) {
	return num ^ ((1u << count) - 1u) << start;
}

// 여기서 static 선언 이유는 없음 - static 선언 시에 해당 파일 내부에서만 사용 (Internal Linkage)
static unsigned int isBitSet(unsigned int num, unsigned int bitPosition) {
	return (num >> bitPosition) & 1u;
}

int main(void) {
	int num = 0b10101010;

	printf("%X\n", setBits(num, 2, 3));
	printf("%X\n", clearBits(num, 2, 3));
	printf("%X\n", toggleBits(num, 2, 3));

	unsigned int number;
	unsigned int bitPosition;

	printf("Enter a number: ");
	scanf("%u", &number);

	printf("Enter bit position to check: ");
	scanf("%u", &bitPosition);

	printf("bit: %u\n", isBitSet(num, bitPosition));
	
	return 0;
}

#endif

#if 0

int main(void) {
	unsigned int number;
	unsigned int d1, d2, d3, d4;
	
	scanf("%d", &number);

	d4 = number / 1000;
	d3 = number / 100 % 10;
	d2 = number / 10 % 10;
	d1 = number % 10;

	printf("%u %u %u %u\n", d4, d3, d2, d1);

	return 0;
}

#endif

#if 0

int main(void) {
	int number;
	scanf("%d", &number);

	// Approach 1: mod operation
	if (number % 2) {
		printf("Odd\n");
	}
	else {
		printf("Even\n");
	}

	// Approach 2: Bit operation
	if (number & 1u) {
		printf("Odd\n");
	}
	else {
		printf("Even\n");
	}

	// Approach 3: ternary operator
	printf(number & 1u ? "Odd\n" : "Even\n");

	return 0;
}

#endif

#if 0

unsigned int getFactor(int number) {
	if (number % 2 == 0) return 2;
	if (number % 3 == 0) return 3;
	if (number % 5 == 0) return 5;
	return 0;
}

int main(void) {
	int number;
	scanf("%d", &number);

	unsigned int factor = getFactor(number);
	printf("%u\n", factor);

	return 0;
}

#endif


#if 0

#include <windows.h>

int main(void) {
	SetConsoleOutputCP(65001); // 한글 설정

	unsigned int score;
	char* result;

	scanf("%u", &score);

	if (score >= 70) result ="합격입니다.";
	else if (score >= 60) result = "재시험보세요.";
	else result = "불합격입니다.";

	printf("%s\n감사합니다.\n", result);

	return 0;
}

#endif

#if 0

int main(void) {
	unsigned int score;
	char grade;

	scanf("%u", &score);

	switch (score / 10) {
	case 10:
	case 9:
		grade = 'A';
		break;
	case 8:
		grade = 'B';
		break;
	case 7:
		grade = 'C';
		break;
	case 6:
		grade = 'D';
		break;
	default:
		grade = 'F';
	}

	printf("Grade: %c\n", grade);

	return 0;
}

#endif


#if 0

int main(void) {
	unsigned int score;
	char *grade = "FFFFFFDCBAA";

	scanf("%u", &score);
	printf("Grade: %c\n", grade[score / 10]);

	return 0;
}

#endif

#if 0

int main(void) {
	int number1, number2;

	// scanf: return - 입력에 성공한 변수의 개수 => do-while 구현과 동일한 원리
	// 성능 측면 비교:
	//1안)
	// while (scanf("%d", &number1) && number1 > 10);
	//	scanf("%d", &number1);
	// 
	//2안)
	// while (number1 > 10) scanf("%d", &number1);

	// 1안에서 scanf의 반환값을 확인하는 비용 << scanf 비용(I/O)
	// 입력 오류가 발생하면? 어떤 코드가 더 안전한가
	// 잘못된 입력 버퍼를 지우고(비우고) 다시 입력을 받도록 하는 방법도 생각해보자

	while (scanf("%d", &number1) && number1 > 10);
	printf("Number1: %d\n", number1);


	do {
		scanf("%d", &number2);
	} while (number2 > 10);

	printf("Number2: %d\n", number2);
}

#endif


#if 0

int main(void) {
	int number;
	unsigned int sum = 0;

	while (scanf("%d", &number) && number != 0) {
		if (number > 0) sum += number;
	}

	printf("Sum: %u\n", sum);

	return 0;
}

#endif


#if 0

// C에서 길이 4짜리 문자열 비교 vs. 4자리 정수 비교
int main(void) {
	unsigned int targetCode = 1357;
	unsigned int inputCode;

	for (int i = 0; i < 3; i++) {
		printf("Enter password: ");
		scanf("%u", &inputCode);

		if (inputCode != targetCode) {
			printf("Fail. (%d/3)\n", i + 1);
			continue;
		}

		printf("Success!\n");
		return 0;
	}

	printf("Please contact to admin.\n");
	return 0;
}

#endif
