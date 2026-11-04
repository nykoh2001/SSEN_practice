#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#if 1

#define MAX_N 101
#define TEMP_N 10

int N, E;
int node1, node2;
int adj_matrix[MAX_N][MAX_N] = { 0, };
int adj_list[MAX_N][MAX_N] = { 0, };

int visited[MAX_N];
int Queue[MAX_N];
int rear, front; // 삽입할 위치, 삭제할 위치

void print_adj_matrix(int (*arr)[MAX_N], int n) {
	for (int j = 1; j <= N; j++) {
		if (arr[n][j])
			printf("%d ", j);
	}
	printf("\n");
}

void print_adj_list(int (*arr)[MAX_N], int node) {
	int count = arr[node][0];
	for (int j = 1; j <= count; j++) {
		printf("%d ", arr[node][j]);
	}
	printf("\n");
}

// 인접 행렬
void input_matrix() {
	for (int i = 0; i < E; i++) {
		scanf("%d %d", &node1, &node2);
		adj_matrix[node1][node2] = 1;
		adj_matrix[node2][node1] = 1;
	}
}

// 인접 리스트
void input_list() {
	int node_count;
	for (int i = 0; i < E; i++) {
		scanf("%d %d", &node1, &node2);

		adj_list[node1][++adj_list[node1][0]] = node2;
		adj_list[node2][++adj_list[node2][0]] = node1;
	}
}

void enqueue(int no) {
	Queue[rear++] = no;
}

int dequeue() {
	return Queue[front++];
}

int virus_BFS1(int start) {
	front = 0;
	rear = 0;

	enqueue(start);
	visited[start] = 1;

	while (front < rear) {
		int curr_node = dequeue();
		for (int i = 1; i < N; i++) {
			if (adj_matrix[curr_node][i] && !visited[i]) {
				enqueue(i);
				visited[i] = 1;
			}
		}
	}
	return rear - 1;
}

int virus_BFS2(int start) {
	front = 0;
	rear = 0;

	enqueue(start);
	visited[start] = 1;

	while (front < rear) {
		int curr_node = dequeue();

		int next_node;
		int adj_count = adj_list[curr_node][0];
		for (int i = 1; i <= adj_count; i++) {
			if ((next_node = adj_list[curr_node][i]) && !visited[next_node]) {
				enqueue(next_node);
				visited[next_node] = 1;
			}
		}
	}
	return rear - 1;
}

int main(void) {
	freopen("01_data.txt", "r", stdin);

	scanf("%d", &N);
	scanf("%d", &E);
	
#if 0
	input_matrix();
	//print_adj_matrix(adj_matrix, 2);
	printf("Connected node count (Matrix): %d\n", virus_BFS1(1));

#else if 1
	input_list();
	//print_adj_list(adj_list, 1);
	printf("Connected node count (List): %d\n", virus_BFS2(1));

#endif
	return 0;
}

#endif
