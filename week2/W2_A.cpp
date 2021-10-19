#include<iostream>
#include<deque>
using namespace std;


int t;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> t;
	while (t--) {
		int N, M;
		cin >> N >> M;
		deque<string>professor;
		deque<string>* student = new deque<string>[N];

		//교수
		for (int i = 0; i < M; i++) {
			string str;
			cin >> str;
			professor.push_back(str);
		}

		//학생
		for (int i = 0; i < N; i++) {	
			int cnt;
			cin >> cnt;
			for (int j = 0; j < cnt; j++) {
				string str;
				cin >> str;
				student[i].push_back(str);
			}
		}
		bool isTrue;
		while (!professor.empty()) {
			string target = professor.front();
			professor.pop_front();
			isTrue = false;

			for (int i = 0; i < N; i++) {
				string temp = student[i].front();
				if (target == temp) {
					isTrue = true;
					student[i].pop_front();
					break;
				}
			}

			if (!isTrue) {
				break;
			}
		}

		cout << isTrue << "\n";
	}
}