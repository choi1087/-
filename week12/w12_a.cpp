#include<iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int** numbers = new int*[n + 1];
		int** path = new int* [n + 1];

		for (int i = 0; i < n + 1; i++) {
			numbers[i] = new int[n + 1];
			path[i] = new int[n + 1];
		}

		for (int i = 1; i < n + 1; i++) {
			for (int j = 1; j < i + 1; j++) {
				cin >> numbers[i][j];
			}
		}

		path[1][1] = numbers[1][1];

		for (int i = 2; i < n + 1; i++) {
			path[i][1] = path[i - 1][1] + numbers[i][1]; //i행j번째 수에 도착ㅎ는 경로 중
			for (int j = 2; j < i; j++) {
				path[i][j] = min(path[i - 1][j - 1], path[i - 1][j]) + numbers[i][j];
			}
			path[i][i] = path[i - 1][i - 1] + numbers[i][i];
		}

		int answer = path[n][1];
		for (int j = 2; j < n + 1; j++) {
			answer = min(answer, path[n][j]);
		}

		cout << answer << "\n";
	}
}