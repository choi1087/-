#include<iostream>
using namespace std;

int t;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> t;
	while (t--) {
		string S;
		cin >> S;
		int K;
		cin >> K;	

		int maxLength = S.length();

		if (K > maxLength) {
			cout << S << endl;
		}
		else {
			int j = 0;			
			for (int i = 0; i < K; i++) {
				int j = 0;
				while (true) {
					if (i + j >= maxLength) {
						break;
					}
					else {
						cout << S[i + j];
					}

					if (j + K * 2 - i - 1 >= maxLength) {
						break;
					}
					else {
						cout << S[j + K * 2 - i - 1];
					}
					j += 2 * K;
				}				
			}
		}
		
		cout << "\n";
	}
}
