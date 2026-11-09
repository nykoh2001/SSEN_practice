#if 1

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

int N, d, k, c;
int curr_count, max_count;
int sushi_rail[3000001 * 2];
int sushi_comb[3001];

// k <= N

void insert_sushi(int sushi) {
	//if (sushi_comb.contains(sushi)) { : C++ 20
	if (sushi_comb[sushi] == 0) curr_count++;
	sushi_comb[sushi]++;
}

int main(void) {
	freopen("11_data.txt", "r", stdin);

	// 입력 최적화 코드
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> d >> k >> c;

	int sushi;
	for (int i = 0; i < N; i++) {
		cin >> sushi;
		sushi_rail[i] = sushi;
		if (i < k)
			insert_sushi(sushi_rail[i]);
	}
	insert_sushi(c);

	for (int i = k; i < N + k; i++) {
		int sushi_to_insert = sushi_rail[i % N], sushi_to_delete = sushi_rail[i - k];
		//cout << i << ": insert(" << sushi_to_insert << "), delete(" << sushi_to_delete << ")" << endl;
		
		sushi_comb[sushi_to_delete]--;
		if (sushi_comb[sushi_to_delete] <= 0) {
			curr_count--;
		}
		insert_sushi(sushi_to_insert);

		if (curr_count > max_count) max_count = curr_count;
		if (max_count == k + 1) break;
	}

	cout << max_count;

	return 0;
}

#endif
