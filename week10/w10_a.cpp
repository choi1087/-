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

		vector<int>road[10000]; //A�� �濡�� �̵��� �� �ִ� ���� ��ȣ�� ����
		int check[10000];
		queue<int>que; //BFS �˰��򿡼� ����� ť
		
		for (int i = 0; i < 10000; i++) {			
			
			check[i] = 10000;

			//i�� �濡�� �̵��� �� �ִ� ���� ��ȣ�� ���
			if (i != 0) {
				road[i].push_back(i - 1);
			}
			if (i != 9999) {
				road[i].push_back(i + 1);
			}

			int num = 0;
			int temp = i;

			//�� ��ȣ�� �������� ������ ��ȣ�� ��
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