#include<iostream>
#include<algorithm>
using namespace std;


struct information {
	int score;
	int distance;

	bool operator<(information inf) {
		if (this->score == inf.score) {
			return this->distance < inf.distance;
		}
		return this->score > inf.score;
	}
};

bool compare(information i1, information i2) {
	if (i1.score == i2.score) {
		return i1.distance < i2.distance;
	}
	return i1.score > i2.score;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;

		information* info = new information[n + 1];
		for (int i = 0; i < n; i++) {
			cin >> info[i].score >> info[i].distance;
		}

		sort(info, info + n, compare);

		int answer = 1;
		int dist = info[0].distance;
		for (int i = 1; i < n; i++) {
			if (info[i].distance < dist) {
				answer++;
				dist = info[i].distance;
			}
		}
		cout << answer << "\n";
	}
}