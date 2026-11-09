/* https://oj.tgthetop.synology.me/problem.php?cid=1004&pid=26 */

//#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <queue>

using namespace::std;

int main(void) {
	//freopen("01_data.txt", "r", stdin);

	int N, E;
	cin >> N >> E;

	int node1, node2;
	vector<vector<int>> graph;
	vector<bool> visited;
	queue<int> nodes_to_visit;

	for (int i = 0; i < N + 1; i++) {
		graph.push_back(vector<int>());
		visited.push_back(false);
	}
	for (int i = 0; i < E; i++) {
		cin >> node1 >> node2;
		graph[node1].push_back(node2);
		graph[node2].push_back(node1);
	}

	nodes_to_visit.push(1);
	visited[1] = true;
	int total_infected_computer = 0;

	while (nodes_to_visit.size()) {
		int current_node = nodes_to_visit.front();
		nodes_to_visit.pop();

		int next_node;
		for (auto it = graph[current_node].begin(); it != graph[current_node].end(); it++) {
			next_node = *it;

			if (visited[next_node]) continue;
			visited[next_node] = true;
			nodes_to_visit.push(next_node);
			total_infected_computer++;
		}
	}

	cout << total_infected_computer << endl;
	
	return 0;
}
