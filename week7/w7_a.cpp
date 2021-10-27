#include<iostream>
#include<vector>
using namespace std;


//깊이 우선 탐색
void dfs(int u, vector<int>*graph, int*visit) {
	visit[u] = 1; //u번 노드 방문 체크

	for (int i = 0; i < graph[u].size(); i++) {
		int v = graph[u][i];
		if (visit[v] == 0) {
			dfs(v, graph, visit);
		}
	}
}

int t;

//양팔 저울, graph traversal 알고리즘
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> t;
	while (t--) {
		int n, m; //공 개수, 비교 횟수

		cin >> n >> m;

		vector<int>* graph = new vector<int>[n + 1];
		int* visit = new int[n + 1]{ 0 };

		for (int i = 0; i < m; i++) {
			int a, b;
			cin >> a >> b; //a가 b보다 무거움
			graph[a].push_back(b); //a->b 간선 추가
		}

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) { //O(N)
				visit[j] = 0; //visite 배열 초기화
			}

			//깊이 우선 탐색, i번 공보다 가벼운 공 탐색
			dfs(i, graph, visit); //O(N+M)
			int answer = 0;

			for (int j = 1; j <= n; j++) { //O(N)
				answer += visit[j];
			}
			cout << answer - 1 << " ";
		}
		cout << "\n";
	}
}