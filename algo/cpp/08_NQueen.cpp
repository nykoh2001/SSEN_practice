#if 1

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <set>

using namespace::std;

typedef pair<int, int> coordinate;

int N, total_case;
vector<coordinate> coords;

void print_coords() {
	for (coordinate coord : coords) {
		cout << coord.first << ", " << coord.second << endl;
	}
}

bool is_valid(coordinate p1) {
	int r1 = p1.first, c1 = p1.second;
	
	for (coordinate p2 : coords) {
		int r2 = p2.first, c2 = p2.second;

		// NOTE: 가로 체크는 필요 없음, 각 행에는 하나씩의 퀸이 있으므로 하나 두고 다음 행으로 넘어가면 됨
		//if (r1 == r2) return false;

		// 세로 체크
		if (c1 == c2) return false;

		// 대각 체크
		if (r1 - c1 == r2 - c2 || r1 + c1 == r2 + c2) {
			return false;
		}
	}

	return true;
}

void dfs(int r, int iter) {
	if (iter == N) {
		total_case++;
		return;
	}
	for (int i = 0; i < N; i++) {
		if (!is_valid({r, i})) continue;
		coords.push_back({ r, i });
		dfs(r+1, iter + 1);
		coords.pop_back();
	}
}

int main(void) {
	//freopen("08_data.txt", "r", stdin);

	cin >> N;

	dfs(0, 0);
	
	cout << total_case << endl;

	return 0;
}

#endif
