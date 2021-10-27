#include<iostream>
#include<vector>
using namespace std;


//���� �켱 Ž��
void dfs(int u, vector<int>*graph, int*visit) {
	visit[u] = 1; //u�� ��� �湮 üũ

	for (int i = 0; i < graph[u].size(); i++) {
		int v = graph[u][i];
		if (visit[v] == 0) {
			dfs(v, graph, visit);
		}
	}
}

int t;

//���� ����, graph traversal �˰���
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> t;
	while (t--) {
		int n, m; //�� ����, �� Ƚ��

		cin >> n >> m;

		vector<int>* graph = new vector<int>[n + 1];
		int* visit = new int[n + 1]{ 0 };

		for (int i = 0; i < m; i++) {
			int a, b;
			cin >> a >> b; //a�� b���� ���ſ�
			graph[a].push_back(b); //a->b ���� �߰�
		}

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) { //O(N)
				visit[j] = 0; //visite �迭 �ʱ�ȭ
			}

			//���� �켱 Ž��, i�� ������ ������ �� Ž��
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