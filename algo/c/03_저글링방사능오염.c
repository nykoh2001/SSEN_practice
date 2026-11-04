#if 1
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_X_Y 102 // 102로 설정, 2칸 여유있게 설정해서 테우리 값은 0으로 남겨두기
#define MAX_N (MAX_X_Y * MAX_X_Y)
#define MOVE_SIZE 4

typedef struct _coordinate {
	int x;
	int y;
} coordinate;

typedef struct _result {
	int duration;
	int dead_juggling;
} result;

int front, rear;
coordinate Queue[MAX_N];
int graph[MAX_X_Y][MAX_X_Y] = { 0, };

int R, C;
int start_x, start_y;

/*
* BFS
* - 인접, 최단거리 이동
* 0. 정점의 타입: 좌표 (y, x)
* 1. 시작점: start_x, start_y
* 2. 인접점: 상하좌우
* 3. 끝점: 모든 저글링을 방문
* 4. 방문 표시: visited 없이, graph 값을 방문하면서 해당 칸 도달까지 걸린 시간을 기록
* 5. BFS를 한번 실행
* 6. 큐의 크기: 100 * 100 + 1 (102 * 102 + 1)
*/

int input_data() {
	int total_juggling = 0;
	scanf("%d %d", &C, &R);

	char row[MAX_X_Y];
	for (int y = 1; y <= R; y++) {
		scanf("%s", row + 1); // TODO: row + 1: 1번째 인덱스부터 사용하므로 row[1] 위치부터 값을 입력 받기 위해
		for (int x = 1; x <= C; x++) {
			graph[y][x] = row[x] - '0'; // row[x]: 0 or 1
			if (row[x] == '1')
				total_juggling++;
		}
	}

	scanf("%d %d", &start_x, &start_y);

	return total_juggling;
}

void print_data() {
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++)
			printf("%d", graph[i][j]);
		printf("\n");
	}
	printf("\n");
}

result BFS() {
	coordinate curr;

	coordinate move[4] = { (coordinate) { 1,0 }, (coordinate) { 0, 1 }, (coordinate) { -1,0 }, (coordinate) { 0, -1 } };
	front = rear = 0;

	Queue[rear++] = (coordinate){ start_x, start_y };
	graph[start_y][start_x] = 3;

	while (front < rear) {
		curr = Queue[front++];

		for (int move_idx = 0; move_idx < MOVE_SIZE; move_idx++) {
			int new_x = curr.x + move[move_idx].x;
			int new_y = curr.y + move[move_idx].y;

			// new_x > C || new_x <= 0 || new_y > R || new_y <= 0 ||  => MAX_X_Y를 102로 설정, 테두리 값은 0으로 초기화되므로 경계 체크 없이 방문 안함
			if (graph[new_y][new_x] != 1)
				continue;

			Queue[rear++] = (coordinate){ new_x, new_y };
			graph[new_y][new_x] = graph[curr.y][curr.x] + 1;
		}
	}
	// NOTE: curr이 큐에 마지막까지 남아있는 좌표 - 가장 큰 값을 갖는 좌표
	return (result) { graph[curr.y][curr.x], rear };
}

int main(void) {
	// 함수 인자는 뒤에서부터 push (stdin -> r -> "~~")
	freopen("03_data.txt", "r", stdin);

	int total_juggling = input_data();
	//print_data();
	result r = BFS();

	//print_data();

	// NOTE: !!!!!!!! 전역 변수인count가 이미 printf 호출 stack 블록에 복사되어 들어간 상태에서 BFS 함수 안에서 count를 변경해도 printf 블록의 count에 반영되지 않음
	//printf("%d\n%d\n", BFS(), count);
	
	printf("%d\n", r.duration);
	printf("%d", total_juggling - r.dead_juggling);

	return 0;
}

#endif
