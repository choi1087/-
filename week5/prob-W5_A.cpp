#include<iostream>
using namespace std;

int t;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> t;
	while (t--) {
		int N;
		cin >> N;
		int* signal = new int[N];
		int* prefix = new int[N];
		for (int i = 0; i < N; i++) {
			cin >> signal[i];
		}

		//computePrefixFunction()
		prefix[0] = 0;
		int k = 0;
		for (int i = 1; i < N; i++) {
			while (k > 0 && signal[i] != signal[k]) {
				//prefix[k] = k;
				k = prefix[k - 1];
			}
			if (signal[i] == signal[k]) {
				k = k + 1;
			}
			prefix[i] = k;
		}

		for (int i = 0; i < N - prefix[N - 1]; i++) {
			cout << signal[i] << " ";
		}
		cout << '\n';
	}
}