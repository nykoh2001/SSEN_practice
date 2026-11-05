/*
* BFS
* - 인접, 최단거리 이동
* 0. 정점의 타입: 좌표 (r, c)
* 1. 시작점: 가장자리 패딩
* 2. 인접점: 상하좌우
* 3. 끝점: 산꼭대기
* 4. 방문 표시: distance에 거리 표시, 현재 방문에서 계산된 값이 지금까지의 방문에서 계산한 값보다 크거나 같으면 이미 방문한 것으로 처리
* 5. 시작점을 여러 개 두고 BFS 한번 실행
* 6. 큐의 크기: 100 * 100 + 1 이상
*/

#if 1

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

#define MAX_R_C 101
#define MAX_CELL (MAX_R_C * MAX_R_C)

int N;
int peak_r, peak_c;
int graph[MAX_R_C][MAX_R_C];
int distances[MAX_R_C][MAX_R_C];

typedef struct _coordinate {
	int r;
	int c;
} coordinate;

coordinate Queue[MAX_CELL * 10]; // 큐 사이즈 여유 있게
coordinate moves[] = { { 1,0 },{ 0,1 },{ 0,-1 },{ -1,0 } };

int front, rear;

void input_data() {
	scanf("%d", &N);

	scanf("%d %d", &peak_r, &peak_c);
	peak_r--;
	peak_c--;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &graph[i][j]);
			distances[i][j] = INT32_MAX;
			if (i == 0 || i == N - 1 || j == 0 || j == N - 1) {
				Queue[rear++] = (coordinate){ i, j };
				distances[i][j] = pow(graph[i][j], 2);
			}
		}
	}
}

void print_data(int (*arr)[MAX_R_C]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[i][j] == INT32_MAX) {
				printf(" INF");
				continue;
			}
			printf("%4d", arr[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void BFS() {
	coordinate curr;

	while (front < rear) {
		curr = Queue[front++];

		for (int i = 0; i < 4; i++) {
			int new_r = curr.r + moves[i].r;
			int new_c = curr.c + moves[i].c;

			if (new_r < 0 || new_c < 0 || new_r > N - 1 || new_c > N - 1) continue;

			int cost = graph[curr.r][curr.c] - graph[new_r][new_c];
			if (cost < 0) cost = pow(cost, 2); // 오르막길

			if (distances[new_r][new_c] <= distances[curr.r][curr.c] + cost) continue;

			distances[new_r][new_c] = distances[curr.r][curr.c] + cost;

			if (curr.r == peak_r && curr.c == peak_c) continue;
			Queue[rear++] = (coordinate){ new_r, new_c };
		}
	}
}

int main(void) {
	freopen("05_data.txt", "r", stdin);
	
	input_data();
	//print_data(graph);
	//print_data(distances);

	BFS();
	//print_data(distances);
	printf("%d\n", distances[peak_r][peak_c]);

	return 0;
}

#endif
