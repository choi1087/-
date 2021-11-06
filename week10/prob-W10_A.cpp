#include<iostream>
#include<deque>
using namespace std;

int change(int x) {
	int temp = 0;
	temp += x / 1000;
	x %= 1000;

	temp += x / 100 * 10;
	x %= 100;

	temp += x / 10 * 100;
	x %= 10;

	temp += x / 1 * 1000;
	x %= 1;

	return temp;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		int a, b;
		cin >> a >> b;

		bool* visited = new bool[10000]{ false };
		deque<int> q;
		q.push_back(a);

		int cnt = 0;
		bool CONTINUE = true;
		while (CONTINUE) {
			cnt++;

			int qSize = q.size();
			for (int i = 0; i < qSize; i++) {
				int target = q.front();
				q.pop_front();

				int case1 = target - 1;
				int case2 = target + 1;
				int case3 = change(target);

				if (target == 0) {
					case1 = target;
				}

				if (target == 9999) {
					case2 = target;
				}

				if (case1 == b || case2 == b || case3 == b) {
					cout << cnt << "\n";
					CONTINUE = false;
					break;
				}
				else {
					if (!visited[case1]) {
						visited[case1] = true;
						q.push_back(case1);
					}
					if (!visited[case2]) {
						visited[case2] = true;
						q.push_back(case2);
					}
					if (!visited[case3]) {
						visited[case3] = true;
						q.push_back(case3);
					}
				}
			}
		}

	}
}