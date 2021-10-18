#include<iostream>
#include<string.h>
using namespace std;

int t;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> t;
	while (t--) {
		int N, M;
		cin >> N >> M;
		
		int** total = new int*[N];
		for (int i = 0; i < N; i++) {
			total[i] = new int[N];
			memset(total[i], 0, sizeof(int) * N);
		}

		int* count = new int[N] {0};

		for (int i = 0; i < N; i++) {
			total[i][i] = 1;
		}

		for (int i = 0; i < M; i++) {
			int A, B;
			cin >> A >> B;
			total[A - 1][B - 1] = 5;
			total[B - 1][A - 1] = 4;
		}			

		for (int k = 0; k < N; k++) {
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					if (total[i][k] == 5 && total[k][j] == 5) {
						total[i][j] = 5;
					}
					else if (total[i][k] == 4 && total[k][j] == 4) {
						total[i][j] = 4;
					}
				}
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (total[i][j] == 5) {
					count[i]++;
				}
			}
		}		

		for (int i = 0; i < N; i++) {
			cout << count[i] << " ";
		}
		cout << "\n";
	}
}