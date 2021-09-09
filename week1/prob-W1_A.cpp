#include<iostream>

using namespace std;

int t;

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> t;
	while(t--){
		string s;
		int k;
		cin >> s;
		cin >> k;

		for (int i = 0; i < k; i++) {
			int j = 0;
			while (true) {
				if ((i + j) >= s.length()) {
					break;
				}
				cout << s[i + j];

				if ((j + 2 * k - i - 1) >= s.length()) {
					break;
				}
				cout << s[j + 2 * k - i - 1];
				j += 2 * k;				
			}
		}		
		cout << "\n";
	}

}