#ifndef __DAY3_LIB_H__

#define __DAY3_LIB_H__ // 중복 include 방지, #pragma once로 대체 가능


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// x를 괄호로 묶는 경우 -> x가 배열 이름일 수 있지만 연산(?)으로 들어오는 경우 고려
#define SIZE(x) (sizeof(x) / sizeof((x)[0]))

void input_data(int* arr, int size);
void print_data(int* arr, int size);
int sum_data(int* score, int size);
double avg_data(int* score, int size);

void swap(int* a, int* b);

int findmax_ary(int* arr, int size);
int findmin_ary(int* arr, int size);
void sort_ary(int* arr, int size);

#endif
