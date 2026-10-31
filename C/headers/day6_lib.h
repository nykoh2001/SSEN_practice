#pragma once
#ifndef __DAY6_LIB_H__

#define __DAY6_LIB_H__
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

// x를 괄호로 묶는 경우 -> x가 배열 이름일 수 있지만 연산(?)으로 들어오는 경우 고려
#define SIZE(x) (sizeof(x) / sizeof((x)[0]))


void print_2D(int (*p)[3][4]);

void exchange0(int* a, int* b);
void exchange1(int** ap, int** bp);
void exchange2(int*** app, int*** bpp);
void exchange3(int** ap, int** bp);
void exchange4(int*** app, int*** bpp);
void exchange5(int*** app, int*** bpp);

#endif
