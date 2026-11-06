#if 1

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>

#define MAX 0xf700000

using namespace::std;

int N;
bool visited[14] = { false, };
vector<vector<int>> cost_arr;

int MIN_COST = MAX;

void print_data() {
    for (vector<int> cost_row : cost_arr) {
        for (int c : cost_row)
            cout << c << " ";
        cout << endl;
    }
    cout << endl;
}

int dfs(int node, int curr_cost, int iter) {
    if (curr_cost >= MIN_COST) return MAX;

    if (iter == N - 1) {
        if (!cost_arr[node][0]) return MAX;
        int total_cost = curr_cost + cost_arr[node][0];
        MIN_COST = MIN_COST > total_cost ? total_cost : MIN_COST;
        //cout << MIN_COST << endl;
        return MIN_COST;
    }

    int min_cost = MAX;

    for (int next_node = 0; next_node < N; next_node++) {
        if (visited[next_node] || !cost_arr[node][next_node]) continue;

        visited[next_node] = true;
        int new_cost = dfs(next_node, curr_cost + cost_arr[node][next_node], iter + 1);
        visited[next_node] = false;

        min_cost = new_cost < min_cost ? new_cost : min_cost;
    }

    if (min_cost == MAX) return MAX;
    return curr_cost;
}

int main(void) {

     //freopen("07_data.txt", "r", stdin);

    cin >> N;

    int c;
    for (int i = 0; i < N; i++) {
        cost_arr.push_back(vector<int>());
        for (int j = 0; j < N; j++) {
            cin >> c;
            cost_arr[i].push_back(c);
        }
    }
    //print_data();

    visited[0] = true;
    dfs(0, 0, 0);
    //print_data();

    cout << MIN_COST << endl;


    return 0;
}

#endif
