#ifndef __DAY4_LIB_H__

#define __DAY4_LIB_H__
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

// x를 괄호로 묶는 경우 -> x가 배열 이름일 수 있지만 연산(?)으로 들어오는 경우 고려
#define SIZE(x) (sizeof(x) / sizeof((x)[0]))

char* to_upper(char* str);
void my_gets(char* str, int size);
char* my_strcpy(char* to, const char* from);

void Incremement();
int GetNum();

#endif
