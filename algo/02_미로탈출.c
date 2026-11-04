#if 0
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_X_Y 102
#define MAX_N (MAX_X_Y * MAX_X_Y)
#define MOVE_SIZE 4

typedef struct _coordinate {
	int x;
	int y;
} coordinate;

int front, rear;
coordinate Queue[MAX_N];
int graph[MAX_X_Y][MAX_X_Y] = { 0, };

int X, Y;
int start_x, start_y, dest_x, dest_y;

/*
* BFS
* - 인접, 최단거리 이동
* 0. 정점의 타입 결정 (2차원 좌표)
* 1. 시작점: 1개 이상, 여러 개인 경우 하나씩 따로 사용 또는 여러 개 동시 사용 결정
* 2. 인접점: 인접의 정의
* 3. 끝점: 1개 이상
* 4. 방문 표시: 0과 1 사용, 이미 방문한 곳은 재방문하지 않도록. 비용을 기록해서 더 낮은 비용으로 이동. (visited 없이, graph 값을 방문 후 해당 칸 도달까지 걸린 시간을 기록)
* 5. BFS를 한번 실행 or 여러 번 실행
* 6. 큐의 크기 계산
*/

void input_data() {
	scanf("%d %d", &X, &Y);
	scanf("%d %d %d %d", &start_x, &start_y, &dest_x, &dest_y);

	char row[MAX_X_Y];
	for (int y = 1; y <= Y; y++) {
		scanf("%s", row + 1); // TODO: row + 1: 1번째 인덱스부터 사용하므로 row[1] 위치부터 값을 입력 받기 위해
		for (int x = 1; x <= X; x++) {
			graph[y][x] = row[x] - '0'; // row[x]: 0 or 1
		}
	}
}

void print_data() {
	for (int i = 1; i <= Y; i++) {
		for (int j = 1; j <= X; j++)
			printf("%d", graph[i][j]);
		printf("\n");
	}
	printf("\n");
}

int BFS() {
	coordinate move[4] = { (coordinate) { 1,0 }, (coordinate) { 0, 1 }, (coordinate) { -1,0 }, (coordinate) { 0, -1 } };
	front = rear = 0;

	Queue[rear++] = (coordinate){ start_x, start_y };
	graph[start_y][start_x] = 1;

	while (front < rear) {
		coordinate curr = Queue[front++];

		for (int move_idx = 0; move_idx < MOVE_SIZE; move_idx++) {
			int new_x = curr.x + move[move_idx].x;
			int new_y = curr.y + move[move_idx].y;

			if (new_x > X || new_x <= 0 || new_y > Y || new_y <= 0 || graph[new_y][new_x]) // MAX_X_Y가 아닌 논리적 경계 (X, Y)를 기준으로 범위 유효성 검사
				continue;

			if ((new_x == dest_x) && (new_y == dest_y)) {
				graph[new_y][new_x] = graph[curr.y][curr.x] + 1;
				return graph[new_y][new_x] - 1;
			}

			Queue[rear++] = (coordinate){ new_x, new_y };
			graph[new_y][new_x] = graph[curr.y][curr.x] + 1;
		}
	}
	return 0; // 가는 방법이 없는 경우 or 시작 == 목표점인 경우
}

int main(void) {
	freopen("02_data.txt", "r", stdin);

	input_data();
	int result = BFS();

	//print_data();

	printf("%d", result);

	return 0;
}

#endif
