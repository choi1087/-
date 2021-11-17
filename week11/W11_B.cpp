#include<iostream>
using namespace std;

struct paperInfo {
	int redNumber, redSize, blueNumber, blueSize;
};

paperInfo solution(int x, int y, int size, char** paper) {
	paperInfo ret;
	ret.redNumber = 0;
	ret.redSize = 0;
	ret.blueNumber = 0;
	ret.blueSize = 0;

	if (size == 1) {
		if (paper[x][y] == 'R') {
			ret.redNumber = 1;
			ret.redSize = 1;
		}
		else {
			ret.blueNumber = 1;
			ret.blueSize = 1;
		}
		return ret;
	}

	paperInfo status[4];
	status[0] = solution(x, y, size / 2, paper);
	status[1] = solution(x + size / 2, y, size / 2, paper);
	status[2] = solution(x, y + size / 2, size / 2, paper);
	status[3] = solution(x + size / 2, y + size / 2, size / 2, paper);

	for (int i = 0; i < 4; i++) {
		ret.redNumber += status[i].redNumber;
		ret.redSize += status[i].redSize;
		ret.blueNumber += status[i].blueNumber;
		ret.blueSize += status[i].blueSize;
	}

	if (ret.redNumber == 0) {
		ret.blueNumber = 1;
	}
	if (ret.blueNumber == 0) {
		ret.redNumber = 1;
	}
	return ret;
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

		char** paper = new char* [n + 1];
		for (int i = 0; i < n + 1; i++) {
			paper[i] = new char [n + 1];
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> paper[i][j];
			}
		}

		paperInfo answer = solution(0, 0, n, paper);

		cout << answer.redNumber << " " << answer.redSize << " " << answer.blueNumber << " " << answer.blueSize << "\n";
	}
}