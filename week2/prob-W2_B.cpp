#include<iostream>
#include<utility>
#include<algorithm>
using namespace std;

int t;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> t;
	while (t--) {
		int n;
		cin >> n;

		int* resourceA = new int[n];
		int* resourceB = new int[n];
		pair<int, int>* resourceSum = new pair<int, int>[n];

		for (int i = 0; i < n; i++) {
			cin >> resourceA[i] >> resourceB[i];
			resourceSum[i] = make_pair(resourceA[i] + resourceB[i], i);
		}
	
		sort(resourceSum, resourceSum + n);		

		int answer = 0;
		bool flag = true;

		for (int i = n - 1; i >= 0; i--) {
			if (flag) {
				answer += resourceA[resourceSum[i].second];
				flag = false;
			}
			else {
				answer -= resourceB[resourceSum[i].second];
				flag = true;
			}
		}
		cout << answer << "\n";
	}
}
