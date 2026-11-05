#if 1

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>

using namespace::std;


int N;
pair<int, int> moves[] = { { 0, 1 },{ 1,0 },{ 0, -1 },{ -1, 0 } };

void print_data(vector<string> &graph) {
	for (string str : graph) {
		cout << str << endl;
	}
	cout << endl;
}

int dfs(vector<string> &graph, int r, int c) {
	// dfs 함수로 진입 시점에 방문 처리
	graph[r][c] = '0';
	int size = 1; 
	int new_r, new_c;

	for (pair<int, int> move : moves) {
		new_r = r + move.first;
		new_c = c + move.second;

		if (new_r < 0 || new_c < 0 || new_r >= N || new_c >= N || graph[new_r][new_c] == '0') continue;

		size += dfs(graph, new_r, new_c);
	}

	return size;
}


// Edge: 1 하나짜리 단지
int main(void) {

	//freopen("06_data.txt", "r", stdin);

	vector<int> area;
	vector<string> graph;

	cin >> N;

	string str;
	for (int i = 0; i < N; i++) {
		cin >> str;
		graph.push_back(str);
	}

	//print_data(graph);

	int size;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (graph[i][j] == '0') continue;

			size = dfs(graph, i, j);
			area.push_back(size); 
		}
	}

	sort(area.begin(), area.end());

	cout << area.size() << endl;
	for (int size : area)
		cout << size << endl;

	return 0;
}

#endif
