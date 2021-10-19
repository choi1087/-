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

		int* signal = new int[N]; //주파수
		int* prefix = new int[N]; //접두사, 접미사 일치 길이

		//주파수 입력
		for (int i = 0; i < N; i++) {
			cin >> signal[i];
		}

		
		prefix[0] = 0; //접두사, 접미사 0번째는 일치 길이 0
		int k = 0; //길이 0부터 시작

		for (int i = 1; i < N; i++) {

			//일치 길이가 0이상이고, 해당 수가 k번째 수와 일치하지 않으면
			while (k > 0 && signal[i] != signal[k]) {
				k = prefix[k - 1]; //이전 일치 길이로 갱신
			}

			//현재 주파수와 k번째 주파수가 같으면
			if (signal[i] == signal[k]) {
				k++; //일치 길이 증가
			}

			prefix[i] = k; //일치 길이 갱신
		}

		for (int i = 0; i < N - prefix[N - 1]; i++) {
			cout << signal[i] << " ";
		}
		cout << "\n";

	}
}