#include<iostream>
using namespace std;

int t;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> t;
	while (t--) {
		int A, B, x, y;
		cin >> A >> B >> x >> y;
		

		if (A < B) {
			swap(A, B);
		}

		int gcd = A - B;

		int answer = (gcd - (B % gcd)) * x;

		if (B > gcd) {
			answer = min(answer, (B % gcd) * y);
		}

		cout << gcd << " " << answer << "\n";
	}

}