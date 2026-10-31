#if 1

#include "day3_lib.h"

void input_data(int* arr, int size) {
	for (int i = 0; i < size; i++) {
		scanf("%d", &arr[i]);
		//scanf("%d", arr + i);
	}
}

void print_data(int* arr, int size) {
	for (int i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int sum_data(int* score, int size) {
	int sum = 0;
	for (int i = 0; i < size; i++) sum += score[i];
	return sum;
}

double avg_data(int* score, int size) {
	int sum = sum_data(score, size);
	return (double)sum / size;
}

void swap(int* a, int* b) {
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}


int findmax_ary(int* arr, int size) {
	int max = arr[0];
	for (int i = 1; i < size; i++)
		if (max < arr[i]) max = arr[i];

	return max;
}

int findmin_ary(int* arr, int size) {
	int min = arr[0];
	for (int i = 1; i < size; i++)
		if (min > arr[i]) min = arr[i];

	return min;
}

void sort_ary(int* arr, int size) {
	for (int i = 0; i < size - 1; i++) {
		for (int j = i + 1; j < size; j++) {
			if (arr[i] > arr[j]) {
				swap(&arr[i], &arr[j]);
			}
		}
	}
}

#endif
