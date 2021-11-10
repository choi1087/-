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
		int* matryoshka = new int[n + 1];
		int* dp = new int[n + 1];

		for (int i = 1; i < n + 1; i++) {
			cin >> matryoshka[i];
		}

		int answer = 0;
		for (int i = 1; i < n + 1; i++) {
			dp[i] = 1;
			for (int j = 1; j < i; j++) {
				if (matryoshka[j] < matryoshka[i]) {
					dp[i] = max(dp[i], dp[j] + 1);
				}
			}
			answer = max(dp[i], answer);
		}
		cout << answer << "\n";
	}
}