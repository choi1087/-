#include<iostream>
using namespace std;

void failureFunction(string p, int* failure) {
	failure[0] = 0;
	int i = 1, j = 0;
	while (i < p.size()) {
		if (p[i] == p[j]) {
			failure[i] = j + 1;
			i++;
			j++;
		}
		else if (j > 0) {
			j = failure[j - 1];
		}
		else {
			failure[i] = 0;
			i++;
		}
	}
}

bool kmpMatch(string t, string p, int* failure) {
	int i = 0, j = 0;
	while (i < t.size()) {
		if (t[i] == p[j]) {
			if (j == p.size() - 1) {
				return true;
			}
			i++;
			j++;
		}
		else if (j > 0) {
			j = failure[j - 1];
		}
		else {
			i++;
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	string* board = new string[n];
	int* failure = new int[n];

	for (int i = 0; i < n; i++) {
		cin >> board[i];
	}

	string text = "";	

	//가로
	for (int i = 0; i < n; i++) {
		text += board[i];
		text += "$";
	}

	//세로
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			text += board[j][i];
		}
		text += "$";
	}

	//대각선
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - i; j++) {
			text += board[j][i + j];
		}
		text += "$";
	}

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < n - i; j++) {
			text += board[i + j][j];
		}
		text += "$";
	}

	while (m--) {
		string word;
		cin >> word;

		failureFunction(word, failure);
		if (kmpMatch(text, word, failure)) {
			cout << 1 << "\n";
		}
		else {
			cout << 0 << "\n";
		}
	}
}