#include<iostream>
#include<deque>
using namespace std;

int t;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		deque<string>professor;
		deque<string>* student = new deque<string>[n];
		for (int i = 0; i < m; i++) {
			string str;
			cin >> str;
			professor.push_back(str);
		}

		for (int i = 0; i < n; i++) {
			int k;
			cin >> k;
			for (int j = 0; j < k; j++) {
				string str;
				cin >> str;
				student[i].push_back(str);
			}
		}

		int answer = 1;

		while (!professor.empty()) {
			bool flag = false;
			for (int i = 0; i < n; i++) {
				if (student[i].front() == professor.front()) {
					student[i].pop_front();
					professor.pop_front();
					flag = true;
					break;
				}
			}
			if (!flag) {
				answer = 0;
				break;
			}
		}
		cout << answer << "\n";

	}
}