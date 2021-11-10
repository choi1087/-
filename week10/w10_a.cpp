#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		int a, b;
		cin >> a >> b;

		vector<int>road[10000]; //A번 방에서 이동할 수 있는 방의 번호를 저장
		int check[10000];
		queue<int>que; //BFS 알고리즘에서 사용할 큐
		
		for (int i = 0; i < 10000; i++) {			
			
			check[i] = 10000;

			//i번 방에서 이동할 수 있는 방의 번호를 계산
			if (i != 0) {
				road[i].push_back(i - 1);
			}
			if (i != 9999) {
				road[i].push_back(i + 1);
			}

			int num = 0;
			int temp = i;

			//방 번호를 역순으로 변경한 번호의 방
			for (int j = 0; j < 4; j++) {
				num = num * 10 + temp % 10;
				temp = temp / 10;
			}
			road[i].push_back(num);
		}

		check[a] = 0;
		que.push(a);
		while (!que.empty()) {
			int now = que.front();
			que.pop();

			for (int i = 0; i < road[now].size(); i++) {
				if (check[road[now][i]] > check[now] + 1) {
					que.push(road[now][i]);
					check[road[now][i]] = check[now] + 1;
				}
			}
		}
		cout << check[b] << "\n";

	}
}