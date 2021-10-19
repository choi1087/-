#include<iostream>
#include<utility> //pair 
#include<algorithm> //sort
using namespace std;

int t;

bool compare(const pair<int, int>& a, const pair<int, int>& b) {
	if (a.first == b.first) {
		return a.second > b.second;
	}
	return a.first > b.first;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> t;
	while (t--) {
		int N; //자원의 종류의 수
		cin >> N;

		int* resourceA = new int[N];
		int* resourceB = new int[N];
		pair<int, int>* resourceSum = new pair<int, int>[N];

		for (int i = 0; i < N; i++) {
			cin >> resourceA[i] >> resourceB[i];
			resourceSum[i] = make_pair(resourceA[i] + resourceB[i], i);
		}

		//내림차순 정렬
		sort(resourceSum, resourceSum + N, compare);

		int answer = 0;
		for (int i = 0; i < N; i++) {
			if (i % 2 == 0) {
				answer += resourceA[resourceSum[i].second];
			}
			else {
				answer -= resourceB[resourceSum[i].second];
			}
		}

		cout << answer << "\n";
	}
}