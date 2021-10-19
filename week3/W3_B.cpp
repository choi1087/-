#include<iostream>
#include<vector>
using namespace std;

struct roadInfo {
	int neighbor;
	int distance;
};

int t;
int answer;

int treeSearch(int u, vector<roadInfo>* house, bool* visited) {

	int maxDist = 0;
	int secondDist = 0;
	int tempDist;
	
	visited[u] = true;

	for (int i = 0; i < house[u].size(); i++) {
		int target = house[u][i].neighbor;

		//이전에 방문한적 없다면
		if (visited[target] == false) {
			tempDist = treeSearch(target, house, visited) + house[u][i].distance;

			if (tempDist > maxDist) {
				swap(tempDist, maxDist);				
			}
			if (tempDist > secondDist) {
				swap(tempDist, secondDist);
			}
		}
	}

	answer = max(answer, maxDist + secondDist);

	return maxDist;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		vector<roadInfo>* house = new vector<roadInfo>[n + 1];
		bool* visited = new bool[n + 1]{ false };
		answer = 0;
		for (int i = 0; i < n - 1; i++) {
			int u, v, d;
			cin >> u >> v >> d;
			house[u].push_back({ v,d });
			house[v].push_back({ u,d });
		}

		treeSearch(1, house, visited);
		cout << answer << "\n";
	}
}