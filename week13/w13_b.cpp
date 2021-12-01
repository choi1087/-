#include<iostream>
#include<set>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;

		int* messenger = new int[m];
		int* answer = new int[m];

		for (int i = 0; i < m; i++) {
			cin >> messenger[i];
		}

		set<int> readers;
		for (int i = m - 1; i >= 0; i--) {
			if (readers.find(messenger[i]) == readers.end()) {
				readers.insert(messenger[i]);
			}
			answer[i] = n - readers.size();
		}

		for (int i = 0; i < m; i++) {
			cout << answer[i] << "\n";
		}		
	}
}