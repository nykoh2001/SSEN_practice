#pragma once
#ifndef __DAY7_LIB_H__

#define __DAY7_LIB_H__
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

// x를 괄호로 묶는 경우 -> x가 배열 이름일 수 있지만 연산(?)으로 들어오는 경우 고려
#define SIZE(x) (sizeof(x) / sizeof((x)[0]))

int sum(int a, int b);
int sub(int a, int b);
int mul(int a, int b);
int divi(int a, int b);
int mod(int a, int b);

int comp_asc(int a, int b);
int comp_desc(int a, int b);
void sort_array(int* arr, int size, int(*comp)(int, int));

int compInt(const void* a, const void* b);
int compDouble(const void* a, const void* b);
void print_doubledata(double* arr, int size);

void print_strdata(char** str, int size);
int compStr(void* str1, void* str2);

void print_2Darr(int (*arr)[3], int r, int c);
int comp2D(const void* a, const void* b);

#endif
