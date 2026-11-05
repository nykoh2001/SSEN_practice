/*
* BFS
* - 인접, 최단거리 이동
* 0. 정점의 타입: 좌표 (r, c)
* 1. 시작점: 입력 받으면서 값이 1인 좌표들이 모두 시작점
* 2. 인접점: 상하좌우
* 3. 끝점: 연결된 모든 안익은 토마토를 방문
* 4. 방문 표시: 그래프에 익은 일수 표시
* 5. 시작점을 여러 개 두고 BFS 한번 실행
* 6. 큐의 크기: 1000 * 1000 + 1 이상
* 
* - input -> 안익은 토마토 세기, 전부 익은 경우도 고려
* - 모두 익힘 판정 -> unripe - rear == 0 => 모두 익음
*/

#if 0

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#define MAX_R_C 1001
#define MAX_CELLS (MAX_R_C * MAX_R_C)

typedef struct _coordinate {
	int r;
	int c;
} coordinate;

coordinate moves[] = { { 0, 1 },{ 1, 0 },{ 0,-1 },{ -1,0 } };

int unripe_tomato;
int R, C;
int front, rear;

coordinate Queue[MAX_CELLS];
int graph[MAX_R_C][MAX_R_C];

void input_data() {
	front = rear = 0;
	int num;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			scanf("%d ", &num);
			graph[i][j] = num;
			if (graph[i][j] == 0) unripe_tomato++;
			if (graph[i][j] == 1) Queue[rear++] = (coordinate){ i, j };
		}
	}
}

void print_data() {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++)
			printf("%3d ", graph[i][j]);
		printf("\n");
	}
	printf("\n");
}

int BFS() {
	if (unripe_tomato == 0) return 0;
	if (!rear) return -1; // Edge 1: 익은 토마토가 하나도 없을 때

	coordinate curr;
	int new_r, new_c;
	
	while (front < rear) {
		curr = Queue[front++];

		for (int i = 0; i < 4; i++) {
			new_r = curr.r + moves[i].r;
			new_c = curr.c + moves[i].c;

			if (new_r < 0 || new_c < 0 || new_r >= R || new_c >= C || graph[new_r][new_c] != 0) continue;

			Queue[rear++] = (coordinate){ new_r, new_c };
			graph[new_r][new_c] = graph[curr.r][curr.c] + 1;
		}
	}

	return graph[curr.r][curr.c] - 1;
}

int main(void) {
	//freopen("04_data.txt", "r", stdin);

	unripe_tomato = 0;

	scanf("%d %d\n", &C, &R); // TODO: 확인

	input_data();
	int already_riped = rear;
	//print_data();

	int days = BFS();
	//print_data();

	printf("%d", ((unripe_tomato != rear - already_riped) ? -1 : days));

	return 0;
}


#endif
