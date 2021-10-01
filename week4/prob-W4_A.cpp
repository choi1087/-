#include<iostream>
using namespace std;

int t;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> t;
	while (t--) {
		int A, B, x, y;
		cin >> A >> B >> x >> y;

		int g = abs(A - B); //최대공약수의 최댓값
		int cost = (g - (B % g)) * x;

		if (min(A, B) >= g) {
			cost = min(cost, ((B % g) * y));
		}
		cout << g << " " << cost << "\n";
	}
}