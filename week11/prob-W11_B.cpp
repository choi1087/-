#include<iostream>
using namespace std;


int red, blue;
int redTotal, blueTotal;

void rotation(char** paper, int a, int b, int n) {
	char target = paper[a][b];
	bool flag = true;

	for (int i = a; i < a + n; i++) {
		if (!flag) {
			break;
		}
		for (int j = b; j < b + n; j++) {

			//일치하지 않으면 분할 및 재귀
			if (target != paper[i][j]) {
				flag = false;
				n /= 2;
				rotation(paper, a, b, n);
				rotation(paper, a, b + n, n);
				rotation(paper, a + n, b, n);
				rotation(paper, a + n, b + n, n);
				break;
			}
		}
	}

	//a, b 범위 내의 데이터들이 모두 target과 일치한 경우
	if (flag) {
		if (target == 'R') {
			red++;
			redTotal += n * n;
		}
		else {
			blue++;
			blueTotal += n * n;
		}
	}
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
		char** paper = new char*[n];
		for (int i = 0; i < n; i++) {
			paper[i] = new char[n];
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> paper[i][j];
			}
		}
		
		red = 0;
		blue = 0;
		redTotal = 0;
		blueTotal = 0;

		rotation(paper, 0, 0, n);
		cout << red << " " << redTotal << " " << blue << " " << blueTotal << "\n";
		
	}
}